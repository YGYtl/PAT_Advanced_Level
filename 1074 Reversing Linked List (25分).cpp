#include<bits/stdc++.h>
using namespace std;
struct node{
	int head, num, next;
};
const int maxn = 100005;
node l1[maxn];
vector<node> l2, l3;
int main()
{
	node t;
	int head, n, k;
	scanf("%d %d %d", &head, &n, &k);
	for(int i=0; i<n; i++){
		scanf("%d %d %d", &t.head, &t.num, &t.next);
		l1[t.head] = t;
	}
	while(head!=-1){
		t = l1[head];
		l2.push_back(t);
		head = t.next;
	}
	for(int i=0, j; i<l2.size(); i+=k){
		if(i+k<=l2.size()){
			j = i+k-1;
			while(j>=i){
				l3.push_back(l2[j]);
				j--;
			}
		}
		else{
			j = i;
			while(j<l2.size()){
				l3.push_back(l2[j]);
				j++;
			}
			break;
		}
	}
	for(int i=0; i<l3.size()-1; i++){
		printf("%05d %d %05d\n", l3[i].head, l3[i].num, l3[i+1].head);
	}
	printf("%05d %d -1\n", l3[l3.size()-1].head, l3[l3.size()-1].num);
	return 0;
}
