#include<bits/stdc++.h>
using namespace std;
int n, k, sum, s1, s2;
const int maxn = 1e5+5;
vector<int> v;
int dist[maxn];
int main()
{
	s1 = s2 = sum = 0;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &k);
		sum += k;
		v.push_back(k);
	}
	sort(v.begin(),v.end());
	for(int i=0; i<n/2; i++) s1 += v[i];
	s2 = sum-s1;
	printf("%d %d\n", n%2, abs(s1-s2));
	return 0;
}
