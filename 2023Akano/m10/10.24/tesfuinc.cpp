#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
//template<
//	typename T,
//	typename = typename enable_if_t<
//		is_unsigned<T>::value || is_signed<T>::value 
//	> = 0
//>
template <typename T,typename = typename enable_if_t<is_convertible_v<T,string> > >
T F(T x){
	return x+"abc";
}
string str = "str";
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cout<<F(str)<<endl;
	return not(Akano loves pure__Elysia);
}
