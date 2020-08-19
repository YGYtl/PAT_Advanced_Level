#include<bits/stdc++.h>
using namespace std;
int n, m, q;
const int maxn = 1000;
vector<int> G[maxn], l;
map<int,int> vis;
set<int> st;
int vis2[maxn];
bool judge(){
	bool flag = true;
	memset(vis2,0,sizeof(vis2));
	if(l[0]!=l[l.size()-1]) return false;
	int u=l[0], v; vis[u]++;
	for(int i=1; i<l.size(); i++){
		v = l[i]; flag = false;
		for(int j=0; j<G[u].size(); j++){
			if(G[u][j]==v){
				flag = true;
				break;
			}
		}
		vis2[v]++;
		if(!flag) return false;
		else u = v;
	}
	set<int>::iterator it;
	for(it=st.begin(); it!=st.end(); it++){
		if(vis2[*it]!=1) return false;
	}
	return true;
}
int main()
{
	int a, b, k;
	bool flag;
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; i++){
		scanf("%d %d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
		vis[a] = vis[b] = true;
		st.insert(a); st.insert(b);
	}
	scanf("%d", &q);
	for(int i=0; i<q; i++){
		scanf("%d", &m);
		flag = true;
		for(int j=0; j<m; j++){
			scanf("%d", &k);
			if(vis[k]==false) flag = false;
			l.push_back(k);
		}
		if(judge()&&flag) printf("YES\n");
		else printf("NO\n");
		l.clear();
	}
	return 0;
}
