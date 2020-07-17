#include<bits/stdc++.h>
using namespace std;
vector<int> v, ans;
map<int,int> p;
int n, m;
bool flag;
struct node{
	int index, sum;
	vector<int> list;
	node(){
		sum = 0;
		list.clear();
	}
};
void bfs(int s_index){
	queue<node> q;
	node t, tt;
	t.index = s_index; t.sum += v[t.index];
	t.list.push_back(v[t.index]);
	q.push(t);
	while(!q.empty()){
		t = q.front();
		q.pop();
		if(t.sum==m){
			if(ans.size()<t.list.size()){
				flag = true;
				ans = t.list;
			}
			continue;
		}
		for(int i=t.index+1; i<v.size(); i++){
			if(t.sum+v[i]<=m){
				tt.index = i;
				tt.sum = t.sum + v[i];
				tt.list = t.list;
				tt.list.push_back(v[i]);
				q.push(tt);
			}
		}
	}
}
int main()
{
	int k; flag = false;
	scanf("%d %d", &n, &m);
	if(n>1e4) n = 1e4;
	for(int i=0; i<n; i++){
		scanf("%d", &k);
		v.push_back(k);
	}
	sort(v.begin(),v.end());
	for(int i=0; i<v.size(); i++){
		if(v[i]<=m) bfs(i);
	}
	if(flag){
		for(int i=0; i<ans.size(); i++){
			if(i) printf(" ");
			printf("%d", ans[i]);
		}
	}
	else printf("No Solution\n");
	return 0;
}
