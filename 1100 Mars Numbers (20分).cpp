#include<bits/stdc++.h>
using namespace std;
map<string,int> p1;
map<int,string> p2;
int getint(string s){
	int t=0;
	for(int i=0; i<s.size(); i++){
		t = t*10 + s[i]-'0';
	}
	return t;
}

void solve1(string s){//×ÖÄ¸->Êı×Ö 
	int ans = 0;
	string t = "";
	for(int i=0; i<s.length(); i++){
		if(s[i]==' '){
			ans += p1[t];
			t = "";
		}
		else
			t += s[i];
	}
	ans += p1[t];
	cout << ans << endl;
}
void solve2(string s){//Êı×Ö->×ÖÄ¸ 
	int n = getint(s);
	int g1 = n/13;
	int g2 = n%13;
	if(g1!=0){
		cout << p2[g1*13];
		if(g2!=0) cout << " ";
	}
	if(g1!=0&&g2==0)
		cout << endl;
	else
		cout << p2[g2] << endl;
}
int main()
{
	int n;
	scanf("%d", &n); getchar();
	string s;
	p1["tret"]=0; p1["jan"]=1; p1["feb"]=2; p1["mar"]=3; p1["apr"]=4;
	p1["may"]=5; p1["jun"]=6; p1["jly"]=7; p1["aug"]=8; p1["sep"]=9;
	p1["oct"]=10; p1["nov"]=11; p1["dec"]=12;
	p1["tam"]=13; p1["hel"]=26; p1["maa"]=39;
	p1["huh"]=4*13; p1["tou"]=5*13; p1["kes"]=6*13; p1["hei"]=7*13;
	p1["elo"]=8*13; p1["syy"]=9*13; p1["lok"]=130; p1["mer"]=11*13;
	p1["jou"]=12*13;
	
	p2[0]="tret"; p2[1]="jan"; p2[2]="feb"; p2[3]="mar"; p2[4]="apr";
	p2[5]="may"; p2[6]="jun"; p2[7]="jly"; p2[8]="aug"; p2[9]="sep";
	p2[10]="oct"; p2[11]="nov"; p2[12]="dec";
	p2[13]="tam"; p2[26]="hel"; p2[39]="maa"; p2[4*13]="huh";
	p2[5*13]="tou"; p2[6*13]="kes"; p2[7*13]="hei"; p2[8*13]="elo";
	p2[9*13]="syy"; p2[130]="lok"; p2[11*13]="mer"; p2[12*13]="jou";
	
	for(int i=0; i<n; i++){
		getline(cin,s);
		if(s[0]>='a'&&s[0]<='z') solve1(s);
		else solve2(s);
	}
	return 0;
}
