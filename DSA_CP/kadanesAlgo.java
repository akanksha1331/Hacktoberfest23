/*
   Kadane's algorithm is a dynamic programming algorithm used to find the maximum sum of a contiguous subarray within a one-dimensional array of numbers
 */
 import java.util.Scanner;

 public class kadanesAlgo {

 public static int kadanes(int numbers[]){
     int maximumSum = Integer.MIN_VALUE;  
     int currentSum = 0;  

     for(int i = 0; i < numbers.length; i++){
         currentSum = currentSum + numbers[i];
         if(currentSum < 0){
            currentSum = 0;
         }
         maximumSum = Math.max(currentSum ,maximumSum);
     }
     return maximumSum;
 }

 public static void main(String args[]){
     Scanner sc = new Scanner(System.in);

     int numbers[] = {-2, -3, 4, -1, -2, 1, 5, -3};

     int maxSum = kadanes(numbers);
     System.out.println("Maximum Sum of Sub-Array is : " + maxSum);


     sc.close();
 }
 }
