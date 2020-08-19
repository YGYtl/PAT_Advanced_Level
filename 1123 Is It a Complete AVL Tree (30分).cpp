#include<bits/stdc++.h>
using namespace std;
int n, k;
vector<int> level;
struct node{
	int num;
	node *l, *r;
	node(){
		l = r = NULL;
	}
};
node *LeftRoute(node *root){
	node *t;
	t = root->r;
	root->r = t->l;
	t->l = root;
	return t;
}
node *RightRoute(node *root){
	node *t;
	t = root->l;
	root->l = t->r;
	t->r = root;
	return t;
}
node *LeftRightRoute(node *root){
	root->l = LeftRoute(root->l);
	root = RightRoute(root);
	return root;
}
node *RightLeftRoute(node *root){
	root->r = RightRoute(root->r);
	root = LeftRoute(root);
	return root;
}
int height(node *root){
	if(root==NULL) return 1;
	return max(height(root->l),height(root->r))+1;
}
node *Insert(node *root, int k){
	if(root==NULL){
		root = new node();
		root->num = k;
		root->l = root->r = NULL;
	}
	else if(k>=root->num){
		root->r = Insert(root->r,k);
		if(abs(height(root->r)-height(root->l))>=2){
			root = k>=root->r->num ? LeftRoute(root) : RightLeftRoute(root);
		}
	}
	else{
		root->l = Insert(root->l,k);
		if(abs(height(root->l)-height(root->r))>=2){
			root = k<=root->l->num ? RightRoute(root) : LeftRightRoute(root);
		}
	}
	return root;
}
void bfs(node *root){
	pair<node *, int> t, tt;
	queue<pair<node *, int> > q;
	t.first = root; t.second = 1;
	q.push(t);
	bool flag = true;
	int cnt = 1;
	while(!q.empty()){
		t = q.front(); q.pop();
		if(cnt!=t.second) flag = false;
		cnt++;
		level.push_back(t.first->num);
		if(t.first->l!=NULL){
			tt.first = t.first->l;
			tt.second = t.second*2;
			q.push(tt);
		}
		if(t.first->r!=NULL){
			tt.first = t.first->r;
			tt.second = t.second*2+1;
			q.push(tt);
		} 
	}
	for(int i=0; i<level.size(); i++){
		if(i) printf(" ");
		printf("%d", level[i]);
	}
	printf("\n");
	if(flag) printf("YES\n");
	else printf("NO\n");
}
int main()
{
	node *tree = NULL;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &k);
		tree = Insert(tree,k);
	}
	bfs(tree);
	return 0;
}
