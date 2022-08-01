#include <stdio.h>
#include <stdlib.h>

struct tree {
    int data;
    struct tree *left, *right;
};

typedef struct tree node;
typedef node* btree;

btree create_tree(btree, int);

int main()
{
    int i, data[]={5,6,24,8,12,3,17,1,9};
    btree ptr=NULL;
    btree root=NULL;

    for(i=0;i<9;i++)
        ptr=create_tree(ptr,data[i]);
    
    printf("left subtree:\n");

    root=ptr->left;
    while(root != NULL){
        printf("%d\n", root->data);
        root=root->left;
    }

    printf("-------------------------\n");

    printf("right subtree:\n");
    root=ptr->right;
    while(root != NULL){
        printf("%d\n", root->data);
        root=root->right;
    }

    printf("\n");
    return 0;
}

btree create_tree(btree root, int val)
{
    btree newnode, current, backup;
    newnode=(btree)malloc(sizeof(node));
    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;

    if(root == NULL){
        root=newnode;
        return root;
    } else {
        for(current=root;current != NULL;){
            backup=current;
            /*
            printf("current->data:%d\n", current->data);
            printf("value:%d\n",val);
            */
            if(current->data > val)         // compare with nextnode
                current=current->left;
            else
                current=current->right;
        }

        if(backup->data > val)
            backup->left=newnode;           // place node
        else
            backup->right=newnode;
    }
    return root;
}