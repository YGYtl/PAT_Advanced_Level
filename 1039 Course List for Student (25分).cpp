#include<bits/stdc++.h>
using namespace std;
int n, k;
const int maxn = 200000;
set<int> mp[maxn];
int main()
{
	int id, m, g;
	string str;
	scanf("%d %d", &n, &k);
	for(int i=0; i<k; i++){
		scanf("%d %d", &id, &m);
		for(int j=0; j<m; j++){
			cin >> str;
			g = (str[0]-'A')*26*26*10;
			g += (str[1]-'A')*26*10;
			g += (str[2]-'A')*10;
			g += str[3]-'0';
			mp[g].insert(id);
		}
	}
	set<int>::iterator it;
	for(int i=0; i<n; i++){
		cin >> str;
		g = (str[0]-'A')*26*26*10;
		g += (str[1]-'A')*26*10;
		g += (str[2]-'A')*10;
		g += str[3]-'0';
		cout << str << " " << mp[g].size();
		for(it=mp[g].begin(); it!=mp[g].end(); it++){
			cout << " " << *it;
		}
		cout << endl;
	}
	return 0;
}
