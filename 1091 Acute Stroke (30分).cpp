#include<bits/stdc++.h>
using namespace std;
int m, n, l, t;
const int maxn1 = 1500;
const int maxn2 = 150;
const int maxn3 = 100;
int X[10] = {1, -1, 0, 0, 0, 0};
int Y[10] = {0, 0, -1, 1, 0, 0};
int Z[10] = {0, 0, 0, 0, 1, -1};
int G[maxn1][maxn2][maxn3];
bool vis[maxn1][maxn2][maxn3];
struct node{
	int x, y, z;
};
int bfs(int x, int y, int z){
	node tn, tn2;
	tn.x = x; tn.y = y; tn.z = z;
	queue<node> q;
	q.push(tn);
	int c = 0; vis[tn.x][tn.y][tn.z] = true;
	while(!q.empty()){
		tn = q.front(); q.pop();
		c++;
		for(int i=0; i<6; i++){
			tn2.x = tn.x + X[i];
			tn2.y = tn.y + Y[i];
			tn2.z = tn.z + Z[i];
			if(tn2.x<0||tn2.y<0||tn2.z<0||tn2.x>=m||tn2.y>=n||tn2.z>=l) continue;
			if(vis[tn2.x][tn2.y][tn2.z]||G[tn2.x][tn2.y][tn2.z]==0) continue;
			vis[tn2.x][tn2.y][tn2.z] = true;
			q.push(tn2);
		}
	}
	if(c>=t) return c;
	else return 0;
}
int main()
{
	scanf("%d %d %d %d", &m, &n, &l, &t);
	for(int i=0; i<l; i++){
		for(int j=0; j<m; j++){
			for(int k=0; k<n; k++){
				scanf("%d", &G[j][k][i]);
			}
		}
	}
	int ans = 0;
	for(int i=0; i<l; i++){
		for(int j=0; j<m; j++){
			for(int k=0; k<n; k++){
				if(G[j][k][i]==1&&!vis[j][k][i]){
					ans += bfs(j,k,i);
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
}
