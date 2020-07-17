#include<bits/stdc++.h>
using namespace std;
int main()
{
	map<int,string> p;
	p[0] = "ling"; p[1] = "yi"; p[2] = "er"; p[3] = "san";
	p[4] = "si"; p[5] = "wu"; p[6] = "liu"; p[7] = "qi";
	p[8] = "ba"; p[9] = "jiu";
	string str, ans="";
	cin >> str;
	int l, s=0;
	bool flag = false;
	l = str.length();
	if(str[0]=='-'){
		ans += "Fu";
		s++; l--; flag = true;
	}
	bool f1=false, f2=false, f3=false;
	for(int i=s; i<str.length(); i++,l--){
		f1 = false;
		if(l>=5&&l<=8) f2 = true;
		if(str[i]=='0') f3 = true;
		else{
			f1 = true;
			if(flag) ans += " ";
			if(f3) ans += "ling ";
			ans += p[str[i]-'0'];
			flag = true;
			f3 = false;
		}
		if(f1){
			if(l==2||l==6) ans += " Shi";
			if(l==3||l==7) ans += " Bai";
			if(l==4||l==8) ans += " Qian";
			if(l==9) ans += " Yi";
		}
		if(f2&&l==5){
			ans += " Wan"; f2 = false;
		}
	}
	if(str=="0") ans = "ling";
	cout << ans << endl;
	return 0;
}
