#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
string a[2006];
int main(){
	while(1){
		getch();
		system("cls");
		for(int i = 0;i < 50;i++){
			for(int j = 0;j < 20;j++){
				a[j] += '.';
				a[j][i] = 'e';
				cout<<a[j][i];
			}
			cout<<endl;
		}
	}
	
	return 0;
}

