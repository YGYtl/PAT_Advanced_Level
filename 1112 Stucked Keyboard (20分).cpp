#include<bits/stdc++.h>
using namespace std;
map<char,bool> p, p2, p3;
int main()
{
	int k, c;
	string s, str="", str2="";
	cin >> k >> s;
	char t1, t2;
	for(int i=0; i<s.length(); i+=c){//�Ƿ񻵼� 
		t1 = s[i]; c=0;
		for(int j=i; j<s.length(); j++){
			t2 = s[j];
			if(t1==t2) c+=1;
			else break;
		}
		if(c%k==0&&p2[t1]==false){//���� 
			p[t1] = false;
		}
		if(c%k!=0){//�õ�
			p[t1] = true;
			p2[t1] = true;
		}
	}
	for(int i=0; i<s.length(); i+=c){//��� 
		t1 = s[i]; c = 0;
		for(int j=i; j<s.length(); j++){
			t2 = s[j];
			if(t1==t2) c+=1;
			else break;
		}
		int tc = c;
		if(p[t1]){
			while(tc--) str += t1;
		}
		else{
			if(p3[t1]==false){
				str2+=t1;
				p3[t1] = true;
			}
			tc /= k;
			while(tc--) str += t1;
		}
	}
	cout << str2 << endl;
	cout << str << endl;
	return 0;
}
