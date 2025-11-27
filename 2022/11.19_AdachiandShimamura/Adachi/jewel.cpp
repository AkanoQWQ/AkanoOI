#include<bits/stdc++.h>
#define FILE_ST using namespace std;namespace Mi_Shatas_Lilion{
#define EXCUTE_ST int main(){
#define FILE_ED_And_excute return 0;}}int main(){return Mi_Shatas_Lilion::main();}
#define ll long long
FILE_ST
ll n,x,y,r[16],b[16];
EXCUTE_ST
	freopen("jewel.in","r",stdin);
	freopen("jewel.out","w",stdout);
	cin>>n>>x>>y;
	r[n] = 1;
	for(int i = 16;i >= 2;i--){
		if(r[i] > 0){
			r[i-1] += r[i];
			b[i] += x*r[i];
			r[i] = 0;
		}
		if(b[i] > 0){
			r[i-1] += b[i];
			b[i-1] += y*b[i];
			b[i] = 0;
		}
	}
	cout<<b[1];
FILE_ED_And_excute
