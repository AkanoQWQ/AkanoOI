#include<bits/stdc++.h>
using namespace std;
int tms = 1000;
int main(){
	for(int t = 1;t <= tms;t++){
		cout<<"µÚ"<<t<<"¸ö²âÊÔµã:"<<endl;
		system("lotus_data.exe");
		system("lotus.exe");
		system("lotus_org_vector.exe");
		if(system("fc lotus.out lotus2.out")){
			cout<<"WA"<<endl;
			break;
		}
	}
	return 0;
}

