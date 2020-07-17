#include<bits/stdc++.h>
using namespace std;
vector< set<int> > v;
int main()
{
	int n, m, k, g;
	scanf("%d", &n);
	v.resize(n+1);
	for(int i=1; i<=n; i++){
		scanf("%d", &m);
		for(int j=0; j<m; j++){
			scanf("%d", &g);
			v[i].insert(g);
		}
	}
	int count=0, all_num=0, a, b;
	scanf("%d", &k);
	set<int>::iterator it;
	for(int i=0; i<k; i++){
		scanf("%d %d", &a, &b);
		all_num = v[a].size()+v[b].size();
		count = 0;
		for(it=v[a].begin(); it!=v[a].end(); it++){
			if(v[b].find(*it)!=v[b].end()) count++;//在集合b中可以找到 
		}
		printf("%.1f%\n", count*100.0/(all_num-count));//共同的元素出现了两次 
	}
	return 0;
}
