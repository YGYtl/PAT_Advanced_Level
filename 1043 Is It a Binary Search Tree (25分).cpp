#include<bits/stdc++.h>
using namespace std;
vector<int> pre, post;
bool flag;
void getpost(int root, int tail){
	int i=root+1, j=tail;
	if(!flag){
		while(i<=tail&&pre[root]>pre[i]) i++;
		while(j>root&&pre[root]<=pre[j]) j--;
	}
	else{
		while(i<=tail&&pre[root]<=pre[i]) i++;
		while(j>root&&pre[root]>pre[j]) j--;
	}
	if(i-j!=1) return;
	getpost(root+1,j);
	getpost(i,tail);
	post.push_back(pre[root]);
}
int main()
{
	int n, k;
	scanf("%d", &n);
	flag = false;
	for(int i=0; i<n; i++){
		scanf("%d", &k);
		pre.push_back(k);
	}
	getpost(0,n-1);
	if(post.size()!=n){
		post.clear();
		flag = true;
		getpost(0,n-1);
	}
	if(post.size()==n){
		printf("YES\n");
		for(int i=0; i<post.size(); i++){
			if(i) printf(" ");
			printf("%d", post[i]);
		}
	}
	else printf("NO\n");
	return 0;
}
