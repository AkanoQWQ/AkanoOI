#include<bits/stdc++.h>
#define FILE_ST using namespace std;namespace Mi_Shatas_Lilion{
#define EXCUTE_ST int main(){
#define FILE_ED_And_excute return 0;}}int main(){return Mi_Shatas_Lilion::main();}
FILE_ST
int lef;
int n = 20000,q = 20000;
EXCUTE_ST
	srand(time(0));
	freopen("percent.in","w",stdout);
	for(int i = 1;i <= n;i++){
		if(n-i+1 <= lef){
			for(int j = i;j <= n;j++){
				putchar(')');
			}
			break;
		}
		if(rand()%2 || lef == 0){
			putchar('(');
			lef++;
		}else{
			putchar(')');
			lef--;
		}
	}
	cout<<endl<<q<<endl;
	while(q--){
		int r = 1,l = 2;
		while(r < l){
			r = rand()%n + 1;
			l = rand()%n + 1;
		}
		cout<<l<<" "<<r<<endl;
	}
FILE_ED_And_excute

