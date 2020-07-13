#include<bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	getline(cin,str);
	int len = str.size();
	string s1="", s2="", s3="";
	int t1, t2;
	for(int i=len; i>=1; i--){
		if(i*2<=len&&len-i*2>i){
			t1 = i;
			t2 = len-i*2;
			break;
		}
	}
	s1 = str.substr(0,t1); str = str.substr(t1);
	s2 = str.substr(0,t2); str = str.substr(t2);
	s3 = str;
	reverse(s3.begin(),s3.end());
	for(int i=0; i<s1.size(); i++){
		cout << s1[i];
		for(int j=0; j<t2-2; j++) cout << " ";
		cout << s3[i] << endl;
	}
	cout << s2 << endl;
	return 0;
}
