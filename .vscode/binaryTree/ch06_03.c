#include <stdio.h>
#include <stdlib.h>

struct tree{
    int data;
    struct tree *left, *right;
};
typedef struct tree node;
typedef node* btree;

btree create_tree(btree, int);
void inorder(btree);

int main()
{
    int i, data[]={5,6,24,8,12,3,17,1,9};
    btree ptr=NULL;

    for(i=0;i < 9;i++)
        ptr=create_tree(ptr, data[i]);

    printf("===================\n");
    printf("result of complete sorting:\n");
    inorder(ptr);
    printf("\n");
    
    return 0;
}

btree create_tree(btree root, int val)
{
    btree newnode,current, previous;
    newnode=(btree)malloc(sizeof(node));
    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;

    if(root == NULL){
        root=newnode;
        return root;    
    } else {
        for(current=root;current != NULL;){
            previous=current;
            if(current->data > val)
                current=current->left;
            else
                current=current->right;
        }

        if(previous->data > val)
            previous->left=newnode;
        else
            previous->right=newnode;
    }
    return root;
}

void inorder(btree ptr)
{
    if(ptr != NULL){
        inorder(ptr->left);
        printf("[%2d] ", ptr->data);
        inorder(ptr->right);
    }
}