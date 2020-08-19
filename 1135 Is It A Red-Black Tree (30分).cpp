#include<bits/stdc++.h>
using namespace std;
int n, m, cnt;
bool flag;
struct node{
	int num;
	node *l, *r;
	node(){
		l = r = NULL;
	}
};
node *Insert(node *root, int k){
	if(root==NULL){
		root = new node();
		root->num = k;
		root->l = root->r = NULL;
	}
	else if(abs(k)>=abs(root->num)){
		root->r = Insert(root->r,k);
	}
	else root->l = Insert(root->l,k);
	return root;
}
void bfs(node *root){
	pair<node*,int> t, tt;
	node *troot;
	queue<pair<node*,int>> q;
	t.first = root; t.second = 0;
	q.push(t);
	while(!q.empty()&&flag){
		t = q.front(); q.pop();
		troot = t.first;
		if(troot==NULL){
			t.second++;
			if(cnt==-1) cnt = t.second;
			if(cnt!=t.second) flag = false;
			continue;
		}
		if(troot->num>0) t.second++;
		
		if(troot->l!=NULL&&troot->num<0&&troot->l->num<0) flag = false;
		tt.first = troot->l; tt.second = t.second;
		q.push(tt);
		
		if(troot->r!=NULL&&troot->num<0&&troot->r->num<0) flag = false;
		tt.first = troot->r; tt.second = t.second;
		q.push(tt);
	}
}
int main()
{
	int k;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &m);
		node *tree = NULL;
		for(int j=0; j<m; j++){
			scanf("%d", &k);
			tree = Insert(tree,k);
		}
		flag = true;
		cnt = -1;
		if(tree->num<0) flag = false;
		else bfs(tree);
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
