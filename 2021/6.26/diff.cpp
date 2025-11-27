#include<bits/stdc++.h>
using namespace std;
string s;
char cchar;
int len,q,ca,i,bo[1000],ans,l,r;
int main(){
	freopen("diff.in","r",stdin);
	freopen("diff.out","w",stdout);
	cin>>len>>s>>q;
	while(q--){
		ans = 0;
		cin>>ca;
		if(ca == 1){
			cin>>i>>cchar;
			s[i-1] = cchar;
		}else{
			cin>>l>>r;
			for(i = 0;i < 30;i++){
				bo[i] = 0;
			}
			for(i = l-1;i < r;i++){
				bo[int(s[i])-97] = 1;
				//cout<<"test";
			}
			for(i = 0;i < 30;i++){
				if(bo[i] == 1){
					ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}

