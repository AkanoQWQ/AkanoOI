#include<bits/stdc++.h>
#define FILE_ST using namespace std;namespace Mi_Shatas_Lilion{
#define EXCUTE_ST int main(){
#define FILE_ED_And_excute return 0;}}int main(){return Mi_Shatas_Lilion::main();}
FILE_ST
int n = 800,m = 500,q = 2e5;
EXCUTE_ST
	srand(time(0));
	freopen("area.in","w",stdout);
	cout<<n<<" "<<m<<endl;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(rand()%4 < 7){
				putchar('O');
			}else{
				putchar('X');
			}
		}
		putchar('\n');
	}
	cout<<q<<endl;
	while(q--){
		int x = (rand()%n) + 1;
		int y = (rand()%n) + 1;
		cout<<x<<" "<<y<<endl;
	}
FILE_ED_And_excute

