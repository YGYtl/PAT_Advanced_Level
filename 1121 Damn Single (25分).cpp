#include<bits/stdc++.h>
using namespace std;
int n, m;
map<int,int> p;
map<int,bool> vis1, vis2;
vector<int> v, ans;
int main()
{
	int a, b, k;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d %d", &a, &b);
		p[a] = b; p[b] = a;
		vis1[a] = vis1[b] = true;
	}
	scanf("%d", &m);
	for(int i=0; i<m; i++){
		scanf("%d", &k);
		v.push_back(k);
		vis2[k] = true;
	}
	for(int i=0; i<m; i++){
		k = v[i];
		if(vis1[k]){
			int kk = p[k];
			if(!vis2[kk]) ans.push_back(k);
		}
		else ans.push_back(k);
	}
	printf("%d\n", ans.size());
	sort(ans.begin(),ans.end());
	for(int i=0; i<ans.size(); i++){
		if(i) printf(" ");
		printf("%05d", ans[i]);
	}
	return 0;
}
