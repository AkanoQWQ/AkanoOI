#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 1e5 + 1018 + 1108;

class FastIO{
private:
	const static int buffSize = 1<<23;
	using charp = char*;
	using ccp = const char*;
	using FILEp = FILE*;
	typedef ostream& (*ostreamFunc)(ostream&);
	FILEp inFile,outFile;
	char inputBuff[buffSize +2],outputBuff[buffSize + 2];
	charp inputPtr = inputBuff,inputEnd = inputPtr;
	charp outputPtr = outputBuff,outputEnd = outputBuff + buffSize;
	inline bool IsSplited(char ch){
		return (ch == ' ' || ch == '\n');
	}
	template <typename T>
	void ReadInt(T &x){
		x = 0;
		char ch = FastGetChar();
		int f = 1;
		while(!isdigit(ch) && !fail){
			if(ch == '-')f = -1;
			ch = FastGetChar();
		}
		while(isdigit(ch)  && !fail){
			x = (x * 10) + (ch ^ 48);
			ch = FastGetChar();
		}
		x *= f;
		return ;
	}
	template <typename T>
	void WriteInt(T x){
		static int writeBuff[128];
		if(x < 0){
			FastPutChar('-');
			x = -x;
		}else if(x==0){
			FastPutChar('0');
		}
		int tail = 0;
		while(x){
			writeBuff[++tail] = x % 10;
			x /= 10;
		}
		while(tail){
			FastPutChar(writeBuff[tail--] + '0');
		}
		return ;
	}
	inline void ReadString(string& str){
		str = "";
		char ch = FastGetChar();
		while(!IsSplited(ch) && !fail){
			str += ch;
			ch = FastGetChar();
		}
		return ;
	}
	inline void WriteString(const string& str){
		for(auto i : str){
			FastPutChar(i);
		}
		return ;
	}
	inline void FmtOutput(ccp format){
		for(;*format;format++){
			FastPutChar(*format);
		}
		return ;
	}
	template<typename FirstType,typename... ResType>
	inline void FmtOutput(ccp format,const FirstType& firstElement,const ResType&... res){
		for(;*format;format++){
			if(*format == '{' && *(format+1) == '}'){
				operator<<(firstElement);
				FmtOutput(format + 2,res...);
				return ;
			}
			FastPutChar(*format);
		}
		return ;
	}
	template<typename T>
	inline void ReadFloat(T& ret){
		ret = 0;
		int f = 1;
		char ch = FastGetChar();
		while(!isdigit(ch)){
			if(ch == '-')f = -1;
			ch = FastGetChar();
		}
		bool afterPoint = false;
		T now = 1;
		while(isdigit(ch) || ch == '.'){
			if(ch == '.'){
				afterPoint = true;
			}else if(afterPoint == false){
				ret = ret * 10 + ch - '0';
			}else{
				now /= 10;
				ret += now * (ch - '0');
			}
			ch = FastGetChar();
		}
		ret *= f;
		return ;
	}
	template<typename T>
	inline void WriteFloat(T x){
		const static double EPS = 1e-8;
		if(fabs(x) <= EPS){
			FastPutChar('0');
			return ;
		}else if(x < 0){
			FastPutChar('-');
			x = -x;
		}
		T noww = 1;
		while(noww * 10 <= x)noww *= 10;
		while(noww >= 1){
			int cnt = x / noww;
			x -= cnt * noww;
			FastPutChar('0' + cnt);
			noww /= 10;
		}
		if(fabs(x) <= EPS)return ;
		FastPutChar('.');
		T nowEPS = EPS;
		while(fabs(x) > nowEPS){
			x *= 10;
			int res = int(x);
			x -= res % 10;
			nowEPS *= 10;
			FastPutChar('0' + res);
		}
		return ;
	}
public:
	bool fail;
	inline char FastGetChar(){
		if(inputPtr == inputEnd){
			size_t res = fread(inputBuff,1,buffSize,inFile);
			inputEnd = inputBuff + res;//为什么其他地方不改inputEnd呢
			if(res == 0){
				fail = true;
				inputPtr = inputBuff;
				return EOF;
			}
			inputPtr = inputBuff;
		}
		return *(inputPtr++);
	}
	inline void FastPutChar(char ch){
		if(outputPtr == outputEnd){
			Flush();
		}
		*(outputPtr++) = ch;
		return ;
	}
	inline void Flush(){
		fwrite(outputBuff,1,outputPtr - outputBuff,outFile);
		outputPtr = outputBuff;
		return ;
	}
	inline void Endl(){
		FastPutChar('\n');
		return ;
	}
	FastIO& operator>>(short& integerVar){
		ReadInt(integerVar);
		return *this;
	}
	FastIO& operator>>(int& integerVar){
		ReadInt(integerVar);
		return *this;
	}
	FastIO& operator>>(long& integerVar){
		ReadInt(integerVar);
		return *this;
	}
	FastIO& operator>>(long long& integerVar){
		ReadInt(integerVar);
		return *this;
	}
	FastIO& operator>>(__int128& integerVar){
		ReadInt(integerVar);
		return *this;
	}
	FastIO& operator>>(float& floatVar){
		ReadFloat(floatVar);
		return *this;
	}
	FastIO& operator>>(double& floatVar){
		ReadFloat(floatVar);
		return *this;
	}
	FastIO& operator>>(string& stringVar){
		ReadString(stringVar);
		return *this;
	}
	FastIO& operator>>(char& charVar){
		charVar = FastGetChar();
		while(IsSplited(charVar))charVar = FastGetChar();
		return *this;
	}
	FastIO& operator<<(short integerVar){
		WriteInt(integerVar);
		return *this;
	}
	FastIO& operator<<(int integerVar){
		WriteInt(integerVar);
		return *this;
	}
	FastIO& operator<<(long integerVar){
		WriteInt(integerVar);
		return *this;
	}
	FastIO& operator<<(long long integerVar){
		WriteInt(integerVar);
		return *this;
	}
	FastIO& operator<<(__int128 integerVar){
		WriteInt(integerVar);
		return *this;
	}
	FastIO& operator<<(string stringVar){
		WriteString(stringVar);
		return *this;
	}
	FastIO& operator<<(char charVar){
		FastPutChar(charVar);
		return *this;
	}
	FastIO& operator<<(float floatVar){
		WriteFloat(floatVar);
		return *this;
	}
	FastIO& operator<<(double floatVar){
		WriteFloat(floatVar);
		return *this;
	}
	FastIO& operator<<(ostreamFunc func){
		ostringstream oss;
		oss<<func;
		string str = oss.str();
		for(auto i : str){
			FastPutChar(i);
		}
		Flush();
		return *this;
	}
	template<typename... ArgTypes>
	FastIO& operator()(ccp format,const ArgTypes&... args){
		FmtOutput(format,args...);
		return *this;
	}
	operator bool(){
		return not(fail);
	}
	FastIO(){
		inFile = stdin,outFile = stdout;
		return ;
	}
	FastIO(FILEp _inFile,FILEp _outFile){
		inFile = _inFile,outFile = _outFile;
		return ;
	}
	~FastIO(){
		Flush();
		return ;
	}
};
FastIO fio(stdin,stdout),ferr(nullptr,stderr);

int n,len,endPos;
char cmd[MAXN];
int t[MAXN];
vector<int> rk;
int maxdeltaTime,maxPos;
class SegmentTree{
private:
	struct Node{
		int delta,mn,mx;
		Node(){
			delta = 0,mn = 0,mx = len;
			return ;
		}
		inline int Ask(int x){
			return max(mn,min(mx,x + delta));
		}
	}node[MAXN * 4];
	inline void Build(int p,int l,int r){
		node[p] = Node();
		if(l == r)return ;
		const int mid = (l + r) >> 1;
		Build(p*2,l,mid),Build(p*2+1,mid+1,r);
		return ;
	}
	inline void PushUp(int p){
		node[p].delta = node[p*2].delta + node[p*2+1].delta;
		node[p].mn = max(node[p*2+1].mn,min(node[p*2].mn + node[p*2+1].delta,node[p*2+1].mx));
		node[p].mx = min(node[p*2+1].mx,max(node[p*2].mx + node[p*2+1].delta,node[p*2+1].mn));
		return ;
	}
	void Change(int p,int l,int r,int pos){
		if(l == r){
			if(cmd[pos] == '+'){
				node[p].delta = 1,node[p].mn = 1,node[p].mx = len;
			}else{
				node[p].delta = -1,node[p].mn = 0,node[p].mx = len - 1;
			}
			return ;
		}
		const int mid = (l + r) >> 1;
		if(mid >= pos)Change(p*2,l,mid,pos);
		if(mid < pos)Change(p*2+1,mid+1,r,pos);
		PushUp(p);
		return ;
	}
public:
	inline void Change(int pos){
		assert(pos != 1);
		if(pos == -1)return ;
		Change(1,1,n,pos);
		return ;
	}
	inline Node GetRoot(){
		return node[1];
	}
	inline void Build(){
		Build(1,1,n);
		return ;
	}
}tr;
inline int DeltaT(int x){
	if(x == -1)return -10181108;
	return t[x] - t[x-1];
}
bool Cmp(int x,int y){
	return DeltaT(x) < DeltaT(y);
}
int main(){
	fio>>n>>len>>endPos;
	tr.Build();
	rk.push_back(-1);
	for(int i = 1;i <= n;i++){
		fio>>cmd[i]>>t[i];
		if(i != 1)rk.push_back(i);
	}
	sort(rk.begin() + 1,rk.end(),Cmp);
	for(int nowtime = 0;nowtime < n;nowtime++){
		tr.Change(rk[nowtime]);
		while(nowtime + 1 < n && DeltaT(rk[nowtime+1]) == DeltaT(rk[nowtime])){
			nowtime++;
			tr.Change(rk[nowtime]);
		}
		auto it = tr.GetRoot();
		if(it.Ask(0) <= endPos && it.Ask(len) >= endPos){
			maxdeltaTime = nowtime;
			int l = 0,r = len + 1;
			while(l < r){
				const int mid = (l + r) >> 1;
				if(it.Ask(mid) <= endPos){
					l = mid + 1;
				}else{
					r = mid;
				}
			}
			maxPos = l - 1;
		}
	}
	if(maxdeltaTime == n-1){
		fio<<"infinity"<<endl;
	}else{
		fio<<DeltaT(rk[maxdeltaTime+1]) - 1<<" "<<maxPos<<endl;
	}
//	ferr("time used : {} ms\n",1e3 * clock() / CLOCKS_PER_SEC);
	return not(Akano loves pure__Elysia);
}
