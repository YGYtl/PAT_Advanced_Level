#include<bits/stdc++.h>
using namespace std;
map<int,int> G;
vector<int> v;
int main()
{
	int n, k;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &k);
		v.push_back(k);
		G[k]++;
	}
	bool flag = true;
	for(int i=0; i<v.size(); i++){
		if(G[v[i]]==1){
			flag = false;
			printf("%d\n", v[i]);
			break;
		}
	}
	if(flag) printf("None\n");
	return 0;
}
