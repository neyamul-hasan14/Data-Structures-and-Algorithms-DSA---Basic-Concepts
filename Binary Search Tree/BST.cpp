#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left, *right;
};

node* insert(node* root, int data)
{
    node *temp;
    temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    if(root == NULL)
        return temp;

    if(temp->data < root->data)
        root->left = insert(root->left, temp->data);
    else root->right = insert(root->right, temp->data);

    return root;
}

node* deleteBST(node* root, int key)
{
    if(root==NULL)
        return root;
    else if(key < root->data )
    {
        root->left = deleteBST(root->left, key);
        return root;
    }
    else if(key > root->data)
    {
        root->right = deleteBST(root->right, key);
        return root;
    }
    else
    {
        if(root->left==NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            node *temp = root;
            node *temp1 = temp->right;
            while(temp1->left!=NULL)
            {
                temp = temp1;
                temp1 = temp1->left;
            }
            root->data = temp1->data;
            root->right = deleteBST(root->right, temp1->data);
            return root;
        }
    }
}


void inorder(node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}


int main()
{
    node *root;
    root = NULL;
    while(1)
    {
        cout<<"1. Insert\n2. Inorder\n3. Postorder\n4. Preorder\n5. Delete\n0. Exit"<<endl;
        int x;
        cin>>x;
        if(x==0) break;
        else if(x==1)
        {
            int y;
            cin>>y;
            if(root == NULL)
                root = insert(root, y);
            else
                insert(root, y);
        }
        else if(x==2)
        {
            inorder(root);
            cout<<endl;
        }
        else if(x==5)
        {
            int y;
            cin>>y;
            root = deleteBST(root, y);
        }

    }
}