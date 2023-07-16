#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int value;
        Node* left;
        Node* right;
        Node(int value)
        {
            this->value=value;
            this->left=NULL;
            this->right=NULL;
        }
};
Node* input_tree()
{
    int val;
    cin >> val;
    Node* root;
    if(val == -1)
    {
        root = NULL;
    }
    else
    {
        root = new Node(val);
    }
    queue<Node*> q;
    if(root)
    {
        q.push(root);
        while(!q.empty())
        {
            Node* p = q.front();
            q.pop();
            int l,r;
            cin >> l >> r;
            Node* myleft;
            Node* myright;
            if(l == -1)
            {
                myleft = NULL;
            }
            else
            {
                myleft = new Node(l);
            }
            if(r==-1)
            {
                myright = NULL;
            }
            else
            {
                myright = new Node(r);
            }
            p->left = myleft;
            p->right = myright; 
        if(p->left)
        {
            q.push(p->left);
        }
        if(p->right)
        {
            q.push(p->right);
        }
        }
    }
    return root;
}
void level_order(Node* root)
{
    if(root == NULL)
    {
        cout << "Blank Tree" << endl;
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* f = q.front();
        q.pop();
        cout<<f->value<<" ";
        if(f->left)
        {
            q.push(f->left);
        }
        if(f->right)
        {
            q.push(f->right);
        }
    } 
}
bool search(Node* root, int x)
{
    if(root == NULL)
    {
        return false;
    }
    if(root->value==x)
    {
        return true;
    }
    if(x < root->value)
    {
        return search(root->left,x);
    }
    else
    {
        return search(root->right,x);
    }
}
int main()
{
    Node* root = input_tree();
    if(search(root,6))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}