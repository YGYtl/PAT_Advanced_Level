#include<bits/stdc++.h>
using namespace std;
set<int> st;
int main()
{
	int n, k, t, g;
	string s;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		cin >> s;
		k = stoi(s);
		t = 0;
		while(k){
			t += k%10;
			k/=10;
		}
		st.insert(t);
	}
	printf("%d\n", st.size());
	set<int>::iterator it;
	g = 0;
	for(it=st.begin(); it!=st.end(); it++){
		if(g) printf(" ");
		printf("%d", *it);
		g++;
	}
	return 0;
}
