#include<bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize(2)
#define Akano 1
#define pure__Elysia 0
#define loves ^
using namespace std;
using ll = unsigned long long;
const int MAXN = 1018 + 1108;
const int MAXVAL = 1e9;
const int MAXSQRT = 1e5;
int n,q,posW,posH,MOD,a,b;
int h[MAXN],x[MAXN],y[MAXN],OX,OY,sizeX,sizeY,maxX,maxY,blk,newh[MAXN][MAXN];
ll baseA1[MAXSQRT],baseA2[MAXSQRT],baseB1[MAXSQRT],baseB2[MAXSQRT],sum[4][MAXN][MAXN];
inline ll LightPow(ll nowb,ll base1[],ll base2[]){
	return (base2[nowb / blk] * base1[nowb % blk]) % MOD;
}
vector<int> vecX,vecY;
inline void Init(){
	blk = sqrt(MAXVAL)+1;
	baseA1[0] = 1;
	for(int i = 1;i <= blk;i++)baseA1[i] = (baseA1[i-1] * a) % MOD;
	baseA2[0] = 1;
	for(int i = 1;i <= blk;i++)baseA2[i] = (baseA2[i-1] * baseA1[blk]) % MOD;
	baseB1[0] = 1;
	for(int i = 1;i <= blk;i++)baseB1[i] = (baseB1[i-1] * b) % MOD;
	baseB2[0] = 1;
	for(int i = 1;i <= blk;i++)baseB2[i] = (baseB2[i-1] * baseB1[blk]) % MOD;
	return ;
}
inline int Read(){//no f
	int ret = 0;
	char ch = getchar();
	while(!isdigit(ch))ch = getchar();
	while(isdigit(ch)){
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("satellite/org/satellite2.in","r",stdin);
	n = Read(),q = Read(),posW = Read(),posH = Read(),MOD = Read(),a = Read(),b = Read();
	Init();
	for(int i = 1;i <= n;i++){
		h[i] = Read(),x[i] = Read(),y[i] = Read();
		maxX = max(maxX,x[i]),maxY = max(maxY,y[i]);
		vecX.push_back(x[i]),vecY.push_back(y[i]);
	}
	vecX.push_back(0),vecY.push_back(0),vecX.push_back(posW+2),vecY.push_back(posH+2);
 	sort(vecX.begin(),vecX.end()),sort(vecY.begin(),vecY.end());
	auto itX = unique(vecX.begin(),vecX.end()),itY = unique(vecY.begin(),vecY.end());
	vecX.erase(itX,vecX.end()),vecY.erase(itY,vecY.end());
	sizeX = int(vecX.size()) - 1,sizeY = int(vecY.size()) - 1;
	for(int i = 1;i <= n;i++){
		ll newx = upper_bound(vecX.begin(),vecX.end(),x[i]) - vecX.begin() - 1;
		ll newy = upper_bound(vecY.begin(),vecY.end(),y[i]) - vecY.begin() - 1;
		newh[newx][newy] += h[i];
	}
	int deltaX = 0,deltaY = 0;
	for(int i = 1;i <= sizeX;i++){//左上 
		for(int j = 1;j <= sizeY;){
			deltaX = vecX[i] - vecX[i-1],deltaY = vecY[j] - vecY[j-1];
			sum[0][i][j] = newh[i][j];
			sum[0][i][j] += sum[0][i-1][j] * LightPow(deltaX,baseA1,baseA2);
			sum[0][i][j] += sum[0][i][j-1] * LightPow(deltaY,baseB1,baseB2);
			sum[0][i][j] -= (((sum[0][i-1][j-1] * LightPow(deltaX,baseA1,baseA2)) % MOD) * LightPow(deltaY,baseB1,baseB2)) % MOD;
			sum[0][i][j] = (sum[0][i][j] + MOD) % MOD;
			j++;if(j > sizeY)break;
			
			deltaX = vecX[i] - vecX[i-1],deltaY = vecY[j] - vecY[j-1];
			sum[0][i][j] = newh[i][j];
			sum[0][i][j] += sum[0][i-1][j] * LightPow(deltaX,baseA1,baseA2);
			sum[0][i][j] += sum[0][i][j-1] * LightPow(deltaY,baseB1,baseB2);
			sum[0][i][j] -= (((sum[0][i-1][j-1] * LightPow(deltaX,baseA1,baseA2)) % MOD) * LightPow(deltaY,baseB1,baseB2)) % MOD;
			sum[0][i][j] = (sum[0][i][j] + MOD) % MOD;
			j++;if(j > sizeY)break;
			
			deltaX = vecX[i] - vecX[i-1],deltaY = vecY[j] - vecY[j-1];
			sum[0][i][j] = newh[i][j];
			sum[0][i][j] += sum[0][i-1][j] * LightPow(deltaX,baseA1,baseA2);
			sum[0][i][j] += sum[0][i][j-1] * LightPow(deltaY,baseB1,baseB2);
			sum[0][i][j] -= (((sum[0][i-1][j-1] * LightPow(deltaX,baseA1,baseA2)) % MOD) * LightPow(deltaY,baseB1,baseB2)) % MOD;
			sum[0][i][j] = (sum[0][i][j] + MOD) % MOD;
			j++;if(j > sizeY)break;
			
			deltaX = vecX[i] - vecX[i-1],deltaY = vecY[j] - vecY[j-1];
			sum[0][i][j] = newh[i][j];
			sum[0][i][j] += sum[0][i-1][j] * LightPow(deltaX,baseA1,baseA2);
			sum[0][i][j] += sum[0][i][j-1] * LightPow(deltaY,baseB1,baseB2);
			sum[0][i][j] -= (((sum[0][i-1][j-1] * LightPow(deltaX,baseA1,baseA2)) % MOD) * LightPow(deltaY,baseB1,baseB2)) % MOD;
			sum[0][i][j] = (sum[0][i][j] + MOD) % MOD;
			j++;if(j > sizeY)break;
			
			deltaX = vecX[i] - vecX[i-1],deltaY = vecY[j] - vecY[j-1];
			sum[0][i][j] = newh[i][j];
			sum[0][i][j] += sum[0][i-1][j] * LightPow(deltaX,baseA1,baseA2);
			sum[0][i][j] += sum[0][i][j-1] * LightPow(deltaY,baseB1,baseB2);
			sum[0][i][j] -= (((sum[0][i-1][j-1] * LightPow(deltaX,baseA1,baseA2)) % MOD) * LightPow(deltaY,baseB1,baseB2)) % MOD;
			sum[0][i][j] = (sum[0][i][j] + MOD) % MOD;
			j++;if(j > sizeY)break;
			
			deltaX = vecX[i] - vecX[i-1],deltaY = vecY[j] - vecY[j-1];
			sum[0][i][j] = newh[i][j];
			sum[0][i][j] += sum[0][i-1][j] * LightPow(deltaX,baseA1,baseA2);
			sum[0][i][j] += sum[0][i][j-1] * LightPow(deltaY,baseB1,baseB2);
			sum[0][i][j] -= (((sum[0][i-1][j-1] * LightPow(deltaX,baseA1,baseA2)) % MOD) * LightPow(deltaY,baseB1,baseB2)) % MOD;
			sum[0][i][j] = (sum[0][i][j] + MOD) % MOD;
			j++;if(j > sizeY)break;
			
			deltaX = vecX[i] - vecX[i-1],deltaY = vecY[j] - vecY[j-1];
			sum[0][i][j] = newh[i][j];
			sum[0][i][j] += sum[0][i-1][j] * LightPow(deltaX,baseA1,baseA2);
			sum[0][i][j] += sum[0][i][j-1] * LightPow(deltaY,baseB1,baseB2);
			sum[0][i][j] -= (((sum[0][i-1][j-1] * LightPow(deltaX,baseA1,baseA2)) % MOD) * LightPow(deltaY,baseB1,baseB2)) % MOD;
			sum[0][i][j] = (sum[0][i][j] + MOD) % MOD;
			j++;if(j > sizeY)break;
			
			deltaX = vecX[i] - vecX[i-1],deltaY = vecY[j] - vecY[j-1];
			sum[0][i][j] = newh[i][j];
			sum[0][i][j] += sum[0][i-1][j] * LightPow(deltaX,baseA1,baseA2);
			sum[0][i][j] += sum[0][i][j-1] * LightPow(deltaY,baseB1,baseB2);
			sum[0][i][j] -= (((sum[0][i-1][j-1] * LightPow(deltaX,baseA1,baseA2)) % MOD) * LightPow(deltaY,baseB1,baseB2)) % MOD;
			sum[0][i][j] = (sum[0][i][j] + MOD) % MOD;
			j++;if(j > sizeY)break;
			
			deltaX = vecX[i] - vecX[i-1],deltaY = vecY[j] - vecY[j-1];
			sum[0][i][j] = newh[i][j];
			sum[0][i][j] += sum[0][i-1][j] * LightPow(deltaX,baseA1,baseA2);
			sum[0][i][j] += sum[0][i][j-1] * LightPow(deltaY,baseB1,baseB2);
			sum[0][i][j] -= (((sum[0][i-1][j-1] * LightPow(deltaX,baseA1,baseA2)) % MOD) * LightPow(deltaY,baseB1,baseB2)) % MOD;
			sum[0][i][j] = (sum[0][i][j] + MOD) % MOD;
			j++;if(j > sizeY)break;
			
			deltaX = vecX[i] - vecX[i-1],deltaY = vecY[j] - vecY[j-1];
			sum[0][i][j] = newh[i][j];
			sum[0][i][j] += sum[0][i-1][j] * LightPow(deltaX,baseA1,baseA2);
			sum[0][i][j] += sum[0][i][j-1] * LightPow(deltaY,baseB1,baseB2);
			sum[0][i][j] -= (((sum[0][i-1][j-1] * LightPow(deltaX,baseA1,baseA2)) % MOD) * LightPow(deltaY,baseB1,baseB2)) % MOD;
			sum[0][i][j] = (sum[0][i][j] + MOD) % MOD;
			j++;if(j > sizeY)break;
			
			deltaX = vecX[i] - vecX[i-1],deltaY = vecY[j] - vecY[j-1];
			sum[0][i][j] = newh[i][j];
			sum[0][i][j] += sum[0][i-1][j] * LightPow(deltaX,baseA1,baseA2);
			sum[0][i][j] += sum[0][i][j-1] * LightPow(deltaY,baseB1,baseB2);
			sum[0][i][j] -= (((sum[0][i-1][j-1] * LightPow(deltaX,baseA1,baseA2)) % MOD) * LightPow(deltaY,baseB1,baseB2)) % MOD;
			sum[0][i][j] = (sum[0][i][j] + MOD) % MOD;
			j++;if(j > sizeY)break;
			
			deltaX = vecX[i] - vecX[i-1],deltaY = vecY[j] - vecY[j-1];
			sum[0][i][j] = newh[i][j];
			sum[0][i][j] += sum[0][i-1][j] * LightPow(deltaX,baseA1,baseA2);
			sum[0][i][j] += sum[0][i][j-1] * LightPow(deltaY,baseB1,baseB2);
			sum[0][i][j] -= (((sum[0][i-1][j-1] * LightPow(deltaX,baseA1,baseA2)) % MOD) * LightPow(deltaY,baseB1,baseB2)) % MOD;
			sum[0][i][j] = (sum[0][i][j] + MOD) % MOD;
			j++;if(j > sizeY)break;
		}
	}
	for(int i = 1;i <= sizeX;i++){//右上 
		for(int j = sizeY-1;j >= 0;){
			deltaX = vecX[i] - vecX[i-1],deltaY = vecY[j+1] - vecY[j];
			sum[1][i][j] = newh[i][j];
			sum[1][i][j] += sum[1][i-1][j] * LightPow(deltaX,baseA1,baseA2);
			sum[1][i][j] += sum[1][i][j+1] * LightPow(deltaY,baseB1,baseB2);
			sum[1][i][j] -= (((sum[1][i-1][j+1] * LightPow(deltaX,baseA1,baseA2)) % MOD) * LightPow(deltaY,baseB1,baseB2)) % MOD;
			sum[1][i][j] = (sum[1][i][j] + MOD) % MOD;
			j--;if(j < 0)break;
			
			deltaX = vecX[i] - vecX[i-1],deltaY = vecY[j+1] - vecY[j];
			sum[1][i][j] = newh[i][j];
			sum[1][i][j] += sum[1][i-1][j] * LightPow(deltaX,baseA1,baseA2);
			sum[1][i][j] += sum[1][i][j+1] * LightPow(deltaY,baseB1,baseB2);
			sum[1][i][j] -= (((sum[1][i-1][j+1] * LightPow(deltaX,baseA1,baseA2)) % MOD) * LightPow(deltaY,baseB1,baseB2)) % MOD;
			sum[1][i][j] = (sum[1][i][j] + MOD) % MOD;
			j--;if(j < 0)break;
			
			deltaX = vecX[i] - vecX[i-1],deltaY = vecY[j+1] - vecY[j];
			sum[1][i][j] = newh[i][j];
			sum[1][i][j] += sum[1][i-1][j] * LightPow(deltaX,baseA1,baseA2);
			sum[1][i][j] += sum[1][i][j+1] * LightPow(deltaY,baseB1,baseB2);
			sum[1][i][j] -= (((sum[1][i-1][j+1] * LightPow(deltaX,baseA1,baseA2)) % MOD) * LightPow(deltaY,baseB1,baseB2)) % MOD;
			sum[1][i][j] = (sum[1][i][j] + MOD) % MOD;
			j--;if(j < 0)break;
			
			deltaX = vecX[i] - vecX[i-1],deltaY = vecY[j+1] - vecY[j];
			sum[1][i][j] = newh[i][j];
			sum[1][i][j] += sum[1][i-1][j] * LightPow(deltaX,baseA1,baseA2);
			sum[1][i][j] += sum[1][i][j+1] * LightPow(deltaY,baseB1,baseB2);
			sum[1][i][j] -= (((sum[1][i-1][j+1] * LightPow(deltaX,baseA1,baseA2)) % MOD) * LightPow(deltaY,baseB1,baseB2)) % MOD;
			sum[1][i][j] = (sum[1][i][j] + MOD) % MOD;
			j--;if(j < 0)break;
			
			deltaX = vecX[i] - vecX[i-1],deltaY = vecY[j+1] - vecY[j];
			sum[1][i][j] = newh[i][j];
			sum[1][i][j] += sum[1][i-1][j] * LightPow(deltaX,baseA1,baseA2);
			sum[1][i][j] += sum[1][i][j+1] * LightPow(deltaY,baseB1,baseB2);
			sum[1][i][j] -= (((sum[1][i-1][j+1] * LightPow(deltaX,baseA1,baseA2)) % MOD) * LightPow(deltaY,baseB1,baseB2)) % MOD;
			sum[1][i][j] = (sum[1][i][j] + MOD) % MOD;
			j--;if(j < 0)break;
			
			deltaX = vecX[i] - vecX[i-1],deltaY = vecY[j+1] - vecY[j];
			sum[1][i][j] = newh[i][j];
			sum[1][i][j] += sum[1][i-1][j] * LightPow(deltaX,baseA1,baseA2);
			sum[1][i][j] += sum[1][i][j+1] * LightPow(deltaY,baseB1,baseB2);
			sum[1][i][j] -= (((sum[1][i-1][j+1] * LightPow(deltaX,baseA1,baseA2)) % MOD) * LightPow(deltaY,baseB1,baseB2)) % MOD;
			sum[1][i][j] = (sum[1][i][j] + MOD) % MOD;
			j--;if(j < 0)break;
			
			deltaX = vecX[i] - vecX[i-1],deltaY = vecY[j+1] - vecY[j];
			sum[1][i][j] = newh[i][j];
			sum[1][i][j] += sum[1][i-1][j] * LightPow(deltaX,baseA1,baseA2);
			sum[1][i][j] += sum[1][i][j+1] * LightPow(deltaY,baseB1,baseB2);
			sum[1][i][j] -= (((sum[1][i-1][j+1] * LightPow(deltaX,baseA1,baseA2)) % MOD) * LightPow(deltaY,baseB1,baseB2)) % MOD;
			sum[1][i][j] = (sum[1][i][j] + MOD) % MOD;
			j--;if(j < 0)break;
			
			deltaX = vecX[i] - vecX[i-1],deltaY = vecY[j+1] - vecY[j];
			sum[1][i][j] = newh[i][j];
			sum[1][i][j] += sum[1][i-1][j] * LightPow(deltaX,baseA1,baseA2);
			sum[1][i][j] += sum[1][i][j+1] * LightPow(deltaY,baseB1,baseB2);
			sum[1][i][j] -= (((sum[1][i-1][j+1] * LightPow(deltaX,baseA1,baseA2)) % MOD) * LightPow(deltaY,baseB1,baseB2)) % MOD;
			sum[1][i][j] = (sum[1][i][j] + MOD) % MOD;
			j--;if(j < 0)break;
			
			deltaX = vecX[i] - vecX[i-1],deltaY = vecY[j+1] - vecY[j];
			sum[1][i][j] = newh[i][j];
			sum[1][i][j] += sum[1][i-1][j] * LightPow(deltaX,baseA1,baseA2);
			sum[1][i][j] += sum[1][i][j+1] * LightPow(deltaY,baseB1,baseB2);
			sum[1][i][j] -= (((sum[1][i-1][j+1] * LightPow(deltaX,baseA1,baseA2)) % MOD) * LightPow(deltaY,baseB1,baseB2)) % MOD;
			sum[1][i][j] = (sum[1][i][j] + MOD) % MOD;
			j--;if(j < 0)break;
			
			deltaX = vecX[i] - vecX[i-1],deltaY = vecY[j+1] - vecY[j];
			sum[1][i][j] = newh[i][j];
			sum[1][i][j] += sum[1][i-1][j] * LightPow(deltaX,baseA1,baseA2);
			sum[1][i][j] += sum[1][i][j+1] * LightPow(deltaY,baseB1,baseB2);
			sum[1][i][j] -= (((sum[1][i-1][j+1] * LightPow(deltaX,baseA1,baseA2)) % MOD) * LightPow(deltaY,baseB1,baseB2)) % MOD;
			sum[1][i][j] = (sum[1][i][j] + MOD) % MOD;
			j--;if(j < 0)break;
			
			deltaX = vecX[i] - vecX[i-1],deltaY = vecY[j+1] - vecY[j];
			sum[1][i][j] = newh[i][j];
			sum[1][i][j] += sum[1][i-1][j] * LightPow(deltaX,baseA1,baseA2);
			sum[1][i][j] += sum[1][i][j+1] * LightPow(deltaY,baseB1,baseB2);
			sum[1][i][j] -= (((sum[1][i-1][j+1] * LightPow(deltaX,baseA1,baseA2)) % MOD) * LightPow(deltaY,baseB1,baseB2)) % MOD;
			sum[1][i][j] = (sum[1][i][j] + MOD) % MOD;
			j--;if(j < 0)break;
			
			deltaX = vecX[i] - vecX[i-1],deltaY = vecY[j+1] - vecY[j];
			sum[1][i][j] = newh[i][j];
			sum[1][i][j] += sum[1][i-1][j] * LightPow(deltaX,baseA1,baseA2);
			sum[1][i][j] += sum[1][i][j+1] * LightPow(deltaY,baseB1,baseB2);
			sum[1][i][j] -= (((sum[1][i-1][j+1] * LightPow(deltaX,baseA1,baseA2)) % MOD) * LightPow(deltaY,baseB1,baseB2)) % MOD;
			sum[1][i][j] = (sum[1][i][j] + MOD) % MOD;
			j--;if(j < 0)break;
		}
	}
	for(int i = sizeX - 1;i >= 0;i--){//左下 
		for(int j = 1;j <= sizeY;){
			deltaX = vecX[i+1] - vecX[i],deltaY = vecY[j] - vecY[j-1];
			sum[2][i][j] = newh[i][j];
			sum[2][i][j] += sum[2][i+1][j] * LightPow(deltaX,baseA1,baseA2);
			sum[2][i][j] += sum[2][i][j-1] * LightPow(deltaY,baseB1,baseB2);
			sum[2][i][j] -= (((sum[2][i+1][j-1] * LightPow(deltaX,baseA1,baseA2)) % MOD) * LightPow(deltaY,baseB1,baseB2)) % MOD;
			sum[2][i][j] = (sum[2][i][j] + MOD) % MOD;
			j++;if(j > sizeY)break;
			
			deltaX = vecX[i+1] - vecX[i],deltaY = vecY[j] - vecY[j-1];
			sum[2][i][j] = newh[i][j];
			sum[2][i][j] += sum[2][i+1][j] * LightPow(deltaX,baseA1,baseA2);
			sum[2][i][j] += sum[2][i][j-1] * LightPow(deltaY,baseB1,baseB2);
			sum[2][i][j] -= (((sum[2][i+1][j-1] * LightPow(deltaX,baseA1,baseA2)) % MOD) * LightPow(deltaY,baseB1,baseB2)) % MOD;
			sum[2][i][j] = (sum[2][i][j] + MOD) % MOD;
			j++;if(j > sizeY)break;
			
			deltaX = vecX[i+1] - vecX[i],deltaY = vecY[j] - vecY[j-1];
			sum[2][i][j] = newh[i][j];
			sum[2][i][j] += sum[2][i+1][j] * LightPow(deltaX,baseA1,baseA2);
			sum[2][i][j] += sum[2][i][j-1] * LightPow(deltaY,baseB1,baseB2);
			sum[2][i][j] -= (((sum[2][i+1][j-1] * LightPow(deltaX,baseA1,baseA2)) % MOD) * LightPow(deltaY,baseB1,baseB2)) % MOD;
			sum[2][i][j] = (sum[2][i][j] + MOD) % MOD;
			j++;if(j > sizeY)break;
			
			deltaX = vecX[i+1] - vecX[i],deltaY = vecY[j] - vecY[j-1];
			sum[2][i][j] = newh[i][j];
			sum[2][i][j] += sum[2][i+1][j] * LightPow(deltaX,baseA1,baseA2);
			sum[2][i][j] += sum[2][i][j-1] * LightPow(deltaY,baseB1,baseB2);
			sum[2][i][j] -= (((sum[2][i+1][j-1] * LightPow(deltaX,baseA1,baseA2)) % MOD) * LightPow(deltaY,baseB1,baseB2)) % MOD;
			sum[2][i][j] = (sum[2][i][j] + MOD) % MOD;
			j++;if(j > sizeY)break;
			
			deltaX = vecX[i+1] - vecX[i],deltaY = vecY[j] - vecY[j-1];
			sum[2][i][j] = newh[i][j];
			sum[2][i][j] += sum[2][i+1][j] * LightPow(deltaX,baseA1,baseA2);
			sum[2][i][j] += sum[2][i][j-1] * LightPow(deltaY,baseB1,baseB2);
			sum[2][i][j] -= (((sum[2][i+1][j-1] * LightPow(deltaX,baseA1,baseA2)) % MOD) * LightPow(deltaY,baseB1,baseB2)) % MOD;
			sum[2][i][j] = (sum[2][i][j] + MOD) % MOD;
			j++;if(j > sizeY)break;
			
			deltaX = vecX[i+1] - vecX[i],deltaY = vecY[j] - vecY[j-1];
			sum[2][i][j] = newh[i][j];
			sum[2][i][j] += sum[2][i+1][j] * LightPow(deltaX,baseA1,baseA2);
			sum[2][i][j] += sum[2][i][j-1] * LightPow(deltaY,baseB1,baseB2);
			sum[2][i][j] -= (((sum[2][i+1][j-1] * LightPow(deltaX,baseA1,baseA2)) % MOD) * LightPow(deltaY,baseB1,baseB2)) % MOD;
			sum[2][i][j] = (sum[2][i][j] + MOD) % MOD;
			j++;if(j > sizeY)break;
			
			deltaX = vecX[i+1] - vecX[i],deltaY = vecY[j] - vecY[j-1];
			sum[2][i][j] = newh[i][j];
			sum[2][i][j] += sum[2][i+1][j] * LightPow(deltaX,baseA1,baseA2);
			sum[2][i][j] += sum[2][i][j-1] * LightPow(deltaY,baseB1,baseB2);
			sum[2][i][j] -= (((sum[2][i+1][j-1] * LightPow(deltaX,baseA1,baseA2)) % MOD) * LightPow(deltaY,baseB1,baseB2)) % MOD;
			sum[2][i][j] = (sum[2][i][j] + MOD) % MOD;
			j++;if(j > sizeY)break;
			
			deltaX = vecX[i+1] - vecX[i],deltaY = vecY[j] - vecY[j-1];
			sum[2][i][j] = newh[i][j];
			sum[2][i][j] += sum[2][i+1][j] * LightPow(deltaX,baseA1,baseA2);
			sum[2][i][j] += sum[2][i][j-1] * LightPow(deltaY,baseB1,baseB2);
			sum[2][i][j] -= (((sum[2][i+1][j-1] * LightPow(deltaX,baseA1,baseA2)) % MOD) * LightPow(deltaY,baseB1,baseB2)) % MOD;
			sum[2][i][j] = (sum[2][i][j] + MOD) % MOD;
			j++;if(j > sizeY)break;
			
			deltaX = vecX[i+1] - vecX[i],deltaY = vecY[j] - vecY[j-1];
			sum[2][i][j] = newh[i][j];
			sum[2][i][j] += sum[2][i+1][j] * LightPow(deltaX,baseA1,baseA2);
			sum[2][i][j] += sum[2][i][j-1] * LightPow(deltaY,baseB1,baseB2);
			sum[2][i][j] -= (((sum[2][i+1][j-1] * LightPow(deltaX,baseA1,baseA2)) % MOD) * LightPow(deltaY,baseB1,baseB2)) % MOD;
			sum[2][i][j] = (sum[2][i][j] + MOD) % MOD;
			j++;if(j > sizeY)break;
			
			deltaX = vecX[i+1] - vecX[i],deltaY = vecY[j] - vecY[j-1];
			sum[2][i][j] = newh[i][j];
			sum[2][i][j] += sum[2][i+1][j] * LightPow(deltaX,baseA1,baseA2);
			sum[2][i][j] += sum[2][i][j-1] * LightPow(deltaY,baseB1,baseB2);
			sum[2][i][j] -= (((sum[2][i+1][j-1] * LightPow(deltaX,baseA1,baseA2)) % MOD) * LightPow(deltaY,baseB1,baseB2)) % MOD;
			sum[2][i][j] = (sum[2][i][j] + MOD) % MOD;
			j++;if(j > sizeY)break;
			
			deltaX = vecX[i+1] - vecX[i],deltaY = vecY[j] - vecY[j-1];
			sum[2][i][j] = newh[i][j];
			sum[2][i][j] += sum[2][i+1][j] * LightPow(deltaX,baseA1,baseA2);
			sum[2][i][j] += sum[2][i][j-1] * LightPow(deltaY,baseB1,baseB2);
			sum[2][i][j] -= (((sum[2][i+1][j-1] * LightPow(deltaX,baseA1,baseA2)) % MOD) * LightPow(deltaY,baseB1,baseB2)) % MOD;
			sum[2][i][j] = (sum[2][i][j] + MOD) % MOD;
			j++;if(j > sizeY)break;
			
			deltaX = vecX[i+1] - vecX[i],deltaY = vecY[j] - vecY[j-1];
			sum[2][i][j] = newh[i][j];
			sum[2][i][j] += sum[2][i+1][j] * LightPow(deltaX,baseA1,baseA2);
			sum[2][i][j] += sum[2][i][j-1] * LightPow(deltaY,baseB1,baseB2);
			sum[2][i][j] -= (((sum[2][i+1][j-1] * LightPow(deltaX,baseA1,baseA2)) % MOD) * LightPow(deltaY,baseB1,baseB2)) % MOD;
			sum[2][i][j] = (sum[2][i][j] + MOD) % MOD;
			j++;if(j > sizeY)break;
		}
	}
	for(int i = sizeX - 1;i >= 0;i--){//右下 
		for(int j = sizeY-1;j >= 0;){
			deltaX = vecX[i+1] - vecX[i],deltaY = vecY[j+1] - vecY[j];
			sum[3][i][j] = newh[i][j];
			sum[3][i][j] += sum[3][i+1][j] * LightPow(deltaX,baseA1,baseA2);
			sum[3][i][j] += sum[3][i][j+1] * LightPow(deltaY,baseB1,baseB2);
			sum[3][i][j] -= (((sum[3][i+1][j+1] * LightPow(deltaX,baseA1,baseA2)) % MOD) * LightPow(deltaY,baseB1,baseB2)) % MOD;
			sum[3][i][j] = (sum[3][i][j] + MOD) % MOD;
			j--;if(j < 0)break;
			
			deltaX = vecX[i+1] - vecX[i],deltaY = vecY[j+1] - vecY[j];
			sum[3][i][j] = newh[i][j];
			sum[3][i][j] += sum[3][i+1][j] * LightPow(deltaX,baseA1,baseA2);
			sum[3][i][j] += sum[3][i][j+1] * LightPow(deltaY,baseB1,baseB2);
			sum[3][i][j] -= (((sum[3][i+1][j+1] * LightPow(deltaX,baseA1,baseA2)) % MOD) * LightPow(deltaY,baseB1,baseB2)) % MOD;
			sum[3][i][j] = (sum[3][i][j] + MOD) % MOD;
			j--;if(j < 0)break;
			
			deltaX = vecX[i+1] - vecX[i],deltaY = vecY[j+1] - vecY[j];
			sum[3][i][j] = newh[i][j];
			sum[3][i][j] += sum[3][i+1][j] * LightPow(deltaX,baseA1,baseA2);
			sum[3][i][j] += sum[3][i][j+1] * LightPow(deltaY,baseB1,baseB2);
			sum[3][i][j] -= (((sum[3][i+1][j+1] * LightPow(deltaX,baseA1,baseA2)) % MOD) * LightPow(deltaY,baseB1,baseB2)) % MOD;
			sum[3][i][j] = (sum[3][i][j] + MOD) % MOD;
			j--;if(j < 0)break;
			
			deltaX = vecX[i+1] - vecX[i],deltaY = vecY[j+1] - vecY[j];
			sum[3][i][j] = newh[i][j];
			sum[3][i][j] += sum[3][i+1][j] * LightPow(deltaX,baseA1,baseA2);
			sum[3][i][j] += sum[3][i][j+1] * LightPow(deltaY,baseB1,baseB2);
			sum[3][i][j] -= (((sum[3][i+1][j+1] * LightPow(deltaX,baseA1,baseA2)) % MOD) * LightPow(deltaY,baseB1,baseB2)) % MOD;
			sum[3][i][j] = (sum[3][i][j] + MOD) % MOD;
			j--;if(j < 0)break;
			
			deltaX = vecX[i+1] - vecX[i],deltaY = vecY[j+1] - vecY[j];
			sum[3][i][j] = newh[i][j];
			sum[3][i][j] += sum[3][i+1][j] * LightPow(deltaX,baseA1,baseA2);
			sum[3][i][j] += sum[3][i][j+1] * LightPow(deltaY,baseB1,baseB2);
			sum[3][i][j] -= (((sum[3][i+1][j+1] * LightPow(deltaX,baseA1,baseA2)) % MOD) * LightPow(deltaY,baseB1,baseB2)) % MOD;
			sum[3][i][j] = (sum[3][i][j] + MOD) % MOD;
			j--;if(j < 0)break;
			
			deltaX = vecX[i+1] - vecX[i],deltaY = vecY[j+1] - vecY[j];
			sum[3][i][j] = newh[i][j];
			sum[3][i][j] += sum[3][i+1][j] * LightPow(deltaX,baseA1,baseA2);
			sum[3][i][j] += sum[3][i][j+1] * LightPow(deltaY,baseB1,baseB2);
			sum[3][i][j] -= (((sum[3][i+1][j+1] * LightPow(deltaX,baseA1,baseA2)) % MOD) * LightPow(deltaY,baseB1,baseB2)) % MOD;
			sum[3][i][j] = (sum[3][i][j] + MOD) % MOD;
			j--;if(j < 0)break;
			
			deltaX = vecX[i+1] - vecX[i],deltaY = vecY[j+1] - vecY[j];
			sum[3][i][j] = newh[i][j];
			sum[3][i][j] += sum[3][i+1][j] * LightPow(deltaX,baseA1,baseA2);
			sum[3][i][j] += sum[3][i][j+1] * LightPow(deltaY,baseB1,baseB2);
			sum[3][i][j] -= (((sum[3][i+1][j+1] * LightPow(deltaX,baseA1,baseA2)) % MOD) * LightPow(deltaY,baseB1,baseB2)) % MOD;
			sum[3][i][j] = (sum[3][i][j] + MOD) % MOD;
			j--;if(j < 0)break;
			
			deltaX = vecX[i+1] - vecX[i],deltaY = vecY[j+1] - vecY[j];
			sum[3][i][j] = newh[i][j];
			sum[3][i][j] += sum[3][i+1][j] * LightPow(deltaX,baseA1,baseA2);
			sum[3][i][j] += sum[3][i][j+1] * LightPow(deltaY,baseB1,baseB2);
			sum[3][i][j] -= (((sum[3][i+1][j+1] * LightPow(deltaX,baseA1,baseA2)) % MOD) * LightPow(deltaY,baseB1,baseB2)) % MOD;
			sum[3][i][j] = (sum[3][i][j] + MOD) % MOD;
			j--;if(j < 0)break;
			
			deltaX = vecX[i+1] - vecX[i],deltaY = vecY[j+1] - vecY[j];
			sum[3][i][j] = newh[i][j];
			sum[3][i][j] += sum[3][i+1][j] * LightPow(deltaX,baseA1,baseA2);
			sum[3][i][j] += sum[3][i][j+1] * LightPow(deltaY,baseB1,baseB2);
			sum[3][i][j] -= (((sum[3][i+1][j+1] * LightPow(deltaX,baseA1,baseA2)) % MOD) * LightPow(deltaY,baseB1,baseB2)) % MOD;
			sum[3][i][j] = (sum[3][i][j] + MOD) % MOD;
			j--;if(j < 0)break;
			
			deltaX = vecX[i+1] - vecX[i],deltaY = vecY[j+1] - vecY[j];
			sum[3][i][j] = newh[i][j];
			sum[3][i][j] += sum[3][i+1][j] * LightPow(deltaX,baseA1,baseA2);
			sum[3][i][j] += sum[3][i][j+1] * LightPow(deltaY,baseB1,baseB2);
			sum[3][i][j] -= (((sum[3][i+1][j+1] * LightPow(deltaX,baseA1,baseA2)) % MOD) * LightPow(deltaY,baseB1,baseB2)) % MOD;
			sum[3][i][j] = (sum[3][i][j] + MOD) % MOD;
			j--;if(j < 0)break;
			
			deltaX = vecX[i+1] - vecX[i],deltaY = vecY[j+1] - vecY[j];
			sum[3][i][j] = newh[i][j];
			sum[3][i][j] += sum[3][i+1][j] * LightPow(deltaX,baseA1,baseA2);
			sum[3][i][j] += sum[3][i][j+1] * LightPow(deltaY,baseB1,baseB2);
			sum[3][i][j] -= (((sum[3][i+1][j+1] * LightPow(deltaX,baseA1,baseA2)) % MOD) * LightPow(deltaY,baseB1,baseB2)) % MOD;
			sum[3][i][j] = (sum[3][i][j] + MOD) % MOD;
			j--;if(j < 0)break;
			
			deltaX = vecX[i+1] - vecX[i],deltaY = vecY[j+1] - vecY[j];
			sum[3][i][j] = newh[i][j];
			sum[3][i][j] += sum[3][i+1][j] * LightPow(deltaX,baseA1,baseA2);
			sum[3][i][j] += sum[3][i][j+1] * LightPow(deltaY,baseB1,baseB2);
			sum[3][i][j] -= (((sum[3][i+1][j+1] * LightPow(deltaX,baseA1,baseA2)) % MOD) * LightPow(deltaY,baseB1,baseB2)) % MOD;
			sum[3][i][j] = (sum[3][i][j] + MOD) % MOD;
			j--;if(j < 0)break;
		}
	}
	for(int i = 1;i <= q;i++){
		OX = Read(),OY = Read();
		int newx = upper_bound(vecX.begin(),vecX.end(),OX) - vecX.begin() - 1;
		int newy = upper_bound(vecY.begin(),vecY.end(),OY) - vecY.begin() - 1;
		ll ans = 0;
		ans += (((sum[0][newx][newy] * LightPow(OX - vecX[newx],baseA1,baseA2)) % MOD) * LightPow(OY-vecY[newy],baseB1,baseB2)) % MOD;
		ans += (((sum[1][newx][newy+1] * LightPow(OX - vecX[newx],baseA1,baseA2)) % MOD) * LightPow(vecY[newy+1]-OY,baseB1,baseB2)) % MOD;
		ans += (((sum[2][newx+1][newy] * LightPow(vecX[newx+1] - OX,baseA1,baseA2)) % MOD) * LightPow(OY-vecY[newy],baseB1,baseB2)) % MOD;
		ans += (((sum[3][newx+1][newy+1] * LightPow(vecX[newx+1] - OX,baseA1,baseA2)) % MOD) * LightPow(vecY[newy+1]-OY,baseB1,baseB2)) % MOD;
		ans %= MOD;
		cout<<ans<<'\n';
	}
	return not(Akano loves pure__Elysia);
}
