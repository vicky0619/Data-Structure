#include <bits/stdc++.h>
using namespace std;

typedef struct node *tree_ptr;
struct node{
    int val;
    tree_ptr left;
    tree_ptr right;
};

void create_binary_tree(int,vector<int> &,tree_ptr*);
void preorder(tree_ptr);
void inorder(tree_ptr);
void postorder(tree_ptr);
bool is_root=1;

int main(){
    int n;
    tree_ptr first;
    cin >> n;
    vector <int> data(n);
    for(int i=0;i<n;i++){
        cin >> data[i];
    }
    create_binary_tree(n, data , &first);
    preorder(first);
    cout << "\n";
    is_root=1;
    inorder(first);
    cout << "\n";
    is_root=1;
    postorder(first);
    return 0;
}

void create_binary_tree(int n,vector<int> & v,tree_ptr* first){
    queue <tree_ptr> q;
    tree_ptr temp;
    tree_ptr now;
    int i=0;
    while(1){
        if(i==0){
            *first = new node;
            (*first)->val=v[0];
            (*first)->left=NULL;
            (*first)->right=NULL;
            q.push(*first);
            i++;
        }
        else{
            if(i>=n) break;
            now=q.front();
            q.pop();
            //處理左節點
            temp = new node;
            temp->val = v[i];
            temp->left=NULL;
            temp->right=NULL;
            now->left=temp;
            q.push(temp);
            i++;
            //處理右節點
            if(i>=n) break;
            temp = new node;
            temp->val = v[i];
            temp->left=NULL;
            temp->right=NULL;
            now->right=temp;
            q.push(temp);
            i++;
        }
    }
}

void preorder(tree_ptr first){
    if(first){
        if(first->val!=0){
            if(is_root){
                cout << first->val;
                is_root=0;
            }
            else{
                cout << " " << first->val;
            }
        }    
        preorder(first->left);
        preorder(first->right); 
    }
}

void inorder(tree_ptr first){
    if(first){
        inorder(first->left);
        if(first->val!=0){
            if(is_root){
                cout << first->val;
                is_root=0;
            }
            else{
                cout << " " << first->val;
            }
        }
        inorder(first->right); 
    }
}

void postorder(tree_ptr first){
    if(first){
        postorder(first->left);
        postorder(first->right);
        if(first->val!=0){
            if(is_root){
                cout << first->val;
                is_root=0;
            }
            else{
                cout << " " << first->val;
            }
        }
    }
}