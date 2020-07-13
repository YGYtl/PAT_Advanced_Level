#include<bits/stdc++.h>
using namespace std;
vector<int> sum, resultArr;
int n, m;
void Func(int i, int &j, int &tempsum){
	int l=i, r=n;
	while(l<r){
		int mid = (l+r)/2;
		if(sum[mid]-sum[i-1]>=m) r = mid;
		else l = mid+1;
	}
	j = r;
	tempsum = sum[j]-sum[i-1];
}
int main()
{
	scanf("%d %d", &n, &m);
	sum.resize(n+1);
	for(int i=1; i<=n; i++){
		scanf("%d", &sum[i]);
		sum[i] += sum[i-1];
		printf("%d\n", sum[i]);
	}
	int minans = sum[n];
	for(int i=1; i<=n; i++){
		int j, tempsum;
		Func(i,j,tempsum);
		if(tempsum>minans) continue;
		if(tempsum>=m){
			if(tempsum<minans){
				resultArr.clear();
				minans = tempsum;
			}
			resultArr.push_back(i);
			resultArr.push_back(j);
		}
	}
	for(int i=0; i<resultArr.size(); i+=2){
		printf("%d-%d\n", resultArr[i], resultArr[i+1]);
	}
	return 0;
}
