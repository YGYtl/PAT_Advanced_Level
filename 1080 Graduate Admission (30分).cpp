#include<bits/stdc++.h>
using namespace std;
const int maxn = 40000+5;
int n, m, k, snum[200], ltsum[200], ltge[200];
bool vis[maxn];
struct node{
	int ge, gi, id, sum;
	vector<int> sc;
	bool operator <( const node &x )const{
        if( sum!=x.sum ) return sum > x.sum;
        return ge > x.ge;
    }
};
vector<int> ans[200];
vector<node> v;
//bool cmp(node a, node b){
//	if(a.sum!=b.sum) return a.sum > b.sum;
//	else return a.ge > b.ge;
//}
int main()
{
	int g;
	memset(vis,true,sizeof(vis));
	scanf("%d %d %d", &n, &m, &k);
	for(int i=0; i<m; i++) scanf("%d", &snum[i]);
	for(int i=0; i<n; i++){//学生 
		node t;
		scanf("%d %d", &t.ge, &t.gi);
		t.id = i; t.sum = t.ge+t.gi;
		for(int j=0; j<k; j++){
			scanf("%d", &g);
			t.sc.push_back(g);//学生报志愿 
		}
		v.push_back(t);
	}
//	sort(v.begin(),v.end(),cmp);
	sort(v.begin(), v.end());
	for(int i=0; i<n; i++){
		node t = v[i];
		for(int j=0; j<k; j++){
			int cid = t.sc[j];
			if(!vis[t.id]) continue;
			if(ans[cid].size()<snum[cid]){
				ltsum[cid] = t.sum;
				ltge[cid] = t.ge;
				ans[cid].push_back(t.id);
				vis[t.id] = false;
			}
			else if(t.sum==ltsum[cid]&&t.ge==ltge[cid]){
				ans[cid].push_back(t.id);
				vis[t.id] = false;
			}
		}
	}
	for(int i=0; i<m; i++){
		sort(ans[i].begin(),ans[i].end());
		for(int j=0; j<ans[i].size(); j++){
			if(j) printf(" ");
			printf("%d", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}
