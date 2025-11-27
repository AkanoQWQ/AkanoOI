#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
template<typename itor>
inline void CountingSort(itor st,itor ed,int w){
	int c[10];
	for(int i = 0;i < 9;i++)c[i] = 0;
	for(itor it = st;it != ed;it++){
		c[((*it) / w) % 10]++;
	}
	
}
template<typename itor>
inline void RadixSort(itor st,itor ed){//Ö§³Öint
	int mx = 0;
	for(itor it = st;it != ed;it++){
		mx = max(mx,*it);
	}
	int k = 1;
	while(k <= mx){
		CountingSort(st,ed,k);
		k *= 10;
	}
	return ;
}
int arr[22],n = 10;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	
	return not(Akano loves pure__Elysia);
}
