#include<bits/stdc++.h>
using namespace std;
int n, m;
const int maxn = 1e4+5;
vector<int> G[maxn], v;
set<pair<int,int> > s, ts;
void judge(){
	pair<int,int> tp;
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<G[v[i]].size(); j++){
			tp.first = v[i];
			tp.second = G[v[i]][j];
			ts.insert(tp);
			tp.first = G[v[i]][j];
			tp.second = v[i];
			ts.insert(tp);
		}
	}
	if(ts!=s) printf("No\n");
	else printf("Yes\n");
}
int main()
{
	int a, b, g, k;
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; i++){
		scanf("%d %d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
		pair<int,int> tp;
		tp.first = a; tp.second = b;
		s.insert(tp);
		tp.first = b; tp.second = a;
		s.insert(tp);
	}
	scanf("%d", &m);
	for(int i=0; i<m; i++){
		scanf("%d", &g);
		for(int j=0; j<g; j++){
			scanf("%d", &k);
			v.push_back(k);
		}
		judge();
		v.clear();
		ts.clear();
	}
	return 0;
}
