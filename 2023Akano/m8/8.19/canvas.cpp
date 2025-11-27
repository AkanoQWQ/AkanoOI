#include<bits/stdc++.h>
#include<locale>
#include<AL/main.h>
using namespace std;
class Canvas{
	wchar_t opt[50][50];
	public:
	inline void Insert(int x,int y,wstring str){
		for(auto i : str){
			opt[x][y++] = i;
		}
		return ;
	}
	inline void Show(){
		for(int i = 1;i <= 5;i++){
			for(int j = 1;j <= 5;j++){
				wcout<<opt[i][j];
			}
			cout<<endl;
		}
		return ;
	}
}canvas;
wchar_t str[1145143] = L"Ö»²»¹ýÎ¢²©";
int x,y;
int main(){
	
	return 0;
}
