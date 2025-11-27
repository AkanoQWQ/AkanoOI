#include<bits/stdc++.h>
using namespace std;
const int MN = 40;
const int MM = 50;
int t = 100,n = MN,m = MM,k = 5000,epa = 70;
int mp[2006][2006];
int main(){
	srand(time(0));
	freopen("lotus.in","w",stdout);
	cout<<t<<endl;
	while(t--){
		cout<<n<<" "<<m<<endl;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				mp[i][j] = rand();
			}
		}
		int s = epa;
		while(s--){
			int szx = rand()%(n/2) + 1,szy = rand()%(m/2) + 1;
			int x = n,y = m;
			int szm = szx * szy,cnt = 0;
			while(x+szx >= n)x = (rand()%n) + 1;
			while(y+szy >= m)y = (rand()%m) + 1;
			cnt = 0;
			for(int i = 0;i < szx;i++){
				for(int j = 0;j < szy;j++){
					int np = rand() % max((k * 2 / szm),1);
					mp[x+i][y+j] = np;
					cnt += np;
				}
			}
			mp[x][y] -= (cnt-k);
		}
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				cout<<mp[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<k<<endl;
		n = MN,m = MM;
	}
	return 0;
}

