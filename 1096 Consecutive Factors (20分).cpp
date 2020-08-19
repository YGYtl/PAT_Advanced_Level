#include<bits/stdc++.h>
using namespace std;
vector<int> ans, v;
int main()
{
	long long n, t;
	int l, r, g = 0, k;
	scanf("%lld", &n);
	for(int i=2; i<=sqrt(n); i++){
		l = r = i;
		while(n%l==0) l*=(++r);
		if(r-i>g){
			g = r-i;
			k = i;
		}
	}
	if(g==0) printf("1\n%lld\n", n);
	else{
		printf("%d\n", g);
		for(int i=0; i<g; i++){
			if(i) printf("*");
			printf("%d", k+i);
		}
	}
	return 0;
}
