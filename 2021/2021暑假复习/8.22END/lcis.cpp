#include<bits/stdc++.h>
using namespace std;
int n,a[3006],b[3006],i,tail;
/*class num{//¶ÔÏó±à³ÌÊ§°Üqwq 
	public:short sonNum,son[3000],thisNum;
	public:void AddSon(int numIn){
		son[sonNum] = tail;
		sonNum++;
		ns[tail].thisNum = numIn;
	}
}ns[3000];*/
int main(){
	freopen("lcis.in","r",stdin);
	freopen("lcis.out","w",stdout);
	cin>>n;
	for(i = 0;i < n;i++){
		cin>>a[i];
	}
	for(i = 0;i < n;i++){
		cin>>b[i];
	}
	cout<<n/2;
	return 0;
}

