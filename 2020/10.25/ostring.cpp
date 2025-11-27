#include<bits/stdc++.h>
using namespace std;
string s;
char c;
char ss[600006];
int q,i,j,n,f,h1 = 1,h2 = 1,fan,len,t;
int main(){
	freopen("ostring.in","r",stdin);
	freopen("ostring.out","w",stdout);
	cin>>s>>q;
	len = s.length();
	for(i = 300000;i < 300000+len;i++){
		ss[i] = s[i-300000];
	}
	for(i = 0;i < q;i++){
		cin>>t;
		if(t == 1){
			if(fan == 0){
				fan = 1;
			}else{
				fan = 0;
			}
		}
		if(t == 2){
			cin>>f>>c;
			if(f == 1){
				if(fan == 0){
					ss[300000-h1] = c;
					h1++;
				}else{
					ss[300000+len+h2] = c;
					h2++;
				}
			}
			if(f == 2){
				if(fan == 1){
					ss[300000-h1] = c;
					h1++;
				}else{
					ss[300000+len+h2] = c;
					h2++;
				}
			}
		}
	}
	if(fan == 0){
		for(i = 300000-h1;i < 300000+len+h2;i++){
		if(ss[i] >= 'a' && ss[i] <= 'z'){
			cout<<ss[i];
		} 
	}
	}
	if(fan == 1){
		for(i =300000+len+h2;i >= 300000-h1;i--){
		if(ss[i] >= 'a' && ss[i] <= 'z'){
			cout<<ss[i];
		} 
	}
	}
	return 0;
}
