#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <math.h>
using namespace std;


//https://leetcode.com/problems/longest-palindromic-substring/
string longestPalindrome(string s) {
	//cout<<s;
	unordered_map< char,vector<size_t>> lut;
	vector<char> order;

	for(size_t i=0;i<s.length();i++){
		if(lut.count( s[i] ) ==0)
			order.push_back(s[i]);
		lut[s[i]].push_back(i);
	}


	int maxLength =0;
	int maxIndexStart =0;
	//int maxIndexEnd =0;

	for(auto itr : order){
		for(int i=0;i<(int)(lut[itr].size());i++){
			for(int j=((lut[itr].size())-1);j>i;j--){

				int len = (lut[itr][j]-lut[itr][i]);
				if(len <= maxLength)
					break;

				int startIndex = lut[itr][i];
				int endIndex = lut[itr][j];
				int count=0;
				bool match = true;
				len /= 2;
				while((count++)<=(len)){
//					cout<<"count="<<count<<endl;
//					cout<<startIndex<<" "<<endIndex<<endl;
//					cout<<s[startIndex]<<" "<<s[endIndex]<<endl;
					if(s[startIndex++] != s[endIndex--]){
						match = false;
						break;
					}
				}

				if(match == true){
					maxLength =lut[itr][j] - lut[itr][i];
					maxIndexStart =lut[itr][i];
					//maxIndexEnd =lut[itr][j];
				}
			}
		}
	}

	//cout<<maxIndexStart<<" "<<maxIndexEnd<<endl;

	return s.substr(maxIndexStart,maxLength+1);
}


int main() {

	cout<<"match="<<longestPalindrome("abccba")<<endl;
	cout<<"-------------------------------------"<<endl;
	cout<<"match="<<longestPalindrome("mmabccba")<<endl;
	cout<<"-------------------------------------"<<endl;
	cout<<"match="<<longestPalindrome("babad")<<endl;
	cout<<"-------------------------------------"<<endl;
	cout<<"match="<<longestPalindrome("cbbd")<<endl;

	cout<<"-------------------------------------"<<endl;
	cout<<"match="<<longestPalindrome("aaabaaaa")<<endl;



return 0;
}
