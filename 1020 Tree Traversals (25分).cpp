#include<bits/stdc++.h>
using namespace std;
int n;
int post[100], in[100];
int level[10000];
void getlevel(int proot, int il, int ir, int index){
	if(il>ir) return; 
	int t=il;
	while(t<ir&&post[proot]!=in[t]) t++;
	level[index] = post[proot];
	getlevel(proot-(ir-t)-1,il,t-1,index*2+1);//×ó
	getlevel(proot-1,t+1,ir,index*2+2);//ÓÒ 
}
int main()
{
	scanf("%d", &n);
	memset(post,0,sizeof(post));
	memset(in,0,sizeof(in));
	memset(level,-1,sizeof(level));
	for(int i=0; i<n; i++) scanf("%d", &post[i]);
	for(int i=0; i<n; i++) scanf("%d", &in[i]);
	getlevel(n-1,0,n-1,0);
	int i=0, c=0;
	while(1){
		if(level[i]!=-1){
			if(c) printf(" ");
			printf("%d", level[i]);
			c++;
		}
		i++;
		if(c==n) break;
	}
	return 0;
}
