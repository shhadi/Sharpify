# Sharpify is a library provides powerful features of C# to C++ developers.

Key Features:
1) Collection's LINQ methods: where / forEach / aggregate / all / any / concat , and more.
2) String class methods: startsWith / endsWith / insertAt / toLower / toUpper ,  and more.
3) Extension methods (not implemented yet)

More features already planned, but not completed yet.

**Contributions will be much appreciated!**

Examples:

`

#include "sharpify.h"

using namespace std;

int main()
{
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






`
