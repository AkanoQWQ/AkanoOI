#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2006;
bool t[MAXN];
int ts,tn;
int n = 10;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	for(int i = 1;i <= 10000;i++){
		ts = 0;
		memset(t,0,sizeof(t));
		while(ts < n){
			tn++;
			const int m = rand()%n;
			if(t[m] == 0){
				t[m] = 1;
				ts++;
			}
		}
		
	}
	printf("%.3lf",double(tn)/10000.0f);
	return 0;
}

