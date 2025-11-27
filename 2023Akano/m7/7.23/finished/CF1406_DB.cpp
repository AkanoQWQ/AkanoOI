#include<bits/stdc++.h>
using namespace std;
const int MAXM = 1e6;
bool now[MAXM];
int n = 4,MAINX = 4;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cout<<n<<endl;
	for(int i = 1;i <= n;i++)now[i] = true;
	while(1){
		char opt;
		int x;
		cin>>opt>>x;
		int ret = 0;
		for(int i = 1;i <= n;i++){
			if(i%x == 0){
				ret += now[i];
				if(opt == 'B' && i != MAINX){
					now[i] = false;
				}
			}
		}
		cout<<ret<<endl;
		
	}
	return 0;
}

