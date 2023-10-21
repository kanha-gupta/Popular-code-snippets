#include <iostream>
using namespace std;

// INORDER TRAVERSAL GIVES THE ASCENDING ORDER elements inside 
// OF THE BINARY SEARCH TREE

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* create_node_func(int datais){
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = datais; 
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node * search(struct node* root, int key){
    if(root==NULL){
        return NULL;
    }
    if(key == root->data){
        return root;
    }
    else if(key < root->data){
        return search(root->left, key);
    }
    else{
        return search(root->right, key);
    }
}

int main(){

    struct node* a = create_node_func(101);
    struct node* b = create_node_func(98);
    struct node* c = create_node_func(103);
    struct node* d = create_node_func(97);
    struct node* e = create_node_func(102);

    a->left = b;
    a->right = c;

    b->left = d;
    b->right = NULL;

    c->left = e;
    c->right = NULL;

    d->left = NULL;
    d->right = NULL;

    e->left = NULL;
    e->right = NULL;
    

    struct node* new_var = search(a, 102);
    if(new_var!=NULL){
    printf("Found: %d", new_var->data);
    }
    else{
        printf("Element not found");
    }
    return 0;
}
