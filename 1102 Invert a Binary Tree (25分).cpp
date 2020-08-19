#include<bits/stdc++.h>
using namespace std;
struct node{
	int l, r;
	int value;
};
vector<node> tree;
vector<int> lv, inorder;
stack<int> st;
int n;
bool vis[100];
bool bfs(int index){
	memset(vis,false,sizeof(vis));
	queue<int> q;
	q.push(index);
	while(!q.empty()){
		int t = q.front(); q.pop(); 
		vis[t] = true;
		lv.push_back(t);
		if(tree[t].l!=-1) q.push(tree[t].l);
		if(tree[t].r!=-1) q.push(tree[t].r);
	}
	for(int i=0; i<n; i++){
		if(vis[i]==false) return false;
	}
	return true;
}
void dfs(int index){
	if(index==-1){
		return ;
	}
	dfs(tree[index].l);
	inorder.push_back(index);
	dfs(tree[index].r);
}

int main()
{
	int aa, bb, root;
	char a, b;
	scanf("%d", &n); getchar();
	tree.resize(n);
	for(int i=0; i<n; i++){
		aa = bb = -1;
		scanf("%c %c", &a, &b); getchar();
		if(a!='-') aa = a - '0';
		if(b!='-') bb = b - '0';
		tree[i].l = bb;
		tree[i].r = aa;
		tree[i].value = i;
	}
	for(int i=0; i<n; i++){
		if(bfs(i)){
			root = i;
			break;
		}
		lv.clear();
	}
	dfs(root);
	for(int i=0; i<n; i++){
		if(i) printf(" ");
		printf("%d", lv[i]);
	}
	printf("\n");
	for(int i=0; i<n; i++){
		if(i) printf(" ");
		printf("%d", inorder[i]);
	}
	return 0;
}
