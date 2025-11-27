#pragma once
#include<bits/stdc++.h>
#include "basic.h"
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
	
	namespace Vars{
		string _string;
		const string _const_string;
		int _int;
		long long _long_long;
		const char* _const_char_p;
		char* _char_p;
	}
	namespace typeName{
		string _string = GetTypename(Vars::_string);
		string _const_string = GetTypename(Vars::_const_string);
		string _int = GetTypename(Vars::_int);
		string _long_long = GetTypename(Vars::_long_long);
		string _const_char_p = GetTypename(Vars::_const_char_p);
		string _char_p = GetTypename(Vars::_char_p);
	}
	namespace kolorName{
		vector<string> kolors = {
			"[nothing]",
			"[red]",
			"[green]",
			"[blue]",
			"[black]",
			"[yellow]",
			"[gray]",
			"[lightwhite]",
		};
		vector<string> kolorsf = {
			"[/nothing]",
			"[/red]",
			"[/green]",
			"[/blue]",
			"[/black]",
			"[/yellow]",
			"[/gray]",
			"[/lightwhite]"
		};
		vector<string> kolorName = {
			"white",
			"lightred",
			"lightgreen",
			"lightblue",
			"black",
			"lightyellow",
			"gray",
			"lightwhite"
		};
	}
}
/**/
