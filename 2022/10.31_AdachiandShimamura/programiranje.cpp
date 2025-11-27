#include<bits/stdc++.h>
using namespace std;
string s;
int q;
struct lts{
	int c[26];
}empt,clts,quer,quer2;
vector<lts> l;
int main(){
	freopen("programiranje.in","r",stdin);
	freopen("programiranje.out","w",stdout);
	cin>>s>>q;
	l.push_back(clts);
	for(int i = 0;i < s.length();i++){
		clts.c[s[i] - 'a']++;
		l.push_back(clts);
	}
	while(q--){
		bool able = 1;
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		for(int i = 0;i < 26;i++){
			quer.c[i] = l[b].c[i] - l[a-1].c[i];
			quer2.c[i] = l[d].c[i] - l[c-1].c[i];
			if(quer.c[i] != quer2.c[i]){
				able = 0;
				break;
			}
		}
		if(able){
			cout<<"DA"<<endl;
		}else{
			cout<<"NE"<<endl;
		}
	}
	return 0;
}
