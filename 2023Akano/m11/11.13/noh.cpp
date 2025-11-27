namespace AkanoCPP_h{
//include algorithm.h
namespace AkanoAlgorithm_h{
	#define TMPNT template<typename T>
	TMPNT T Min(const T& _valA,const T& _valB){
		if(_valA < _valB)return _valA;
		return _valB;
	}
	TMPNT T Max(const T& _valA,const T& _valB){
		if(_valA > _valB)return _valA;
		return _valB;
	}
	TMPNT using bfTpTp = bool(*)(T,T);
	
	namespace MergeSortSpace{
		TMPNT bool IsMin(T _valA,T _valB){//用于默认比较
			return _valA < _valB;
		}
		TMPNT void MergeSort(T* arr,int l,int r,T* extraArr,bfTpTp<T> cmp){
			if(l == r)return ;
			const int mid = (l + r) >> 1;
			MergeSort(arr,l,mid,extraArr,cmp),MergeSort(arr,mid+1,r,extraArr,cmp);
			int i = l,j = mid + 1,tail = l;
			while(i <= mid && j <= r){
				if(cmp(arr[i],arr[j])){
					extraArr[tail++] = arr[i++];
				}else{
					extraArr[tail++] = arr[j++];
				}
			}
			while(i <= mid){
				extraArr[tail++] = arr[i++];
			}
			while(j <= r){
				extraArr[tail++] = arr[j++];
			}
			for(int i = l;i <= r;i++){
				arr[i] = extraArr[i];
			}
			return ;
		}
	}
	
	TMPNT void Sort(T* st,T* ed,bfTpTp<T> cmp = MergeSortSpace::IsMin<T>){
		const int distance = ed - st;
		T* extraSpace = new T[distance+1];
		MergeSortSpace::MergeSort(st-1,1,distance,extraSpace,cmp);
		return ;
	}
	
	inline void MemoryCopy(void* destination,void* source,int size){
		char *_dest = (char*)(destination),*_sour = (char*)(source);
		for(int i = 0;i < size / int(sizeof(char));i++){
			*(_dest + i) = *(_sour + i);
		}
		return ;
	}
	inline void MemorySet(void* destination,unsigned char v,int size){
		char *_dest = (char*)(destination);
		for(int i = 0;i < size / int(sizeof(char));i++){
			*(_dest + i) = v;
		}
		return ;
	}
	TMPNT inline void Swap(T& a,T& b){
		T temp = a;
		a = b;
		b = temp;
		return ;
	}
}
using namespace AkanoAlgorithm_h;

//include Vector.h
namespace AkanoVector_h{
	template<typename T>
	class Vector{
	private:
		const static int Exsize = 2;
		T* content;
		void SetCapacity(int newSize){
			T* newContent = new T[newSize+1];
			MemoryCopy(newContent,content,sizeof(T) * Min((size+1),newSize));
			Swap(newContent,content);
			delete[] newContent;
			capacity = newSize;
			size = Min(size,capacity);
			return ;
		}
	public:
		int capacity,size;
		using iterator =  T*;
		inline iterator begin(){
			return &content[1];
		}
		inline iterator end(){
			return &content[size+1];
		}
		inline void PushBack(const T& newContent){
			if(size + 1 > capacity){
				SetCapacity(capacity * Exsize); 
			}
			content[++size] = newContent;
			return ;
		}
		inline void PopBack(){
			if(size >= 1)size--;
			return ;
		}
		inline bool Empty(){
			return (size == 0);
		}
		inline void Reserve(int newSize){
			if(newSize > capacity)SetCapacity(newSize);
			return ;
		}
		inline void Resize(int newSize){
			if(capacity < newSize)SetCapacity(newSize);
			size = newSize;
			return ;
		}
		inline void Clear(){
			size = 0;
			return ;
		}
		inline void Free(){
			SetCapacity(1);
			size = 0;
			return ;
		}
		T& operator[](int x){
			return content[x];
		}
		Vector(){
			content = new T[2];
			content[0] = T();
			capacity = 1,size = 0;
			return ;
		}
		Vector(int siz) : Vector(){
			Resize(siz);
			return ;
		}
	};
}
using namespace AkanoVector_h;

//include AkanoIO.h
namespace AkanoIO_h{
	class AkanoIO;
	AkanoIO& endl(AkanoIO& aio);
	class AkanoIO{
	private:
		#define TMPCT template<class T>
		using charp = char*;
		using ccp = const char*;
		using iofp = AkanoIO&(*)(AkanoIO&);
		
		TMPCT T Fabs(T x){
			if(x < 0)return -x;
			return x;
		}
		bool IsSplited(char ch){
			return (ch == ' ' || ch == '\n');
		}
		bool Isdigit(char ch){
			return ('0' <= ch && ch <= '9');
		}
		TMPCT void ReadInt(T& x){
			x = 0;
			int f = 1;
			char ch = Getchar();
			while(!Isdigit(ch)){
				if(ch == '-')f = -1;
				ch = Getchar();
			}
			while(Isdigit(ch)){
				x = x * 10 + ch - '0';
				ch = Getchar();
			}
			x *= f;
			return ;
		}
		TMPCT void WriteInt(T x){
			static int writeBuff[128];
			if(x < 0){
				Putchar('-');
				x = -x;
			}else if(x==0){
				Putchar('0');
			}
			int tail = 0;
			while(x){
				writeBuff[++tail] = x % 10;
				x /= 10;
			}
			while(tail){
				Putchar(writeBuff[tail--] + '0');
			}
			return ;
		}
		TMPCT void ReadFloat(T& ret){
			ret = 0;
			int f = 1;
			char ch = Getchar();
			while(!Isdigit(ch)){
				if(ch == '-')f = -1;
				ch = Getchar();
			}
			bool afterPoint = false;
			T now = 1;
			while(Isdigit(ch) || ch == '.'){
				if(ch == '.'){
					afterPoint = true;
				}else if(afterPoint == false){
					ret = ret * 10 + ch - '0';
				}else{
					now /= 10;
					ret += now * (ch - '0');
				}
				ch = Getchar();
			}
			ret *= f;
			return ;
		}
		TMPCT void WriteFloat(T x){
			const static double EPS = 1e-8;
			if(Fabs(x) <= EPS){
				Putchar('0');
				return ;
			}else if(x < 0){
				Putchar('-');
				x = -x;
			}
			T noww = 1;
			while(noww * 10 <= x)noww *= 10;
			while(noww >= 1){
				int cnt = x / noww;
				x -= cnt * noww;
				Putchar('0' + cnt);
				noww /= 10;
			}
			if(Fabs(x) <= EPS)return ;
			Putchar('.');
			T nowEPS = EPS;
			while(Fabs(x) > nowEPS){
				x *= 10;
				int res = int(x);
				x -= res % 10;
				nowEPS *= 10;
				Putchar('0' + res);
			}
			return ;
		}
		TMPCT void WriteCharp(const T& _cstr){
			ccp cstr = (ccp)_cstr;
			for(;*cstr;cstr++){
				Putchar(*cstr);
			}
			return ;
		}
		TMPCT void ReadChar(T& ch){
			ch = Getchar();
			while(IsSplited(ch) && !fail){
				ch = Getchar();
			}
			return ;
		}
		TMPCT void WriteChar(const T& charvar){
			Putchar(charvar);
			return ;
		}
		void Read(short& v){ReadInt(v);}
		void Read(int& v){ReadInt(v);}
		void Read(long long& v){ReadInt(v);}
		void Read(__int128& v){ReadInt(v);}
		void Read(float& v){ReadFloat(v);}
		void Read(double& v){ReadFloat(v);}
		void Read(char& v){ReadChar(v);}
		void Write(const short& v){WriteInt(v);}
		void Write(const int& v){WriteInt(v);}
		void Write(const long long& v){WriteInt(v);}
		void Write(const __int128& v){WriteInt(v);}
		void Write(const float& v){WriteFloat(v);}
		void Write(const double& v){WriteFloat(v);}
		void Write(const ccp& v){WriteCharp(v);}
		void Write(const char& v){WriteChar(v);}
		
		void FmtOutput(ccp format){
			for(;*format;format++){
				Putchar(*format);
			}
			return ;
		}
		template<typename FirstType,typename... ResType>
		void FmtOutput(ccp format,const FirstType& firstElement,const ResType&... res){
			for(;*format;format++){
				if(*format == '{' && *(format+1) == '}'){
					Write(firstElement);
					FmtOutput(format + 2,res...);
					return ;
				}
				Putchar(*format);
			}
			return ;
		}
	public:
		void Putchar(char ch){
			__builtin_putchar(ch);
			return ;
		}
		char Getchar(){
			char ch;
			__builtin_scanf("%c",&ch);
			return ch;
		}
		bool fail;
		TMPCT AkanoIO& operator>>(T& var){
			Read(var);
			return *this;
		}
		TMPCT AkanoIO& operator<<(const T& var){
			Write(var);
			return *this;
		}
		AkanoIO& operator<<(iofp func){
			return func(*this);
		}
		template<typename... ArgTypes>
		AkanoIO& operator()(ccp format,const ArgTypes&... args){
			FmtOutput(format,args...);
			return *this;
		}
		operator bool(){
			return not(fail);
		}
	};
	AkanoIO& endl(AkanoIO& aio){
		aio.Putchar('\n');
		return aio;
	}
}
using namespace AkanoIO_h;

namespace AkanoSTD{
	#define Akano 1
	#define pure__Elysia 0
	#define loves ^
	AkanoIO io;
}
}

using namespace AkanoCPP_h;
using namespace AkanoSTD;

constexpr int MAXN = 1e5 + 1018 + 1108;
int n;
Vector<int> vec;
int main(){
	io>>n;
	for(int i = 1,x;i <= n;i++){
		io>>x;
		vec.PushBack(x);
	}
	Sort(vec.begin(),vec.end());
	for(auto i : vec){
		io<<i<<" ";
	}
	io<<endl;
	return not(Akano loves pure__Elysia);
}
