# Sharpify is a library provides powerful features of C# to C++ developers.

Key Features:
1) Collection's LINQ methods: where / forEach / aggregate / all / any / concat , and more.
2) String class methods: startsWith / endsWith / insertAt / toLower / toUpper ,  and more.
3) Extension methods (not implemented yet)

More features already planned, but not completed yet.

**Contributions will be much appreciated!**

Example:

`vector<int> numbers = { -1 , 2 , -5 , -6 , 9 };`

`vector<int> positiveNumbers = numbers.where([](int num) {return num>0; })         //oddNumbers: { 2 , 9 }`
