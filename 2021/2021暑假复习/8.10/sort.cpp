#include<bits/stdc++.h>
using namespace std;//fixnum:固定了学生数量 last_max:末尾最大值 
int n,s1[2006],s2[1108],c[1108],fixnum = 0,tail,last_max = 20061108,i; 
int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	cin>>n;
	for(i = 0;i < n;i++){
		cin>>s1[i];
	}
	for(i = n-1;i >= 0;i--){
		if(s1[i] <= last_max){
			c[tail] = s1[i];
			tail++;
			last_max = s1[i]; 
			s1[i] = 0;
		}else{
			break;
		}
	}
	//for(i = 0;i < tail;i++){
	//	s2[tail-1-i] = c[i];
	//}
	cout<<n-tail;
	return 0;
}
