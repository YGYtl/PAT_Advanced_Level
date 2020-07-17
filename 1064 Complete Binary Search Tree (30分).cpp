#include<bits/stdc++.h>
using namespace std;
int n, c=0;
vector<int> level, v;
void get_level(int root){
	if(root<=n){
		get_level(root*2);
		level[root] = v[c++];
		get_level(root*2+1);
	}
}
int main()
{
	scanf("%d", &n);
	v.resize(n);
	level.resize(n+1);
	for(int i=0; i<n; i++){
		scanf("%d", &v[i]);
	}
	sort(v.begin() ,v.end());
	get_level(1);
	for(int i=1; i<=n; i++){
		if(i!=1) printf(" ");
		printf("%d", level[i]);
	}
	return 0;
}
