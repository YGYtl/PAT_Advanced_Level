#include<bits/stdc++.h>
using namespace std;
vector<int> v;
map<int,int> G;
const int maxn = 100050;
int dp[maxn];
int main()
{
	int n, m, k;
	int g;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=m; i++){
		scanf("%d", &g);
		G[g] = i;
	}
	scanf("%d", &k);
	for(int i=0; i<k; i++){
		scanf("%d", &g);
		if(G[g]!=0){
			v.push_back(G[g]);
		}
	}
	int l = v.size(), ans = 0;
	for(int i=0; i<l; i++){
		dp[i] = 1;
		for(int j=0; j<i; j++){
			if(v[j]<=v[i]&&dp[i]<dp[j]+1){
				dp[i] = dp[j]+1;
			}
		}
		ans = max(ans,dp[i]);
	}
	printf("%d\n", ans);
	return 0;
}
