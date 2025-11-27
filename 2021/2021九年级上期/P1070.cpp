#include<bits/stdc++.h>
using namespace std;
string s;
int nums,tellnum,i;
int main(){
	//freopen("P1070.in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>s;                       
	nums += (s[0]-'0')*1+(s[2]-'0')*2+(s[3]-'0')*3;
	nums += (s[4]-'0')*4+(s[6]-'0')*5+(s[7]-'0')*6+(s[8]-'0')*7+(s[9]-'0')*8+(s[10]-'0')*9; 
	if(s[12] == 'X'){
		tellnum = 10;
	}else{
		tellnum = s[12]-'0';
	}
	if(nums%11 == tellnum){
		cout<<"Right";
		return 0;
	}else{
		for(i = 0;i < 12;i++){
			cout<<s[i];
		}
		if(nums%11 == 10){
			cout<<"X";
		}else{
			cout<<nums%11;
		}
	}
	return 0;
}

