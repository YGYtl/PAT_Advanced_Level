#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int n, m;
map<int,int> mp;
int main()
{
	bool flag = true;
	scanf("%d %d", &n, &m);
	v.resize(n);
	for(int i=0; i<n; i++){
		scanf("%d", &v[i]);
		mp[v[i]]++;
	}
	sort(v.begin(),v.end());
	for(int i=0; i<v.size(); i++){
		int t = m-v[i];
		if(t==v[i]&&mp[t]>=2){
			flag = false;
			printf("%d %d\n", v[i], t);
			break;
		}
		else if(t>v[i]&&mp[t]!=0){
			flag = false;
			printf("%d %d\n", v[i], t);
			break;
		}
	}
	if(flag) printf("No Solution\n");
	return 0;
}
