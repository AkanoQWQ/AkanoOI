#include<bits/stdc++.h>
#define NO cout<<"No"<<endl;
using namespace std;
int s[11];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	s[0] = -1;
	for(int i = 1;i <= 8;i++){
		cin>>s[i];
		if(s[i] <  s[i-1]){
			NO;
			return 0;
		}
		if(s[i] < 100 || s[i] > 675){
			NO;
			return 0;
		}
		if(s[i] % 25 != 0){
			NO;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}

