#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main()
{
	int n, m, k;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &m);
		bool f = true;
		for(int j=0; j<m; j++){
			scanf("%d", &k);
			v.push_back(k);
			if(!f) continue;
			for(int o=0; o<j; o++){
				if(v[j]==v[o]||abs(v[j]-v[o]==abs(j-o))){
					f = false;
					break;
				}
			}
		}
		v.erase(v.begin(),v.begin()+v.size());
		if(f) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
