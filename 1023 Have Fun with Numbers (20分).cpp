#include<bits/stdc++.h>
using namespace std;
map<int,int> p, mp;
string gettx(string x){
	string ans="";
	reverse(x.begin(),x.end());
	int a=0, b=0;
	for(int i=0; i<x.length(); i++){
		b =a + (x[i]-'0')*2;
		a = b/10;
		b %= 10;
		ans += b+'0';
	}
	if(a!=0) ans += a +'0';
	reverse(ans.begin(),ans.end());
	return ans;
}
int main()
{
	bool flag = true;
	string x, tx;
	cin >> x;
	for(int i=0; i<x.length(); i++) p[x[i]] = 1;
	tx = gettx(x);
	for(int i=0; i<tx.length(); i++){
		if(p[tx[i]]!=1){
			flag = false;
		}
		mp[tx[i]] = 1;
	}
	if(flag&&p==mp) printf("Yes\n");
	else printf("No\n");
	cout << tx << endl;
	return 0;
}
