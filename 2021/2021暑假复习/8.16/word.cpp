#include<bits/stdc++.h>
using namespace std;
int n,i,j,leni,lenj,ci,cj,FOUND,ans,cha;
string w[206];
int main(){
	freopen("word.in","r",stdin);
	freopen("word.out","w",stdout);
	cin>>n;
	for(i = 0;i < n;i++){
		cin>>w[i];
	}
	for(i = 0;i < n;i++){
		ans = 0;
		leni = w[i].length();
		for(j = 0;j < n;j++){
			lenj = w[j].length();
			if(leni > lenj){
				continue;
			}else{
				cha = lenj - leni;
				for(ci = 0;ci <= cha;ci++){
					FOUND = 1;
					for(cj = 0;cj < leni;cj++){
						if(w[i][cj] != w[j][ci+cj]){
							FOUND = 0;
							break;
						}
					}
					if(FOUND == 1){
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl; 
	}
	return 0;
}

