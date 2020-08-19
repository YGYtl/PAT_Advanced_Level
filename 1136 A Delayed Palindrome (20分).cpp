#include<bits/stdc++.h>
using namespace std;
bool judge(string s){
	string str = s;
	reverse(str.begin(),str.end());
	if(str==s) return true;
	else return false;
}
string add(string s1, string s2){
	int g = 0, k, i;
	string ans = "";
	reverse(s1.begin(),s1.end());
	reverse(s2.begin(),s2.end());
	for(i=0; i<s1.length()&&i<s2.length(); i++){
		k = s1[i]-'0' + s2[i]-'0' + g;
		g = k/10;
		k %= 10;
		ans += k+'0';
	}
	while(i<s1.length()){
		k = s1[i]-'0' + g;
		g = k/10;
		k %= 10;
		ans += k+'0'; 
		i++;
	}
	while(i<s2.length()){
		k = s2[i]-'0' + g;
		g = k/10;
		k %= 10;
		ans += k+'0';
		i++;
	}
	if(g!=0) ans += g+'0';
	reverse(ans.begin(),ans.end());
	return ans;
}
int main()
{
	string s, s1, s2;
	cin >> s;
	int c = 0;
	if(judge(s)==true) cout << s << " is a palindromic number." << endl;
	else{
		while(c<10){
			s1 = s2 = s;
			reverse(s2.begin(),s2.end());
			s = add(s1,s2);
			cout << s1 << " + " << s2 << " = " << s << endl; 
			if(judge(s)==true){
				cout << s << " is a palindromic number." << endl;
				break;
			}
			else c++;
		}
		if(c==10) cout << "Not found in 10 iterations." << endl;
	}
	return 0;
}
