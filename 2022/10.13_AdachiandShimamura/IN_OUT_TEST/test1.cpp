#include<bits/stdc++.h>
using namespace std;
int c,n;
int main(){
	for(int FIL = 1;FIL <= 2;FIL++){
		freopen((to_string(FIL)+".in").c_str(),"r",stdin);
		cin>>n;
		for(int i = 1;i <= n;i++){
			cin>>c;
			cout<<FIL<<":"<<c<<endl;
		}
		cin.clear();
	}
	
	return 0;
}

