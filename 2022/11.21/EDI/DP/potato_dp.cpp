#include<bits/stdc++.h>
using namespace std;

int main(){
	for(int t = 1;t <= 1000;t++){
		cout<<t<<endl;
		system("potato_data.exe");
		system("potato.exe");
		system("potato_ans.exe");
		if(system("fc potato.out potato.ans")){
			cout<<"WA"<<endl;
			return 0;
		}else{
			cout<<"AC"<<endl;
		}
	}
	return 0;
}

