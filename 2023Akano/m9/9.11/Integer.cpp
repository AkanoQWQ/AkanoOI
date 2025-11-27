#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;

struct Integer{
	const static int MAXW = 128;//10^128 位的Integer,加减复杂度 128,乘法复杂度128^2
	bool f;
	int c[MAXW + 2];
	inline void Carry(){
		for(int i = 1;i <= MAXW;i++){
			c[i+1] += c[i] / 10;
			c[i] %= 10;
		}
		return ;
	}
	inline void Borrow(){
		for(int i = 1;i <= MAXW;i++){
			if(c[i] < 0){
				int borrow = ceil((-c[i]) / 10.0f);
				c[i+1] -= borrow;
				c[i] += borrow * 10;
			}
		}
		return ;
	}
	inline int GetW(){
		return MAXW;
	}
	Integer& operator=(const Integer& other){
		if(this == &other)return *this;//防止自赋值
		for(int i = MAXW;i >= 1;i--){
			c[i] = other.c[i];
		}
		f = other.f;
		return *this;
	}
	Integer& operator=(const string& str){
		int len = str.length();
		if(str[0] == '-'){
			f = true;
		}else{
			f = false;
		}
		int now = 0;
		for(int i = len-1;i >= 0;i--){
			if(!isdigit(str[i]))continue;
			c[++now] = str[i] - '0';
		}
		for(int i = now+1;i <= MAXW;i++)c[i] = 0;//重要清空 
		return *this;
	}
	template<typename integerT>//整形变量 
	Integer& operator=(integerT other){//要变号,不常值引用了 
		if(other < 0){
			f = true;
		}else{
			f = false;
		}
		for(int i = MAXW;i >= 1;i--)c[i] = 0;//先清空 
		for(int i = 1;other != 0;i++){
			c[i] = other % 10;
			other /= 10;
		}
		return *this;
	}
	Integer(){
		memset(c,0,sizeof(c));
		f = false;
		return ;
	}
};
Integer abs(Integer bigint){
	bigint.f = false;
	return bigint;//要修改不常值引用了 
}
bool operator<(const Integer& i1,const Integer& i2){
	if(i1.f != i2.f){
		return i1.f;
	}
	bool ret = false;
	for(int i = Integer::MAXW;i >= 1;i--){
		if(i1.c[i] < i2.c[i]){
			ret = true;
			break;
		}
		if(i1.c[i] > i2.c[i]){
			ret = false;
			break;
		}
	}
	if(i1.f == true && i2.f == true){
		ret = !ret;
	}
	return ret;
}
bool operator>(const Integer& i1,const Integer& i2){
	return i2 < i1;
}
bool operator==(const Integer& i1,const Integer& i2){
	return !(i1 > i2 || i1 < i2);
}
bool operator!=(const Integer& i1,const Integer& i2){
	return !(i1 == i2);
}
inline void Decrease(Integer& ret,const Integer& i1,const Integer& i2){
	for(int i = 1;i <= Integer::MAXW;i++){
		ret.c[i] = i1.c[i] - i2.c[i];
	}
	return ;
}
Integer operator-(const Integer& i1,const Integer& i2){
	Integer ret;
	if(i1 < i2){
		ret.f = true;
	}else{
		ret.f = false;
	}
	if(abs(i1) > abs(i2)){
		Decrease(ret,i1,i2);
	}else{
		Decrease(ret,i2,i1);
	}
	ret.Borrow();
	return ret;
}
Integer operator+(const Integer& i1,const Integer& i2){
	Integer ret;
	if(i1.f == i2.f){
		ret.f = i1.f;
		for(int i = 1;i <= Integer::MAXW;i++){
			ret.c[i] = i1.c[i] + i2.c[i];
		}
		ret.Carry();
	}else{
		if(i1.f){
			ret = i2 - i1;
		}else{
			ret = i1 - i2;
		}
	}
	return ret;
}
istream& operator>>(istream& is,Integer& bigint){
	string str;
	is>>str;
	bigint = str;
	return is;
}
ostream& operator<<(ostream& os,const Integer& bigint){
	string str;
	if(bigint.f)os<<'-';
	bool otp = false;
	for(int i = Integer::MAXW;i >= 1;i--){
		otp |= (bigint.c[i] != 0);
		if(otp)os<<bigint.c[i];
	}
	if(otp == false)os<<0;
	return os;
}
Integer a,b;
char ch;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	while(cin>>ch>>a>>b){
		if(ch == '+'){
			cout<<a+b<<endl;
		}else if(ch == '-'){
			cout<<a-b<<endl;
		}
	}
	return not(Akano loves pure__Elysia);
}

