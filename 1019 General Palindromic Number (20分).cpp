#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main()
{
	long long n, k;
	scanf("%lld %lld", &n, &k);
	if(n==0){
		printf("Yes\n0\n");
		return 0;
	}
	while(n){
		v.push_back(n%k);
		n /= k;
	}
	int l=0, r = v.size()-1, f=true;
	while(l<=r){
		if(v[l]==v[r]){
			l++;
			r--;
		}
		else{
			f = false;
			break;
		}
	}
	if(f) printf("Yes\n");
	else printf("No\n");
	for(int i=v.size()-1; i>=0; i--){
		if(i!=v.size()-1) printf(" ");
		printf("%d", v[i]);
	}
	return 0;
}
