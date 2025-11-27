#include<bits/stdc++.h>
using namespace std;
int n,i,j,ZZ = 0/*指针(用于优惠票)*/,JS = 0/*尚存的优惠票的计数*/,m;
int GJ[100001],price[100001],TIME[100001],YHP[100001][2];/*不要吐槽用拼音缩写*/;
int needmoney/*答案*/,fl;//优惠票YHP[0]是时间,YHP[1]是价钱 
bool PD = true,HI = true;
int main(){//编译的时候才发现time[123]非法...换成了大写的TIME 

	cin>>n;
	for(i = 0;i < n;i++){
		scanf("%d%d%d",&GJ[i],&price[i],&TIME[i]);
	} 
	needmoney += price[0];//第一次交钱
	YHP[0][0] = TIME[0];
	YHP[0][1] = price[0];
	ZZ++;
	for(i = 1;i < n;i++){
		PD = false;//true不付钱,false要付钱 
		if(GJ[i] == 1){
			j = 0;
			for(j = fl;j<i;j++){
				//cout<<"执行第"<<i<<"的"<<j<<"的优惠检测"<<endl; 
				if((int(YHP[j][0])+45)>=TIME[i]&&YHP[j][1]>=price[i]){
					PD = true;
				//	cout<<"第"<<i+1<<"张票免票,使用第"<<j+1+m<<"次乘车所用的YHY(误)"<<endl; 
					YHP[j][1] = -1;//这张票就废了 
					break;
				}
				if((int(YHP[j][0])+45)<TIME[i]){
					fl = j;
				}
			}
		m++;
		}
		if(GJ[i] == 0){
			YHP[ZZ][0] = TIME[i];
			YHP[ZZ][1] = price[i];
			ZZ++;
		} 
		if(PD == false) needmoney += price[i];//交钱
	
	}
	cout<<needmoney<<endl;
	return 0;
}
//(现在的代码是这个样子的)(15:55,刚做完)
/*
#include<bits/stdc++.h>
using namespace std;
int n,i,j,ZZ = 0/*指针(用于优惠票);
int GJ[100001],price[100001],TIME[100001],YHP[100001][2];/*不要吐槽用拼音缩写;
long long needmoney/*答案;//优惠票YHP[0]是时间,YHP[1]是价钱 
bool PD = true;//话说YHP的缩写让我想起了YHY......没什么... 
int main(){//编译的时候才发现time[123]非法...换成了大写的TIME 
 
	freopen("transfer.in","r",stdin);
	//freopen("transfer.out","w",stdout);
	cin>>n;
	for(i = 0;i < n;i++){
		scanf("%d%d%d",&GJ[i],&price[i],&TIME[i]);
	} 
	needmoney += price[0];//第一次交钱
	YHP[0][0] = TIME[0];
	YHP[0][1] = price[0];
	ZZ++;
	for(i = 1;i < n;i++){
		PD = false;//true不付钱,false要付钱 
		if(GJ[i] == 1){
		
		for(j = 0;j<100000&&j<i+2;j++){
			if((int(YHP[j][0])+45)>=TIME[i]&&YHP[j][1]>=price[i]){
				PD = true;
				cout<<"第"<<i+1<<"张票免票,使用第"<<j+1<<"次乘车所用的YHY(误)"<<endl; 
				YHP[j][1] = 0;//这张票就废了 
				break;
			}
			 //cout<<i+1<<"  卡死测试 "<<j+1<<endl; 
		}
		}
		if(GJ[i] == 0){
			YHP[ZZ][0] = TIME[i];
			YHP[ZZ][1] = price[i];
			ZZ++;
		} 
		if(PD == false) needmoney += price[i];//交钱
	//cout<<"需付"<<needmoney<<"元"<<endl;
	
	}
	cout<<needmoney;
	return 0;
}
可问题是这个样子好像会超时????????? 
*/
//没错!!!!经过检验我发现程序需要用24秒完成10000个车站!!!!平均每400个车站耗时1S,这当然不行!!!我去优化下 
//16:36 仍然没有做出来!!!!! 试了挺多种方法,都无法正确优化 
//16:42 如果把cout数据关掉的话,10000数据费时6s,光标闪7下(16:53) 
//16:54优化了下,光标闪6下 
//17:10 优化后光标闪5下 17:11 闪4下, 费时5S，不优化了(花了太多时间了,不过反正其他题我也不会做)
// 17:28不做了，大部分时间在做这道题，不过其他题确实太简单/难了，会做的早做了，不会做的做不出来，就这样吧
 
