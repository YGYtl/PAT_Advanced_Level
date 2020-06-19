#include<bits/stdc++.h>
using namespace std;
struct node{
	int student_id, C, E, M, A;
	int nC, nE, nM, nA;
};
map<int,node> mp;
vector<node> v;
bool cmp1(node a, node b){
	return a.C > b.C;
}
bool cmp2(node a, node b){
	return a.E > b.E;
}
bool cmp3(node a, node b){
	return a.M > b.M;
}
bool cmp4(node a, node b){
	return a.A > b.A;
}
int main()
{
	int n, m, id;
	node t;
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		scanf("%d %d %d %d", &t.student_id, &t.C, &t.M, &t.E);
		t.A = (int)((t.C+t.M+t.E)*1.0/3+0.5);
		mp[t.student_id] = t;
		v.push_back(t);
	}
	int t1, t2;
	sort(v.begin(),v.end(),cmp1);
	for(int i=0; i<v.size(); i++){
		t = v[i];
		if(i==0) t1 = t.C, t2 = i+1;
		if(t.C==t1) mp[t.student_id].nC = t2;
		else{
			mp[t.student_id].nC = i+1;
			t2 = i+1;
			t1 = t.C;
		}
	}
	
	sort(v.begin(),v.end(),cmp2);
	for(int i=0; i<v.size(); i++){
		t = v[i];
		if(i==0) t1 = t.E, t2 = i+1;
		if(t.E==t1) mp[t.student_id].nE = t2;
		else{
			mp[t.student_id].nE = i+1;
			t2 = i+1;
			t1 = t.E;
		}
	}
	
	sort(v.begin(),v.end(),cmp3);
	for(int i=0; i<v.size(); i++){
		t = v[i];
		if(i==0) t1 = t.M, t2 = i+1;
		if(t.M==t1) mp[t.student_id].nM = t2;
		else{
			mp[t.student_id].nM = i+1;
			t2 = i+1;
			t1 = t.M;
		}
	}
	
	sort(v.begin(),v.end(),cmp4);
	for(int i=0; i<v.size(); i++){
		t = v[i];
		if(i==0) t1 = t.A, t2 = i+1;
		if(t.A==t1) mp[t.student_id].nA = t2;
		else{
			mp[t.student_id].nA = i+1;
			t2 = i+1;
			t1 = t.A;
		}
	}
	
	for(int i=0; i<m; i++){
		scanf("%d", &id);
		int tmax=n; char ch;
		if(mp.find(id)==mp.end()) printf("N/A\n");
		else{
			t = mp[id];
			if(tmax >= t.nE) tmax = t.nE, ch = 'E';
			if(tmax >= t.nM) tmax = t.nM, ch = 'M';
			if(tmax >= t.nC) tmax = t.nC, ch = 'C';
			if(tmax >= t.nA) tmax = t.nA, ch = 'A';
			printf("%d %c\n", tmax, ch);
		}
	}
	return 0;
}
