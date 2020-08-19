#include<bits/stdc++.h>
using namespace std;
int n, m;
const int maxn = 2000;
vector<int> v[maxn];
int f[maxn], g[maxn];
set<int> s;
int find(int x){
	while(f[x]!=x) x = f[x];
	return x;
}
void Union(int x, int y){
	x = find(x);
	y = find(y);
	f[x] = y;
}
bool cmp(int a, int b){
	return a > b;
}
int main()
{
	int k;
	scanf("%d", &n);
	for(int i=1; i<=n; i++) f[i] = i;
	for(int i=1; i<=n; i++){
		scanf("%d:", &m);
		for(int j=0; j<m; j++){
			scanf("%d", &k);
			v[k].push_back(i);
			s.insert(k);
		}
	}
	set<int>::iterator it;
	for(it=s.begin(); it!=s.end(); it++){//¿Î³Ìid 
		sort(v[*it].begin(),v[*it].end());
		int x, y;
		for(int i=0; i<v[*it].size(); i++){
			if(i==0) x = find(v[*it][i]);
			else{
				y = find(v[*it][i]);
				Union(x,y);
			}
		}
	}
	map<int,int> p;
	for(int i=1; i<=n; i++) p[find(i)]++;
	map<int,int>::iterator it1;
	int cnt=0; 
	for(it1=p.begin(); it1!=p.end(); it1++){
		g[cnt++] = it1->second;
	}
	sort(g,g+cnt,cmp);
	printf("%d\n", cnt);
	for(int i=0; i<cnt; i++){
		if(i) printf(" ");
		printf("%d", g[i]);
	}
	return 0;
}
