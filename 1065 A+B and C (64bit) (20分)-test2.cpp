#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long a, b, c;
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%lld %lld %lld", &a, &b, &c);
		long long ta, tb, tc;
		ta = a>>1;
		tb = b>>1;
		tc = c>>1;
		printf("Case #%d: ", i);
		if(ta+tb>tc){
			printf("true\n");
		}
		else if(ta+tb==tc&&((a&1)+(b&1)>(c&1))){
			printf("true\n");
		}
		else printf("false\n");
	}
	return 0;
}
