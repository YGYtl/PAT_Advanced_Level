#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, ans=0;
	scanf("%d", &n);
	int a=1, l, r;
	while(n/a){
		int now = n/a%10;
		l = n/(a*10);
		r = n%a;
		if(now == 0) ans += l*a;
		else if(now == 1) ans += l*a+1+r;
		else if(now > 1) ans += (l+1)*a;
		a *= 10;
	}
	printf("%d", ans);
	return 0;
}
