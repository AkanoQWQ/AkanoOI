#include<bits/stdc++.h>
using namespace std;

int main(){
	system("echo off");
	for(int t = 1;t <= 1000;t++){
		cout<<t<<endl;
		system("lonely_data.exe");
		system("lonely.exe");
		system("lonely_chain.exe");
		if(system("fc lonely.out lonely2.out")){
			cout<<"WA"<<endl;
			return 0;
		}else{
			system("cls");
			cout<<"AC"<<endl;
		}
	}
	return 0;
}

