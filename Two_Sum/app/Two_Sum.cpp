//============================================================================
// Name        : Two_Sum.cpp
// Author      : helmelig
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

//https://leetcode.com/problems/two-sum/description/
vector<int> twoSum(vector<int>& nums, int target)
{
	const vector<int> originalNums = nums;

	bool negativeOperation = false;

	if(target <0){
		target *= -1;
		for( auto& i: nums )
		    i *= -1;
		negativeOperation= true;
	}

	//Lesson Learned! Working on sorted data will improve your efficiency significantly specially when you will do a lot of search on the data afterwards.
	std::sort(nums.begin(), nums.end());

	int targetPair1,targetPair2;
	for(auto testVal:nums){
		targetPair1 = testVal;
		targetPair2 = target - targetPair1;

		auto it = find (nums.begin(),nums.end(), targetPair2);
		if (it != nums.end())
		 break;
	}

	if(negativeOperation){
		targetPair1 *= -1;
		targetPair2 *= -1;
	}

	auto startIt =  find (originalNums.begin(), originalNums.end(), targetPair1);
	int pos1 =startIt - originalNums.begin();
	int pos2 = find (originalNums.begin(), originalNums.end(), targetPair2) - originalNums.begin();

	if(pos1 == pos2)
		pos1 = find (startIt+1, originalNums.end(), targetPair2) - originalNums.begin();

	vector<int> indices;
	indices.push_back(pos1);
	indices.push_back(pos2);

	return indices;
}

int main()
{
	 high_resolution_clock::time_point t1 = high_resolution_clock::now();



	for(int i=0;i<10000;i++){

	{
		vector<int> v = {3,3};
		int target = 6;
		vector<int> indices = twoSum(v, target);
		cout<<"------------------------------------------"<<endl;
		cout<<indices[0]<<"+"<<indices[1]<<"="<<target<<endl;
		cout<<v[indices[0]]<<"+"<<v[indices[1]]<<"="<<target<<endl;
		cout<<"------------------------------------------"<<endl;
		}

		{
		vector<int> v = {2,7,11,15};
		int target = 9;
		vector<int> indices = twoSum(v, target);
		cout<<"------------------------------------------"<<endl;
		cout<<indices[0]<<"+"<<indices[1]<<"="<<target<<endl;
		cout<<v[indices[0]]<<"+"<<v[indices[1]]<<"="<<target<<endl;
		cout<<"------------------------------------------"<<endl;
		}

		{
			vector<int> v = {-3,4,3,90};
			int target = 0;
			vector<int> indices = twoSum(v, target);
			cout<<"------------------------------------------"<<endl;
			cout<<indices[0]<<"+"<<indices[1]<<"="<<target<<endl;
			cout<<v[indices[0]]<<"+"<<v[indices[1]]<<"="<<target<<endl;
			cout<<"------------------------------------------"<<endl;
		}

		{
			vector<int> v = {-1,-2,-3,-4,-5};
			int target = -8;
			vector<int> indices = twoSum(v, target);
			cout<<"------------------------------------------"<<endl;
			cout<<indices[0]<<"+"<<indices[1]<<"="<<target<<endl;
			cout<<v[indices[0]]<<"+"<<v[indices[1]]<<"="<<target<<endl;
			cout<<"------------------------------------------"<<endl;
		}

		{
			vector<int> v = {3,2,4};
			int target = 6;
			vector<int> indices = twoSum(v, target);
			cout<<"------------------------------------------"<<endl;
			cout<<indices[0]<<"+"<<indices[1]<<"="<<target<<endl;
			cout<<v[indices[0]]<<"+"<<v[indices[1]]<<"="<<target<<endl;
			cout<<"------------------------------------------"<<endl;
		}



		{
			vector<int> v = {230,863,916,585,981,404,316,785,88,12,70,435,384,778,887,755,740,337,86,92,325,422,815,650,920,125,277,336,221,847,168,23,677,61,400,136,874,363,394,199,863,997,794,587,124,321,212,957,764,173,314,422,927,783,930,282,306,506,44,926,691,568,68,730,933,737,531,180,414,751,28,546,60,371,493,370,527,387,43,541,13,457,328,227,652,365,430,803,59,858,538,427,583,368,375,173,809,896,370,789};
			int target = 542;
			vector<int> indices = twoSum(v, target);
			cout<<"------------------------------------------"<<endl;
			cout<<indices[0]<<"+"<<indices[1]<<"="<<target<<endl;
			cout<<v[indices[0]]<<"+"<<v[indices[1]]<<"="<<target<<endl;
			cout<<"------------------------------------------"<<endl;
		}
	}

	   high_resolution_clock::time_point t2 = high_resolution_clock::now();
	   auto duration = duration_cast<microseconds>( t2 - t1 ).count();
	   cout << duration;

	return 0;
}
