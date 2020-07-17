#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
vector<int> v[maxn];
double ans;
int c;
double p, r;
void bfs(int root){
	c = 0; ans = 0;
	pair<int,double> tp, tp2;
	tp.first = root; tp.second = p;
	queue< pair<int,double> > q;
	q.push(tp);
	while(!q.empty()){
		tp = q.front(); q.pop();
		if(tp.second>ans&&v[tp.first].size()==0){
			ans = tp.second;
			c = 0;
		}
		if(tp.second == ans&&v[tp.first].size()==0) c++;
		for(int i=0; i<v[tp.first].size(); i++){
			int u = v[tp.first][i];
			tp2.first = u;
			tp2.second = tp.second*r;
			q.push(tp2);
		}
	}
	printf("%.2f %d", ans, c);
}
int main()
{
	int n, k, root;
	scanf("%d %lf %lf", &n, &p, &r);
	r = r*1.0/100 + 1;
	for(int i=0; i<n; i++){
		scanf("%d", &k);
		if(k==-1) root = i;
		else{
			v[k].push_back(i);
		}
	}
	bfs(root);
	return 0;
}
