// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

#include "sharpify.h"
#include<vector>
#include<iostream>
//#include <algorithm>
using namespace std;

int main()
{
	//vector<int> numbers = vector<int>();
	//numbers.where(NULL);



	vector<int> numbers = vector<int>{ 1,2,3,4,5,6 };

	cout << "'Where' example:" << endl;
	numbers.where([](int num) {return num > 3; })
		   .forEach([](int num) {cout << num << endl; });
	
	cout << "========================================" << endl;

	cout << "'Aggregate' example:" << endl;
	int sum = numbers.aggregate([](int num, int sum) {return num + sum; });
	cout << sum << endl;
	
	cout << "========================================" << endl;

	cout << "'All' example:" << endl;
	bool all = numbers.all([](int num) {return num > 0; });
	cout << all << endl;

	cout << "========================================" << endl;

	cout << "'Any' example:" << endl;
	bool any = numbers.any([](int num) {return num % 2 == 0; });
	cout << any << endl;

	cout << "========================================" << endl;

	cout << "'Concat' example:" << endl;
	vector<int>{ 6, 7, 8, 9 }
	.concat(numbers)
		.forEach([](int num) {cout << num << endl; });

	cout << "========================================" << endl;

	cout << "'Contains' example:" << endl;
	bool contains = vector<int>{ 6, 7, 8, 9 }
	.contains(8);

	cout << contains << endl;

	cout << "========================================" << endl;

	cout << "'Count' example:" << endl;
	cout << vector<int>{ 6, 7, 8, 9, 10, 11}.count([](int num) {return num % 2 == 0; }) << endl;

	cout << "========================================" << endl;

	string s = string("shhadi");
	bool start = s.startsWith("shh");
	cout << start << endl;

	cout << "========================================" << endl;

	s = string("shhadi");
	bool end = s.endsWith("di");
	cout << end << endl;

	cout << "========================================" << endl;

}
