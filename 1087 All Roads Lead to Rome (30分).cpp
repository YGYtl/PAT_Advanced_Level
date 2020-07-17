#include<bits/stdc++.h>
using namespace std;
int n, m, st, et, c;
map<string,int> p;
map<int,string> pp;
const int maxn = 400+5;
const int inf = 0x3f3f3f3f;
int hs[maxn], cost[maxn], dt[maxn], c_cost[maxn], c_dt[maxn];
int Gcost[maxn][maxn], f[maxn];
bool vis[maxn];
vector<int> G[maxn];
string start_city;
void Dij(){//st - > et 
	fill(vis,vis+maxn,false);
	fill(cost,cost+maxn,inf);
	fill(dt,dt+maxn,inf);
	fill(c_dt,c_dt+maxn,0);
	memset(c_cost,0,sizeof(c_cost));
	cost[st] = 0; dt[st] = hs[st]; c_cost[st] = 1;
	for(int i=0; i<c; i++) f[i]=i;
	while(1){
		int index = -1, mx = inf;
		for(int i=0; i<c; i++){
			if(!vis[i]&&mx>cost[i]){
				index = i;
				mx = cost[i];
			}
		}
		if(index==-1) break;
		vis[index] = true;
		for(int i=0; i<G[index].size(); i++){
			int u = G[index][i];
			if(!vis[u]&&cost[u]>cost[index]+Gcost[index][u]){
				cost[u] = cost[index] + Gcost[index][u];//路费 
				dt[u] = dt[index] + hs[u];//快乐值 
				c_dt[u] = c_dt[index]+1;//步数 
				c_cost[u] = c_cost[index];//路费最少的条数 
				f[u] = index;
			}
			else if(!vis[u]&&cost[u]==cost[index]+Gcost[index][u]){
				c_cost[u] += c_cost[index];
				if(dt[index] + hs[u] > dt[u]){
					dt[u] = dt[index] + hs[u];
					c_dt[u] = c_dt[index]+1;
					f[u] = index;
				}
				else if(dt[u] == dt[index] + hs[u]&&c_dt[index]+1<c_dt[u]){//平均快乐值 
					c_dt[u] = c_dt[index]+1;
					f[u] = index;
				}
			}
		}
	}
	vector<int> l;
	int t = et;
	while(f[t]!=t){
		l.push_back(t);
		t = f[t];
	}
	l.push_back(t);
	reverse(l.begin(), l.end());
	printf("%d %d %d %d\n", c_cost[et], cost[et], dt[et], dt[et]/c_dt[et]);
	for(int i=0; i<l.size(); i++){
		if(i) cout << "->";
		cout << pp[l[i]];
	}
	cout << endl;
}
int main()
{
	string str, s1, s2;
	int k; st = 0;
	memset(hs,0,sizeof(hs));
	cin >> n >> m;
	cin >> start_city;
	pp[c] = start_city;
	if(start_city=="ROM") et = c;
	p[start_city] = c++;
	for(int i=0; i<n-1; i++){
		cin >> str >> k;
		if(p[str]==0){
			pp[c] = str;
			if(str=="ROM") et = c;
			p[str] = c++;
		}
		hs[p[str]] = k;
	}
	for(int i=0; i<m; i++){
		cin >> s1 >> s2 >> k;
		if(p[s1]==0&&s1!=start_city){
			pp[c] = s1;
			if(s1=="ROM") et = c;
			p[s1] = c++;
		}
		if(p[s2]==0&&s2!=start_city){
			pp[c] = s2;
			if(s2=="ROM") et = c;
			p[s2] = c++;
		}
		G[p[s1]].push_back(p[s2]);
		G[p[s2]].push_back(p[s1]);
		Gcost[p[s1]][p[s2]] = Gcost[p[s2]][p[s1]] = k;
	}
	Dij();
	return 0;
}
