#include<bits/stdc++.h>
using namespace std;
struct node{
	double amount, price, avg;
};
vector<node> v;
bool cmp(node a, node b){
	return a.avg > b.avg; 
}
int main()
{
	int n;
	double ans=0, d;
	node t;
	scanf("%d %lf", &n, &d);
	v.resize(n);
	for(int i=0; i<n; i++) scanf("%lf", &v[i].amount);
	for(int i=0; i<n; i++){
		scanf("%lf", &v[i].price);
		v[i].avg = v[i].price/v[i].amount;
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0; i<v.size()&&d>0; i++){
		t = v[i];
		if(t.amount<=d){
			d -= t.amount;
			ans += t.price;
		}
		else{
			ans += t.avg*d;
			d = 0;
		}
	}
	printf("%.2f\n", ans);
	return 0;
}
