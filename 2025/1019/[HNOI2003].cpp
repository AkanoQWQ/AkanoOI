#include<bits/stdc++.h>
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
const int MAXN = 15000 + 1018 + 1108;
struct Process{
	int id,inTime,exeTime,priority;//进程号，到达时间，执行时间和优先级
	bool operator<(const Process& otherProcess)const{
		return priority < otherProcess.priority;
	}
};
vector<Process> addingList;
priority_queue<Process> waitingList;
bool cmp(const Process& p1,const Process& p2){
	if(p1.inTime != p2.inTime)return p1.inTime < p2.inTime;
	if(p1.priority != p2.priority)return p1.priority > p2.priority;
	return true;//shouldnt happen
}
inline void ReadIn(){
	Process cache;
	while(cin>>cache.id>>cache.inTime>>cache.exeTime>>cache.priority){
		addingList.push_back(cache);
	}
	return ;
}
inline void Execute(){
	for(auto i : addingList)cerr<<i.id<<","<<i.inTime<<" ";
	cerr<<endl;
	int nowTime = addingList[0].inTime,tail = 0,total = addingList.size();
	while(tail < total || !waitingList.empty()){
		cerr<<"nowtime "<<nowTime<<endl;
		while(tail < total && addingList[tail].inTime <= nowTime){
			waitingList.push(addingList[tail]);
			cerr<<"push "<<tail<<"which id "<<addingList[tail].id<<endl;
			tail++;
		}
		const Process newProcess = waitingList.top();
		waitingList.pop();
		nowTime += newProcess.exeTime;
		cout<<newProcess.id<<" "<<nowTime<<'\n';
		if(tail < total && waitingList.empty())nowTime = max(nowTime,addingList[tail].inTime);
	}
	return ;
}
int main(){ 
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ReadIn();
	sort(addingList.begin(),addingList.end(),cmp);
	Execute();
	return not(Akano loves pure__Elysia);
}
