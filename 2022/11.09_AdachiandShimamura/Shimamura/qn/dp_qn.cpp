#include<bits/stdc++.h>
using namespace std;
int tmss = 1000;
int main(){
	for(int i = 1;i <= tmss;i++){
		cout<<i<<":"<<endl;
		system("query_num_data.exe");
		system("BF_query_num.exe");
		system("query_num.exe");
		if(system("fc qn.out qn_BF.out")){
			cout<<"WA";
			return 0;
		}
	}

	return 0;
}

