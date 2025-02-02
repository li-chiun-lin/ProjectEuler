/*
5%

<p>Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with $1$ and $2$, the first $10$ terms will be:
$$1, 2, 3, 5, 8, 13, 21, 34, 55, 89, \dots$$</p>
<p>By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.</p>
*/

#include <cstdlib>
#include <iostream>

using namespace std;

int euler()
{
    int f1 = 1;
    int fn1 = 1;
    int fn = 2;
    int sum = 0;
    long long ret = sum;

    while (fn < 4000000)
    {
        sum += fn;
        fn1 = fn;
        fn = sum * 4 - fn1 + 2;

        ret += sum;

        cout << fn << endl;
    }

	return sum;
}

int main()
{
	cout << euler() << endl;

	return 0;
}
