#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, l, l1, l2, common;
	bool flag = true;
	scanf("%d", &n);
	getchar();
	string s, tmp;
	for(int i=0; i<n; i++){
		getline(cin,tmp);
		if(i==0){
			s = tmp;
			l1 = s.length();
			common = l1;
			continue;
		}
		l2 = tmp.length();
		l = min(l1,l2);
		int count = 0;
		for(int j=1; j<=l; j++){
			if(tmp[l2-j]==s[l1-j]){
				count++;
			}
			else break;
		}
		if(count==0){
			flag = false;
		}
		common = min(common,count);
	}
	if(flag){
		string ans = s.substr(l1-common);
		cout << ans << endl;
	}
	else printf("nai\n");
	return 0;
}
