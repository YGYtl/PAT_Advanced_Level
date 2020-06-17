#include<bits/stdc++.h>
using namespace std;
vector<int> v, vt;
int main()
{
	int n, a, l, r;
	int ansl=0, ansr=0;
	int tmax=0, ans=0; 
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &a);
		v.push_back(a);
		if(a>=0) vt.push_back(i); 
	}
	if(vt.size()==0){//没有大于等于0的数 
		printf("%d %d %d", 0, v[0], v[n-1]);
	}
	else{
		int c = 0, len = vt.size();
		while(c<len){
			tmax = 0;
			l = vt[c];
			for(int i=l; i<n; i++){
				if(tmax+v[i]>0){
					tmax = tmax+v[i];
					if(tmax > ans){
						ans = tmax;
						ansl = v[l];
						ansr = v[i];
					}
				}
				else break;
			}
			c++;
		}
		printf("%d %d %d", ans, ansl, ansr);
	}
	return 0;
}
