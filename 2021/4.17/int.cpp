#include<bits/stdc++.h>
using namespace std;
string i;
int len,j,k;
int main(){
	freopen("int.in","r",stdin);
	freopen("int.out","w",stdout);
	cin>>i;
	len = i.length();
	for(j = 0;j < len;j++){
		if(i[j] == '.'){
			return 0;
		}
		cout<<i[j];
	}
	return 0;
}

