#include<bits/stdc++.h>
using namespace std;
struct node{
	string name;
	long long stime, etime;
};
vector<node> vt;
bool cmp1(node a, node b){
	return a.stime < b.stime;
}
bool cmp2(node a, node b){
	return a.etime > b.etime;
}

int main()
{
	int n;
	string str;
	node t;
	int a, b, c;
	scanf("%d", &n);
	while(n--){
		cin >> str;
		t.name = str;
		scanf("%d:%d:%d", &a, &b, &c);
		t.stime = a*3600 + b*60 + c;
		scanf("%d:%d:%d", &a, &b, &c);
		t.etime = a*3600 + b*60 + c;
		vt.push_back(t);
	}
	string ans1="", ans2="";
	sort(vt.begin(), vt.end(), cmp1);
	ans1 = vt[0].name;
	sort(vt.begin(), vt.end(), cmp2);
	ans2 = vt[0].name;
	cout << ans1 << " " << ans2 << endl;
	return 0;
}
