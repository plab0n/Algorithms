#include <bits/stdc++.h>
using namespace std;

int main()
{
    int factorialDigitExtended ( int n, int base ) {
    double x = 0;
    for ( int i = 1; i <= n; i++ ) {
        x += log10 ( i ) / log10(base); ///Base Conversion
    }
    int res = ( (int) x ) + 1;
    return res;
}
}
