#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ull = unsigned long long;
string fileName;
char ch;
ull val;
inline ull XorHash(ull x){
	x ^= x << 7;
	x ^= x >> 11;
	x ^= x << 13;
	x ^= x >> 23;
	return x;
}
inline string ull2str(ull x){
	const static int LEN = 11;
	string ret;
	for(int i = 1;i <= LEN;i++){
		int now = x % 62;
		x /= 62;
		if(now <= 9){
			ret += '0' + now;
		}else if(now <= 35){
			ret += 'a' + (now - 10);
		}else if(now < 62){
			ret += 'A' + (now - 36);
		}
	}
	return ret;
}
int main(){
	cout<<"请输入文件名:";
	cin>>fileName;
	ifstream fin(fileName.c_str(),ios::binary);
	while(fin>>ch){
		val = XorHash(val);
		val = val * 257 + int(ch);
	}
	cout<<"哈希值为:"<<ull2str(val)<<endl;
	system("pause");
	return not(Akano loves pure__Elysia);
}
