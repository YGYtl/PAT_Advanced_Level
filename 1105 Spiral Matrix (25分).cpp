#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
int v[maxn];
vector<vector<int> > G;
vector<vector<bool> > vis;
bool cmp(int a, int b){
	return a > b;
}
int main()
{
	int n, k, x, y;
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d", &v[i]);
	sort(v, v+n, cmp);
	x = sqrt(n)+1;
	for(int i=x; i>=1; i--){
		if(n%i==0){
			x = i;
			break;
		}
	}
	y = min(x,n/x); x = max(x,n/x);
	if(y==1){
		for(int i=0; i<n; i++) printf("%d\n", v[i]);
		return 0;
	}
	G.resize(x+1); vis.resize(x+1);
	for(int i=1; i<=x; i++){
		G[i].resize(y+2);
		vis[i].resize(y+2);
		vis[i][0] = false; vis[i][y+1] = false;
		for(int j=1; j<=y; j++) vis[i][j] = true;
	}
	int i = 1, j = 1, c=0;
	while(vis[i][j]&&c<n){//Ȧ 
		while(j<=y&&vis[i][j]){
			G[i][j] = v[c];
			vis[i][j] = false;
			c++; j++;
		}
		i++; j--;
		while(i<=x&&vis[i][j]){
			G[i][j] = v[c];
			vis[i][j] = false;
			c++; i++;
		}
		i--; j--;
		while(j>=1&&vis[i][j]){
			G[i][j] = v[c];
			vis[i][j] = false;
			c++; j--;
		}
		j++; i--;
		while(i>=1&&vis[i][j]){
			G[i][j] = v[c];
			vis[i][j] = false;
			c++; i--;
		}
		i++; j++;
	}
	for(i=1; i<=x; i++){
		for(j=1; j<=y; j++){
			if(j!=1) printf(" ");
			printf("%d", G[i][j]);
		}
		printf("\n");
	}
	return 0;
}
