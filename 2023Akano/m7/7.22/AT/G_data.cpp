#include<bits/stdc++.h>
using namespace std;
int n = 60,m = 60;
int main(){
	srand(time(0));
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("G.in","w",stdout);
	cout<<n<<" "<<m<<endl;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cout<<(rand()%300) + 1<<" ";
		}
		cout<<endl;
	}
	return 0;
}

