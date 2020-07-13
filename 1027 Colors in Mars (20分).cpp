#include<bits/stdc++.h>
using namespace std;
int main()
{
	string ans="#", str="";
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	while(a){
		int k = a%13;
		if(k>=10) str += k-10+'A';
		else str += k+'0';
		a /= 13;
	}
	reverse(str.begin(),str.end());
	if(str.size()==1) str = '0'+str;
	if(str.size()==0) str="00";
	ans += str;str = "";
	while(b){
		int k = b%13;
		if(k>=10) str += k-10+'A';
		else str += k+'0';
		b /= 13;
	}
	reverse(str.begin(),str.end());
	if(str.size()==1) str = '0'+str;
	if(str.size()==0) str="00";
	ans += str; str = "";
	while(c){
		int k = c%13;
		if(k>=10) str += k-10+'A';
		else str += k+'0';
		c /= 13;
	}
	reverse(str.begin(),str.end());
	if(str.size()==1) str = '0'+str;
	if(str.size()==0) str="00";
	ans += str;
	cout << ans << endl;
	return 0;
}
