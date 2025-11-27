#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 6;
int n,l,pos = 1,x;
bool able = 1,r2 = 0;
int main(){
	cin>>n>>l;
	for(int i = 1;i <= n;i++){
		cin>>x;
		if(pos + x - 1 > l){
			r2 = 1;
			pos = 1;
			if(x == 2){
				able = 0;
				break;
			}
		}
		if(able == 0)break;
		if(r2 == 0){
			if(pos + x - 1 == l){
				continue;
			}
			pos++;
			pos = pos + x;
		}else{
			if(x == 2){
				able = 0;
				break;
			}
		}
	}
	if(able){
		puts("Yes");
	}else{
		puts("No");
	}
	return 0;
}
