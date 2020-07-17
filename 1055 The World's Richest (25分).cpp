#include<bits/stdc++.h>
using namespace std;
int n, m;
struct node{
	char name[10];
	int age, worth;
};
vector<node> v;
bool cmp(node a, node b){
	if(a.worth!=b.worth) return a.worth > b.worth;
	else if(a.age!=b.age) return a.age < b.age;
	else return strcmp(a.name,b.name)<0;
}
int main()
{
	int k, l, r;
	node t;
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		scanf("%s %d %d", t.name, &t.age, &t.worth);
		v.push_back(t);
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0; i<m; i++){
		scanf("%d %d %d", &k, &l, &r);
		printf("Case #%d:\n", i+1);
		int count = 0;
		for(int j=0; j<n&&count<k; j++){
			t = v[j];
			if(t.age>=l&&t.age<=r){
				count++;
				printf("%s %d %d\n", t.name, t.age, t.worth);
			}
		}
		if(count==0) printf("None\n");
	}
	return 0;
}
