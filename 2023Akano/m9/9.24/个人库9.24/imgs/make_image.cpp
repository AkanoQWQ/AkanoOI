#include<bits/stdc++.h>
using namespace std;

vector<string> strs;
char cache[256];
string str,inName,outName;
int len;
int main(){
	cout<<"请输入转化前的文件名:";
	cin>>inName;
	cout<<"请输入转化后的文件名:";
	cin>>outName; 
	ifstream fin(inName.c_str());
	ofstream fout(outName.c_str());
	while(fin.getline(cache,256)){
		str = cache;
		strs.push_back(str);
		len = max(len,int(str.length()));
	}
	fout<<strs.size()<<" "<<len<<endl;
	for(auto i : strs){
		fout<<i;
		for(int j = 1;j <= int(len - i.length());j++)fout<<" ";
		fout<<endl;
	}
	return 0;
}
