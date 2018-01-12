//============================================================================
// Name        : ZigZag_Conversion.cpp
// Author      : helmeligi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;


//https://leetcode.com/problems/zigzag-conversion/
string convert(string s, int numRows) {
//	cout<<"Input-->"<<s<<endl;
//	cout<<"Output-->"<<"PAHNAPLSIIGYIR"<<endl;
		vector<char> arr[numRows];



		int rowNum = 0;
		int offset = 1;
		for(unsigned int i=0;i<s.length();i++){
			arr[rowNum].push_back(s[i]);

			if(rowNum == (numRows-1))
				offset = -1;
			else if(rowNum == 0)
				offset = 1;

			rowNum += offset;

			if(rowNum <0)
				rowNum = 0;

		}

		string result;
		for(int i=0;i<numRows;i++){
			std::string str(arr[i].begin(), arr[i].end());
			//cout<<str<<endl;
			result+= str;
		}
//
		cout<<result;
		return "";
}


string convert_c(string s, int numRows) {
//	cout<<"Input-->"<<s<<endl;
//	cout<<"Output-->"<<"PAHNAPLSIIGYIR"<<endl;
		char* arr[numRows];
		int indices[numRows];

		for(int i=0;i<numRows;i++){
			arr[i] = new char[s.length()];
			indices[i] = 0;
		}


		int index =0;
		int rowNum = 0;
		int offset = 1;
		for(unsigned int i=0;i<s.length();i++){
			index = indices[rowNum];
			arr[rowNum][index] = s[i];

//			cout <<"rowNum="<< rowNum<<endl;
//			cout <<"Index="<< index<<endl;
//			cout<< "s[i]=" <<s[i]<<endl;
//
//
//			cout<<"--------------------"<<endl;

			(indices[rowNum])++;

			if(rowNum == (numRows-1))
				offset = -1;
			else if(rowNum == 0)
				offset = 1;

			rowNum += offset;

			if(rowNum <0)
				rowNum = 0;

		}

		string result;
		for(int i=0;i<numRows;i++){
			index = indices[i];
			arr[i][index] = '\0';
//			cout<<arr[i]<<endl;
			result+= arr[i];
		}
//
//		cout<<result<<endl;
		return result;
}


int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	convert("PAYPALISHIRING", 3);
	//convert("AB", 1);
	return 0;
}
