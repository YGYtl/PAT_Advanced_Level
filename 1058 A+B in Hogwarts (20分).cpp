#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a, b, c;
	int aa, bb, cc;
	scanf("%d.%d.%d", &a, &b, &c);
	scanf("%d.%d.%d", &aa, &bb, &cc);
	int t1=0, t2=0, t3=0; 
	int a1, a2, a3;
	t1 = (c+cc)/29;
	a1 = (c+cc)%29;
	t2 = (t1+b+bb)/17;
	a2 = (t1+b+bb)%17;
	a3 = a+aa+t2;
	printf("%d.%d.%d", a3, a2, a1);
	return 0;
}
