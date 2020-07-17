#include<bits/stdc++.h>
using namespace std;
map<string,int> p;
int main()
{
	string s, t="";
	getline(cin,s);
	s += '.';//不加最后一个测试点会错 
	int l = s.length();
	string ans="";
	int count = 0;
	for(int i=0; i<l; i++){
		if(s[i]>='0'&&s[i]<='9'){
			t += s[i];
		}
		else if(s[i]>='A'&&s[i]<='Z'){
			t += s[i]-'A'+'a';
		}
		else if(s[i]>='a'&&s[i]<='z'){
			t += s[i];
		}
		else{
			if(t.length()!=0) p[t]++;
			if(p[t]==count){
				ans = t < ans ? t : ans;
			}
			else if(p[t]>count){
				count = p[t];
				ans = t;
			}
			t = "";
		}
	}
	cout << ans << " " << count << endl;
	return 0;
}
