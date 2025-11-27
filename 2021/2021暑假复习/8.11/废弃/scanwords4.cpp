#include<bits/stdc++.h>
using namespace std;
int n,nums[300][300],c3,shuang[300][300],dantail,i,j;
string a[30][20001],s,dan[20006];
char c1,c2;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n;
	for(i = 0;i < n;i++){
		cin>>s;
		cin>>c3;
		if(s.length() == 1){
			dan[dantail] = c3;
			dantail++;
		}else if(s.length() == 2){
			c1 = s[0],c2 = s[1];
			shuang[int(c1)][int(c2)] = c3;
		}else{
			c1 = s[0];//abc 3
			a[int(c1)][int(c2)][tails] = s;
			nums[int(c1)][int(c2)] = c3;
			cout<<a[int(c1)][int(c2)]<<endl;
		}
	}
	
	return 0;
}

