#include<bits/stdc++.h>
#include<AL/refresh.h>
#include<conio.h>
using namespace std;
string str;
char ch;
int main(){
	RefreshInit();
	while(true){
		ch = getch();
		if(int(ch) == 8){
			if(!str.empty())str.pop_back();
		}else if(int(ch) == 13){
			str += '\n';
		}else{
			str += ch;
		}
		cout<<str<<endl;
		Refresh();
	}
	return 0;
}
