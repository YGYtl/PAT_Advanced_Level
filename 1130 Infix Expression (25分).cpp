#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn = 100;
string ans="";
struct node{
	string ch;
	int l, r;
};
vector<node> tree(maxn);
bool vis[maxn];
void bfs(int index){
	queue<int> q;
	q.push(index);
	while(!q.empty()){
		int u = q.front(); q.pop();
		vis[u] = true;
		node t = tree[u];
		if(t.l!=-1) q.push(t.l);
		if(t.r!=-1) q.push(t.r);
	}
}
void get_inorder(int index, int g){
	if(index==-1) return ;
	node t = tree[index];
	if(tree[index].r!=-1&&g>1) ans += "(";
	get_inorder(t.l,g+1);
	ans += t.ch;
	get_inorder(t.r,g+1);
	if(tree[index].r!=-1&&g>1) ans += ")";
}
int main()
{
	scanf("%d", &n);
	int root;
	for(int i=1; i<=n; i++){
		getchar();
		node t;
		cin >> t.ch >> t.l >> t.r;
		tree[i] = t;
	}
	for(int i=1; i<=n; i++){
		memset(vis,false,sizeof(vis));
		bfs(i);
		bool flag = true;
		for(int j=1; j<=n; j++){
			if(vis[j]==false){
				flag = false;
				break;
			}
		}
		if(flag){
			root = i;
			break;
		}
	}
	get_inorder(root,1);
	cout << ans << endl;
	return 0;
}
