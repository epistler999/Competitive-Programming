#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node*left;
    node*right;

    node(int d){
        data = d;
        left=NULL;
        right=NULL;
    }
};

node* buildtree()
{
    int t;
    cin>>t;

    if(t==-1){
        return NULL;
    }
    node*root=new node(t);
    root->left=buildtree();
    root->right=buildtree();
    return root;

}
void print(node* root)
{
    if(root==NULL)
        return;
    // otherwise print root first followed by subtrees
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}

int main()
{
    node*root=buildtree();
    print(root);
    return 0;
}

