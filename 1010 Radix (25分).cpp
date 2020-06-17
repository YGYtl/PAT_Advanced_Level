#include<bits/stdc++.h>
using namespace std;
long long int getnum(string s, long long d){
	long long int sum = 0;
	int t;
	for(int i=0; i<s.length(); i++){
		if(s[i]>='a'&&s[i]<='z'){
			t = s[i]-'a'+10;
		}
		else t = s[i]-'0';
		sum = sum*d + t;
	}
	return sum;
}
int main()
{
	string n1, n2, s;
	long long int v1, v2;
	long long int tag, radix;
	cin >> n1 >> n2 >> tag >> radix;
	if(tag==1) v1 = getnum(n1,radix), s = n2;
	else v1 = getnum(n2,radix), s = n1;
	long long int tl=1, tr;
	for(int i=0; i<s.size(); i++){
		if(s[i]>='0'&&s[i]<='9'){
			tl = max(tl,(long long int)s[i]-'0');
		}
		else tl = max(tl,(long long int)s[i]-'a'+10);
	}
	tl+=1;
	tr = (v1 > tl ? v1 : tl)+1;
	while(tl<=tr){
		long long int tm = (tl+tr)/2;
		v2 = getnum(s,tm);
		if(tl==tr && v2!=v1){
			break;
		}
		else if(v2==v1){
			printf("%lld\n", tm);
			return 0;
		}
		else if(v2>v1 || v2<0) tr = tm;
		else tl = tm+1;
	}
	printf("Impossible\n");
	return 0;
}
