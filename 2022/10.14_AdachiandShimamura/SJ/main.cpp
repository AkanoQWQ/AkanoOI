#include<bits/stdc++.h>
using namespace std;
vector<string> vec;
string s;
int main(){
	for(int t = 1;t <= 20;t++){
		cin.clear();
		cout.clear();
		freopen(("cannon"+to_string(t)+".in").c_str(),"r",stdin);
		freopen("cannon.in","w",stdout);
		while(1){
			getline(cin,s);
			if(s == "")break;
			cout<<s<<endl;
		}
		system("cannon.exe");
		bool fd = system(("fc cannon.out cannon"+to_string(t)+".out").c_str());
		if(fd){
			vec.push_back("WA!");
		}else{
			vec.push_back("AC");
		}
	}
	cout.clear();
	freopen("SJ.out","w",stdout);
	for(int i = 0;i < vec.size();i++){
		cout<<vec[i]<<endl;
	}
	return 0;
}
