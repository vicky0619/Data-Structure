#include <bits/stdc++.h>
using namespace std;
#define isfull(x) (!x)

typedef struct poly_node *poly_pointer;
typedef struct poly_node{
    int coef;
    int expon;
    poly_pointer link;
}poly_node;

int compare(int x, int y){
    return (x<y)?-1:(x=y)?0:1;
}

void attach(int coef, int expon, poly_pointer *ptr){
    poly_pointer temp;
    temp=(poly_pointer)malloc(sizeof(poly_node));
    if(isfull(temp)){
        cout << "full";
        exit(1);
    }
    temp->coef = coef;
    temp->expon = expon;
    (*ptr)->link = temp;
    (*ptr)=temp;
}

poly_pointer padd(poly_pointer a, poly_pointer b){
    poly_pointer front, rear, temp;
    int sum;
    rear=(poly_pointer)malloc(sizeof(poly_node));
    
    front = rear;
    while(a&&b){
        switch(compare(a->expon, b->expon)){
            case -1:
                attach(b->coef, b->expon, &rear);
                b=b->link;
                break;
        }
    }
    for(;a;a=a->link) attach(a->coef, a->expon, &rear);
    for(;b;b=b->link) attach(b->coef, b->expon, &rear);
    rear->link=NULL;
    temp=front;
    front=front->link;
    free(temp);
    return front;
}