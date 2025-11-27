#include<bits/stdc++.h>
using namespace std;
int n,lens,lent,lenmax,tails,tailt,cnt,idkn_num;
string s,t;//s -> t
char idkn;//I don't know name......
bool IS_NO;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		IS_NO = 0;
		cin>>s>>t;
		lens = s.length(),lent = t.length(),tailt = 0,tails = 0,idkn = ' ',IS_NO = 0;
		lenmax = max(lens,lent);
		while(tailt < lent&&tails < lens){
			//if(n == 22)cout<<tailt<<" "<<tails<<" "<<t[tailt]<<","<<s[tails]<<" "<<idkn<<","<<cnt<<endl;
			if(s[tails] == '*'&&tails > 0){
				if(idkn != s[tails-1]){
					idkn = s[tails-1];
					idkn_num = 0;
				}
			}
			//THIS_IS = 0;
			//if(s[tails] == '*')THIS_IS = 1;
			if(t[tailt] == s[tails]){
				tailt++,tails++,cnt = 0;
				continue;
			}else if(t[tailt] == idkn){
				tailt++,cnt = 0,idkn_num++;
				continue;
			}else if(t[tailt] != idkn&&cnt == 0){
				tails++,cnt++;
				continue;
			}else if(t[tailt] != idkn&&cnt > 0){
				if(idkn_num > 0){
					tails++;
					idkn_num--;
				}else{
					cout<<"No"<<endl;
					//if(n == 22)cout<<tailt<<" "<<t[tailt]<<"Óë"<<idkn<<",and"<<tails<<":"<<s[tails]<<","<<cnt<<endl;
					IS_NO = 1;
					break;
				}
			}
		}
		while(tails < lens&&IS_NO == 0){
			if(s[tails] != '*'&&s[tails] != idkn){
				//if(n == 22)cout<<tails<<":"<<s[tails]<<"Î¥¹æ!"<<endl;
				cout<<"No"<<endl;
				cout<<"TET";
				IS_NO = 1;
				break;
			}else if(s[tails] != '*'&&s[tails] == idkn){
				if(idkn_num <= 0){
					//if(n == 22)cout<<tails<<":"<<s[tails]<<"idkn_numÎ¥¹æ!"<<endl;
					cout<<"No"<<endl;
					IS_NO = 1;
					break;
				}
				idkn_num--;
			}
			tails++;
		}
		if(IS_NO == 0){
			cout<<"Yes"<<endl;
		}
		
		//cout<<IS_NO<<endl;
	}
	return 0;
}

