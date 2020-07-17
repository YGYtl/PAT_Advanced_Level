#include<bits/stdc++.h>
using namespace std;
const int maxn = 20005;
vector<int> prime;
int p[maxn];
bool is_prime(int k){
	if(k==0||k==1) return false;
	for(int i=2; i<=sqrt(k); i++){
		if(k%i==0) return false;
	}
	return true;
}
int find_prime(int k){
	for(int i=0; i<prime.size(); i++){
		if(prime[i]>k) return prime[i];
	}
	return 0;
}
int main()
{
	memset(p,-1,sizeof(p));
	prime.push_back(2);
	for(int i=3; i<=maxn; i+=2){
		if(is_prime(i)) prime.push_back(i);
	}
	int n, m;
	long long k;
	scanf("%d %d", &n, &m);
	if(!is_prime(n)) n = find_prime(n);
	
	for(int i=0; i<m; i++){
		scanf("%lld", &k);
		if(i) printf(" ");
		int g = k%n, c=0;
		while(p[g]!=-1&&c<n){
			c++;
			g = (k+c*c)%n;
		}
		if(p[g]!=-1) printf("-");
		else{
			p[g%n] = g%n;
			printf("%d", g%n);
		}
	}
	return 0;
}
