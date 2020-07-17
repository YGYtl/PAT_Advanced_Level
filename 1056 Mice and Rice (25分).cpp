#include<bits/stdc++.h>
using namespace std;
int n, m;
struct node{
	int weight;
	int id;
};
const int maxn = 2000;
vector<node> v;
int l1[maxn], l2[maxn];
int main()
{
	int k, c1=0, c2=0;
	scanf("%d %d", &n, &m);//人数、mice 
	v.resize(n+1);
	memset(l1,0,sizeof(l1));
	memset(l2,0,sizeof(l2));
	for(int i=0; i<n; i++){//重量 
		scanf("%d", &v[i].weight);
	}
	for(int i=0; i<n; i++){//出场顺序 
		scanf("%d", &l1[i]);
	}
	c1 = n;
	int groups;
	while(1){
		c2 = 0;
		groups = c1/m;
		if(c1%m!=0) groups++;
		int mx, index;
		for(int i=0; i<c1; i+=m){
			mx = 0;
			for(int j=i; j<i+m&&j<c1; j++){
				int u = l1[j];//id号 
				if(v[u].weight>mx){
					mx = v[u].weight;
					index = u;
				}
			}
			for(int j=i; j<i+m&&j<c1; j++){
				int u = l1[j];
				if(u!=index){
					v[u].id = groups+1;
				}
			}
			l2[c2++] = index;
		}
		if(c1<=m){
			v[index].id = 1;
			break;
		}
		for(int i=0; i<c2; i++) l1[i] = l2[i];
		c1 = c2;
	}
	for(int i=0; i<n; i++){
		if(i) printf(" ");
		printf("%d", v[i].id);
	}
	return 0;
}
