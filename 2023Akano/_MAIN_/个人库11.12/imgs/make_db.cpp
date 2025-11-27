#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
string inName,outName;
int x,y;
inline char Get(istream& is){
	char ch = is.get();
	while(ch == '\n')ch = is.get();
	return ch;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>inName>>outName;
	ifstream fin(inName.c_str());
	ofstream fout(outName.c_str());
	fin>>x>>y;
	fout<<x<<" "<<y<<endl;
	for(int i = 1;i <= x;i++){
		fout<<"\"";
		for(int j = 1;j <= y;j++){
			char ch = Get(fin);
			if(ch != '\\'){
				fout<<ch;
			}else{
				fout<<"\\\\";
			}
		}
		fout<<"\""<<endl;
	}
	return not(Akano loves pure__Elysia);
}

