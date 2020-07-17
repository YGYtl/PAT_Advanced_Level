#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int p[maxn], pa[maxn];
int main()
{
	int c = 0, tp = 0, tpa = 0, ans = 0;
	string s;
	cin >> s;
	int l = s.length();
	for(int i=0; i<l; i++){
		if(s[i]=='P') p[i] = tp++;
		p[i] = tp;
		
		if(s[i]=='A') tpa += p[i];
		pa[i] = tpa;
		
		if(s[i]=='T'){
			ans += pa[i];
			ans %= 1000000007;
		}
	}
	printf("%d", ans);
	return 0;
}
