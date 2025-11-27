#include<bits/stdc++.h>
using namespace std;
int a,b,c,m,n,i,j,k,len;
string s[20000];
int main(){
	//freopen(".in","r",stdin);
	freopen("scanwords2.in","w",stdout);
	cin>>n>>m;
	cout<<n<<endl;
	for(i = 0;i < n;i++){
		len = rand()%100;
		for(j = 0;j < max(len,1);j++){
			cout<<char(rand()%26+97);
		}
		cout<<s[i]<<endl<<rand()%1000<<endl;
	}
	cout<<m<<endl;
	//for(i = 0;i < n;i++){
	//	c = rand()%n;
	//	cout<<s[c]<<endl;
	//}
	return 0;
}

