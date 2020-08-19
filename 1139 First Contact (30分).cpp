#include<bits/stdc++.h>
using namespace std;
int n, m;
unordered_map<int,vector<int> > p1, p2;
unordered_map<int,unordered_map<int,int> > f;
struct node{
	int s1, s2;
};
vector<node> v;
bool cmp(node a, node b){
	if(a.s1!=b.s1) return a.s1 < b.s1;
	else return a.s2 < b.s2;
}
void print(){
	node t;
	sort(v.begin(),v.end(),cmp);
	printf("%d\n", v.size());
	for(int i=0; i<v.size(); i++){
		t = v[i];
		printf("%04d %04d\n", t.s1, t.s2);
	}
	v.clear();
}
void solve1(int s1, int s2){//同性 
	node t;
	for(int i=0; i<p1[s1].size(); i++){
		t.s1 = p1[s1][i];
		for(int j=0; j<p1[s2].size()&&t.s1!=s2; j++){
			t.s2 = p1[s2][j];
			if(f[t.s1][t.s2]==1&&t.s2!=s1) v.push_back(t);
		}
	}
	print();
}
void solve2(int s1, int s2){//异性 
	node t;
	for(int i=0; i<p1[s1].size(); i++){
		t.s1 = p1[s1][i];
		for(int j=0; j<p1[s2].size(); j++){
			t.s2 = p1[s2][j];
			if(f[t.s1][t.s2]==1) v.push_back(t);
		}
	}
	print();
}
int main()
{
	string s1, s2;
	int a, b;
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; i++){
		cin >> s1 >> s2;
		a = abs(stoi(s1)); b = abs(stoi(s2));
		if(s1.length()==s2.length()){//同性 
			p1[a].push_back(b);
			p1[b].push_back(a);
		}
		else{//异性 
			p2[a].push_back(b);
			p2[b].push_back(a);
		}
		f[a][b] = f[b][a] = 1;
	}
	scanf("%d", &m);
	for(int i=0; i<m; i++){
		cin >> s1 >> s2;
		a = abs(stoi(s1)); b = abs(stoi(s2));
		if(s1.length()==s2.length()) solve1(a,b);
		else solve2(a,b);
	}
	return 0;
}
