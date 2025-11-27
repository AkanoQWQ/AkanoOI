#include<bits/stdc++.h>
using namespace std;
int n = 30;
const int mod = 3;
int mp[156][156],cnt;
int main(){
	srand(time(0));
	freopen("susliks.in","w",stdout);
	cout<<n<<" "<<n<<endl;
	int mc = rand() % n + 1,mr = rand() % n + 1;
	mc = 1,mr = 1;
	for(int i = 1;i <= 100;i++){
		int stx = rand()%(n-mc+1) + 1;
		int sty = rand()%(n-mr+1) + 1;
		int addd = rand()%100;
		for(int x = 0;x < mc;x++){
			for(int y = 0;y < mr;y++){
				mp[stx+x][sty+y] += addd;
				cnt += addd;
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			cout<<mp[i][j]<<" ";
		}
		cout<<endl;
	}
	freopen("CON","w",stdout);
	cout<<cnt<<" "<<mc<<" "<<mr<<" expected "<<cnt/mc/mr; 
	return 0;
}
