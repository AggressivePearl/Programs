#include <stdio.h>
#include <stdlib.h>

struct tree {
    int data;
    struct tree *left, *right;
};
typedef struct tree node;
typedef node* btree;

btree tree_create(btree, int);
void inorder(btree);
btree search(btree, int);

int main()
{
    btree ptr=NULL;
    int i, data, arr[]={7,1,4,2,8,13,12,11,15,9,5};

    printf("original array");
    for(i=0;i<11;i++){
        ptr=tree_create(ptr, arr[i]);
        printf("[%2d] ", arr[i]);
    }

    printf("\n");
    printf("Please enter a key for searching.");
    scanf("%d", &data);

    if(search(ptr, data) != NULL)
        printf("This is already exist in binary tree.");
    else {
        ptr=tree_create(ptr, data);
        inorder(ptr);
    }
        
    return 0;
}

btree tree_create(btree root, int val)
{
    btree newnode, current, previous;
    newnode=(btree)malloc(sizeof(node));
    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;

    if(root == NULL){
        root=newnode;
        return root;
    } else {
        for(current=root; current != NULL;){
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

btree search(btree ptr, int val)
{
    while(1){
        if(ptr == NULL)
            return NULL;

        if(ptr->data == val)
            return ptr;
        else if(ptr->data > val)
            ptr=ptr->left;
        else
            ptr=ptr->right;
    }
}