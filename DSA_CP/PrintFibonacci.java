class Hactober {
    public static int printNFibonacciNumbers(int n)
    {
        if (n <= 1)return n;
        return printNFibonacciNumbers(n - 1) + printNFibonacciNumbers(n - 2);
    }
    // Tabulation method for Fibonacci Numbers
    // Time complexity O(n)
    public static void fibTabulationDP(int n){
        int[] ar = new int[n+3];
 
        ar[0] = 0;
        ar[1] = 1;
        System.out.print(ar[0]+" "+ar[1]+" ");
        for (int i=2;i<=n;i++){
            ar[i] = ar[i-1] + ar[i-2];
            System.out.print(ar[i] + " ");
        }
        
    }
    
    public static void main(String args[])
    {
        int n = 10;
        for (int i = 0; i < n; i++) {
            System.out.print(printNFibonacciNumbers(i) + " ");
        }

        System.out.println("\n");
        fibTabulationDP(20);
        
    }
}
