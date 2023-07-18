#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {
	// Write your code here.
	if(n==0) return 1;
    //x%=m;
    long long res = 1;
    while (n > 0) {
        if (n & 1)
            res = (1LL*res * x)%m;
        x = (1LL*x * x)%m;
        n >>= 1;
    }
    return res;
}
