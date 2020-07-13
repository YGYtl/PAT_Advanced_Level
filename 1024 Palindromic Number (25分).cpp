#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s, ts, g="";
	int k, count=0, a=0, b=0;
	cin >> s >> k;
	while(count <= k){
		ts = s; g = ""; a = 0, b = 0;
		reverse(ts.begin(),ts.end());
		if(s==ts||count==k){
			cout << s << endl;
			cout << count << endl;
			break;
		}
		count++;
		for(int i=0; i<s.length(); i++){
			b = s[i]-'0'+ts[i]-'0'+a;
			g += b%10+'0';
			a = b/10;
		}
		if(a) g += a+'0';
		s = g;
		reverse(s.begin(),s.end());
	}
	return 0;
}
