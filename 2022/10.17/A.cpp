#include<bits/stdc++.h>
using namespace std;
int t;
struct car{
	int x,y;
}c[2006];
int main(){
	cin>>t;
	while(t--){
		bool fd = 0;
		int n,m;
		cin>>n>>m;
		for(int i = 1;i <= m;i++){
			cin>>c[i].x>>c[i].y;
		}
		if(m < n){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
		continue;
		for(int i = 1;i <= n;i++){
			int cnt = 0;
			for(int j = 1;j <= n;j++){
				if(i == j)continue;
				cnt += (c[i].x == c[j].x) + (c[i].y == c[i].y);
			}
			if(cnt >= 2){
				fd = 1;
			}
		}
		if(fd == 1){
			cout<<"NO"<<endl;
		}else{
			cout<<"YES"<<endl;
		}
	}
	return 0;
}
