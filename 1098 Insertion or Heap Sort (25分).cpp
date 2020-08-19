#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v1, v2;
int main()
{
	scanf("%d", &n);
	v1.resize(n+1); v2.resize(n+1);
	for(int i=1; i<=n; i++) scanf("%d", &v1[i]);
	for(int i=1; i<=n; i++) scanf("%d", &v2[i]);
	int x = 2, k;
	while(x<=n&&v2[x]>=v2[x-1]) x++; k = x;
	while(x<=n&&v2[x]==v1[x]) x++;
	if(x==n+1){
		printf("Insertion Sort\n");
		sort(v2.begin()+1,v2.begin()+k+1);
	}
	else{
		printf("Heap Sort\n");
		int g1 = n;
		while(g1>=2&&v2[g1]>v2[g1-1]) g1--;
		swap(v2[g1],v2[1]);
		make_heap(v2.begin()+1,v2.begin()+g1);
	}
	for(int i=1; i<=n; i++){
		if(i!=1) printf(" ");
		printf("%d", v2[i]);
	}
	return 0;
}
