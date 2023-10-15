import java.util.Arrays;

public class insertion {
    public static void main(String[] args) {
        int a [] = { 4,3,2,6,7};
        for (int i = 1; i < 4 ; i++) {
            int v =a[i];
            int j = i-1 ;
            while(j>=0 && a[j]>v)
            {
                a[j+1] = a[j];
                j-- ;

            }
            a[j+1] = v ;
        }
        System.out.println(Arrays.toString(a));

    }

}
