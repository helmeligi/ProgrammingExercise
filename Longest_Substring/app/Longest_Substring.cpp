//============================================================================
// Name        : Longest_Substring.cpp
// Author      : helmelig
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <set>
using namespace std;


//https://leetcode.com/problems/longest-substring-without-repeating-characters/
int lengthOfLongestSubstring(string s) {

	int currentStringLength = 0;

	 std::unordered_map<char,int> substr;
	 //std::vector<char> insertOrder;
	 int insertOrderIndex = 0;
	 int maxSubstr = 0;
	 int insertOrderStartIndex = 0;
	for (int i=0;i<s.length();i++){
		char newChar = s[i];
		//New element
		//if(substr.find(newChar) == substr.end()){
		if(substr.find(newChar) != substr.end()){
			//find elements before the repeation!
			int cutIndex = substr[newChar]+1;

			//TODO remove this loop and the erase for performance!
			for(int j=insertOrderStartIndex;j<cutIndex;j++){
				//char delChar = insertOrder[j];
				char delChar = s[j];
				substr.erase(delChar);
				currentStringLength--;
			}

			insertOrderStartIndex = cutIndex;
		}

		substr[newChar]= insertOrderIndex;
		//insertOrder.push_back(newChar);
		currentStringLength++;
		insertOrderIndex++;

		if(maxSubstr < currentStringLength){
			maxSubstr = currentStringLength;
		}

//		for(int j=insertOrderStartIndex;j<insertOrder.size();j++){
//		    char c = insertOrder[j];
//		    std::cout << c;
//		}
//
//		std::cout<<endl;
	}
	return maxSubstr;
}

int main() {
	cout << "Longest Substring Without Repeating Characters" << endl; // prints Longest Substring Without Repeating Characters

	cout<<"-------abcabcbb-----------"<<endl;
	cout<<lengthOfLongestSubstring("abcabcbb")<<endl;
	cout<<"--------bbbbb----------"<<endl;
	cout<<lengthOfLongestSubstring("bbbbb")<<endl;
	cout<<"--------pwwkew----------"<<endl;
	cout<<lengthOfLongestSubstring("pwwkew")<<endl;
	cout<<"--------abcdefgh----------"<<endl;
	cout<<lengthOfLongestSubstring("abcdefgh")<<endl;
	cout<<"-------aab-----------"<<endl;
	cout<<lengthOfLongestSubstring("aab")<<endl;
	return 0;
}
