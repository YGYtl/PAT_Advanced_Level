#include<bits/stdc++.h>
using namespace std;
const int maxn = 10086;
int wet[maxn];
int dp[maxn];
int vis[maxn][110];
int n, m;
bool cmp(int a, int b){
	return a > b;
}
int main()
{
	scanf("%d %d", &n, &m);
	memset(dp,0,sizeof(dp));
	memset(vis,false,sizeof(vis));
	for(int i=1; i<=n; i++) scanf("%d", &wet[i]);
	sort(wet+1,wet+n+1,cmp);
	for(int i=1; i<=n; i++){
		for(int j=m; j>=wet[i]; j--){//确保一定可放入第i件物品 
			if(dp[j-wet[i]]+wet[i]>=dp[j]){
				dp[j] = dp[j-wet[i]]+wet[i];
				vis[i][j] = true;
			}
		}
	}
	vector<int> ans;
	if(dp[m]!=m) printf("No Solution");
	else{
		int x = n, y = m;
		while(y>0){
			if(vis[x][y]){
				ans.push_back(wet[x]);
				y -= wet[x];
			}
			x--;
		}
		for(int i=0; i<ans.size(); i++){
			if(i) printf(" ");
			printf("%d", ans[i]);
		}
	}
	return 0;
}
