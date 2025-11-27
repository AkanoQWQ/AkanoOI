#pragma once
#include<bits/stdc++.h>
using namespace std;
struct SaveImage{
	int x,y;
	string content;
	SaveImage() = default;
	SaveImage(int _x,int _y,const string& _content){
		x = _x,y = _y,content = _content;
		return ;
	}
};
namespace ADB{
	const vector<string> names = {
		"Norii",
		"Nafuu",
		"Ilana",
		"Miffiice"
	};
	const vector<string> GCC_PATH = {
		"\"C:\\Program Files (x86)\\Dev-Cpp\\MinGW64\\bin\\g++.exe\"",
		"\"D:\\Dev-Cpp\\MinGW64\\bin\\g++.exe\""
	};
	SaveImage CgalLogo = SaveImage(
		6,38, 
		"   _____    _____              _      "
		"  / ____|  / ____|     /\\     | |     "
		" | |      | |  __     /  \\    | |     "
		" | |      | | |_ |   / /\\ \\   | |     "
		" | |____  | |__| |  / ____ \\  | |____ "
		"  \\_____|  \\_____| /_/    \\_\\ |______|"
		"                                      "
		
		/*origin version  需要取消注释不然会斜体 
		   _____    _____              _      
		  / ____|  / ____|     /\     | |     
		 | |      | |  __     /  \    | |     
		 | |      | | |_ |   / /\ \   | |     
		 | |____  | |__| |  / ____ \  | |____ 
		  \_____|  \_____| /_/    \_\ |______|            
		*/ 
	);
	SaveImage LinuxLogo = SaveImage(
		16,23,
		"         _nnnn_        "
		"        dGGGGMMb       "
		"       @p~qp~~qMb      "
		"       M|@||@) M|      "
		"       @,----.JM|      "
		"      JS^\\__/  qKL     "
		"     dZP        qKRb   "
		"    dZP          qKKb  "
		"   fZP            SMMb "
		"   HZM            MMMM "
		"   FqM            MMMM "
		" __| \".        |\\dS\"qML"
		" |    `.       | `' \\Zq"
		"_)      \\.___.,|     .'"
		"\\____   )MMMMMP|   .'  "
		"     `-'       `--' hjm"
		
		/*origin version  需要取消注释不然会斜体 
		         _nnnn_        
		        dGGGGMMb       
		       @p~qp~~qMb      
		       M|@||@) M|      
		       @,----.JM|      
		      JS^\\__/  qKL     
		     dZP        qKRb   
		    dZP          qKKb  
		   fZP            SMMb 
		   HZM            MMMM 
		   FqM            MMMM 
		 __| ".        |\dS"qML
		 |    `.       | `' \Zq
		_)      \.___.,|     .'
		\____   )MMMMMP|   .'  
		     `-'       `--' hjm"        
		*/ 
	);
}
