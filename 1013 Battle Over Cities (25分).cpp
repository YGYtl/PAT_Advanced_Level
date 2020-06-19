#include<bits/stdc++.h>
using namespace std;
int n, m, k;
vector<int> mp[1005], g[1005];
int vis[1005];
void dfs(int u){
	vis[u] = 1;
	for(int i=1; i<=n; i++){
		if(!vis[i]&&g[u][i]){
			dfs(i);
		}
	}
	return;
}

int solve(int t){
	memset(vis,0,sizeof(vis));
	for(int i=1; i<=n; i++){
		g[i].resize(1005);
		for(int j=1; j<=n; j++) g[i][j] = mp[i][j];
	}
	for(int i=1; i<=n; i++){
		if(g[t][i]){
			g[t][i] = g[i][t] = 0;
		}
	}
	int count = 0;
	for(int i=1; i<=n; i++){
		if(!vis[i]&&i!=t){
			dfs(i);
			count++;
		}
	}
	return count-1;
}
int main()
{
	int u, v, t;
	memset(mp,0,sizeof(mp));
	scanf("%d %d %d", &n, &m, &k);
	for(int i=1; i<=n; i++) mp[i].resize(1005);
	for(int i=0; i<m; i++){
		scanf("%d %d", &u, &v);
		mp[u][v] = mp[v][u] = 1;
	}
	for(int i=0; i<k; i++){
		scanf("%d", &t);
		printf("%d\n", solve(t));
	}
	return 0;
}
