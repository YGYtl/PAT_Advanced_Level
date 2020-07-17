#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	int l1=min(s1.length(),s2.length());
	int l2=min(s3.length(),s4.length());
	int c = 0, a1, a2, a3;
	for(int i=0; i<l1; i++){
		if(s1[i]==s2[i]&&s1[i]>='0'&&s1[i]<='9'){
			if(c==1){
				a2 = s1[i]-'0';
				break;
			}
		}
		else if(s1[i]==s2[i]&&s1[i]>='A'&&s1[i]<='Z'){
			if(c==0&&s1[i]>='A'&&s1[i]<='G'){
				c = 1;
				a1 = s1[i]-'A'+1;
			}
			else if(c==1&&s1[i]>='A'&&s1[i]<='N'){
				a2 = s1[i]-'A'+10;
				break;
			}
		}
	}
	for(int i=0; i<l2; i++){
		if(s3[i]==s4[i]&&((s3[i]>='a'&&s3[i]<='z')||(s3[i]>='A'&&s3[i]<='Z'))){
			a3 = i;
			break;
		}
	}
	map<int,string> mp;
	mp[1] = "MON"; mp[2] = "TUE"; mp[3] = "WED"; mp[4] = "THU"; mp[5] = "FRI";
	mp[6] = "SAT"; mp[7] = "SUN";
	cout << mp[a1];
	printf(" %02d:%02d", a2, a3);
	return 0;
}
