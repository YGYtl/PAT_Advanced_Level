#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> pre, post, inorder;
bool flag = true;
void get_inorder(int prel, int prer, int postl, int postr){
	if(prel==prer){
		inorder.push_back(pre[prel]);
		return ;
	}
	int i=prel, j=postr-1, k;
	if(pre[prel]==post[postr]){//发现中间结点 
		while(i<=prer&&j>=0&&pre[i]!=post[j]) i++;
		k = i-prel-1;
		if(k>0){
			get_inorder(prel+1,i-1,postl,postl+k-1);
		}
		else flag = false;
	}
	inorder.push_back(post[postr]);
	get_inorder(i,prer,postl+k,postr-1);
}
int main()
{
	scanf("%d", &n);
	pre.resize(n);
	post.resize(n);
	for(int i=0; i<n; i++) scanf("%d", &pre[i]);
	for(int i=0; i<n; i++) scanf("%d", &post[i]);
	get_inorder(0,n-1,0,n-1);
	if(flag) printf("Yes\n");
	else printf("No\n");
	for(int i=0; i<inorder.size(); i++){
		if(i) printf(" ");
		printf("%d", inorder[i]);
	}
	printf("\n");
	return 0;
}
