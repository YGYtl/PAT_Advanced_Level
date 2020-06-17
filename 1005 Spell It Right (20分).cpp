#include<bits/stdc++.h>
using namespace std;
map<int,string> p;
string getstr(int n){
	string str="";
	if(n==0) str += '0';
	while(n){
		str += n%10+'0';
		n /= 10;
	}
	reverse(str.begin(),str.end());
	return str;
}
int main()
{
	string s;
	cin >> s;
	int ans = 0;
	string str;
	for(int i=0; i<s.length(); i++){
		ans += s[i]-'0';
	}
	str = getstr(ans);
	p[0]="zero"; p[1]="one"; p[2]="two"; p[3]="three"; p[4]="four";
	p[5]="five"; p[6]="six"; p[7]="seven"; p[8]="eight"; p[9]="nine";
	for(int i=0; i<str.length(); i++){
		if(i) printf(" ");
		cout << p[str[i]-'0'];
	}
	return 0;
}
