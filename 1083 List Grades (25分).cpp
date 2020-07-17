#include<bits/stdc++.h>
using namespace std;
struct node{
	string name, class_name;
	int score;
};
vector<node> v, List;
bool cmp(node a, node b){
	return a.score > b.score;
}
int main()
{
	int n, l, r;
	node t;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		cin >> t.name >> t.class_name >> t.score;
		v.push_back(t);
	}
	scanf("%d %d", &l, &r);
	for(int i=0; i<n; i++){
		t = v[i];
		if(t.score >= l && t.score <= r){
			List.push_back(t);
		}
	}
	sort(List.begin(),List.end(),cmp);
	if(List.size()==0) printf("NONE");
	for(int i=0; i<List.size(); i++){
		cout << List[i].name << " " << List[i].class_name << endl;
	}
	return 0;
}
