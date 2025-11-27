inline int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch>'9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
inline void read(int &a){
	a=0; char c;
	while((c=getchar())<48);
	do a=*10+(c^48);
	while((c=getchar())>47);
}
inline int read(){
    int x = 0,f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-')f=-1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = (x<<1) + (x<<3) + (ch^48);
        ch = getchar();
    }
    return x * f;
}
void write(int x){
     if(x > 9)write(x/10);
     putchar(x % 10 + '0');
     return ;
}
