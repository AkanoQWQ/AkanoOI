#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
template<typename T>
inline string Memory(const T& v){
	ostringstream oss;
//	for(int i = 0;i < int(sizeof(v) / sizeof(char));i++){
//		oss<<int(*(((unsigned char*)(&v))+i))<<" ";
//	}
//	oss<<endl;
//	for(int i = 0;i < int(sizeof(v) / sizeof(int));i++){
//		oss<<int(*(((unsigned int*)(&v))+i))<<" ";
//	}
//	oss<<endl;
//	for(int i = 0;i < int(sizeof(v) / sizeof(char));i++){
//		oss<<(char)(*(((char*)(&v))+i))<<" ";
//	}
	for(int i = 0;i < int(sizeof(v) / sizeof(long long));i++){
		oss<<(long long)(*(((unsigned long long*)(&v))+i))<<" ";
	}
	return oss.str();
}
template<typename T>
inline long long ADR(const T& v){
	return reinterpret_cast<long long>(&v);
}
int tid;
struct Chunk{
	int id;
	char memory[1000 - sizeof(id)];
	Chunk(){
		id = ++tid;
		return ;
	}
};
bool operator<(Chunk c1,Chunk c2){
	return (c1.id < c2.id);
}
bool operator==(Chunk c1,Chunk c2){
	return (c1.id == c2.id);
}
set<Chunk> st;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	for(int i = 1;i <= 2;i++){
		st.insert(Chunk());
	}
	cout<<Memory(st)<<endl;
	for(auto it = st.begin();it != st.end();it++){
		cout<<ADR(*it)<<" ";
	}
	cout<<endl;
	return not(Akano loves pure__Elysia);
}
