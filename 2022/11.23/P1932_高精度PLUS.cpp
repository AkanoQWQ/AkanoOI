#include<bits/stdc++.h>
using namespace std;
const int MAXN = 22006;
int maxlen;
struct num{
	int c[MAXN],len;
	void upp(){
		for(int i = 0;i < maxlen-1;i++){
			c[i+1] += c[i] / 10;
			c[i] %= 10;
		}
		return ;
	}
	int getlen(){
		upp();
		for(int i = maxlen-1;i >= 0;i--){
			if(c[i] != 0)return i;
		}
		return 0;
	}
	void INIT(string str){
		memset(c,0,sizeof(c));
		for(int i = int(str.length()) - 1,j = 0;i >= 0;i--,j++){
			c[j] = str[i] - '0';
		}
		len = str.length() - 1;
		return ;
	}
	void output(){
		len = getlen();
		for(int i = len;i >= 0;i--){
			putchar('0' + c[i]);
		}
		return ;
	}
	num times_ten(){
		num ret;
		ret.INIT("0");
		for(int i = maxlen-2;i > 0;i--){
			ret.c[i] = c[i-1];
		}
		ret.c[0] = 0;
		return ret;
	}
	void it_times(){
		len = getlen();
		for(int i = len+1;i > 0;i--){
			c[i] = c[i-1];
		}
		c[0] = 0;
		len++;
		return ;
	}
	num divide_ten(){
		num ret;
		ret.INIT("0");
		for(int i = 0;i < maxlen-1;i++){
			ret.c[i] = c[i+1];
		}
		return ret;
	}
	void it_divide(){
		len = getlen();
		for(int i = 0;i < len;i++){
			c[i] = c[i+1];
		}
		c[len] = 0;
		len--;
		return ;
	}
}zero,ny;
num operator+(num& a,num& b){
	num ret = zero;
	a.len = a.getlen();
	b.len = b.getlen();
	for(int i = 0;i <= max(a.len,b.len);i++){
		ret.c[i] += a.c[i] + b.c[i];
		ret.c[i+1] += ret.c[i] / 10;
		ret.c[i] %= 10;
	}
	return ret;
}
num operator*(num& a,num& b){
	num ret = zero;
	a.len = a.getlen(),b.len =b.getlen();
	for(int i = 0;i <= a.len;i++){
		for(int j = 0;j <= b.len;j++){
			ret.c[i+j] += a.c[i] * b.c[j];
			ret.c[i+j+1] += ret.c[i+j] / 10;
			ret.c[i+j] %= 10;
		}
	}
	ret.len = ret.getlen();
	return ret; 
}
bool operator==(num& a,num& b){
	a.len = a.getlen(),b.len = b.getlen();
	if(a.len != b.len)return 0;
	for(int i = 0;i <= a.len;i++){
		if(a.c[i] != b.c[i])return 0;
	}
	return 1;
}
bool operator!=(num& a,num& b){
	return !(a == b);
}
bool operator<(num& a,num& b){
	a.len = a.getlen(),b.len = b.getlen();
	if(a.len != b.len)return a.len < b.len;
	for(int i = a.len;i >= 0;i--){
		if(a.c[i] != b.c[i])return a.c[i] < b.c[i];
	}
	return 0;
}
bool operator<=(num a,num b){
	a.len = a.getlen(),b.len = b.getlen();
	if(a.len != b.len)return a.len < b.len;
	for(int i = a.len;i >= 0;i--){
		if(a.c[i] != b.c[i])return a.c[i] < b.c[i];
	}
	return 1;
}
bool operator>(num& a,num& b){
	a.len = a.getlen(),b.len = b.getlen();
	if(a.len != b.len)return a.len > b.len;
	for(int i = a.len;i >= 0;i--){
		if(a.c[i] != b.c[i])return a.c[i] > b.c[i];
	}
	return 0;
}
bool operator>=(num& a,num& b){
	a.len = a.getlen(),b.len = b.getlen();
	if(a.len != b.len)return a.len > b.len;
	for(int i = a.len;i >= 0;i--){
		if(a.c[i] != b.c[i])return a.c[i] > b.c[i];
	}
	return 1;
}
num operator-(num& a,num& b){
	num ret = zero;
	a.len = a.getlen(),b.len = b.getlen();
	for(int i = 0;i <= max(a.len,b.len);i++){
		ret.c[i] += a.c[i] - b.c[i];
		while(ret.c[i] < 0){
			ret.c[i] += 10;
			ret.c[i+1]--;
		}
	}
	ret.len = ret.getlen(); 
	return ret;
}
num operator/(num a,num b){
	num ret = zero,orgb = b,cache;
	cache.INIT("1");
	b.len = b.getlen();
	if(b.len == 0)return a;
	while(b.times_ten() <= a){
		b.it_times();
		cache.it_times();
	}
	while(a >= orgb){
		while(b > a){
			b.it_divide();
			cache.it_divide();
		}
		while(a >= b){
			a = a - b;
			ret = ret + cache;
		}
	}
	ny = a;
	return ret;
}
string a,b;
int main(){
//	freopen("P1932.in","r",stdin);
//	freopen("gj.out","w",stdout);
	num na,nb;
	cin>>a>>b;
	na.INIT(a);
	nb.INIT(b);
	maxlen = (a.length() + b.length() + 15);
	num n_plus = na + nb;
	n_plus.output(),putchar('\n');
	if(na >= nb){
		num n_cha = na - nb;
		n_cha.output(),putchar('\n');
	}else{
		num n_cha = nb - na;
		putchar('-'),n_cha.output(),putchar('\n');
	}
	num nt = na * nb;
	nt.output(),putchar('\n');
	num nd = na / nb;
	nd.output(),putchar('\n');
	ny.output();
	return 0;
}
