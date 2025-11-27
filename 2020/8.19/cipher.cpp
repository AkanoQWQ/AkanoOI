#include<bits/stdc++.h>
using namespace std;
string qw;
int i,j;
int main(){
	freopen("cipher.in","r",stdin);
	freopen("cipher.out","w",stdout);
	cin>>qw;
	while(qw[i] != '#'){
		if((qw[i] >= 'a' && qw[i] <= 'z')||(qw[i] >= 'A' && qw[i] <= 'Z')){
			if(qw[i] != 'A'&&qw[i] != 'a'){
				qw[i] = qw[i] - 1;
			}else{
				if(qw[i] == 'A'){
					qw[i] = 'Z';
				}else{
					qw[i] = 'z';
				}
			}	
		}
		i++;
	}
	for(j = 0;j < i;j++){
		cout<<qw[j];
	}
	return 0;
}
