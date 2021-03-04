#include<bits/stdc++.h>
using namespace std;

struct Node 
{
	int data; 
	Node* left;
	Node* right;
};

Node* GetNewNode(int data) 
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

Node* Insert(Node* root,int data) 
{
	if(root == NULL)                                      // empty tree
    {                                           
		root = GetNewNode(data);
	}
	
	else if(data <= root->data)                         // if data to be inserted start lesser, insert inorder left subtree. 
    {
		root->left = Insert(root->left,data);
	}
	
	else                                                // else, insert inorder right subtree. 
    {
		root->right = Insert(root->right,data);
	}
	return root;
}

void spiral_tarversal(Node* root)
{
	if(root==NULL)
	return ;

	queue<Node*>q;
	stack<int>s;
	bool result=false;
	q.push(root);
	while(q.size())
	{
		int size=q.size();
		for(int i=0;i<size;i++)
		{
			Node* temp=q.front();
			q.pop();
			if(!result)
			{
			cout<<temp->data<<" ";
			}
			else
			{
				s.push(temp->data);
			}
			if(temp->left!=NULL)
			q.push(temp->left);
			if(temp->right!=NULL)
			q.push(temp->right);
		}
		if(result)
		{
			while(!s.empty())
			{
				cout<<s.top()<<" "; 
				s.pop();
			}
		}
		result=!result;
		cout<<endl;
	}
}


int main() 
{
	Node* root = NULL;  			// Creating an empty tree
	root = Insert(root,15);	
	root = Insert(root,10);	
	root = Insert(root,20);
	root = Insert(root,8);
	root = Insert(root,12);
	root = Insert(root,17);
	root = Insert(root,25);

	spiral_tarversal(root);
}