#include<bits/stdc++.h>
using namespace std;
int n, l, h;
struct node{
	int id;
	int virtue, talent;
	int cid;
};
vector<node> v;
bool cmp(node a, node b){
	if(a.cid!=b.cid) return a.cid < b.cid;
	else if(a.virtue+a.talent != b.virtue+b.talent) return a.virtue+a.talent > b.virtue+b.talent;
	else if(a.virtue!=b.virtue) return a.virtue > b.virtue;
	else if(a.id!=b.id) return a.id < b.id;
}
int main()
{
	scanf("%d %d %d", &n, &l, &h);
	for(int i=0; i<n; i++){
		node t;
		scanf("%d %d %d", &t.id, &t.virtue, &t.talent);
		if(t.talent<l||t.virtue<l) continue;
		if(t.talent>=h&&t.virtue>=h) t.cid = 1;
		else if(t.talent<h&&t.virtue>=h) t.cid = 2;
		else if(t.talent<h&&t.virtue<h&&t.virtue>=t.talent) t.cid = 3;
		else t.cid = 4;
		v.push_back(t);
	}
	sort(v.begin(),v.end(),cmp);
	printf("%d\n", v.size());
	for(int i=0; i<v.size(); i++){
		node t = v[i];
		printf("%d %d %d\n", t.id, t.virtue, t.talent);
	}
	return 0;
}
