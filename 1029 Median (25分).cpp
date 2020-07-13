#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<long long> v;
int main()
{
	long long k;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%lld", &k);
		v.push_back(k);
	}
	scanf("%d", &m);
	for(int i=0; i<m; i++){
		scanf("%lld", &k);
		v.push_back(k);
	}
	sort(v.begin(),v.end());
	if(v.size()%2==1) printf("%lld\n", v[v.size()/2]);
	else printf("%lld\n", v[v.size()/2-1]);
	return 0;
}
