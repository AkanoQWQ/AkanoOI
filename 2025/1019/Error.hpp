#include <cmath>

namespace Error{

struct ErrorOperator{
	enum Identity{
		ErrorEndl = 1,
		ErrorPrecision = 2,
	};
	Identity identity;
	int value;
	ErrorOperator(Identity _identity,int _value){
		identity = _identity;
		value = _value;
	}
};
ErrorOperator errl = ErrorOperator(ErrorOperator::ErrorEndl,0);
ErrorOperator errp(int _precision){
	return ErrorOperator(ErrorOperator::ErrorPrecision,_precision);
}

class Error{
private:
	constexpr static int BUFFER_SIZE = 2048;
	constexpr static int ValueBufferSize = 64;
	constexpr static float EPS = 1e-5;
	int errorPrecision = 7;
	char errorBuffer[BUFFER_SIZE];
	char valBuffer[ValueBufferSize];
	int bufferTail = 0;
	//如果无法过编译，注释掉inline
	inline void Append(const char& ch){
		errorBuffer[bufferTail++] = ch;
		return ;
	}
public:
	void Pushback(const char* str){
		int tail = 0;
		while(str[tail] && bufferTail < BUFFER_SIZE){
			Append(str[tail]);
			tail++;
		}
		return ;
	}
	void Pushback(int intval){
		if(intval < 0){
			intval = -intval;
			Append('-');
		}
		int tail = 0;
		while(intval){
			valBuffer[tail] = (intval % 10) + '0';
			tail++;
			intval /= 10;
		}
		for(int i = tail - 1;i >= 0;i--){
			Append(valBuffer[i]);
		}
		return ;
	}
	void Pushback(float floatVal){
		//处理特殊情况
		if(std::isnan(floatVal))return Pushback("nan");
		if(std::isinf(floatVal))return Pushback(floatVal > 0 ? "inf" : "-inf");

		//处理负数
		if(floatVal < 0){
			Append('-');
			floatVal = -floatVal;
		}
		
		//提取整数部分
		int integerPart = static_cast<int>(floatVal);
		float fractionalPart = floatVal - integerPart;
		
		//转换整数部分并添加小数点
		Pushback(integerPart);
		Append('.');
		
		//转换小数部分
		for(int i = 0; i < errorPrecision;i++){
			fractionalPart *= 10;
			int digit = static_cast<int>(fractionalPart);
			Append('0' + digit);
			fractionalPart -= digit;
			
			// 如果小数部分为0，提前结束
			if(std::abs(fractionalPart) < EPS)break;
		}
		return ;
	}
	void Pushback(ErrorOperator errOperator){
		if(errOperator.identity == ErrorOperator::ErrorEndl){
			Append('\n');
		}else if(errOperator.identity == ErrorOperator::ErrorPrecision){
			errorPrecision = errOperator.value;
		}
		return ;
	}
	
	template<typename T>
	Error& operator<<(const T& val){
		Pushback(val);
		return *this;
	}
#ifdef IOSTREAM_DEBUG
	void DEBUG_output(){
		int tail = 0;
		while(errorBuffer[tail]){
			std::cout<<errorBuffer[tail];
			tail++;
		}
		return ;
	}
#endif
};
Error errorHandler;
	
}
