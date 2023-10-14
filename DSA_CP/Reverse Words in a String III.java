class Solution {
    public static String reverseWords(String s) {
        String[] arr = s.split(" ");
        String res = "";
        for(String str:arr){
            res += reverse(str) + " ";
        }
        return res.substring(0,res.length()-1);
    }
    public static String reverse(String str){
        String temp = "";
        for(int i = 0;i < str.length();i++){
            temp = str.charAt(i) + temp;
        }
        return temp;
    }
    public static void main(String[] args){
        String str = "Welcome to Hactober World!!";
        System.out.println(reverseWords(str));
    }
}
