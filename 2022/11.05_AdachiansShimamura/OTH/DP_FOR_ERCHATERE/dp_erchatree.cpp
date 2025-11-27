#include<bits/stdc++.h>
using namespace std;
int tms = 1000;
int main(){
	for(int t = 1;t <= tms;t++){
		cout<<"µÚ"<<t<<"¸ö²âÊÔµã:"<<endl;
		system("erchatree_data.exe");
		system("erchatree.exe");
		system("erchatree_check.exe");
		if(system("fc erchatree.out erchatree.ans")){
			cout<<"WA"<<endl;
			break;
		}
	}
	return 0;
}

