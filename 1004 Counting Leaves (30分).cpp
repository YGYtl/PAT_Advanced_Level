#include<bits/stdc++.h>
using namespace std;
int n, m;
//算出每一层的叶子总数 
struct node{
	int num;
	vector<int> child;
};
node Tree[500];
map<int,int> p, ans;
void bfs(int st){
	pair<int,int> t, tp;
	t.first = st; t.second = 0;
	queue<pair<int,int> > q;
	q.push(t);
	ans[0] = 0;
	int mx=0;
	while(!q.empty()){
		t = q.front();
		q.pop();
		if(Tree[t.first].child.size()==0){
			ans[t.second]++;
		}
		for(int i=0; i<Tree[t.first].child.size(); i++){
			tp.first = Tree[t.first].child[i];
			if(p[tp.first]){//有孩子 
				tp.second = t.second+1;
				q.push(tp);
			}
			else ans[t.second+1]++;
			mx = max(mx,t.second+1);
		}
	}
	for(int i=0; i<=mx; i++){
		if(i!=0) printf(" ");
		printf("%d", ans[i]);
	}
}
int main()
{
	int k, u, v, c;//root==01
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; i++){
		scanf("%d %d", &u, &k);
		Tree[u].num = u;
		p[u] = 1;//有孩子 
		for(int j=0; j<k; j++){
			scanf("%d", &v);
			Tree[u].child.push_back(v);
		}
	}
	bfs(1);
	return 0;
}
