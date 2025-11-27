#include<bits/stdc++.h>
#include<AL/main.h>
using namespace std;
const int MAXN = 1e6;
bool _ST_;
int arr[MAXN];
char ch[MAXN];
long long larr[MAXN];
bool _ED_;

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cout<<(sizeof(arr) + sizeof(ch) + sizeof(larr)) / 1000 / 1000<<endl;
	cout<<((&_ST_ - &_ED_) / 1000 / 1000)<<endl;
	cout<<GetMemory(&_ST_,&_ED_);
	return 0;
}
