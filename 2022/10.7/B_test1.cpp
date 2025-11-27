#include<bits/stdc++.h>
using namespace std;
int pre = 0;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	for(int i = 1;i <= 1000;i++){
		if(i % int(floor(sqrt(i))) == 0){
			cout<<i<<" "<<i-pre<<endl;
			pre = i;
		}
	}
	return 0;
}

