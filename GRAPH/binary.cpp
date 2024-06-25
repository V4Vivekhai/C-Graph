#include <iostream>
using namespace std;
struct node
{
    int info;
    struct node *right;
    struct node *left;
};

struct node *Createnode(int x)
{
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    p->info=x;
    p->right=NULL;
    p->left=NULL;
    return p;
}

void Inorder(struct node *root)
{
    if(root!=NULL)
    {
        Inorder(root->left);
        printf("%d->",root->info);
        Inorder(root->right);
    }
}

int  SumNode(struct node *root)
{
    
    int Sum = 0;
    if(root==NULL)
    return 0;


    else
    {
        int left = SumNode(root->left);
        int right= SumNode(root->right);
        Sum = Sum +left + right; 
    }
    Sum++;

    return Sum;




}

int main()
{
    struct node *root=NULL;
    root=Createnode(100);
    root->left=Createnode(60);
    root->right=Createnode(40);
    root->left->right=Createnode(500);
    root->right->left=Createnode(450);

    int Result = SumNode(root);
    cout<<"Count of Node is : "<<Result<<endl;

    return 0;
}