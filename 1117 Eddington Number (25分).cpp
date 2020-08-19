#include<bits/stdc++.h>
using namespace std;
vector<int> v;
bool cmp(int a, int b){
	return a > b;
}
int main()
{
	int n, k, ans=1;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &k);
		v.push_back(k);
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0; i<n; i++, ans++){
		if(v[i]<=ans) break;
	}
	printf("%d", ans-1);
	return 0;
}
