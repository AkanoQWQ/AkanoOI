#include<bits/stdc++.h>
using namespace std;
int n,m,ma,i,j;
int main(){
	//freopen(".in","r",stdin);
	freopen("forest.in","w",stdout);
	cin>>n;
	m = n;
	cout<<n<<" "<<m<<endl;
	for(i = 0;i < 1547;i++){
		j = rand()%1293;
	}
	for(i = 0;i < n;i++){
		for(j = 0;j < m;j++){
			if(i == 0 && j == 0){
				cout<<1239812371<<" ";
				continue;
			}
			cout<<rand()%198984<<" ";
		}
		cout<<endl; 
	}
	
	return 0;
}

