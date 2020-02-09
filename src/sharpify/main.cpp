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


	vector<int> numbers = vector<int>();
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_back(4);
	numbers.push_back(5);
	numbers.push_back(6);

	auto bigNumbers = numbers.where([](int num) {return num > 3; });


}
