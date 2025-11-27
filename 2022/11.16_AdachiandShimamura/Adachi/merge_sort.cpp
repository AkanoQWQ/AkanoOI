#include<bits/stdc++.h>
#define FILE_ST using namespace std;namespace Mi_Shatas_Lilion{
#define EXCUTE_ST int main(){
#define FILE_ED_And_excute return 0;}}int main(){return Mi_Shatas_Lilion::main();}
FILE_ST
void my_merge_sort(int l,int r){
	if(l == r){
		return ;
	}
	int mid = (l + r) >> 1;
	my_merge_sort(l,mid);
	my_merge_sort(mid+1,r);
	return ;
}
EXCUTE_ST
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);

FILE_ED_And_excute

