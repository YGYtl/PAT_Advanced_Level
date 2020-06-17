#include<iostream>
#include<cstdio>
#include<algorithm> 
using namespace std;
string getstr(int n){
	string ans = "", t="";
	int g = n;
	if(n==0) ans = "0";
	if(n<0) n = -n;
	while(n){
		t += ('0' + n%10);
		n /= 10;
	}
	for(int i=0; i<t.length(); i++){
		ans += t[i];
		if((i+1)%3==0&&i!=t.length()-1){
			ans += ",";
		}
	}
	reverse(ans.begin(),ans.end());
	if(g < 0) ans = "-" + ans;
	return ans;
}
int main()
{
	int a, b, c;
	scanf("%d %d", &a, &b);
	c = a + b;
	cout << getstr(c) << endl;
	return 0;
}
