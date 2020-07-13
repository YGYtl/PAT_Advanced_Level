#include<bits/stdc++.h>
using namespace std;
vector<string> v;
bool cmp(string a, string b){
	return a+b < b+a;
}
int main()
{
	string s, ans="", t="";
	int n;
	bool flag = true;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0; i<v.size(); i++) ans += v[i];
	for(int i=0; i<ans.length(); i++){
		if(ans[i]!='0') flag = false;
		if(!flag) t += ans[i];
	}
	if(t.length()==0) cout << "0" << endl;
	else cout << t << endl;
	return 0;
}
