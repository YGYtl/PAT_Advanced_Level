#include<bits/stdc++.h>
using namespace std;
int n, k, p, mx_sum;
vector<int> v, ans, tv;
void dfs(int index, int tk, int tsum, int tsum2)
{
	if(tk==k){
		if(tsum==n&&tsum2>mx_sum){
			mx_sum = tsum2;
			ans.clear();
			ans = tv;
		}
		return ;
	}
	while(index>=1){
		if(tsum+v[index]<=n){
			tv[tk] = index;
			dfs(index,tk+1,tsum+v[index],tsum2+index);
		}
		if(index==1) return ;
		index--;
	}
}
int main()
{
	scanf("%d %d %d", &n, &k, &p);
	tv.resize(k);
	mx_sum = -1;
	int temp = 0;
    for(int i = 1; temp <= n; i++) {
        v.push_back(temp);
        temp = pow(i, p);
    }
	dfs(v.size()-1, 0, 0, 0);
	if(mx_sum==-1){
		printf("Impossible\n");
		return 0;
	}
	printf("%d = ", n);
	for(int i=0; i<ans.size(); i++){
		if(i) printf(" + ");
		printf("%d^%d", ans[i], p);
	}
	return 0;
}
