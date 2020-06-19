#include<bits/stdc++.h>
using namespace std;
bool J(int n){
	if(n==1||n==0) return false;
	if(n==2||n==3) return true;
	for(int i=2; i<=sqrt(n); i++){
		if(n%i==0) return false;
	}
	return true;
}
bool judge(int n, int d){
	string s="";
	int t = n;
	while(n){
		s += '0'+n%d;
		n/=d;
	}
	int ans=0;
	for(int i=0; i<s.size(); i++){
		ans =  ans*d + s[i]-'0';
	}
	return J(ans);
}
int main()
{
	int n, d;
	while(scanf("%d", &n)){
		if(n<0) break;
		scanf("%d", &d);
		if(judge(n,d)&&J(n)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
