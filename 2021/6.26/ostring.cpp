#include<bits/stdc++.h>
using namespace std;
string s;
char os[800006],cache;
int l = 400005,r = 400005,state/*0×ó1ÓÒ*/,len,i,q,t,f;
int main(){
	freopen("ostring.in","r",stdin);
	freopen("ostring.out","w",stdout);
	cin>>s;
	len = s.length();
	r += len;
	for(i = l;i < r;i++){
		os[i] = s[i-l];
	}
	
	r--;
	cin>>q;
	while(q--){
		cin>>t;
		if(t == 1){
			if(state == 0){
				state = 1;
			}else{
				state = 0;
			}
		}else{
			cin>>f;
			cin>>cache;
			if(f == 1){
				if(state == 0){
					l--;
					os[l] = cache;
				}else{
					r++;
					os[r] = cache;
				}
			}else{
				if(state == 1){
					l--;
					os[l] = cache;
				}else{
					r++;
					os[r] = cache;
				}//a   400005 400005   1
			}//////5
		}
	}
	if(state == 0){
		for(i = l;i <= r;i++){
			cout<<os[i];
		}
	}else{
		for(i = r;i >= l;i--){
			cout<<os[i];
		}
	}
	
	return 0;
}

