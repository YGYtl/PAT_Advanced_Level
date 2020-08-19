#include<bits/stdc++.h>
using namespace std;
int n, m, st, et;
const int maxn = 1e4+5;
vector<int> G[maxn], tv, ans;
bool vis[maxn];
int ans_size, ans_cnt;
const int inf = 0x3f3f3f3f;
unordered_map<int,int> line;
void dfs(int index){
	if(index==et&&tv.size()<=ans_size){
		int cnt = 0, pre = -1;
		for(int i=1; i<tv.size(); i++){
			if(line[tv[i-1]*10000+tv[i]]!=pre) cnt++;
			pre = line[tv[i-1]*10000+tv[i]];
		}
		if(tv.size()<ans_size){
			ans = tv;
			ans_size = ans.size();
			ans_cnt = cnt;
		}
		else if(tv.size()==ans_size&&ans_cnt>cnt){
			ans = tv;
			ans_cnt = cnt;
		}
	}
	if(index==et) return ;
	for(int i=0; i<G[index].size(); i++){
		if(!vis[G[index][i]]){
			vis[G[index][i]] = true;
			tv.push_back(G[index][i]);
			dfs(G[index][i]);
			tv.pop_back();
			vis[G[index][i]] = false;
		}
	}
}
int main()
{
	int k, pre;
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d %d", &m, &pre);
		for(int j=1; j<m; j++){
			scanf("%d", &k);
			G[pre].push_back(k);
			G[k].push_back(pre);
			line[pre*10000+k] = line[k*10000+pre] = i;
			pre = k;
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
		pre = -1;
		for(int i=1; i<ans.size(); i++){
			if(line[ans[i-1]*10000+ans[i]]!=pre){
				if(pre!=-1){
					printf("Take Line#%d from %04d to %04d.\n", pre, st, ans[i-1]);
				}
				pre = line[ans[i-1]*10000+ans[i]];
				st = ans[i-1];
			}
		}
		printf("Take Line#%d from %04d to %04d.\n", pre, st, ans[ans.size()-1]);
		ans.clear();
		tv.clear();
	}
	return 0;
}
