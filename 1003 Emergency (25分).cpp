#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int n, m, c1, c2;
int people[1100];
int V[1100][1100];
int vis[1100];
int dist[1100], pp[1100], path[1100];
void dij(){
	int count = 0;
	memset(dist,inf,sizeof(dist));
	memset(pp,0,sizeof(pp));
	memset(vis,true,sizeof(vis));
	fill(path,path+1100,1);
	dist[c1] = 0;
	pp[c1] = people[c1];
	int u=c1;
	while(1){
		int v=-1, M=inf;
		for(int i=0; i<n; i++){
			if(vis[i]&&M>dist[i]){
				M = dist[i];
				v = i;
			}
		}
		if(v==-1) break;
		vis[v] = false;
		for(int i=0; i<n; i++){
			if(vis[i]&&dist[i]>dist[v]+V[v][i]){
				dist[i] = dist[v]+V[v][i];
				pp[i] = pp[v]+people[i];
				path[i] = path[v];
			}
			else if(vis[i]&&dist[i]==dist[v]+V[v][i]){
				if(pp[i]<pp[v]+people[i]){
					pp[i] = pp[v]+people[i];
				}
				path[i] += path[v];
			}
		}
		u = v;
	}
	printf("%d %d", path[c2], pp[c2]);
}
int main()
{
	int u, v, l;
	memset(vis,false,sizeof(vis));
	scanf("%d %d %d %d", &n, &m, &c1, &c2);
	memset(V,inf,sizeof(V));
	for(int i=0; i<n; i++) scanf("%d", &people[i]);
	for(int i=0; i<m; i++){
		scanf("%d %d %d", &u, &v, &l);
		V[u][v] = V[v][u] = l;
	}
	dij();
	return 0;
}
