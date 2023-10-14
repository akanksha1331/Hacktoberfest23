

import java.util.Arrays;

import static java.util.Collections.swap;
public class quick {
    // creating two classes pivot and quick sort
    public static void main(String[] args) {
        int a[] = {2,1} ;
        quicksort(a , 0 ,1);
        System.out.println(Arrays.toString(a));
    }

    public static void quicksort(int a[],int l,int r) {

        if(l<r)
        {
            int s = part(a,l,r);
            System.out.println(s);
            System.out.println(Arrays.toString(a));
            quicksort( a, l, s-1);
            quicksort(a,s+1,r);
        }


    }
    public static int  part(int a[],int l,int r){
        int p = l ;
        int i = l+1;
        int j = r ;
        while(i<j)
        {
            while(a[p] >=a[i])
                i++;
            while(a[p] <=a[j])
                j--;
            swap(a,i,j);
           // System.out.println(a[i]);
        }

        if(i>j)
        {
            System.out.println(i);
            swap(a,i,j);
            System.out.println(i);
            swap(a,j,p);
        }
            return j;
    }

    private static void swap(int[] a, int i, int j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}
