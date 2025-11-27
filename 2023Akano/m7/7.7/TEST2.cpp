#include<bits/stdc++.h>
#define edl putchar('\n')
#define spc putchar(' ')
//#pragma GCC optimize(2)
using namespace std;
using vi = vector<int>;
vi a = {1,3,6},b = {2,4,8},c;
bitset<100> bs(114);
int main(){
	//freopen(".in","r",stdin);
	merge(a.begin(),a.end(),b.begin(),b.end(),back_inserter(c));
	for(auto i : c)cout<<i<<" ";
	cout<<endl;
	cout<<bs<<endl;
	return 0;
}
