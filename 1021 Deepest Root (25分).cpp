#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn = 10005;
vector<int> G[maxn];
int height[maxn], mx=-1;
bool vis[maxn];
void dfs(int s){
	int u;
	vis[s] = true;
	for(int i=0; i<G[s].size(); i++){
		u = G[s][i];
		if(!vis[u]){
			vis[u] = true;
			dfs(u);
		}
	} 
}
int ans;
void getheight(int s, int h){
	vis[s] = true;
	ans = max(ans,h);
	for(int i=0; i<G[s].size(); i++){
		if(!vis[G[s][i]]){
			getheight(G[s][i],h+1);
		}
	}
}
void solve(){
	memset(vis,false,sizeof(vis));
	memset(height,0,sizeof(height));
	int count = 0;
	for(int i=1; i<=n; i++){
		if(!vis[i]){
			dfs(i);
			count++;
		}
	}
	if(count>1) printf("Error: %d components\n", count);
	else{
		for(int i=1; i<=n; i++){
			ans = 0;
			memset(vis,false,sizeof(vis));
			getheight(i,0);
			height[i] = ans;
			mx = max(mx,ans);
		}
		for(int i=1; i<=n; i++){
			if(height[i]==mx){
				printf("%d\n", i);
			}
		}
	}
}
int main()
{
	int u, v;
	scanf("%d", &n);
	for(int i=0; i<n-1; i++){
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	solve();
	return 0;
}
