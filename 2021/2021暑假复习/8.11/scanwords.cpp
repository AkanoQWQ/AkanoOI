#include<bits/stdc++.h>
using namespace std;
int n,c3,i,j,last_w[260],m,nums[20006];
string s[20006],s1;
int main(){
	freopen("scanwords.in","r",stdin);
	freopen("scanwords.out","w",stdout);
	cin>>n;
	for(i = 0;i < n;i++){
		cin>>s[i];
		cin>>nums[i];
	}
	cin>>m;
	while(m--){
		cin>>s1;
		for(i = 0;i < n;i++){
			if(s1 == s[i]){
				cout<<nums[i]<<endl;
				break;
			}
		}
	}
	return 0;
}

