#include "define.h"

bst_node *insert(bst_node *root, val_type key)
{
	if(root == nullptr)
		root = new bst_node(key);
	else if(root->_val > key)
		root->_left = insert(root->_left, key);
	else if(root->_val < key)
		root->_right = insert(root->_right, key);

	return root;
}

bst_node *search(bst_node *root, val_type key)
{
	if(root == nullptr)
		return nullptr;
	else if(root->_val == key)
		return root;
	else if(root->_val > key)
		return search(root->_left, key);
	else
		return search(root->_right, key);
}

void print_inorder(bst_node *root)
{
	if(root == nullptr)
		return;

	print_inorder(root->_left);
	cout<<root->_val<<" ";
	print_inorder(root->_right);
}