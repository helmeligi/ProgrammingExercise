//============================================================================
// Name        : Add_Two_Numbers.cpp
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
#include <list>
//https://leetcode.com/problems/add-two-numbers/description/
using namespace std;

struct ListNode {
     unsigned int val;
     ListNode *next;
     ListNode(unsigned int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* it1 = l1;
	ListNode* it2 = l2;
	ListNode* sum = new ListNode(0);
	ListNode* it = sum;
	unsigned int qot = 0;
	unsigned int rem = 0;
	unsigned int el1,el2;
	while((it1 != nullptr) || (it2 != nullptr)){

		if(it1 == nullptr){
			el1 = 0;
		}
		else{
			el1 = it1->val;
			it1 = it1->next;
		}

		if(it2 == nullptr){
			el2 = 0;
		}
		else{
			el2 = it2->val;
			it2 = it2->next;
		}

		qot = (el1) + (el2) + qot;


		rem = qot%10;
		qot = qot/10;

		it->next = new  ListNode(rem);
		it = it->next;



	}

	if(qot > 0)
		it->next = new  ListNode(qot);

	return sum->next;

}

int main()
{

	{
		ListNode a1(2);
		ListNode a2(4);
		a1.next = &a2;
		ListNode a3(3);
		a2.next = &a3;



		ListNode b1(5);
		ListNode b2(6);
		b1.next = &b2;
		ListNode b3(4);
		b2.next = &b3;

		ListNode* s = addTwoNumbers(&a1,&b1);

		ListNode* it = s;
		while(it != nullptr){
			cout<<it->val<<endl;
			it = it->next;
		}

		while(it != nullptr){
			ListNode* temp = it;
			it = it->next;
			delete temp;
		}
	}
	cout<<"-----------------------"<<endl;
	{
		ListNode a1(0);
		ListNode b1(0);
		ListNode* s = addTwoNumbers(&a1,&b1);
		ListNode* it = s;
		while(it != nullptr){
				cout<<it->val<<endl;
				it = it->next;
			}
		while(it != nullptr){
			ListNode* temp = it;
			it = it->next;
			delete temp;
		}
	}
	cout<<"-----------------------"<<endl;
	{
		ListNode a1(9);


		ListNode b1(1);
		ListNode b2(9);
		b1.next = &b2;
		ListNode b3(9);
		b2.next = &b3;
		ListNode b4(9);
		b3.next = &b4;
		ListNode b5(9);
		b4.next = &b5;
		ListNode b6(9);
		b5.next = &b6;
		ListNode b7(9);
		b6.next = &b7;
		ListNode b8(9);
		b7.next = &b8;
		ListNode b9(9);
		b8.next = &b9;
		ListNode b10(9);
		b9.next = &b10;
		ListNode* s = addTwoNumbers(&a1,&b1);
		ListNode* it = s;
		while(it != nullptr){
			cout<<it->val<<endl;
			it = it->next;
		}
		while(it != nullptr){
			ListNode* temp = it;
			it = it->next;
			delete temp;
		}
	}

	return 0;
}
