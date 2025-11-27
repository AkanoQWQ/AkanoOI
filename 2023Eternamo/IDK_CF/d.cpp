#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2e5 + 1018 + 1108;
ll t,n,c,a[MAXN];
ll blockTail = 0,blockSize = 0;
bool joined[MAXN];
inline void Update(){
	while(blockTail+1 <= n && blockSize + a[blockTail+1] >= (blockTail+1) * c){
		blockTail++;
		if(joined[blockTail] == false){
			blockSize += a[blockTail];
			joined[blockTail] = true;
		}
	}
	return ;
}
int main(){
	cin>>t;
	while(t--){
		cin>>n>>c;
		for(int i = 1;i <= n;i++){
			cin>>a[i];
			joined[i] = false;
		}
		blockTail = 1,blockSize = a[1];
		joined[1] = true;
		for(int i = 2;i <= n;i++){
			if(joined[i])continue;
			if(a[i] + blockSize >= i * c){
				joined[i] = true;
				blockSize += a[i];
				Update();
			}
		}
		bool OK = true;
		for(int i = 1;i <= n;i++){
			if(joined[i] == false){
				OK = false;
//				cerr<<i<<" joined false"<<endl;
			}
		}
		if(OK){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}
