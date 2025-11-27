inline void Show(int x){
	for(int i = 1;i <= x;i++){
		cout<<setw(3)<<1;
	}
	cout<<endl;
	for(int i = 1;i <= x;i++){
		for(int j = 1;j <= x;j++){
			if(i <= j){
				cout<<setw(3)<<step[min(i,j)][max(i,j)];
			}else{
				cout<<setw(3)<<"";
			}
		}
		cout<<endl;
	}
	return ;
}
inline void Get(){
	for(int i = 1;i <= n;i++){
		int now = 0;
		if(2*i > n)break;
		for(int j = i;j < 2*i;j++){
			now += step[i][j];
		}
		cout<<i<<" : "<<now<<endl;
	}
	return ;
}
