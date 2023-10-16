#include <bits/stdc++.h>

using namespace std;

#define ll long long

/*
Task:
Find the maximum number, x, such that x squared is less than or equal to n (x*x <= n).
In other words, we need to determine the floor value of the square root of n.
*/

// Time Complexity: O(logn)
// Space Complexity: O(1)
int floorSqrt(int n)
{
    int ans = -1;

    int low = 1;
    int high = n;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        ll val = mid * mid;

        if (val <= n)
        {
            ans = mid;
            low = mid + 1; // Search for larger ans
        }
        else
            high = mid - 1;
    }

    return ans;
}

// Another approach
// Time Complexity: O(logn)
// Space Complexity: O(1)
int floorSqrt2(int n)
{
    int ans = -1;

    int low = 1;
    int high = n;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        ll val = mid * mid;

        if (val == n) // ? Extra
            return mid;
        else if (val < n)
        {
            ans = mid;
            low = mid + 1; // Eliminate left half
        }
        else
            high = mid - 1; // Eliminate right half
    }

    return ans;
}

// Directly using sqrt() function
// Time Complexity: O(logn)
// Space Complexity: O(1)
int floorSqrt3(int n)
{
    int ans = sqrt(n);
    return ans;
}

int main()
{
    int n = 10;

    cout << floorSqrt(n) << endl;  // 3
    cout << floorSqrt2(n) << endl; // 3
    cout << floorSqrt3(n) << endl; // 3

    return 0;
}
