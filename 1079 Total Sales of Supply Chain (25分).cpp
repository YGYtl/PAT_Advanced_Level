#include<bits/stdc++.h>
using namespace std;
int n;
double p, r;
const int maxn = 200005;
vector<int> G[maxn];
map<int,int> lvs_sell;
struct node{
	int index;
	double price;
};
void bfs(){
	node t, tt;
	t.index = 0; t.price = p;
	queue<node> q;
	q.push(t);
	double ans = 0;
	while(!q.empty()){
		t = q.front();
		q.pop();
		if(G[t.index].size()==0){
			ans += lvs_sell[t.index]*t.price;
		}
		else{
			for(int i=0; i<G[t.index].size(); i++){
				int v = G[t.index][i];
				tt.index = v;
				tt.price = r*t.price;
				q.push(tt);
			}
		}
	}
	printf("%.1f", ans);
}
int main()
{
	scanf("%d %lf %lf", &n, &p, &r);
	r = r*1.0/100 + 1;
	int a, b;
	for(int i=0; i<n; i++){
		scanf("%d %d", &a, &b);
		if(a==0) lvs_sell[i] = b;
		else{
			G[i].push_back(b);
			for(int j=1; j<a; j++){
				scanf("%d", &b);
				G[i].push_back(b);
			}
		}
	}
	bfs();
	return 0;
}
