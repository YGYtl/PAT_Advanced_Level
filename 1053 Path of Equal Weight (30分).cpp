#include<bits/stdc++.h>
using namespace std;
struct node{
	int id;
	long long ss;
	vector<int> list;
	node(){
		ss = 0;
	}
};
int n, m;
long long s;
const int maxn = 220;
int weight[maxn];
vector<int> G[maxn];
vector< vector<int> > ans;
bool cmp(vector<int> a, vector<int> b){
	int l=0;
	l = min(a.size(),b.size());
	for(int i=0; i<l; i++){
		if(a[i]==b[i]) continue;
		else return a[i] > b[i];
	}
	return false; //如果没有，最后一个测试点段错误! 
}
void bfs(int root){
	node t, tt;
	queue<node> q;
	t.id = root; t.ss = weight[root];
	t.list.push_back(weight[root]);
	q.push(t);
	
	int u, v;
	while(!q.empty()){
		t = q.front();
		u = t.id;
		q.pop();
		if(t.ss==s&&G[u].size()==0){
			ans.push_back(t.list);
			continue;
		}
		else if(t.ss > s) continue;
		for(int i=0; i<G[u].size(); i++){
			v = G[u][i];
			tt.id = v; tt.ss = t.ss + weight[v]; tt.list = t.list;
			tt.list.push_back(weight[v]);
			q.push(tt);
		}
	}
	sort(ans.begin(),ans.end(),cmp);
	
	for(int i=0; i<ans.size(); i++){
		for(int j=0; j<ans[i].size(); j++){
			if(j) printf(" ");
			printf("%d", ans[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	scanf("%d %d %lld", &n, &m, &s);
	int id, k, g;
	for(int i=0; i<n; i++) scanf("%d", &weight[i]);
	for(int i=0; i<m; i++){
		scanf("%d %d", &id, &k);
		for(int j=0; j<k; j++){
			scanf("%d", &g);
			G[id].push_back(g);
		}
	}
	bfs(0);
	return 0;
}
