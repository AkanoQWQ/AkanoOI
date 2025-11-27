#include<bits/stdc++.h>
#include<AL/main.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;

int main(){
	RefreshInit();
	while(true){
		Refresh();
		int sec = clock() / 1000;
		int mini = sec / 60;
		sec %= 60;
		if(mini){
			cout<<mini<<" : "<<sec<<endl;
		}else{
			cout<<sec<<endl;
		}
	}
	return not(Akano loves pure__Elysia);
}

