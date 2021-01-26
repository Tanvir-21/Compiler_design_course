//
//  main.cpp
//  factorial
//
//  Created by MD Tanvir Anjum on 26/1/21.
//  Copyright © 2021 Smart Lab. All rights reserved.
//

#include <iostream>
using namespace std;

//function to find factorial of given number
unsigned int factorial(unsigned int n)
{
    int rest = 1, i;
    for(i=2; i<=n; i++)
        rest *= i;
    return rest;
}

//Driver code
int main() {
    int num = 5;
    cout << "Factorial of " << num << " is " << factorial(num) << endl;
    return 0;
}
