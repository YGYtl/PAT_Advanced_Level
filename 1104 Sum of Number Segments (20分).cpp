#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	double g;
	long long ans=0;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%lf", &g);
		ans += (long long)(g*1000)*(i+1)*(n-i);
	}
	printf("%.2f", ans/1000.0);
	return 0;
}
