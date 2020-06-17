#include<bits/stdc++.h>
using namespace std;
struct node{
	int a;
	double b;
};
vector<node> v;
map<int,double> mp;
int main()
{
	int n, m;
	node t;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d %lf", &t.a, &t.b);
		v.push_back(t);
	}
	scanf("%d", &m);
	for(int i=0; i<m; i++){
		scanf("%d %lf", &t.a, &t.b);
		for(int j=0; j<n; j++){
			mp[t.a+v[j].a] += t.b*v[j].b;
		}
	}
	map<int, double>::reverse_iterator it;
	int count = 0;
	for(it=mp.rbegin(); it!=mp.rend(); it++){
		if(it->second!=0) count++;
	}
	printf("%d", count);
	for(it=mp.rbegin(); it!=mp.rend(); it++){
		if(it->second!=0) printf(" %d %.1lf", it->first, it->second);
	}
	return 0;
}
