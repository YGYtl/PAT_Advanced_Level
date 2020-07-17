#include<bits/stdc++.h>
using namespace std;
int n, m;
const int maxn = 200;
vector<int> T[maxn];
int d[maxn];
map<int,int> p;
void bfs(){
	int u, v;
	queue<int> q;
	q.push(1);
	d[1] = 1;
	while(!q.empty()){
		u = q.front(); q.pop();
		for(int i=0; i<T[u].size(); i++){
			v = T[u][i];
			d[v] = d[u]+1;
			q.push(v);
		}
	}
	int c1=0, c2=0;
	for(int i=1; i<=m; i++){
		p[d[i]]++;
		if(p[d[i]]>c1){
			c1 = p[d[i]];
			c2 = d[i];
		}
	}
	printf("%d %d", c1, c2);
}
int main()
{
	scanf("%d %d", &m, &n);
	int u, v, k;
	for(int i=0; i<n; i++){
		scanf("%d %d", &u, &k);
		for(int j=0; j<k; j++){
			scanf("%d", &v);
			T[u].push_back(v);
		}
	}
	bfs();
	return 0;
}
