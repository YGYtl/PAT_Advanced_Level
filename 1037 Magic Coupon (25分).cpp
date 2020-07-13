#include<bits/stdc++.h>
using namespace std;
bool cmp(int a, int b){
	return a > b;
}
vector<int> v1, v2;
vector<int> s1, s2;
int main()
{
	int n, m, k;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &k);
		if(k>0) v1.push_back(k);
		else v2.push_back(k);
	}
	scanf("%d", &m);
	for(int i=0; i<m; i++){
		scanf("%d", &k);
		if(k>0) s1.push_back(k);
		else s2.push_back(k);
	}
	sort(v1.begin(),v1.end(),cmp);
	sort(v2.begin(),v2.end());
	sort(s1.begin(),s1.end(),cmp);
	sort(s2.begin(),s2.end());
	int l1=min(v1.size(),s1.size());
	int l2=min(v2.size(),s2.size());
	int ans = 0;
	for(int i=0; i<l1; i++) ans += v1[i]*s1[i];
	for(int i=0; i<l2; i++) ans += v2[i]*s2[i];
	printf("%d\n", ans);
	return 0;
}
