/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:
Input: height = [4,2,0,3,2,5]
Output: 9
*/
//Solution
class Trapping_Rainwater {
    public int trap(int[] height) {
        int l=0;
        int maxl=height[l]; 
        int r=height.length-1;
        int maxr=height[r];
        int totalwater=0; 
        while(l<=r){
            if(maxl<=maxr){
                int water=maxl-height[l];
                if(water>0){
                    totalwater+=water;
                }
                maxl=Math.max(height[l], maxl);
                l++;
            }
            else{
                int water=maxr-height[r];
                if(water>0){
                    totalwater+=water;
                }
                maxr=Math.max(height[r], maxr);
                r--;
            }
           
        }
        return totalwater;
    }
}
