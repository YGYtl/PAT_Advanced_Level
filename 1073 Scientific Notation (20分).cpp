#include<bits/stdc++.h>
using namespace std;
int get_num(string s){
	int ans = 0;
	for(int i=0; i<s.size(); i++){
		ans = ans*10 + s[i]-'0';
	}
	return ans;
}
int main()
{
	string s, str;
	cin >> s;
	if(s[0]=='-') cout << '-';
	
	str = s.substr(1);
	string s1="", s2="", s3="";
	int g1=0, g2=0;
	g1 = str.find('.');
	g2 = str.find('E');
	
	s1 = str.substr(0,g1);
	s2 = str.substr(g1+1,g2-g1-1);
	s3 = str.substr(g2+2);
	
	int k = get_num(s3);
	if(k==0){
		cout << s1 + '.' + s2 << endl;
		return 0;
	}
	
	string ans = "";
	if(str[g2+1]=='-'){//前面追加 
		ans = "0.";
		k-=s1.size();
		while(k){
			ans += '0';
			k--;
		}
		ans = ans + s1 + s2; 
	}
	else{//后面追加 
		int l = s2.size();
		if(k-l<0){
			ans += s1;
			ans += s2.substr(0,k);
			ans += '.';
			ans += s2.substr(k);
		}
		else{
			k-=s2.size();
			ans = ans + s1 + s2;
			while(k){
				ans += '0';
				k--;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
