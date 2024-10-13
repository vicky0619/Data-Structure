#include <bits/stdc++.h>
using namespace std;
#define MAX 100

typedef struct{
    int vert;
    int horiz;
}offsets;

typedef struct{
    int row;
    int col;
    int dir;
}element;

void push(element* stack, int*top, element val){
    stack[++(*top)]=val;
}

element pop(element* stack, int* top){
    return stack[(*top)--];
}

int main(){
    offsets move[8] = {{0, 1}, {1, 0},  {0, -1},  {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    int row_num, col_num;
    cin >> row_num >> col_num;
    int maze[row_num+2][col_num+2];
    for(int i = 0;i<=row_num+1;i++){
        maze[i][0]=1;
        maze[i][col_num+1]=1;
    }
    for(int i = 0;i<=col_num+1;i++){
        maze[0][i]=1;
        maze[row_num+1][i]=1;
    }
    for(int i = 1;i<=row_num;i++){
        for(int j=1;j<=col_num;j++){
            cin >> maze[i][j];
        }
    }

    bool found=0;
    int top=0, row, col, next_row, next_col, dir;
    element position;
    element stack[MAX];
    bool mark[row_num+1][col_num+1];
    memset(mark, 0, sizeof(mark));
    mark[1][1]=1;
    stack[0].row=1, stack[0].col=1, stack[0].dir=0;
    while(top>-1 &&!found){
        position = pop(stack, &top);
        row = position.row;
        col = position.col;
        dir = position.dir;
        while(dir<8 && !found){
            next_row=row+move[dir].vert;
            next_col=col+move[dir].horiz;
            if(next_row==row_num && next_col==col_num){
                found=1;
                position.row=row;
                position.col=col;
                position.dir=++dir;
                push(stack, &top, position);
            }
            else if(!maze[next_row][next_col]&&!mark[next_row][next_col]){
                mark[next_row][next_col]=1;
                position.row=row;
                position.col=col;
                position.dir=++dir;
                push(stack, &top, position);
                row=next_row;
                col=next_col;
                dir=0;
            }
            else ++dir;
        }
    }  
    if(found){
        stack[top+1].row=row_num;
        stack[top+1].col=col_num;
        top++;

        for(int i=0;i<=top;i++){
            cout << stack[i].row << stack[i].col;
        }
    } 
    return 0;
}