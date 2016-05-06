#include"yuanf.h"
#include<iostream>
using namespace std;
int main()
{
    double area;
    double r;

    cout << "Please enter the r of the circle:";
    cin >> r;

    area = calculate(r);

    cout << "The area of the circle is: " << area << endl;

    return 0;
}
