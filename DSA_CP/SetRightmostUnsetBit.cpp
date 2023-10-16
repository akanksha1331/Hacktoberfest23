#include <bits/stdc++.h>

using namespace std;

/*
Problem Statement:
The problem is to find the rightmost bit of a non-negative number
'N'that is currently unset (i.e., has a value of 0) in its binary
representation and set it to 1.

Return the number after setting the rightmost unset bit of 'N'. If
there are no unset bits in N's binary representation, then the
number should remain unchanged.
*/

// Time: O(1)
// Space: O(1)
int setRightmostUnsetBit(int n)
{
    // If all bits are set then return the number itself
    if (!(n & (n + 1)))
        return n;

    return n | (n + 1); // Set the rightmost unset bit
}

int main()
{
    int n = 10;                              // 10 (1010)
    cout << setRightmostUnsetBit(n) << endl; // 11 (1011)
    return 0;
}
