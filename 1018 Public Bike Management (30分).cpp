#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
struct node{
	int u, v, c;
	node(){}
	node(int _u, int _v, int _c):u(_u),v(_v),c(_c){}
};
int Cmax, n, sp, m;
int bike[1100], dist[1100];
bool vis[1100];
vector<node> mp[1100];
vector<int> anspath, path;
int Bring, Taking, bring, taking, Sum, sum;
void dfs(int st){
	if(st==sp){
		if(Sum>sum||(Sum==sum&&Bring>bring)||(Sum==sum&&Bring==bring&&Taking>taking)){
			Sum = sum;
			Bring = bring;
			Taking = taking;
			anspath = path;
		}
		return;
	}
	node t;
	for(int i=0; i<mp[st].size(); i++){
		t = mp[st][i];
		int u=t.u, v=t.v, len=t.c;
		int tsum = sum, tbring = bring, ttaking = taking;
		if(!vis[v]&&dist[v]>=dist[u]+len){
			vis[v] = true;
			dist[v] = dist[u]+len;
			sum += len;
			taking += bike[v];
			path.push_back(v);
			if(taking<0) bring -= taking, taking = 0;
			dfs(v);
			path.pop_back();
			sum = tsum;
			bring = tbring;
			taking = ttaking;
			vis[v] = false;
		}
	}
}
int main()
{
	Sum = inf;
	memset(vis,false,sizeof(vis));
	memset(dist,inf,sizeof(dist));
	dist[0] = 0;
	int u, v, c;
	scanf("%d %d %d %d", &Cmax, &n, &sp, &m);
	Cmax /= 2;
	for(int i=1; i<=n; i++){
		scanf("%d", &bike[i]);
		bike[i] -= Cmax;
	}
	for(int i=0; i<m; i++){
		scanf("%d %d %d", &u, &v, &c);
		mp[u].push_back(node(u,v,c));
		mp[v].push_back(node(v,u,c));
	}
	dfs(0);
	printf("%d 0", Bring);
	for(int i=0; i<anspath.size(); i++){
		printf("->");
		printf("%d", anspath[i]);
	}
	printf(" %d", Taking);
	return 0;
}
