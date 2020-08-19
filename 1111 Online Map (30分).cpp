#include<bits/stdc++.h>
using namespace std;
int n, m, st, et;
const int maxn = 1000 + 5;
const int inf = 0x3f3f3f3f;
vector<int> G[maxn];
int G2[maxn][maxn], G3[maxn][maxn];
bool vis[maxn];
int dist1[maxn], T1[maxn], f1[maxn], f2[maxn], dist2[maxn], T2[maxn];
stack<int> s1, s2;
void Dij1(){
	int sst = st, eet = et;
	memset(vis,false,sizeof(vis));
	memset(dist1,inf,sizeof(dist1));
	memset(T1,inf,sizeof(T1));
	dist1[st] = 0; T1[st] = 0;
	f1[st] = st;
	while(1){
		int index=-1, mx = inf;
		for(int i=0; i<n; i++){
			if(!vis[i]&&dist1[i]<mx){
				mx = dist1[i];
				index = i;
			}
		}
		if(index==-1) break;
		vis[index] = true;
		int u = index, v;
		for(int i=0; i<G[u].size(); i++){
			v = G[u][i];
			if(!vis[v]){
				if(dist1[v]>dist1[u]+G2[u][v]){
					dist1[v] = dist1[u] + G2[u][v];
					T1[v] = T1[u] + G3[u][v];
					f1[v] = u;
				}
				else if(dist1[v]==dist1[u]+G2[u][v]){
					if(T1[v]>T1[u] + G3[u][v]){
						T1[v] = T1[u] + G3[u][v];
						f1[v] = u;
					}
				}
			}
		}
	}
	while(f1[eet]!=eet){
		s1.push(eet);
		eet = f1[eet];
	}
	s1.push(sst);
}
void Dij2(){
	int sst = st, eet = et;
	memset(vis,false,sizeof(vis));
	memset(dist2,0,sizeof(dist2));
	memset(T2,inf,sizeof(T2));
	T2[st] = 0; dist2[st] = 1;
	f2[st] = st;
	while(1){
		int index=-1, mx = inf;
		for(int i=0; i<n; i++){
			if(!vis[i]&&T2[i]<mx){
				mx = T2[i];
				index = i;
			}
		}
		if(index==-1) break;
		vis[index] = true;
		int u = index, v;
		for(int i=0; i<G[u].size(); i++){
			v = G[u][i];
			if(!vis[v]){
				if(T2[v]>T2[u]+G3[u][v]){
					T2[v] = T2[u] + G3[u][v];
					f2[v] = u;
					dist2[v] = dist2[u] + 1;
				}
				else if(T2[v]==T2[u]+G3[u][v]){
					if(dist2[v]>dist2[u]+1){
						dist2[v] = dist2[u] + 1;
						f2[v] = u;
					}
				}
			}
		}
	}
	while(f2[eet]!=eet){
		s2.push(eet);
		eet = f2[eet];
	}
	s2.push(sst);
}

int main()
{
	int v1, v2, way, length, time;
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; i++){
		scanf("%d %d %d %d %d", &v1, &v2, &way, &length, &time);
		
		if(way==1) G[v1].push_back(v2);//v1 -> v2
		else{
			G[v1].push_back(v2);
			G[v2].push_back(v1);
		}
		G2[v1][v2] = G2[v2][v1] = length;
		G3[v1][v2] = G3[v2][v1] = time;
	}
	scanf("%d %d", &st, &et);
	Dij1();
	Dij2();
	if(s1==s2){
		printf("Distance = %d; Time = %d:", dist1[et], T2[et]);
		int c = 0;
		while(!s1.empty()){
			if(c==0) printf(" ");
			else printf(" -> ");
			printf("%d", s1.top());
			s1.pop(); c++;
		}
	}
	else{
		printf("Distance = %d:", dist1[et]);
		int c = 0;
		while(!s1.empty()){
			if(c==0) printf(" ");
			else printf(" -> ");
			printf("%d", s1.top());
			s1.pop(); c++;
		}
		printf("\nTime = %d:", T2[et]);
		c = 0;
		while(!s2.empty()){
			if(c==0) printf(" ");
			else printf(" -> ");
			printf("%d", s2.top());
			s2.pop(); c++;
		} 
	}
	return 0;
}
