/*
comp.h
inline void PreCompile(const string name){//预先编译data,std,code三个exe 
	CreateDirectory(pre_file.c_str(),NULL);
	Compile(name+".cpp",pre_file + code_name);
	Compile(name+"_std.cpp",pre_file + std_name);
	Compile(name+"_data.cpp",pre_file + data_name);
	return ;
}

comp.h
inline long long Run(){//执行data,std,code三个exe 
	long long result = 0;
	IO::Write(pre_file + in_name);
	result |= Execute(pre_file + data_name).first;//data
	IO::Open(pre_file + in_name);
	IO::Write(pre_file + out_name);
	result |= Execute(pre_file + code_name).first;//main
	IO::Open(pre_file + in_name);
	IO::Write(pre_file + ans_name);
	result |= Execute(pre_file + std_name).first;//std
	IO::Open("CON");
	IO::Write("CON");
	return result;
}

comp.h
inline pair<int,vector<string> > Compare(auto _ouf[],auto _ans[],int comp_length){//比较两数组内容 
	pair<int,vector<string> > ret;
	//注:GetLength函数貌似有误,详情见basic.h
	//该段代码已废弃 
//	int len = min(GetLength(_ouf),GetLength(_ans));
//	if(len < comp_length){
//		cout<<"WARNING : Your compArray is too short!"<<endl;
//	}
//	comp_length = min(comp_length,len);
	for(int i = 0;i <= comp_length;i++){
		if(_ouf[i] != _ans[i]){
			++ret.first;
			string errInf = "In the "+TransToString(i);
			errInf += " element,read " + TransToString(_ouf[i]);
			errInf += " but expected "+ TransToString(_ans[i]);
			ret.second.push_back(errInf);
		}
	}
	return ret;
}

comp.h
inline void Delete(){//删除data,std,code三个文件 
	DeleteFile((pre_file + code_name).c_str());
	DeleteFile((pre_file + std_name).c_str());
	DeleteFile((pre_file + data_name).c_str());
	DeleteFile((pre_file + in_name).c_str());
	DeleteFile((pre_file + out_name).c_str());
	DeleteFile((pre_file + ans_name).c_str());
	RemoveDirectory(pre_file.c_str());
	return ;
}
*/
