#include<bits/stdc++.h>
using namespace std;
int n, l;
const int maxn = 1000+5;
vector<int> G[maxn];
bool vis[maxn];
struct node{
	int index, level;
	node(){
		index = level = 0;
	}
};
void query(int start){
	fill(vis,vis+maxn,false);
	node t, tt;
	t.index = start;
	t.level = 0;
	queue<node> q;
	q.push(t);
	vis[start] = true;
	int ans = 0;
	while(!q.empty()){
		t = q.front(); q.pop();
		for(int i=0; i<G[t.index].size(); ++i){
			int u = G[t.index][i];
			if(!vis[u]&&t.level<l){
				ans++;
				vis[u] = true;
				tt.index = u;
				tt.level = t.level+1;
				q.push(tt);
			}
		}
	}
	printf("%d\n", ans);
}
int main()
{
	int k, g;
	scanf("%d %d", &n, &l);
	for(int i=1; i<=n; ++i){
		scanf("%d", &k);
		for(int j=0; j<k; ++j){
			scanf("%d", &g);
			G[g].push_back(i);
		}
	}
	scanf("%d", &k);
	for(int i=0; i<k; ++i){
		scanf("%d", &g);
		query(g);
	}
	return 0;
}
