#include<bits/stdc++.h>
using namespace std;
struct data{
	int l;
	string name;
}a[100001];
bool cmp(data a, data b)
{
	if(a.l != b.l) return a.l > b.l;
	else{
		return a.name < b.name;
	}
}
int main()
{
	int n, k, j, u=0;
	scanf("%d %d", &n, &k);
	int m = n / k;
	int f = m+n-m*k;
	for(int i=0; i<n; i++) cin >> a[i].name >> a[i].l;
	sort(a,a+n,cmp);
	for(int i=0; i<k; i++)
	{
		if(!i) j = f;
		else j = m;
		int mid = j/2;
		vector<string> h(j);
		h[mid] = a[u++].name;
		int l = mid-1;
		int r = mid+1;
		while(l>=0&&r<j)
		{
			h[l--] = a[u++].name;
			h[r++] = a[u++].name;
		}
		if(l==0) h[l] = a[u++].name;
		cout << h[0];
		for(int o=1; o<h.size(); o++) cout << " " << h[o];
		cout << endl;
	}
	return 0;
}
