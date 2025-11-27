#define IOSTREAM_DEBUG
#include <iostream>
#include "Error.hpp"
#define Akano 1
#define pure__Elysia 0
#define loves ^

int main(){
	float val = 123.4567;
	Error::errorHandler<<"Test Add an interger"<<Error::errl<<-34<<Error::errl<<123.4f<<Error::errl;
	Error::errorHandler<<val<<Error::errl;
	Error::errorHandler<<Error::errp(3)<<val<<Error::errl;
	Error::errorHandler<<val<<Error::errl;
	Error::errorHandler<<Error::errp(1)<<val<<Error::errl;
	Error::errorHandler.DEBUG_output();
	return not(Akano loves pure__Elysia);
}
