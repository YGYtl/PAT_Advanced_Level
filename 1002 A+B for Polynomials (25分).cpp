#include<bits/stdc++.h>
using namespace std;
struct node{
	int c;//¥Œ√›
	double val;
};
map<int,double> ans;
int main()
{
	int n, m;
	node t, tt;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d %lf", &t.c, &t.val);
		ans[t.c] += t.val;
	}
	scanf("%d", &m);
	for(int i=0; i<m; i++){
		scanf("%d %lf", &t.c, &t.val);
		ans[t.c] += t.val;
	}
	int count = 0;
	map<int,double>::reverse_iterator it;
	for(it=ans.rbegin(); it!=ans.rend(); it++){
		if(it->second!=0) count++;
	}
	printf("%d", count);
	for(it=ans.rbegin(); it!=ans.rend(); it++){
		if(it->second!=0)
			printf(" %d %.1lf", it->first, it->second);
	}
	return 0;
}
