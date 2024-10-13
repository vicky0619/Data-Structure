#include <bits/stdc++.h>
using namespace std;
#define BUFFER_SIZE 100
#define IS_FULL(x) (!x)
#define COMPARE(x,y) ((x)<(y)?-1:((x)==(y)?0:1))
typedef struct poly_node *poly_pointer;
typedef struct poly_node {
	int coef;
	int expon;
	poly_pointer link;
} poly_node;
inline int compare(int x, int y) {
	return (x<y)?-1:(x==y)?0:1;
}
void attach(int coefficient, int exponent, poly_pointer *ptr) {
	poly_pointer temp;
	temp=(poly_pointer)malloc(sizeof(poly_node));
	if (IS_FULL(temp)) {
		fprintf(stderr, "The memory is full\n");
		exit(1);
	}
	temp->coef=coefficient;
	temp->expon=exponent;
	(*ptr)->link=temp;
	*ptr=temp;
}
poly_pointer padd(poly_pointer a, poly_pointer b) {
	poly_pointer front, rear, temp;
	int sum;
	rear=(poly_pointer)malloc(sizeof(poly_node));
	if (IS_FULL(rear)) {
		fprintf(stderr, "The memory is full\n");
		exit(1);
	}
	front=rear;
	while (a && b) {
		switch (COMPARE(a->expon, b->expon)) {
			case -1:
				attach(b->coef, b->expon, &rear);
				b=b->link;
				break;
			case 0:
				sum=a->coef+b->coef;
				if (sum)
					attach(sum, a->expon, &rear);
				a=a->link;
				b=b->link;
				break;
			case 1:
				attach(a->coef, a->expon, &rear);
				a=a->link;
				break;
		}
	}
	for (;a;a=a->link)
		attach(a->coef, a->expon, &rear);
	for (;b;b=b->link)
		attach(b->coef, b->expon, &rear);
	rear->link=NULL;
	temp=front;
	front=front->link;
	free(temp);
	return front;
}
void show(poly_node *p) {
	for (;p!=NULL;p=p->link)
		printf("%d %d\n", p->coef, p->expon);
}
void poly_list_free(poly_node *p) {
	poly_node *temp;
	while (p!=NULL) {
		temp=p->link;
		free(p);
		p=temp;
	}
}
int main(int argc, char *argv[]) {
	char c, buf[BUFFER_SIZE], file_name[]="input3.txt";
	int i, coef, expon, number=0;
	FILE *fPtr;
	poly_node p[2], *rear[2], *pc;
	memset(p, 0, 2*sizeof(poly_node));
	rear[0]=p;
	rear[1]=p+1;
	fPtr=fopen(file_name, "r");
	if (!fPtr) {
		fprintf(stderr, "open file (%s) error.", file_name);
		exit(1);
	}
	while (fgets(buf, sizeof(buf), fPtr)) {
		if ((strlen(buf)==1 && buf[0]=='\n')
				|| (strlen(buf)==2 && buf[0]=='\r' && buf[1]=='\n')) {
			++number;
			continue;
		}
		sscanf(buf, "%d%d", &coef, &expon);
		attach(coef, expon, rear+number);
	}
	fclose(fPtr);
	rear[0]->link=NULL;
	rear[1]->link=NULL;
	pc=padd(p[0].link, p[1].link);
	show(pc);
	poly_list_free(p[0].link);
	poly_list_free(p[1].link);
	poly_list_free(pc);
	return 0;
}