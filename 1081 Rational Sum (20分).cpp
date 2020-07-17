#include<bits/stdc++.h>
using namespace std;
int n, a1, b1, a2, b2;
int gcd(int a, int b){ return a == 0 ? b : gcd(b % a, a); } 
void sum(){
	int g = gcd(b1,b2);
	b1 /= g;
	b2 /= g;
	a1*=b2; a2 *= b1;
	a1 += a2;
	b1 *= b2*g;
}
int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		if(i==0) scanf("%d/%d", &a1, &b1);
		else{
			scanf("%d/%d", &a2, &b2);
			sum();
		}
	}
	int g = gcd(a1,b1);
	a1 /= g; b1 /= g;
	if(a1%b1==0) printf("%d\n", a1/b1);
	else if(a1>b1) printf("%d %d/%d\n", a1/b1, a1%b1, b1);
	else printf("%d/%d", a1%b1, b1);
	return 0;
}
