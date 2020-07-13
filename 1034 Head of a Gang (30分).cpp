#include<bits/stdc++.h>
using namespace std;
int n, k;
map<string,vector<string> > G;
map<string,map<string,int> > Gp;
map<string,int> dist;
map<string,bool> vis;
map<string,map<string,bool> > vis2;
set<string> Set;
struct node{
	string name;
	int num;
};
vector<node> v;
vector<string> g;
set<string> snum;
bool cmp(node a, node b){
	return a.name < b.name;
}
string tname;
int tnum, tmx, mx, all_mx;
void dfs(string s, int tmx){
	vis[s] = true;
	snum.insert(s);
	if(mx<tmx){
		tname = s;
		mx = tmx;
	}
	for(int i=0; i<G[s].size(); i++){
		if(vis2[s][G[s][i]]){
			all_mx += Gp[s][G[s][i]];
			vis2[s][G[s][i]] = false;
			dfs(G[s][i],dist[G[s][i]]);
		}
	}
}

void solve(){
	node t;
	for(int i=0; i<g.size(); i++){
		if(!vis[g[i]]){
			tname = g[i];
			tnum=0, mx=dist[tname];
			all_mx = 0; snum.clear();
			dfs(g[i],dist[tname]);
			t.name = tname;
			t.num = snum.size();
			if(snum.size()>2&&all_mx>k) v.push_back(t);
		}
	}
	cout << v.size() << endl;
	sort(v.begin(),v.end(),cmp);
	for(int i=0; i<v.size(); i++){
		t = v[i];
		cout << t.name << " " << t.num << endl;
	}
}
int main()
{
	string s1, s2;
	int dis;
	scanf("%d %d", &n, &k);
	for(int i=0; i<n; i++){
		cin >> s1 >> s2 >> dis;
		dist[s1]+=dis;
		dist[s2]+=dis;
		G[s1].push_back(s2);
		G[s2].push_back(s1);
		Set.insert(s1);
		Set.insert(s2);
		vis[s1] = false;
		vis[s2] = false;
		Gp[s1][s2] += dis;
		vis2[s1][s2] = true;
	}
	set<string>::iterator it;
	for(it=Set.begin(); it!=Set.end(); it++) g.push_back(*it);
	solve();
	return 0;
}
