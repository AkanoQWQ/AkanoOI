#include<bits/stdc++.h>
using namespace std;
int t,n,m,c,k;
int main(){
	freopen("contest2.in","r",stdin);
	freopen("contest.in","w",stdout);
	cin>>t;
	cout<<110<<endl;
	for(int i = 1;i <= 110;i++){
		cin>>n>>m;
		cout<<n<<" "<<m<<endl;
		while(m--){
			cin>>k;
			cout<<k<<" ";
			while(k--){
				cin>>c;
				cout<<c<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}

