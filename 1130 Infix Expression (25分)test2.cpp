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
	memset(vis,false,sizeof(vis));
	for(int i=1; i<=n; i++){
		getchar();
		node t;
		cin >> t.ch >> t.l >> t.r;
		tree[i] = t;
		if(t.l!=-1) vis[t.l] = true;
		if(t.r!=-1) vis[t.r] = true;
	}
	for(int i=1; i<=n; i++){
		if(vis[i]==false){
			root = i;
			break;
		}
	}
	get_inorder(root,1);
	cout << ans << endl;
	return 0;
}
