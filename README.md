# Sharpify is a simple library provides powerful features of C# to C++ developers.

Key Features:
1) Collection's LINQ methods: Where / Select / Take and so on.
2) Extension methods.

More features already planned, but not completed yet.

Contributions will be much appreciated!

Example:

#include<vector>
int main()
{
    vector<int> numbers = { 9 , 3 , 7 , 5 , 1 };
    numbers.where( [](num)-> {num>5} );   //numbers: { 9 , 7 }
}


