#include<bits/stdc++.h>
using namespace std;
int n, cnt;
const int maxn = 1e4+5;
vector<int> inorder, post;
vector<int> level[maxn];
void get_level(int root, int inl, int inr, int index){
	if(inl>inr) return ;
	int i = inl;
	cnt = index;
	level[index].push_back(post[root]);
	while(i<=inr&&inorder[i]!=post[root]) i++;
	get_level(root-(inr-i+1),inl,i-1,index+1);
	get_level(root-1,i+1,inr,index+1);
}
int main()
{
	scanf("%d", &n);
	inorder.resize(n);
	post.resize(n);
	for(int i=0; i<n; i++) scanf("%d", &inorder[i]);
	for(int i=0; i<n; i++) scanf("%d", &post[i]);
	get_level(n-1,0,n-1,1);/*
	for(int i=1; i<=cnt; i++){
		if(i%2==0){
			for(int j=0; j<level[i].size(); j++){
				if(i!=1) printf(" ");
				printf("%d", level[i][j]);
			}
		}
		else{
			for(int j=level[i].size()-1; j>=0; j--){
				if(i!=1) printf(" ");
				printf("%d", level[i][j]);
			}
		}
	}*/
	return 0;
}
