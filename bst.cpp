#include <iostream>
#include "bst.h"

using namespace std;

BST::BST() 
{
	Node* root;
	root = NULL; 
}
BST::~BST() 
{

}
        
void BST::insert(elem_t data) 
{
	root = insert(root, data);
}  

Node* BST::insert(Node* node, elem_t data) 
{
	if (node == NULL)
	{
		node = new Node(data);
	}
	else if (node->key > data)
	{
		node->left = insert(node->left, data);
	}
	else if (data > node->key)
	{
		node->right = insert(node->right, data);
	}
	return node;
}

Node* BST::search(elem_t key) 
{
	return search(root,key);
}
Node* BST::search(Node* node, elem_t key) 
{
	if (root == NULL || root->key == key)
	{
		return root;
	}
	if (root->key < key)
	{
		return search (root->right, key);
	}
	return search (root->left, key);
}

void BST::inorder() 
{

}
void BST::inorder(Node* node) 
{
	if (root != NULL)
	{
		inorder(root->left);
		cout << root->key << " ";
		inorder(root->right);
	}
}
		
void BST::remove(elem_t key)
{
	root = remove(root, key);
}
Node* BST::remove(Node* node, elem_t key)
{
	if (node == NULL)
	{
		return node;
	}
	if (node->key > key)
	{
		node->left = remove(node->left,key);
	}
	else if (key > node->key)
	{
		node->right = remove(node->right, key);
	}
	else
	{
		if (node->left == NULL)
		{
			Node *temp = node->right;
			delete node;
			return temp;
		}
		else if (node->right == NULL)
		{
			Node *temp = node->left;
			delete node;
			return temp;
		}
		else
		{
			Node *temp = leftmostNode(node->left);
			node->key = temp->key;
			node->left = delete(node->left, temp->key);
		}
	}
	return node;
}

Node* BST::leftmostNode(Node* node)
{
	Node* current = node;
	while (current->right != NULL)
	{
		current = current->right;
	}
	return current;
}
