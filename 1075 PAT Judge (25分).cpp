#include<bits/stdc++.h>
using namespace std;
int n, k, m;
const int maxn = 1e5+1;
int score[maxn];
struct node{
	int id;
	int b[6];//记录每道题的分数 
	int all_score;
	int TG;
	int perfit_count;//记录完美答题个数 
	node(){
		TG = all_score = 0;
		perfit_count = 0;
		memset(b,-1,sizeof(b));
	}
};
map<int,node> p;
map<int,int> vis;
vector<node> v;
bool cmp(node a, node b){
	if(a.all_score!=b.all_score) return a.all_score > b.all_score;
	else if(a.perfit_count!=b.perfit_count) return a.perfit_count > b.perfit_count;
	else return a.id < b.id;
}
int main()
{
	int A, B, C;
	scanf("%d %d %d", &n, &k, &m);
	for(int i=1; i<=k; i++) scanf("%d", &score[i]);
	for(int i=0; i<m; i++){
		scanf("%d %d %d", &A, &B, &C);
		if(vis[A]==0){//没有记录过，把他添加到map中 
			node t;
			if(C==-1) C=0;
			else t.TG = 1;
			t.id = A;
			t.all_score = C;
			t.b[B] = C;
			if(C==score[B]){//标记B题已经满分 
				t.perfit_count++;
			}
			vis[A] = 1;
			p[A] = t;
		}
		else{//该学生之前已经答过题了 
			node t;
			t = p[A];
			if(C==-1) C=0;
			else t.TG = 1;
			if(t.b[B]==-1){//第B道题没有回答过 
				t.b[B] = C;
				t.all_score += C;
				if(C==score[B]){//标记B题已经满分 
					t.perfit_count++;
				}
			}
			else if(C>t.b[B]){
				t.all_score -= t.b[B];
				t.all_score += C;
				t.b[B] = C;
				if(C==score[B]){//标记B题已经满分 
					t.perfit_count++;
				}
			}
			p[A] = t;
		}
	}
	map<int,node>::iterator it;
	node t;
	for(it=p.begin(); it!=p.end(); it++){
		t = it->second;
		if(t.TG) v.push_back(t);
	}
	sort(v.begin(),v.end(),cmp);
	int rank = 1, tscore=0;
	for(int i=0; i<v.size(); i++){
		t = v[i];
		if(i==0) tscore = t.all_score;
		if(t.all_score!=tscore){
			rank = i+1;
			tscore = t.all_score;
		}
		printf("%d %05d %d", rank, t.id, t.all_score);
		for(int j=1; j<=k; j++){
			if(t.b[j]==-1) printf(" -");
			else printf(" %d", t.b[j]);
		}
		printf("\n");
	}
	return 0;
}
