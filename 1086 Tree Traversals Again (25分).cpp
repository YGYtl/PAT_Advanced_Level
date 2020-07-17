#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn = 100;
int in[maxn], pre[maxn];
vector<int> post;
void get_post(int root, int l, int r){
	if(l>r) return ;
	int i = l;
	while(i<=r&&pre[root]!=in[i]) i++;
	get_post(root+1,l,i-1);
	get_post(root+i-l+1,i+1,r);
	post.push_back(pre[root]);
}
int main()
{
	string str;
	int c1=0, c2=0, c3=0, k;
	stack<int> s; 
	cin >> n;
	for(int i=0; i<2*n; i++){
		cin >> str;
		if(str=="Push"){
			cin >> k;
			pre[c1++] = k;
			s.push(k);
		}
		else{
			in[c2++] = s.top();
			s.pop();
		}
	}
	get_post(0, 0, n-1);
	for(int i=0; i<post.size(); i++){
		if(i) printf(" ");
		printf("%d", post[i]);
	}
	return 0;
}
