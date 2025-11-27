#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;

template<typename valueT>
class SetBasic{
private:
	valueT val;
public:
	inline bool Include(int _val){
		return (val & (valueT(1)<<(_val-1)));
	}
	inline bool Include(SetBasic oth){
		return ((val & oth.val) == oth.val);
	}
	inline bool In(SetBasic oth){
		return oth.Include(*this);
	}
	inline void Flip(int _val){
		val ^= (valueT(1)<<(_val-1));
		return ;
	}
	inline void Insert(int _val){
		val |= (valueT(1)<<(_val-1));
		return ;
	}
	inline void Erase(int _val){
		if(not(Include(_val)))return ;
		return Flip(_val);
	}
	operator valueT(){
		return val;
	}
	SetBasic& operator=(valueT _val){
		val = _val;
		return *this;
	}
	SetBasic& operator=(const char* str){
		val = 0;
		for(;*str;str++){
			val = (val << 1) + ((*str) - '0');
		}
		return *this;
	}
	SetBasic& operator=(const string& str){
		return operator=(str.c_str());
	}
	SetBasic& operator++(){
		val++;
		return *this;
	}
	SetBasic operator++(int){
		SetBasic ret = *this;
		operator++();
		return ret;
	}
	SetBasic& operator--(){
		val--;
		return *this;
	}
	SetBasic operator--(int){
		SetBasic ret = *this;
		operator--();
		return ret;
	}
	SetBasic(){
		val = 0;
		return ;
	}
	template<typename T>
	SetBasic(T _val){
		operator=(_val);
		return ;
	}
};
//Set32/Set64/Set128 可能导致无符号整形下溢,谨慎使用
using Set32 = SetBasic<unsigned int>;
using Set64 = SetBasic<unsigned long long>;
using Set128 = SetBasic<unsigned __int128>;
using Set31 = SetBasic<int>;
using Set63 = SetBasic<long long>;
using Set127 = SetBasic<__int128>;
using Set = Set31;

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	Set32 it;
	it--;
	return not(Akano loves pure__Elysia);
}
