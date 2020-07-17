#include<bits/stdc++.h>
using namespace std;
const int maxn = 200000+5;
long long v[maxn];
int n, p;
int search(int g){
	int l=g, r=n-1, mid;
	int tx = 0;
	while(l<=r){
		mid = (l+r)/2;
		if(v[mid]<=v[g]*p){
			tx = max(tx,mid-g+1);
			l = mid + 1;
		}
		else r = mid-1;
	}
	return tx;
}
int main()
{
	int ans=0;
	scanf("%d %d", &n, &p);
	for(int i=0; i<n; i++) scanf("%lld", &v[i]);
	sort(v,v+n);//Ð¡µ½´ó 
	for(int i=0; i<n; i++){
		ans = max(ans,search(i));
	}
	printf("%d", ans);
	return 0;
}
