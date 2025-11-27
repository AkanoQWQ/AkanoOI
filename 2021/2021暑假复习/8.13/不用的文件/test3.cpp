#include<bits/stdc++.h>
using namespace std;
string a;
int main(){
	freopen("test3.in","r",stdin);
	freopen("test3.out","w",stdout);
	cin>>a;
	for(int i = 0;i < a.length();i++){
		if(i == 94)cout<<"<";
		cout<<a[i];
		if(i == 94)cout<<">";
	}
	//cout<<a[165];
	return 0;
}

