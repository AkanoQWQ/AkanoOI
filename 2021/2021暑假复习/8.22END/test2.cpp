#include<bits/stdc++.h>
using namespace std;
string s;
int t,i,len,n,l;
int main(){
	freopen("words.in","r",stdin);
	freopen("words.out","w",stdout);
	cin>>t;
	while(t--){
		scanf("%s%l",&s,&n);
		
		//cin>>s>>n;
		len = s.length();
		n %= len;
		n = len - n;
		for(i = n;i < len;i++){
			printf("%c",s[i]);
		}
		for(i = 0;i < n;i++){
			printf("%c",s[i]);
		}
		cout<<endl;
	}
	return 0;
}

