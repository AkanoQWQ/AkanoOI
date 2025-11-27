#include<bits/stdc++.h>
using namespace std;
long long t,q,opt,k;
//long long a[28],b[28];
string s;
int main(){
	std::ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		long long alen = 1,blen = 1;
		//memset(a,0,sizeof(a));
		//memset(b,0,sizeof(b));
		bool HAVE_B = 0;
		bool ALL_A = 1;
		cin>>q;
		while(q--){
			cin>>opt>>k>>s;
			if(opt == 1){
				alen += s.length()*k;
				for(int i = 0;i < s.length();i++){
					if(s[i] > 'a')ALL_A = 0;
				}
			}else{
				blen += s.length()*k;
				for(int i = 0;i < s.length();i++){
					if(s[i] > 'a')HAVE_B = 1;
				}
			}
			if(HAVE_B){
				cout<<"YES"<<endl;
				continue;
			}
			if(ALL_A == 0){
				cout<<"NO"<<endl;
				continue;
			}
			if(alen < blen){
				cout<<"YES"<<endl;
			}else{
				cout<<"NO"<<endl;
			}
		}
	}
	return 0;
}
