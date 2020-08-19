#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main()
{
	int n, k, ans=0;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &k);
		v.push_back(k);
	}
	sort(v.begin(),v.end());
	for(int i=0; i<v.size(); i++){
		if(i==0) ans = v[i];
		else ans = (ans+v[i])/2;
	}
	printf("%d", ans);
	return 0;
}
