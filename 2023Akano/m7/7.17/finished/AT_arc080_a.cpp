#include<bits/stdc++.h>
using namespace std;
int n,n1,n2,n4,c;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	while(n--){
		cin>>c;
		if(c % 4 == 0){
			n4++;
		}else if(c % 2 == 0){
			n2++;
		}else{
			n1++;
		}
	}
	if(n1 > n4){
		if(n1 == n4 + 1){
			if(n2 == 0){
				cout<<"Yes"<<endl;
			}else{
				cout<<"No"<<endl;
			}
		}else{
			cout<<"No"<<endl;
		}
	}else{
		cout<<"Yes"<<endl;
	}
	return 0;
}
