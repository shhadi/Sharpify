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



	vector<int> numbers = vector<int>{ 1,-2,3,-4,5,-6 };

	numbers.where([](int num) {return num > 0; })
		   .forEach([](int num) {cout << num << endl; });


}
