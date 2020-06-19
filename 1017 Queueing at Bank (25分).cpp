#include<bits/stdc++.h>
using namespace std;
struct node{
	int nowtime, dtime, wait;
	int pretime;
};
vector<node> v, g;
bool cmp1(node a, node b){
	return a.pretime < b.pretime;
}
bool cmp2(node a, node b){
	return a.nowtime < b.nowtime;
}
int main()
{
	int n, k;
	node t;
	int hh, mm, ss;
	int c, cl = 8*3600, cr = 17*3600;
	scanf("%d %d", &n, &k);
	for(int i=0; i<n; i++){
		scanf("%d:%d:%d %d", &hh, &mm, &ss, &t.dtime);
		t.dtime = t.dtime*60;
		c = hh*3600 + mm*60 + ss;
		t.pretime = c;
		t.wait = 0;
		if(c>cr) continue;
		if(c<cl){
			t.wait = cl-c;
			t.nowtime = cl;
		}
		else t.nowtime = c;
		v.push_back(t);
	}
	int ans = 0, count=0;
	sort(v.begin(),v.end(),cmp1);
	for(int i=0; i<k&&i<v.size(); i++){
		ans += v[i].wait;
		t = v[i];
		t.nowtime += t.dtime;
		g.push_back(t);
	}
	sort(g.begin(),g.end(),cmp2);
	node t2;
	for(int i=k; i<v.size(); i++){
		t = v[i];
		t2 = g[0];
		if(t2.nowtime > t.nowtime){
			t.wait += t2.nowtime - t.nowtime;
			t.nowtime = t2.nowtime;
		}
		ans += t.wait;
		t.nowtime += t.dtime;
		g[0] = t;
		sort(g.begin(),g.end(),cmp2);
	}
	printf("%.1f", ans*1.0/(60*v.size()));
	return 0;
}
