#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,pos;
string A[56],Z[10006],llist[56];
int nums[56],mb;
string botle[12301];
bool found;
int main(){
	freopen("pjesma.in","r",stdin);
	freopen("pjesma.out","w",stdout);
	cin>>n;
	mb = (n+1) / 2;
	for(i = 0;i < n;i++){
		cin>>A[i];
		found = 0;
		for(j = 0;j < pos;j++){
			if(A[i] == llist[j]){
				nums[j]++;
				found = 1;
				break;
			}
		}
		if(found == 0){
			llist[pos] = A[i];
			nums[pos] = 1;
			pos++;
		}
	}
	//for(i = 0;i < pos;i++){
	//	cout<<llist[i]<<":"<<nums[i]<<",";
	//}
	cin>>m;
	for(i = 0;i < m;i++){
		cin>>Z[i];
		for(j = 0;j < pos;j++){
			if(Z[i] == llist[j] && nums[j] > 0){
				mb--;
				nums[j]--;
				break;
			}
		}
		if(mb <= 0){
			cout<<i+1;
			return 0;
		}
	}
	return 0;
}

