#include<bits/stdc++.h>
using namespace std;
int n, m;
map<int,int> p, p2, p3;
bool is_prime(int g){
	if(g==2||g==3) return true;
	for(int i=2; i<=sqrt(g); i++){
		if(g%i==0) return false;
	}
	return true;
}
int main()
{
	scanf("%d", &n);
	int g, k;
	for(int i=1; i<=n; i++){
		scanf("%d", &k);
		p[k] = true;
		p3[k] = i;
	}
	scanf("%d", &m);
	for(int i=0; i<m; i++){
		scanf("%d", &k);
		if(p[k]==false){//查无此人 
			printf("%04d: Are you kidding?\n", k);
		}
		else if(p2[k]==true){//查询过 
			printf("%04d: Checked\n");
		}
		else{
			if(p3[k]==1){
				printf("%04d: Mystery Award\n", k);
			}
			else{
				if(is_prime(p3[k])){
					printf("%04d: Minion\n", k);
				}
				else{
					printf("%04d: Chocolate\n", k);
				}
			}
		}
		p2[k] = true;
	}
	return 0;
}
