#include "std_lib_facilities.h"

int main()
{
    int i = 1;

    int sz = 0;

    while(i!=0)
    {
        i = i << 1;

        sz++;
    }

    cout << sz << "\n";
}