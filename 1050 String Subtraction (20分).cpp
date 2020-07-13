#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s1, s2;
	getline(cin,s1);
	getline(cin,s2);
	string ans="", t="";
	for(int i=0; i<s1.size(); i++){
		t += s1[i];
		if(s2.find(t)==s2.npos){
			ans += t;
		}
		t = "";
	}
	cout << ans << endl;
	return 0;
}
