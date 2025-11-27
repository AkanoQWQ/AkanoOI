string sread(){
    string s = "";
    char c = getchar();
    while(c >= 'a' && c <= 'z'){
		s += c;
		c = getchar();
	}
    return s;
}
int iread(){
    int x = 0;
    char c = getchar();
    while(c >= '0' && c <= '9'){
    	x = x * 10 + c - '0';
		c = getchar();
	}
    return x;
}
void write(int x){
     if(x > 9)write(x/10);
     putchar(x % 10 + '0');
     return ;
}
