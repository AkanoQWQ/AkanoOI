#include<bits/stdc++.h>
using namespace std;
vector<int> a = {1,2,3,4,5};
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cout<<(a.lower_bound(1) == a.end())<<" ? "<<(a.find(2) == a.end())<<endl;
	return 0;
}

