#include<bits/stdc++.h>
using namespace std;
int T,n,k,x;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>k>>x;
		if(x != 1){
			cout<<"YES"<<endl;
			cout<<n<<endl;
			for(int i = 1;i <= n;i++){
				cout<<1<<" ";
			}
			cout<<endl;
		}else{//x == 1
			if(k == 1){
				cout<<"NO"<<endl;
			}else if(k == 2){
				if(n % 2 == 0){
					cout<<"YES"<<endl;
					cout<<n/2<<endl;
					for(int i = 1;i <= n/2;i++){
						cout<<2<<" ";
					}
					cout<<endl;
				}else{
					cout<<"NO"<<endl;
				}
			}else{//k >= 3
				cout<<"YES"<<endl;
				cout<<n/2<<endl;
				while(n){
					if(n == 3){
						cout<<"3 ";n -= 3;
					}else{
						cout<<"2 ";n -= 2;
					}
				}
				cout<<endl;
			}
		}
	}
	return 0;
}

