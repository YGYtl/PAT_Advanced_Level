#include<bits/stdc++.h>
using namespace std;
int n, c;
struct node{
	int id, grade;
	string name;
};
vector<node> v;
bool cmp1(node a, node b){
	return a.id < b.id;
}
bool cmp2(node a, node b){
	if(a.name!=b.name) return a.name < b.name;
	else return a.id < b.id;
}
bool cmp3(node a, node b){
	if(a.grade!=b.grade) return a.grade < b.grade;
	else return a.id < b.id;
}
int main()
{
	node t;
	scanf("%d %d", &n, &c);
	for(int i=0; i<n; i++){
		scanf("%d", &t.id);
		cin >> t.name;
		scanf("%d", &t.grade);
		v.push_back(t);
	}
	if(c==1){
		sort(v.begin(),v.end(),cmp1);
	}
	else if(c==2){
		sort(v.begin(),v.end(),cmp2);
	}
	else{
		sort(v.begin(),v.end(),cmp3);
	}
	for(int i=0; i<v.size(); i++){
		printf("%06d ", v[i].id);
		cout << v[i].name;
		printf(" %d\n", v[i].grade);
	}
	return 0;
}
