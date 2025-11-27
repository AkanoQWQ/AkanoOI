#include<bits/stdc++.h>
#define FILE_ST using namespace std;namespace Mi_Shatas_Lilion{
#define EXCUTE_ST int main(){
#define FILE_ED_And_excute return 0;}}int main(){return Mi_Shatas_Lilion::main();}
FILE_ST
int a[2006];
int n = 50,m = 85;
vector<int> otp[1006];
EXCUTE_ST
	srand(time(0));
	freopen("ball.in","w",stdout);
	for(int j = 1;j <= m*n;j++){
		int rd = rand()%n + 1;
		int rdn = rand()%n +1; 
		while(otp[rd].size() >= m)rd = rand()%n + 1;
		while(a[rdn] >= m)rdn = rand()%n + 1;
		otp[rd].push_back(rdn);
		a[rdn]++;
	}
	cout<<n<<" "<<m<<endl;
	for(int i = 1;i <= n;i++){
		for(int j = 0;j < otp[i].size();j++){
			cout<<otp[i][j]<<" ";
		}
		cout<<endl;
	}
FILE_ED_And_excute

