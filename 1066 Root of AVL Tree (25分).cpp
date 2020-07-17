#include<bits/stdc++.h>
using namespace std;
struct node{
	int val;
	node *left, *right;
};

node *routerRight(node *root){
	node *t = NULL;
	t = root->left;
	root->left = t->right;
	t->right = root;
	return t;
}
node *routerLeft(node *root){
	node *t = NULL;
	t = root->right;
	root->right = t->left;
	t->left = root;
	return t;
}

node *routerLeftRight(node *root){
	root->left = routerLeft(root->left);
	return routerRight(root);
}

node *routerRightLeft(node *root){
	root->right = routerRight(root->right);
	return routerLeft(root);
}

int height(node *root){
	if(root==NULL) return 0;
	return max(height(root->left),height(root->right))+1;
}
node *insert(node *root, int val){
	if(root==NULL){
		root = new node();
		root->val = val;
		root->left = root->right = NULL;
	}
	else if(val < root->val){
		root->left = insert(root->left,val);
		if(height(root->left)-height(root->right)==2){
			root = val < root->left->val ? routerRight(root):routerLeftRight(root);
		}
	}
	else{
		root->right = insert(root->right,val);
		if(height(root->right)-height(root->left)==2){
			root = val > root->right->val ? routerLeft(root):routerRightLeft(root); 
		}
	}
	return root;
}
int n;
int main()
{
	int m;
	scanf("%d", &n);
	node *root = NULL;
	for(int i=0; i<n; i++){
		scanf("%d", &m);
		root = insert(root,m);
	}
	printf("%d", root->val);
	return 0;
}
