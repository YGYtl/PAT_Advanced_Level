#include<bits/stdc++.h>
using namespace std;
int n, m, k, Ds;
const int maxn = 2005;
const int inf = 0x3f3f3f3f;
int G[maxn][maxn];
int dist[maxn];//各点到目的地的最短距离 
bool vis[maxn];
double t_avg, t_min;
bool dij(int u){
	t_min = inf*1.0; t_avg = 0;
	bool f = true;
	fill(dist,dist+maxn,inf);
	memset(vis,false,sizeof(vis));
	int index, mx;
	dist[u] = 0;
	while(1){
		index=-1, mx = inf;
		for(int i=1; i<=n+m; i++){
			if(!vis[i]&&dist[i]<mx){
				mx = dist[i];
				index = i;
			}
		}
		if(index==-1) break;
		vis[index] = true;
		for(int i=1; i<=n+m; i++){
			if(!vis[i]&&dist[index]+G[index][i]<dist[i]){
				dist[i] = dist[index]+G[index][i];
			}
		}
	}
	
	for(int i=1; i<=n; i++){
		if(dist[i]>Ds){
			f = false;
			break;
		}
		t_min = min(t_min,1.0*dist[i]);
		t_avg += 1.0*dist[i];
	}
	t_avg = t_avg/n*1.0;
	return f;
}
int main()
{
	string s1, s2;
	int d, t1, t2;
	fill(G[0],G[0]+maxn*maxn,inf);
	scanf("%d %d %d %d", &n, &m, &k, &Ds);
	for(int i=0; i<k; i++){
		cin >> s1 >> s2 >> d;
		if(s1[0]=='G'){
			s1 = s1.substr(1);
			t1 = stoi(s1) + n;
		}
		else t1 = stoi(s1);
		if(s2[0]=='G'){
			s2 = s2.substr(1);
			t2 = stoi(s2) + n;
		}
		else t2 = stoi(s2);
		G[t1][t2] = G[t2][t1] = min(G[t1][t2],d);
	}
	int ans_id = -1;
	double ans_avg=inf*1.0, ans_min=0;
	for(int i=n+1; i<=n+m; i++){
		if(dij(i)){
			if(ans_min<t_min){
				ans_id = i;
				ans_min = t_min;
				ans_avg = t_avg;
			}
			else if(ans_min==t_min&&ans_avg>t_avg){
				ans_avg = t_avg;
				ans_id = i;
			}
		}
	}
	if(ans_id!=-1){
		printf("G%d\n", ans_id-n);
		printf("%.1f %.1f\n", ans_min, 1.0*ans_avg);
	}
	else printf("No Solution");
	return 0;
}
