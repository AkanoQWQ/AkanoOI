#include<bits/stdc++.h>
using namespace std;
int a,b,c,m,n,i,j,k,len,p[20006];
string s[20006];
int main(){
	freopen("scanwords2.in","r",stdin);
	freopen("scanwords.in","w",stdout);
	cin>>n;
	cout<<n<<endl;
	for(i = 0;i < n;i++){
		cin>>s[i]>>p[i];
		cout<<s[i]<<endl<<p[i]<<endl;
	}
	cin>>m;
	cout<<m<<endl;
	for(i = 0;i < m;i++){
		c = rand()%n;
		cout<<s[c]<<endl;
	}
	return 0;
}

