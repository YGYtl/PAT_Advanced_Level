#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s1, s2;
	getline(cin,s1);
	getline(cin,s2);
	int c = 0;
	map<char,bool> p;
	for(int i=0; i<s1.length(); i++){
		char ch1=s1[i], ch2=s2[c];
		if(s1[i]>='a'&&s1[i]<='z') ch1 = s1[i]-'a'+'A';
		if(s2[c]>='a'&&s2[c]<='z') ch2 = s2[c]-'a'+'A'; 
		if(ch1!=ch2&&p[ch1]==false){
			cout << ch1;
			p[ch1] = true;
		}
		else if(ch1==ch2) c++;
	}
    cout << endl;
	return 0;
}
