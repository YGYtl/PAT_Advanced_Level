#include<bits/stdc++.h>
using namespace std;
int n, k;
const int maxn = 1e4+5;
vector<int> v[maxn];
struct node{
	int num;
	node *l, *r;
	node(){
		l = r = NULL;
	}
};
node* build(node *tree, int x){
	if(tree==NULL){
		tree = new node();
		tree->num = x;
		tree->l = tree->r = NULL;
	}
	else if(tree->num<x){
		tree->r = build(tree->r,x);
	}
	else tree->l = build(tree->l,x);
	return tree;
}

void bfs(node *tree){
	int cnt = 0;
	queue<pair<node*,int> > q;
	pair<node*,int> t, tt;
	t.first = tree;
	t.second = 0;
	q.push(t);
	while(!q.empty()){
		t = q.front(); q.pop();
		cnt = t.second;
		v[t.second].push_back(t.first->num);
		if(t.first->l!=NULL){
			tt.first = t.first->l;
			tt.second = t.second+1;
			q.push(tt);
		}
		if(t.first->r!=NULL){
			tt.first = t.first->r;
			tt.second = t.second+1;
			q.push(tt);
		}
	}
	int n1 = v[cnt].size(), n2 = v[cnt-1].size();
	printf("%d + %d = %d\n", n1, n2, n1+n2);
}

int main()
{
	node *tree = NULL;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &k);
		tree = build(tree,k);
	}
	bfs(tree);
	return 0;
}
