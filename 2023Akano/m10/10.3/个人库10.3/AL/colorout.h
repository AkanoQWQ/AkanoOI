#pragma once
#include<bits/stdc++.h>
#include "basic.h"
#include "DB.h"
#include "error.h"
using namespace std;
class KolorOutputEndlFlag{
	
}kend;
class KolorOutput{
	private:
		inline int TryKolor(const string& str,int pos){
			using namespace ADB::kolorName;
			for(int i = 1;i < int(kolors.size());i++){
				if(str.length() - pos >= kolors[i].length()){
					string subs = str.substr(pos,kolors[i].length());
					if(subs == kolors[i])return i;
				}
			}
			for(int i = 1;i < int(kolorsf.size());i++){
				if(str.length() - pos >= kolorsf[i].length()){
					string subs = str.substr(pos,kolorsf[i].length());
					if(subs == kolorsf[i])return -i;
				}
			}
			return 0;
		}
		inline void Output(const string& str){
			if(ios::sync_with_stdio() == false){
				Error::PE("colorout.h","发现关闭流同步,会导致色彩无法正确输出,已被解决");
			}
			using namespace ADB::kolorName;
			int len = str.length() - 1;
			for(int i = 0;i <= len;i++){
				int tryKolor = TryKolor(str,i);
				if(tryKolor > 0){
					if(ios::sync_with_stdio() == false){
						cout<<flush;//先尝试把当前的输出
					}
					SetColor(kolorName[tryKolor]);
					i += kolors[tryKolor].length() - 1;
					continue;
				}else if(tryKolor < 0){
					if(ios::sync_with_stdio() == false){
						cout<<flush;//先尝试把当前的输出
					}
					SetColor("white");
					i += kolorsf[-tryKolor].length() - 1;
					continue;
				}
				cout<<str[i];
			}
			return ;
		}
	public:
		KolorOutput& operator<<(KolorOutputEndlFlag flag){
			cout<<endl;
			return *this;
		}
		KolorOutput& operator<<(const char* t){
			Output(t);
			return *this;
		}
		KolorOutput& operator<<(const string& t){
			Output(t);
			return *this;
		}
		template<typename T>
		KolorOutput& operator<<(T t){
			cout<<t;//可以直接输出,因为不可能包含标签了
			return *this;
		}
}kout;
