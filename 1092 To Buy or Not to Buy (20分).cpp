#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
bool vis[maxn];
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int c = 0, l1=0, l2=0;
	l1 = s1.length();
	l2 = s2.length();
	for(int i=0; i<l2; i++){
		for(int j=0; j<l1; j++){
			if(s2[i]==s1[j]&&!vis[j]){
				vis[j] = true;
				c++;
				break;
			}
		}
	}
	if(c==l2) printf("Yes %d", l1-c);
	else printf("No %d", l2-c);
	return 0;
}

