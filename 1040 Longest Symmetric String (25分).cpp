#include<bits/stdc++.h>
using namespace std;
bool judge(string str){
	string ts = str;
	reverse(str.begin(),str.end());
	return ts == str;
}
int main()
{
	string s, sg;
	int ans=1;
	getline(cin,s);
	int len = s.length();
	for(int i=0; i<len; i++){
		for(int j=1; j<=i; j++){
			if(i-j+2*j+1<=len) sg = s.substr(i-j,2*j+1);
			else break;
			if(judge(sg)){
				ans = max(ans,int(sg.size()));
			}
			else break;
		}
	}
	for(int i=1; i<len; i++){
		if(s[i]!=s[i-1]) continue;
		ans = max(ans,2);
		for(int j=1; j<i; j++){
			if(i-j+2*j+1<=len) sg = s.substr(i-1-j,2*j+2);
			else break;
			if(judge(sg)){
				ans = max(ans,int(sg.size()));
			}
			else break;
		}
	}
	cout << ans << endl;
	return 0;
}
