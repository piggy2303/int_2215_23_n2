#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // cout << "Hello World!" << endl;

    // int a, b, c;

    // cin >> a >> b >> c;

    // int sum = a + b + c;

    // cout << "Sum = " << sum << endl;

    int a;
    long b;
    char c;
    float d;
    double e;

    cin >> a >> b >> c >> d >> e;

    cout << a << endl
         << b << endl
         << c << endl
         << fixed << setprecision(3) << d << endl
         << fixed << setprecision(9) << e << endl;

    return 0;
}