/*Given an array of integers, return the indices of the two numbers whose sum is equal to a given target. You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15, 19], target = 13

The output should be [0, 2]. 
Because nums[0] + nums[1] = 2 + 11 = 13 */

import java.util.*;
public class Example {
public static void main(String[] args) {
int[] nums = {2, 7, 11, 15, 19};
int target = 13;
int[] arr = twoSum(nums, target);
for(int i = 0; i < 2; i++) {
System.out.print(arr[i]+" ");
}
}
private static int[] twoSum(int[] nums, int target) {
int[] arr = new int[2];
Map<Integer, Integer> map = new HashMap<Integer,Integer>();
 for(int j = 0; j < nums.length; j++) {
    Integer value = map.get(target - nums[j]);
  if(value == null) { /* no match found */
    map.put(nums[j], j);
   }
else {     /* pair found, updating index */
    arr[0] = value;
    arr[1] = j;
    break; //  loop exit
   }
}
   return arr;
}
}
