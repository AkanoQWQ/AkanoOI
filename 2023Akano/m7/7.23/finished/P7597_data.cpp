#include<bits/stdc++.h>
#include "DP_FILE/comp.h"
using namespace std;
Rander rd;
int n = 10;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("P7597.in","w",stdout);
	cout<<n<<endl;
	for(int i = 2;i <= n;i++){
		cout<<i<<" "<<rd(1,i-1)<<endl;
	}
	return 0;
}

