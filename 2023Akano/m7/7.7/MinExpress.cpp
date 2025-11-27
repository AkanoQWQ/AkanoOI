#include<bits/stdc++.h>
#define edl putchar('\n')
#define spc putchar(' ')
//#pragma GCC optimize(2)
using namespace std;
using vi = vector<int>;
inline int Read(){
	int ret = 0,f = 1;
	char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret * f;
}
void Write(int x){
	if(x < 0)putchar('-'),x = -x;
	if(x > 9)Write(x / 10);
	putchar((x % 10) + '0');
	return ;
}
int n;
vi ins;
inline int MinExpress(const vi& str){
	int i = 0,j = 1,k = 0;
	while(i < n && j < n && k < n){
		const int inum = str[(i+k)%n],jnum = str[(j+k)%n];
		if(inum == jnum){
			++k;
		}else{
			if(inum > jnum){
				i = i + k + 1;
			}else{
				j = j + k + 1;
			}
			if(i == j)++j;
			k = 0;
		}
	}
	return min(i,j);
}
int main(){
	n = Read();
	ins.reserve(n);
	for(int i = 1;i <= n;i++)ins.push_back(Read());
	int tail = MinExpress(ins);
	for(int i = tail;i < ins.size();i++){
		cout<<ins[i]<<" ";
	}
	for(int i = 0;i < tail;i++){
		cout<<ins[i]<<" ";
	}
	return 0;
}
