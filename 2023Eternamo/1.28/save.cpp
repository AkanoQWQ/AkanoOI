/*		for(int k = 1;k*line < len;k++){
			if(k*line*2 <= len)continue;
			const int newline = k*line;
			int a = 1,b = 2;
			if(pos <= newline){
				a = pos,b = pos + newline;
			}else{
				a = pos - newline,b = pos;
				if(newline > len - a)puts("ERRRRRRRRRRRRR");
			}
			if(newline > len - a)ans++;
		}*/
		
		//k * line >= pos		k *  >= pos	/ line
//		if(k > (len - pos) / line)ans++;//k*line > len-pos


		//1.k*line < len       k < len / line
		//2.k*line >= pos     k >= pos / line
		//3.k*line > (len-pos)		k > (len-pos)/line
		//4.k >= 1
		/*nt c2 =(pos/line)+1;
		if(pos % line == 0)c2--;
		const int upper = max(c2,1);
		int cache = len/line;
		if(len % line == 0)cache--;
		const int upp = min(((len-pos)/line)+1,cache);*/
	//	cout<<int(ceil((1.0f*pos/line)))<<"!!!"<<endl;
