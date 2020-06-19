#include<bits/stdc++.h>
using namespace std;
int main()
{
	double a, b, c, ans=1;
	int n = 3;
	for(int i=0; i<n; i++){
		scanf("%lf %lf %lf", &a, &b, &c);
		if(i) printf(" ");
		if(a>b&&a>c){
			printf("W");
			ans *= a;
		}
		else if(b>a&&b>c){
			printf("T");
			ans *= b;
		}
		else{
			printf("L");
			ans *= c;
		}
	}
	printf(" %.2f", (ans*0.65-1)*2);
	return 0;
}
