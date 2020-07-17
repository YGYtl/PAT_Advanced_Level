#include<bits/stdc++.h>
using namespace std;
stack<int> st;
int main()
{
	int m, n, k;
	int g;
	bool flag = true;
	scanf("%d %d %d", &m, &n, &k);
	for(int i=0; i<k; i++){
		int o=1; flag = true;
		for(int j=1; j<=n; j++){
			scanf("%d", &g);
			while(o<=g){
				st.push(o);
				o++;
			}
			if(st.size()>m) flag = false;
			if(st.top()==g) st.pop();
		}
		if(flag&&st.empty()) printf("YES\n");
		else printf("NO\n");
		while(!st.empty()){
			st.pop();
		}
	}
	return 0;
}
