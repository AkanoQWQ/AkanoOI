#include<bits/stdc++.h>
#include "DP_FILE/comp.h"
using namespace std;
int n = 1018;
Rander rd = Rander(1,1e9);
int main(){
	freopen("P2487.in","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cout<<n<<endl;
	while(n--){
		cout<<rd()<<" "<<rd()<<endl;
	}
	return 0;
}

