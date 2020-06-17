#include<bits/stdc++.h>
using namespace std;
int main()
{
	//ÉÏ6£¬ÏÂ4£¬Í£5 
	int n, ans=0, a, t=0;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &a);
		ans += 5;
		if(a>t){
			ans += (a-t)*6;
		}
		else ans += (t-a)*4;
		t = a;
	}
	printf("%d", ans);
	return 0;
}
//(2-0)*6+5+(3-2)*6+5+(3-1)*4
