#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> line;
int n, m, st, et;
const int maxn = 1e4+5;
const int inf = 0x3f3f3f3f;
vector<int> G[maxn], ans, tv;
int ans_cnt, ans_size;
bool vis[maxn];
void dfs(int index){
	if(index==et&&tv.size()<=ans_size){
		int g=-1, cnt=0, u, v;
		for(int i=1; i<tv.size(); i++){
			u = tv[i-1]; v = tv[i];
			if(g!=line[u*10000+v]) cnt++;
			g = line[u*10000+v];
		}
		if(tv.size()<ans_size){
			ans_size = tv.size();
			ans_cnt = cnt;
			ans = tv;
		}
		else if(tv.size()==ans_size&&cnt<ans_cnt){
			ans_cnt = cnt;
			ans = tv;
		}
		return ;
	}
	if(index==et) return ;
	for(int i=0; i<G[index].size(); i++){
		int v = G[index][i];
		if(!vis[v]){
			vis[v] = true;
			tv.push_back(v);
			dfs(v);
			tv.pop_back();
			vis[v] = false;
		}
	}
}
int main()
{
	int u, v;
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d %d", &m, &u);
		for(int j=1; j<m; j++){
			scanf("%d", &v);
			G[u].push_back(v);
			G[v].push_back(u);
			line[u*10000+v] = line[v*10000+u] = i;
			u = v;
		}
	}
	scanf("%d", &m);
	for(int i=0; i<m; i++){
		scanf("%d %d", &st, &et);
		memset(vis,false,sizeof(vis));
		vis[st] = true;
		ans_cnt = ans_size = inf;
		tv.push_back(st);
		dfs(st);
		printf("%d\n", ans.size()-1);
		int l = -1, start = ans[0];
		for (int j = 1; j < ans.size(); j++) {
			if (line[ans[j - 1] * 10000 + ans[j]] != l) {
				if (l != -1) printf("Take Line#%d from %04d to %04d.\n", l, start, ans[j-1]);
				l = line[ans[j - 1] * 10000 + ans[j]];
				start = ans[j - 1];
			}
		}
		printf("Take Line#%d from %04d to %04d.\n", l, start, et);
		ans.clear();
		tv.clear();
	}
	return 0;
}
