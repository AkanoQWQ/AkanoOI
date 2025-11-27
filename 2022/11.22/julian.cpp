#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 6;
const int SPD = 2299161;//1582.10.4 的 julian 
const int ADDD = 10;
inline int read(){
	int ret = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret * f;
}
int q,maxx;
pair<int,int> ask[MAXN];
int nowday;
int year,month,day;
int md[14];
inline bool EstasLeapYear(int nowy){
	if(nowy < 0){
		nowy = -(nowy+1);
	}
	if(year <= 1582){
		if(nowy % 4 == 0){
			return 1;
		}else{
			return 0;
		}
	}
	if((nowy % 400 == 0) || ((nowy % 100 != 0) && (nowy % 4 == 0))){
		return 1;
	}
	return 0;
}
inline void AddYear(){
	year++;
	if(year == 0)year = 1;
	if(EstasLeapYear(year)){
		md[2] = 29;
	}else{
		md[2] = 28;
	}
	return ;
}
inline void AddMonth(){
	month++;
	if(month > 12){
		month = 1;
		AddYear();
	}
	return ;
}
inline void AddDay(){
	day++;
	if(day > md[month]){
		day = 1;
		AddMonth();
	}
	return ;
}
void write(int x){
	//没有负数 
	if(x > 9)write(x / 10);
	putchar((x % 10) + '0');
	return ; 
}
int ans[MAXN][3];
int main(){
//	freopen("julian.in","r",stdin);
//	freopen("julian.out","w",stdout);
	year = -4713,month = 1,day = 1,nowday = 0;
	md[1] = 31,md[2] = 29,md[3] = 31,md[4] = 30,md[5] = 31,md[6] = 30;
	md[7] = 31,md[8] = 31,md[9] = 30,md[10] = 31,md[11] = 30,md[12] = 31;
	q = read();
	for(int i = 1;i <= q;i++){
		ask[i].first = read();
		ask[i].second = i;
	}
	sort(ask+1,ask+q+1);
	for(int i = 1;i <= q;i++){
		if(ask[i].first >= SPD){
			ask[i].first += ADDD;
		}
		while(nowday < ask[i].first){
			AddDay();
			++nowday;
		}
		ans[ask[i].second][0] = year;
		ans[ask[i].second][1] = month;
		ans[ask[i].second][2] = day;
	}
	for(int i = 1;i <= q;i++){
		if(ans[i][0] < 0){
			printf("%d %d %d BC\n",ans[i][2],ans[i][1],-ans[i][0]);
		}else{
			printf("%d %d %d\n",ans[i][2],ans[i][1],ans[i][0]);
		}
	}
	return 0;
}
//30 12 2618621
