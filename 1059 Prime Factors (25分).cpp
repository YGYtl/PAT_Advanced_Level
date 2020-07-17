#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
vector<int> prime;
vector<node> ans;
struct node{
	int value;
	int cnt;
};
bool isPrime(int x){
	for(int i=2; i<=sqrt(x); i++){
		if(x%i==0) return false;
	}
	return true;
}
void getprime(){
	for(int i=2; i<maxn; i++){
		if(isPrime(i)) prime.push_back(i);
	}
}
int main()
{
	int n, i=0;
	scanf("%d", &n);
	printf("%d=", n);
	if(n==0||n==1) printf("%d", n==0?0:1);
	getprime();
	node t;
	bool flag;
	while(n>1){
		flag = false;
		if(n%prime[i]==0){
			t.value = prime[i];
			t.cnt = 0;
			flag = true;
		}
		while(n%prime[i]==0){
			t.cnt++;
			n /= prime[i];
		}
		if(flag) ans.push_back(t);
		i++;
	}
	for(int i=0; i<ans.size(); i++){
		if(i) printf("*");
		printf("%d", ans[i].value);
		if(ans[i].cnt>1) printf("^%d", ans[i].cnt);
	}
	return 0;
}
