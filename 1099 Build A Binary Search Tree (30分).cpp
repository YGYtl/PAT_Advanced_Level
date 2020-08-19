#include<bits/stdc++.h>
using namespace std;
struct node{
	int l, r;
	int value;
};
int n, cnt;
vector<node> tree;
vector<int> v, lv;
void dfs(int root){
	if(root==-1) return;
	dfs(tree[root].l);
	tree[root].value = v[cnt];
	cnt++;
	dfs(tree[root].r);
}
void solve(){
	queue<int> q;
	q.push(0);
	while(!q.empty()){
		int t = q.front();
		q.pop();
		lv.push_back(tree[t].value);
		if(tree[t].l!=-1) q.push(tree[t].l);
		if(tree[t].r!=-1) q.push(tree[t].r);
	}
	for(int i=0; i<n; i++){
		if(i) printf(" ");
		printf("%d", lv[i]);
	}
}
int main()
{
	scanf("%d", &n);
	v.resize(n);
	node t;
	for(int i=0; i<n; i++){
		scanf("%d %d", &t.l, &t.r);
		tree.push_back(t);
	}
	for(int i=0; i<n; i++) scanf("%d", &v[i]);
	sort(v.begin(),v.end());//变为中序遍历 
	cnt = 0;
	dfs(0);
	solve();
	return 0;
}
