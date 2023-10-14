// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

// Example 1:

// Input: x = 123
// Output: 321
// Example 2:

// Input: x = -123
// Output: -321
// Example 3:

// Input: x = 120
// Output: 21

func reverse(x int) int {
	res, a := 0, 0
	 for x != 0 {
 
		 x, a = divideBy10(x)
		 res = res*10 + a
	 }
	 if res < -2147483648 || res > 2147483648 {
		 return 0
	 }
	 return res
 }
 
 func divideBy10(x int) (int, int) {
	 return x / 10, x % 10
 }
