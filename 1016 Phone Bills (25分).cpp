#include<bits/stdc++.h>
using namespace std;
int a[25];
struct node{
	string name;
	int mouth, count;
	int dd, hh, mm, f;
	string flag;
};
vector<node> v;
bool cmp(node b1, node b2){
	if(b1.name!=b2.name) return b1.name < b2.name;
	else if(b1.mouth!=b2.mouth) return b1.mouth < b2.mouth;
	else if(b1.dd!=b2.dd) return b1.dd < b2.dd;
	else if(b1.hh!=b2.hh) return b1.hh < b2.hh;
	else if(b1.mm!=b2.mm) return b1.mm < b2.mm;
}

double solve(node b1, node b2, int &time){
	int ans=0;
	while(b2.dd > b1.dd || b2.hh > b1.hh || b2.mm > b1.mm){
		time++;
		ans += a[b1.hh];
		b1.mm++;
		if(b1.mm>=60) b1.mm=0, b1.hh++;
		if(b1.hh>=24) b1.hh=0, b1.dd++;
	}
	return ans*1.0/100;
}

int main()
{
	memset(a,0,sizeof(a));
	for(int i=0; i<24; i++) scanf("%d", &a[i]);
	int n;
	node t;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		cin >> t.name;
		scanf("%d:%d:%d:%d", &t.mouth, &t.dd, &t.hh, &t.mm);
		cin >> t.flag;
		if(t.flag=="on-line") t.f=1;
		else t.f = 0;
		v.push_back(t);
	}
	sort(v.begin(),v.end(),cmp);
	bool fg=false;
	int on=-1, off=0;
	t = v[0];
	if(t.f) on=0;
	int time = 0;
	double ans = 0, g=0;
	for(int i=1; i<v.size(); i++){
		if(v[i].name == t.name){
			if(v[i].f) on = i;
			else off = i;
			if(on+1 == off){//可以出来啦 
				if(!fg){//第一个 
					cout << t.name << " ";
					printf("%02d\n", t.mouth);
					fg = true;
				}
				int time=0;
				double g = 0;
				printf("%02d:%02d:%02d %02d:%02d:%02d", t.dd, t.hh, t.mm, v[i].dd, v[i].hh, v[i].mm);
				g = solve(t,v[i],time);
				printf(" %d $%.2f\n", time, g);
				ans += g;
			}
		}
		else{
			if(fg){
				printf("Total amount: $%.2f\n", ans);
				fg = false; ans = 0;
			}
		}
		t = v[i];
		if(v[i].f) on = i;
		else off = i;
		if(i==n-1){
			if(fg) printf("Total amount: $%.2f\n", ans);
		}
	}
	return 0;
}
