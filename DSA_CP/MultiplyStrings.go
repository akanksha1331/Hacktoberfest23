// Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

// Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

// Example 1:

// Input: num1 = "2", num2 = "3"
// Output: "6"

// Example 2:

// Input: num1 = "123", num2 = "456"
// Output: "56088"
 

// Constraints:

// 1 <= num1.length, num2.length <= 200
// num1 and num2 consist of digits only.
// Both num1 and num2 do not contain any leading zero, except the number 0 itself.

func multiply(num1 string, num2 string) string {
    if num1 == "0" || num2 == "0" {
        return "0"
    }
    
    l1, l2 := len(num1), len(num2)
    res := make([]byte, l1+l2)
    
    for i := l1 - 1; i >= 0; i-- {
        carry := byte(0)
        n1 := num1[i] - '0'
        
        for j := l2 - 1; j >= 0; j-- {
            n2 := num2[j] - '0'
            product := n1 * n2 + res[i+j+1] + carry
            carry = product / 10
            res[i+j+1] = product % 10
        }
        
        res[i] += carry
    }
    
    if res[0] == 0 {
        res = res[1:]
    }
    
    for i := range res {
        res[i] += '0'
    }
    
    return string(res)
}
