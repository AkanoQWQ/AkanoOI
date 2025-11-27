#include<bits/stdc++.h>
using namespace std;
set<int> st;
using setit = _Rb_tree_const_iterator<int>;
setit operator+(setit it,int num){
	for(int i = 1;i <= num;i++)it++;
	return it;
}
setit operator-(setit it,int num){
	for(int i = 1;i <= num;i++)it--;
	return it;
}
int main(){
	for(int i = 1;i <= 10;i++){
		st.insert(i);
	}
	auto it = st.begin();
	for(int i = 1;i <= 10;i++){
		cout<<*(it+(i-1))<<" ";
	}
	return 0;
}
