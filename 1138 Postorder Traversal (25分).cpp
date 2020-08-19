#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> pre, in, post;
void dfs(int root, int inl, int inr){
	if(inl > inr) return;
	int i = inl;
	while(pre[root]!=in[i]) i++;
	dfs(root+1,inl,i-1);
	dfs(root+1+(i-inl),i+1,inr);
	post.push_back(pre[root]);
}
int main()
{
	scanf("%d", &n);
	pre.resize(n);
	in.resize(n);
	for(int i=0; i<n; i++) scanf("%d", &pre[i]);
	for(int i=0; i<n; i++) scanf("%d", &in[i]);
	dfs(0,0,n-1);
	printf("%d\n", post[0]);
	return 0;
}
