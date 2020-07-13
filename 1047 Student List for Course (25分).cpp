#include<bits/stdc++.h>
using namespace std;
int n, k, m;
const int maxn = 3000;
vector<int> v[maxn];
int main()
{
	string name;
	int c = 0, g;
	scanf("%d %d", &n, &k);
	for(int i=0; i<n; i++){
		cin >> name >> m; c = 0;
		c = (name[0]-'A')*26*26*10;
		c += (name[1]-'A')*26*10;
		c += (name[2]-'A')*10;
		c += (name[3]-'0');
		for(int j=0; j<m; j++){
			scanf("%d", &g);
			v[g].push_back(c);
		}
	}
	for(int i=1; i<=k; i++){
		printf("%d %d\n", i, v[i].size());
		sort(v[i].begin(),v[i].end());
		for(int j=0; j<v[i].size(); j++){
			int a1 = v[i][j]/(26*26*10)+'A';
			int a2 = v[i][j]%(26*26*10)/(26*10)+'A';
			int a3 = v[i][j]%(26*26*10)%(26*10)/10+'A';
			int a4 = v[i][j]%10+'0';
			printf("%c%c%c%c\n", a1, a2, a3, a4);
		}
	}
	return 0;
}
