#include<bits/stdc++.h>
using namespace std;
int n, m, k, q, ans;
const int maxn = 10000+5;
int f[maxn];
set<int> st;
map<int,int> p;
int find(int x){//ע�ⳬʱ 
	if(f[x]==x) return x;
	return f[x] = find(f[x]);
}
void Union(int x, int y){
	x = find(x);
	y = find(y);
	f[x] = y;
}
int main()
{
	int t, x, y; ans = 0;
	for(int i=0; i<maxn; i++) f[i] = i;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &m);
		for(int j=0; j<m; j++){
			scanf("%d", &k);
			st.insert(k);
			if(j==0) t = k;
			else Union(t,k);
		}
	}
	set<int>::iterator it;
	for(it=st.begin(); it!=st.end(); it++) p[find(*it)]++;
	printf("%d %d\n", p.size(), st.size());
	scanf("%d", &q);
	for(int i=0; i<q; i++){
		scanf("%d %d", &x, &y);
		if(find(x)==find(y)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
