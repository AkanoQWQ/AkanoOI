#include<bits/stdc++.h>
#define FILE_ST using namespace std;namespace Mi_Shatas_Lilion{
#define EXCUTE_ST int main(){
#define FILE_ED_And_excute return 0;}}int main(){return Mi_Shatas_Lilion::main();}
FILE_ST

EXCUTE_ST
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int l = 3,r = 99,ret = 0;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(mid <= 99){
			l = mid + 1;
			ret = mid;
		}else{
			r = mid - 1;
		}
	}
	cout<<ret;
FILE_ED_And_excute

