#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main()
{
	int n, m, k;
	int a, b, ta, tb;
	scanf("%d", &n);
	int sum = 0;
	v.push_back(0);
	for(int i=0; i<n; i++){
		scanf("%d", &k);
		sum += k;
		v.push_back(k);
	}
	scanf("%d", &m);
	for(int i=0; i<m; i++){
		scanf("%d %d", &a, &b);
		ta = min(a,b);
		tb = max(a,b);
		int t=0;
		for(int j=ta; j<tb; j++) t+=v[j];
		int ans = min(t,sum-t);
		printf("%d\n", ans);
	}
	return 0;
}
