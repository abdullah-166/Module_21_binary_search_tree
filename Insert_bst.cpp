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
void insert(Node* &root, int x)
{
    if(root == NULL)
    {
        root = new Node(x);
        return;
    }
    if(x < root->value)
    {
        if(root->left == NULL)
        {
            root->left = new Node(x);
        }
        else
        {
            insert(root->left,x);
        }
    }
    else
    {
        if(root->right == NULL)
        {
            root->right = new Node(x);
        }
        else
        {
            insert(root->right,x);
        }
    }
}
int main()
{
    Node* root = input_tree();
    int x;
    cin >> x;
    insert(root,x);
    level_order(root);
    return 0;
}