#include<bits/stdc++.h>
using namespace std;
map<string,int> mp;
int main()
{
	int n, m;
	string s;
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cin >> s;
			mp[s]++;
		}
	}
	map<string,int>::iterator it;
	int mx = 0;
	string ans;
	for(it=mp.begin(); it!=mp.end(); it++){
		if(it->second>mx){
			mx = it->second;
			ans = it->first;
		}
	}
	cout << ans << endl;
	return 0;
}
