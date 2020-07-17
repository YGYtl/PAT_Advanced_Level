#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b){
	if(a==0) return b;
	gcd(b%a,a);
}
void com(long long x, long long y){
	long long g, c;
	bool f = false;
	g = gcd(abs(x),abs(y));
	x/=g; y/=g;
	c = x/y;
	if(c<0) x *= -1;
	x %= y;
	if(c!=0){
		if(c<0){
			printf("(%lld", c);
			f = true;
		}
		else printf("%lld", c);
	}
	if(x<0){
		printf("(%lld", x);
		f = true;
	}
	else{
		if(c==0) printf("%lld", x);
		else if(c!=0&&x!=0) printf(" %lld", x);
	}
	if(x!=0&&y!=1){
		printf("/%lld", y);
	}
	if(f) printf(")");
}
void solve1(long long a1, long long b1, long long a2, long long b2){
	com(a1,b1); printf(" + ");
	com(a2,b2); printf(" = ");
	long long a, b;
	b = b1*b2;
	a = a1*b2 + a2*b1;
	com(a,b);
}
void solve2(long long a1, long long b1, long long a2, long long b2){
	com(a1,b1); printf(" - ");
	com(a2,b2); printf(" = ");
	long long a, b;
	b = b1*b2;
	a = a1*b2 - a2*b1;
	com(a,b);
}
void solve3(long long a1, long long b1, long long a2, long long b2){
	com(a1,b1); printf(" * ");
	com(a2,b2); printf(" = ");
	if(a1==0||a2==0){
		printf("0");
		return ;
	}
	long long a, b;
	a = a1*a2; b = b1*b2;
	if(b<0){
		b*=-1;
		a*=-1;
	}
	com(a,b);
}
void solve4(long long a1, long long b1, long long a2, long long b2){
	com(a1,b1); printf(" / ");
	com(a2,b2); printf(" = ");
	if(a2==0){
		printf("Inf");
		return ;
	}
	long long a, b;
	a = a1*b2; b = b1*a2;
	if(b<0){
		b*=-1;
		a*=-1;
	}
	com(a,b);
}

int main()
{
	long long a1, b1, a2, b2;
	scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
	solve1(a1,b1,a2,b2); printf("\n");
	solve2(a1,b1,a2,b2); printf("\n");
	solve3(a1,b1,a2,b2); printf("\n");
	solve4(a1,b1,a2,b2); printf("\n");
	return 0;
}
