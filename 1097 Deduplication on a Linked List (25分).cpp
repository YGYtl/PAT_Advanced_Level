#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
struct node{
	int head, num, next;
}l1[maxn];
vector<node> l2, l3, l4;
map<int,bool> p;
int main()
{
	int h, n, th;
	scanf("%d %d", &h, &n);
	node t;
	for(int i=0; i<n; i++){
		scanf("%d %d %d", &t.head, &t.num, &t.next);
		l1[t.head] = t;
	}
	th = h;
	while(th!=-1){
		t = l1[th];
		l2.push_back(t);
		th = t.next;
	}
	for(int i=0; i<l2.size(); i++){
		t = l2[i];
		if(p[abs(t.num)]==false){
			p[abs(t.num)] = true;
			l3.push_back(t);
		}
		else{
			l4.push_back(t);
		}
	}
	
	if(!l3.empty()){
		for(int i=0; i<l3.size()-1; i++){
			printf("%05d %d %05d\n", l3[i].head, l3[i].num, l3[i+1].head);
		}
		printf("%05d %d -1\n", l3[l3.size()-1].head, l3[l3.size()-1].num);
	}
	if(!l4.empty()){
		for(int i=0; i<l4.size()-1; i++){
			printf("%05d %d %05d\n", l4[i].head, l4[i].num, l4[i+1].head);
		}
		printf("%05d %d -1\n", l4[l4.size()-1].head, l4[l4.size()-1].num);
	}
	return 0;
}
