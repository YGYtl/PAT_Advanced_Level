#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
struct data{
	int id, fid, mid;
	int num, aera;
	int cid[10];
}a[10010];
struct node{
	int id, people;
	double num, aera;
	bool flag;
	node(){
		flag = false;
		aera = 0;
		num = 0;
	}
}ans[10010];
bool vis[10010];
int father[10010];
int find(int x){
	while(x!=father[x]) x = father[x];
	return x;
}
void Union(int x, int y){
	int xid = find(x);
	int yid = find(y);
	if(xid > yid) father[xid] = yid;
	else father[yid] = xid;
}
bool cmp(node a, node b){
	if(a.aera!=b.aera){
		return a.aera > b.aera;
	}
	else return a.id < b.id;
}
int main()
{
	int n, k, c = 0;
	for(int i=0; i<10000; i++) father[i] = i;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d %d %d %d", &a[i].id, &a[i].fid, &a[i].mid, &k);
		vis[a[i].id] = true;
		if(a[i].fid!=-1){
			Union(a[i].fid,a[i].id);
			vis[a[i].fid] = true;
		}
		if(a[i].mid!=-1){
			Union(a[i].mid,a[i].id);
			vis[a[i].mid] = true;
		}
		for(int j=0; j<k; j++){
			scanf("%d", &a[i].cid[j]);
			Union(a[i].id,a[i].cid[j]);
			vis[a[i].cid[j]] = true;
		}
		scanf("%d %d", &a[i].num, &a[i].aera);
	}
	for(int i=0; i<n; i++){
		int id = find(a[i].id);
		ans[id].id = id;
		ans[id].num += a[i].num;
		ans[id].aera += a[i].aera;
		ans[id].flag = true;
	}
	for(int i=0; i<10000; i++){
		if(vis[i]) ans[find(i)].people++;
		if(ans[i].flag) c++;
	}
	for(int i=0; i<10000; i++){
		if(ans[i].flag){
			ans[i].num = (double)(ans[i].num*1.0)/ans[i].people;
			ans[i].aera = (double)(ans[i].aera*1.0)/ans[i].people;
		}
	}
	sort(ans,ans+10000,cmp);
	printf("%d\n", c);
	for(int i=0; i<c; i++){
		printf("%04d %d %.3f %.3f\n", ans[i].id, ans[i].people, ans[i].num, ans[i].aera);
	}
	return 0;
}
