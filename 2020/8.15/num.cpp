#include<bits/stdc++.h>
using namespace std;
int k,i,j,a,b,n,ans; 
int main(){
	freopen("num.in","r",stdin);
	freopen("num.out","w",stdout);
	cin>>n;
	ans = n % 10;
	if(ans == 3){
		cout<<"bon";
		return 0; 
	}else if(ans == 0||ans == 1||ans == 6||ans == 8){
		cout<<"pon";
		return 0;
	}else{
		cout<<"hon";
	}
	return 0;
}
