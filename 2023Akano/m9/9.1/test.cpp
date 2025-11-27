#include<bits/stdc++.h>
#include<conio.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
istringstream iss("1 3");
int a,b;
char ch;
string str,nows;
int main(){
	cin.rdbuf(iss.rdbuf());
	while(ch = getch()){
		if(int(ch) == 13){
			iss.str(str);
			iss.clear();
			cin.clear();
			str = "";
		}else if(int(ch) == 45){
			cin>>nows;
			cout<<nows<<endl;
		}else{
			str += ch;
		}
	}
	return not(Akano loves pure__Elysia);
}
