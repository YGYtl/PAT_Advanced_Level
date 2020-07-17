#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	vector<int> v;
	scanf("%d", &n);
	v.resize(n);
	for(int i=0; i<n; i++){
		scanf("%d", &v[i]);
	}
	int ans = 0;
	for(int i=0; i<n; i++){
		if(v[i]==i) continue;
		while(v[i]!=i){
			swap(v[i],v[v[i]]);
			ans++;
		}
		if(i!=0) ans+=2;
	}
	printf("%d\n", ans);
	return 0;
}
