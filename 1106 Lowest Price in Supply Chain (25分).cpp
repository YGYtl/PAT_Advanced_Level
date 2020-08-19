#include<bits/stdc++.h>
using namespace std;
int n, c;
double p, r, ans;
const int maxn = 1e5+5; 
vector<int> v[maxn];
double d[maxn];
void bfs(){
	queue<int> q;
	q.push(0);
	d[0] = p;
	while(!q.empty()){
		int t = q.front(); q.pop();
		if(v[t].size()==0){
			if(c==0) ans = d[t];
			if(d[t]<ans){
				ans = d[t];
				c = 0;
			}
			if(d[t]==ans) c++;
		}
		for(int i=0; i<v[t].size(); i++){
			d[v[t][i]] = d[t]*r;
			q.push(v[t][i]);
		}
	}
}
int main()
{
	int k, id, m; c = 0;
	scanf("%d %lf %lf", &n, &p, &r);
	r = r/100.0+1;
	for(int i=0; i<n; i++){
		scanf("%d", &m);
		for(int j=0; j<m; j++){
			scanf("%d", &k);
			v[i].push_back(k);
		}
	}
	bfs();
	printf("%.4f %d", ans, c);
	return 0;
}
