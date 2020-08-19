#include<bits/stdc++.h>
using namespace std;
vector<int> v1, v2;
map<int,bool> p;
int main()
{
	int n;
	scanf("%d", &n);
	v1.resize(n);
	for(int i=0; i<n; i++) scanf("%d", &v1[i]);
	int mx, mi;
	for(int i=0; i<n; i++){
		if(i==0) mx = v1[i];
		if(v1[i]>=mx){
			p[v1[i]] = true;
			mx = v1[i];
		}
	}
	for(int i=n-1; i>=0; i--){
		if(i==n-1) mi = v1[i];
		if(v1[i]<=mi){
			mi = v1[i];
			if(p[v1[i]]) v2.push_back(v1[i]);
		}
	}
	sort(v2.begin(),v2.end());
	printf("%d\n", v2.size());
	for(int i=0; i<v2.size(); i++){
		if(i) printf(" ");
		printf("%d", v2[i]);
	}
	printf("\n");
	return 0;
}
