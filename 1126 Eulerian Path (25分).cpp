#include<bits/stdc++.h>
using namespace std;
int n, m;
const int maxn = 1000;
vector<int> G[maxn];
bool vis[maxn];
void judge(){
	bool flag = true;
	int c = 0, t;
	memset(vis,false,sizeof(vis));
	for(int i=1; i<=n; i++){
		if(G[i].size()%2!=0) c++;
		if(G[i].size()==0&&n!=1) flag = false;
	}
	if(c!=0&&c!=2&&n!=1) flag = false;
	
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		t = q.front(); q.pop();
		vis[t] = true;
		for(int i=0; i<G[t].size(); i++){
			if(vis[G[t][i]]==false){
				q.push(G[t][i]);
			}
		}
	}
	for(int i=1; i<=n; i++){
		if(vis[i]==false) flag = false;
	}
	if(flag==false) printf("Non-Eulerian\n");
	else if(c==2) printf("Semi-Eulerian\n");
	else printf("Eulerian\n");
}
int main()
{
	int a, b;
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; i++){
		scanf("%d %d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int i=1; i<=n; i++){
		if(i!=1) printf(" ");
		printf("%d", G[i].size());
	}
	printf("\n");
	judge();
	return 0;
}
