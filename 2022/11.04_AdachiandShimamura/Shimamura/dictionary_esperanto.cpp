#include<bits/stdc++.h>
#include<Windows.h>
using namespace std;
map<string,string> mp;
string s1,s2;
int main(){
	freopen("ENG_EPR.dic","r",stdin);
	while(1){
		s1 = "",s2 = "";
		cin>>s1>>s2;
		if(s1 != "" && s2 != ""){
			mp[s1] = s2;
			mp[s2] = s1;
		}else{
			break;
		}
	}
	cin.clear();
	freopen("CON","r",stdin);
	while(1){
		cin>>s1;
		if(mp.find(s1) != mp.end()){
			cout<<mp[s1]<<endl;
		}else{
			cout<<s1<<" NOT FONUD"<<endl;
		}
		cout<<"___________________________"<<endl;
	}
	return 0;
}
