#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	long long id;
	int location_number, score;
	int local_rank, final_rank;
};
vector<node> v1[35000], v2;
bool cmp(node a, node b){
	if(a.score!=b.score) return a.score > b.score;
	else return a.id < b.id;
}
int main()
{
	int m, rank, mx_score;
	scanf("%d", &n);
	node t;
	for(int i=1; i<=n; i++){
		scanf("%d", &m);
		for(int j=0; j<m; j++){
			scanf("%013lld %d", &t.id, &t.score);
			t.location_number = i;
			v1[i].push_back(t);
		}
		sort(v1[i].begin(), v1[i].end(), cmp);
		rank = 1; mx_score = v1[i][0].score;
		for(int j=0; j<m; j++){
			if(v1[i][j].score==mx_score){
				v1[i][j].local_rank = rank;
				v2.push_back(v1[i][j]);
			}
			else{
				mx_score = v1[i][j].score;
				v1[i][j].local_rank = j+1;
				rank = j+1;
				v2.push_back(v1[i][j]);
			}
		}
	}
	sort(v2.begin(),v2.end(),cmp);
	rank = 1; mx_score = v2[0].score;
	for(int i=0; i<v2.size(); i++){
		if(v2[i].score==mx_score){
			v2[i].final_rank = rank;
		}
		else{
			mx_score = v2[i].score;
			v2[i].final_rank = i+1;
			rank = i+1;
		}
	}
  printf("%d\n", v2.size());
	for(int i=0; i<v2.size(); i++){
		t = v2[i];
		printf("%013lld %d %d %d\n", t.id, t.final_rank, t.location_number, t.local_rank);
	}
	return 0;
}
