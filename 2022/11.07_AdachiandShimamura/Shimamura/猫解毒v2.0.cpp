#include<stdlib.h>
using namespace std;
int main(){
	
	system("taskkill /im 猫病毒.exe /f");
	system("taskkill /im \"嘉然的CSP-S 2022 游记.exe\" /f");
	system("taskkill /im *猫*病*毒*.exe /f");
	system("taskkill /im *嘉*然*.exe /f");
	system("taskkill /im 猫* /f");
	return 0;
}

