#include<bits/stdc++.h>
using namespace std;
int n, m, k;
map<int,int> p, pid;
struct node{
	int num, cnt = 0;
};
vector<node> G;
bool cmp(node a, node b){
	if(a.cnt!=b.cnt) return a.cnt > b.cnt;//½µÐò 
	else return a.num < b.num;//ÉýÐò 
}
int main()
{
	map<int,int>::iterator it;
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		scanf("%d", &k);
		pid[k] = i;
		node t;
		if(i){
			printf("%d:", k);
			for(int j=0; j<m&&j<G.size(); j++){
				printf(" %d", G[j].num);
			}
			printf("\n");
		}
		p[k]++;
		t.num = k; t.cnt = p[k];
		bool flag = true;
		for(int j=0; j<G.size(); j++){
			if(G[j].num==k){
				G[j].cnt = t.cnt;
				flag = false;
				break;
			}
		}
		if(flag) G.push_back(t);
		sort(G.begin(),G.end(),cmp);
		if(G.size()>m) G.pop_back();
	}
	return 0;
}
