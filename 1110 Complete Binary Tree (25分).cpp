#include<bits/stdc++.h>
using namespace std;
int n, mx_size = 0;
const int maxn = 100;
bool vis[maxn], flag;
struct node{
	int l, r;
	node(){
		l = r = -1;
	}
};
vector<node> v;
vector<int> lt;
bool judge(){
	for(int i=0; i<n; i++){
		if(vis[i]==false) return false;
	}
	return true;
}
void dfs(int index)
{
	vis[index] = true;
	if(v[index].l==-1&&v[index].r==-1) return ;
	if(v[index].l!=-1) dfs(v[index].l);
	if(v[index].r!=-1) dfs(v[index].r);
}
bool judge2(int root){
	queue<pair<int,int> > q;
	pair<int,int> t, tt;
	t.first = root; t.second = 1;
	q.push(t);
	int cc = 0; bool flag = true;
	while(!q.empty()){
		t = q.front(); q.pop();
		lt[t.second] = t.first;
		mx_size = t.second;
		cc++;
		if(v[t.first].l==-1&&v[t.first].r==-1){
			if(t.second!=cc) flag = false;
		}
		if(v[t.first].l!=-1){
			tt.first = v[t.first].l;
			tt.second = t.second*2;
			q.push(tt);
		}
		if(v[t.first].r!=-1){
			tt.first = v[t.first].r;
			tt.second = t.second*2+1;
			q.push(tt);
		}
	}
	return flag;
}
int main()
{
	node t;
	string s1, s2;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		cin >> s1 >> s2;
		if(s1=="-") t.l = -1;
		else t.l = stoi(s1);
		if(s2=="-") t.r = -1;
		else t.r = stoi(s2);
		v.push_back(t);
	}
	int root = -1;
	for(int i=0; i<n; i++){
		memset(vis,false,sizeof(vis));
		dfs(i);
		if(judge()==true){
			root = i;
			break;
		}
	}
	lt.resize(100,-1);
	if(judge2(root)) printf("YES %d", lt[mx_size]);
	else printf("NO %d", root);
	return 0;
}
