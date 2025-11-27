#include<bits/stdc++.h>
using namespace std;
vector<string> vec;
string s;
int n = 10;
int main(){
	for(int t = 1;t <= 100;t++){
		freopen("sequence.in","w",stdout);
		cout<<n<<endl;
		for(int i = 1;i <= n;i++){
			int a = rand()%100,b = a + rand()%100;
			cout<<a<<" "<<b<<endl;
		}
		system("sequence.exe");
		system("sequence_std.exe");
		bool fd = system("fc sequence.out sequence2.out");
		if(fd){
			vec.push_back("WA!");
			break;
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
