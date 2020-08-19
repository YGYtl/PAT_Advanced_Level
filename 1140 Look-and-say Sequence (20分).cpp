#include<bits/stdc++.h>
using namespace std;
int main()
{
	char ch;
	string s, str;
	int m, cnt;
	cin >> s >> m;
	while(m>1){
		cnt = 0;
		ch = s[0];
		str = "";
		for(int i=0; i<s.length(); i++){
			if(s[i]==ch) cnt++;
			else{
				str += ch;
				str += cnt + '0'; 
				cnt = 1;
				ch = s[i]; 
			}
		}
		str += ch;
		str += cnt + '0';
		s = str;
		m--;
	}
	cout << s << endl;
	return 0;
}
