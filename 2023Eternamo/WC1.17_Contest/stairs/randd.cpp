#include<bits/stdc++.h>
using namespace std;
int m = 300;
const int a = 300,b = 600;
int main(){
	//freopen(".in","r",stdin);
	freopen("stairs.in","w",stdout);
	cout<<m<<endl;
	while(m--){
		const int rd = rand()%5;
		if(rd == 0 || rd == 4){
			cout<<"? "<<rand()%10<<endl;
		}else if(rd == 1){
			cout<<"+ "<<(rand()%a)+1<<" "<<rand()%b<<endl;
		}else if(rd == 2){
			cout<<"- "<<(rand()%a)+1<<" "<<rand()%b<<endl;
		}else{
			cout<<"R "<<1<<endl;
		}
	}
	return 0;
}

