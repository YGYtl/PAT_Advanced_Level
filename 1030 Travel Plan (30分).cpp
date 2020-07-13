#include<bits/stdc++.h>
using namespace std;
int n, m, st, dt;
struct node{
	int v;
	int Dis, Cos;
};
const int maxn = 1100;
vector<node> G[maxn];
vector<int> path(maxn);
bool vis[maxn];
int dist[maxn], cost[maxn];
const int inf = 0x3f3f3f3f;
void Dij(){
	int et = dt;
	memset(vis,false,sizeof(vis));
	memset(dist,inf,sizeof(dist));
	memset(cost,inf,sizeof(dist));
	dist[st] = 0; cost[st] = 0;
	node t;
	while(1){
		int index=-1, mx = inf;
		for(int i=0; i<n; i++){
			if(!vis[i]&&dist[i]<mx){
				index = i;
				mx = dist[i];
			}
		}
		if(index==-1) break;
		vis[index] = true;
		for(int i=0; i<G[index].size(); i++){
			t = G[index][i];
			if(!vis[t.v]&&dist[t.v]>dist[index]+t.Dis){
				dist[t.v] = dist[index]+t.Dis;
				cost[t.v] = cost[index]+t.Cos;
				path[t.v] = index;
			}
			else if(!vis[t.v]&&dist[t.v]==dist[index]+t.Dis){
				if(cost[t.v]>cost[index]+t.Cos){
					cost[t.v] = cost[index]+t.Cos;
					path[t.v] = index;
				}
			}
		}
	}
	vector<int> g; g.push_back(dt);
	while(path[dt]!=st){
		g.push_back(path[dt]);
		dt = path[dt];
	}
	g.push_back(st);
	reverse(g.begin(),g.end());
	for(int i=0; i<g.size(); i++){
		if(i) printf(" ");
		printf("%d", g[i]);
	}
	printf(" %d %d\n", dist[et], cost[et]);
}
int main()
{
	scanf("%d %d %d %d", &n, &m, &st, &dt);
	int c1, c2, dis, c;
	node t;
	for(int i=0; i<m; i++){
		scanf("%d %d %d %d", &c1, &c2, &dis, &c);
		t.v = c2; t.Dis = dis; t.Cos = c;
		G[c1].push_back(t);
		t.v = c1;
		G[c2].push_back(t);
	}
	Dij();
	return 0;
}
