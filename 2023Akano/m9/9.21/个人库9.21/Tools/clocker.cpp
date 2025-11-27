#include<bits/stdc++.h>
#include<AL/refresh.h>
#include<AL/container.h>
#include<conio.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int ticks = 8;//8 ticks
inline string ToW2(int x){
	string ret;
	for(int i = 1;i <= 2;i++){
		ret += (x % 10) + '0';
		x /= 10;
	}
	reverse(ret.begin(),ret.end());
	return ret;
}
inline string Trans(int clk){
	int s = clk / 1000;clk %= 1000;
	int m = s / 60;s %= 60;
	int h = m / 60;m %= 60;
	return ToW2(h)+":"+ToW2(m)+":"+ToW2(s);
}
bool added;
Container::Vector<int> inf;
inline void ShowEvent(){
	while(true){
		if(added){
			inf.PushBack(clock()); 
			added = false;
		}
		Refresh();
		cout<<Trans(clock())<<endl; 
		int cnt = 0; 
		for(auto i : inf){
			cout<<"第 "<<++cnt<<" 次计时为: "+Trans(i)+" 距今 "+Trans(clock()-i)<<endl; 
		}
		Sleep(1000 / ticks);
	}
	return ;
}
int main(){
	SetConsoleTitle("计时器");
	RefreshInit();
	thread showThread(ShowEvent);
	showThread.detach();
	while(true){
		char ch = getch();
		if(int(ch) == 13){//回车 
			added = true;
		}else if(int(ch) == 8){//退格 
			if(int(inf.size) >= 1)inf.PopFront();
		}
	}
	return not(Akano loves pure__Elysia);
}
