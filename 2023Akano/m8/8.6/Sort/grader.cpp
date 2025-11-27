#include<bits/stdc++.h>
#include "sort.h"
using namespace std;
namespace GRD{
	const int MAXN = 1e5 + 1018;
	int arr[MAXN],n;
	inline int Read(){
		cin>>n;
		for(int i = 1;i <= n;i++){
			cin>>arr[i];
		}
		return n;
	}
	inline void Output(){
		for(int i = 1;i <= n;i++){
			cout<<arr[i]<<" ";	
		}
		cout<<endl;
		return ;
	}
}
void Read(int arr[],int l,int r,int st){
	int cnt = st;
	for(int i = l;i <= r;i++){
		arr[cnt++] = GRD::arr[i];
	}
	return ;
}
void Write(int arr[],int l,int r,int st){
	int cnt = st;
	for(int i = l;i <= r;i++){
		GRD::arr[i] = arr[cnt++];
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	GRD::Read();
	int block = GRD::n / 4;
	int* operation_array = new int[block+1];
	for(int i = 1;i <= block;i++)operation_array[i] = 0;
	Sort(operation_array,GRD::n);
	GRD::Output();
	return 0;
}
