#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
   int a = 1012;
   int b = a;
   int count = 0;

   while (a >0)
   {
        int x = a %10;
        a = a/10;

        if (b % x == 0){
            count++;
        }
   }
   cout << count <<endl;
}



