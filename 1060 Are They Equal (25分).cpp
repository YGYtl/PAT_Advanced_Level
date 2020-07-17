#include<bits/stdc++.h>
using namespace std;
string get(int num){
	string str="";
	if(num==0) str = "0";
	while(num){
		str += num%10+'0';
		num /= 10;
	}
	reverse(str.begin(),str.end());
	return str;
}
string getstr(int k, string s){
	string ans="0.";
	string t = "";
	int l, r;//l大于0, r小于0
	int c = 0, index=s.length(), c1=0, c2=0;
	for(int i=0; i<s.length(); i++){
		if(s[i]=='.') index = i;
		if(c==0&&s[i]=='0'){
			if(index==s.length()) c1++;
			else c2++;
			continue;
		}
		if(s[i]!='.'&&c<k){
			t += s[i];
			c++;
		}
		if(index!=0){
			r++;
		}
	}
	l = index-c1;
	if(t.size()==0) c2 = 0;
	while(t.length()<k) t += '0';
	ans += t; ans += "*10"; ans += "^";
	l -= c2;
	if(l<0){
		ans += '-';
		l = l*(-1);
	}
	ans += get(l);
	return ans;
}
int main()
{
	int n;
	string s1, s2;
	cin >> n >> s1 >> s2;
	s1 = getstr(n,s1);
	s2 = getstr(n,s2);
	if(s1==s2){
		cout << "YES" << " " << s1 << endl;
	}
	else{
		cout << "NO" << " " << s1 << " " << s2 << endl;
	}
	return 0;
}
