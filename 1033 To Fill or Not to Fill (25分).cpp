#include<bits/stdc++.h>
using namespace std;
double Cmax, D, Davg;
int n;
struct node{
	double price;
	double dist;
};
vector<node> v;
bool cmp(node a, node b){
	return a.dist < b.dist;
}
int main()
{
	node t, t1, t2;
	double mx_price=0;
	scanf("%lf %lf %lf %d", &Cmax, &D, &Davg, &n);
	t.price=0; t.dist=D;
	v.push_back(t);
	for(int i=0; i<n; i++){
		scanf("%lf %lf", &t.price, &t.dist);
		v.push_back(t);
	}
	sort(v.begin(), v.end(), cmp);
	double nowdist=0, maxdist=0, nowprice=0,totalprice=0,leftdist=0;
	if(v[0].dist!=0){
		printf("The maximum travel distance = 0.00");
		return 0;
	}
	else nowprice=v[0].price;
	while(nowdist<D){
		maxdist=nowdist+Cmax*Davg;
		double minpricedist=0, minprice=0x3f3f3f3f;
		int flag = 0;
		for(int i=1; i<=n&&v[i].dist<=maxdist; i++){
			if(v[i].dist<=nowdist) continue;
			if(v[i].price<nowprice){//�ҵ��ȵ�ǰ�۸�С��վ�� 
				totalprice+=(v[i].dist-nowdist-leftdist)*nowprice/Davg;
				leftdist=0;
				nowprice=v[i].price;
				nowdist=v[i].dist;
				flag = 1;
				break;
			}
			if(v[i].price < minprice){//���߾����ڣ��ҵ��۸���С��վ�� 
				minprice = v[i].price;
				minpricedist=v[i].dist;
			}
		}
		if(flag==0&&minprice!=0x3f3f3f3f){//������һ�����߾����ڼ۸���С��վ�� 
			totalprice+=(nowprice*(Cmax-leftdist/Davg));
			leftdist=Cmax*Davg-(minpricedist-nowdist);
			nowprice = minprice;
			nowdist=minpricedist;
		}
		if(flag==0&&minprice==0x3f3f3f3f){//���ﲻ����һ��վ�� 
			nowdist+=Cmax*Davg;
			printf("The maximum travel distance = %.2f", nowdist);
			return 0;
		}
		printf("%.2f %.2f %.2f %.2f\n", totalprice, leftdist, nowprice, nowdist);
	}
	printf("%.2f", totalprice);
	return 0;
}
