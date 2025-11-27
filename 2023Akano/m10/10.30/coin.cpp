#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
const int MAXN = 1e6 + 1018 + 1108;

class FastIO{//1.2
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

template<typename T,typename container = vector<T>,typename Cmper = less<T> >
class DeleteablePriority_queue{
private:
	priority_queue<T,container,Cmper> pq,del;
	inline void Check(){
		while(!del.empty() && !pq.empty() && pq.top() == del.top()){
			pq.pop(),del.pop();
		}
		return ;
	}
public:
	inline bool Empty(){
		Check();
		return pq.empty();
	}
	inline T Top(){
		Check();
		return pq.top();
	}
	inline T DelTop(){
		Check();
		if(del.empty())return T();
		return del.top();
	}
	inline void Push(const T& newElement){
		pq.push(newElement);
		return ;
	}
	inline void Delete(const T& delElement){
		del.push(delElement);
		return ;
	}
	inline int Size(){
		Check();
		return pq.size();
	}
	inline void Clear(){
		while(!pq.empty())pq.pop();
		while(!del.empty())del.pop();
		return ;
	}
};

ll n,m,now[MAXN],a[MAXN],b[MAXN],ans[MAXN],otp;
struct Node{
	ll fir,sec,id;
};
bool operator==(const Node& node1,const Node& node2){
	return node1.fir == node2.fir && node1.sec == node2.sec && node1.id == node2.id;
}
class NodeCmper{
public:
	bool operator()(const Node& node1,const Node& node2)const{
		if(node1.fir != node2.fir)return node1.fir < node2.fir;
		if(node1.sec != node2.sec)return node1.sec < node2.sec;
		return node1.id < node2.id;
	}
};
DeleteablePriority_queue<Node,vector<Node>,NodeCmper> now1,now2;
inline void Repush(int id){
	if(now[id] == 1){
		now1.Push({a[id],b[id],id});
		now2.Push({a[id]+b[id],a[id],id});
	}
	if(now[id] == 2){
		now1.Push({b[id],a[id],id});
		now2.Push({b[id]+a[id],-1,id});
	}
	if(now[id] == 3){
		now1.Push({a[id],-1,id});
	}
	return ;
}
inline void DeleteVal(int id){
	if(now[id] == 1){
		now1.Delete({a[id],b[id],id});
		now2.Delete({a[id]+b[id],a[id],id});
	}
	if(now[id] == 2){
		now1.Delete({b[id],a[id],id});
		now2.Delete({b[id]+a[id],-1,id});
	}
	if(now[id] == 3){
		now1.Delete({a[id],-1,id});
	}
	return ;
}
inline void Solve(int st){
	now1.Clear(),now2.Clear();
	for(int i = 1;i <= n;i++){
		now[i] = 1;
		Repush(i);
	}
	if(st == 1){
		Node tp = now1.Top();
		DeleteVal(tp.id);
		now[tp.id]++;
		Repush(tp.id);
		ans[st] = tp.fir;
		st += 2;
	}
	for(int i = st;i <= m;i += 2){
		ll delta1 = -1,delta2 = -1;
		Node tp1,tp2,tp3;
		if(now1.Size() >= 2){
			tp1 = now1.Top();
			now1.Delete(tp1);
			tp2 = now1.Top();
			now1.Push(tp1);
			delta1 = tp1.fir + tp2.fir;
		}
		if(!now2.Empty()){
			tp3 = now2.Top();
			delta2 = tp3.fir;
		}
		if(delta1 == -1 && delta2 == -1){
			ans[i] = ans[i-2];
		}else if(delta1 >= delta2){
			ans[i] = ans[i-2] + delta1;
			DeleteVal(tp1.id),DeleteVal(tp2.id);
			now[tp1.id]++,now[tp2.id]++;
			Repush(tp1.id),Repush(tp2.id);
		}else{
			ans[i] = ans[i-2] + delta2;
			DeleteVal(tp3.id);
			now[tp3.id] += 2;
			Repush(tp3.id);
		}
	}
	return ;
}

int main(){
	freopen("coin.in","r",stdin);
	freopen("coin.out","w",stdout);
	fio>>n>>m;
	for(int i = 1;i <= n;i++){
		fio>>a[i];
	}
	for(int i = 1;i <= n;i++){
		fio>>b[i];
	}
	Solve(1),Solve(2);
	for(int i = 1;i <= m;i++){
		otp ^= ans[i];
//		ferr<<i<<" : "<<ans[i]<<endl;
	}
	fio<<otp<<endl;
	return not(Akano loves pure__Elysia);
}
