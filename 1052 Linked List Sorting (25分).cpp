#include<bits/stdc++.h>
using namespace std;
const int maxn = 100000;
struct node{
	int front, num, next;
}l1[maxn];
vector<int> v;
vector<node> l;
map<int,node> mp;
int main()
{
	int n, head;
	node t;
	scanf("%d %d", &n, &head);
	for(int i=0; i<n; i++){
		scanf("%d %d %d", &t.front, &t.num, &t.next);
		l1[t.front].front = t.front;
		l1[t.front].num = t.num;
		l1[t.front].next = t.next;
	}
	while(head!=-1){
		v.push_back(l1[head].num);
		mp[l1[head].num] = l1[head];
		head = l1[head].next;
	}
	sort(v.begin(),v.end());
	for(int i=0; i<v.size(); i++){
		l.push_back(mp[v[i]]);
	}
	if(v.size()>0) printf("%d %05d\n", v.size(), l[0].front);
	else{
		printf("0 -1\n");
		return 0;
	}
	for(int i=0; i<l.size()-1; i++){
		t = l[i];
		printf("%05d %d %05d\n", t.front, t.num, l[i+1].front);
	}
	printf("%05d %d -1\n", l[l.size()-1].front, l[l.size()-1].num);
	return 0;
}
