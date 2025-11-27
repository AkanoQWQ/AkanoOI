#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int main(){
	while(1){
		char opt;
		cin>>opt;
		if(opt == 'a'){
			cin>>s1>>s2;
			m[s1].push_back(s2);
		}else{
			cin>>s1;
			for(int i = 0;i < m[s1].size();i++){
				cout<<m[s1][i]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}

