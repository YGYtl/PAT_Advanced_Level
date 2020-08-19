#include<bits/stdc++.h>
using namespace std;
int n;
long long a, b, c;
int main()
{
	string s;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		cin >> s;
		a = stoi(s);
		b = c = 0;
		for(int j=0; j<s.length()/2; j++){
			b = b*10 + s[j]-'0';
		}
		for(int j=s.length()/2; j<s.length(); j++){
			c = c*10 + s[j]-'0';
		}
		if(b!=0&&c!=0&&a%(b*c)==0) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
