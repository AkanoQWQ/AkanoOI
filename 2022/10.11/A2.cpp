#include<bits/stdc++.h>
using namespace std;
int t;
string s1,s2;
int num[257];
int main(){
	cin>>t;
	num['S'] = 10;
	num['M'] = 20;
	num['L'] = 30;
	while(t--){
		cin>>s1>>s2;
		if(s1 == s2){
			cout<<"="<<endl;
			continue;
		}else{
			if(num[s1[s1.length()-1]] < num[s2[s2.length()-1]]){
				cout<<"<"<<endl;
			}else if(num[s1[s1.length()-1]] > num[s2[s2.length()-1]]){
				cout<<">"<<endl;
			}else{
				if(s1[s1.length()-1] == 'L'){
					if(s1.length() > s2.length()){
						cout<<">"<<endl;
					}else{
						cout<<"<"<<endl;
					}
				}else{
					if(s1.length() < s2.length()){
						cout<<">"<<endl;
					}else{
						cout<<"<"<<endl;
					}
				}
				
			}
		}
	}
	return 0;
}
