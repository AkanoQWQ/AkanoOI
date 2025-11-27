#include<bits/stdc++.h>
using namespace std;
string s;
long long len,sum,i;
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	cin>>s;
	len = s.length();
	for(i = 0;i < len;i++){
		sum += s[i] - '0';
	}
	cout<<sum;
	return 0;
}

