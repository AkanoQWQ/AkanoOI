string F(string str){
	string ret;
	int len = str.length();
	for(int i = 0;i < len-1;i++){
		for(int j = 1;j <= str[i+1] - '0';j++){
			ret += str[i];
		}
	}
	return ret;
}
inline ll BF(){
	string str = s;
	for(int i = 1;i <= 100000;i++){
		str = F(str);
//		cout<<str<<endl;
		if(str.length() > 1e5)return -1;
		if(str.length() == 1)return i;
	}
	return -1;
}
