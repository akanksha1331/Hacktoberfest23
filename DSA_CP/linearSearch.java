/*
  Linear Search is defined as a sequential search algorithm that starts at one end and goes through each element of a list until the desired element is found, 
  otherwise the search continues till the end of the data set.

  How Does Linear Search Algorithm Work?
    In Linear Search Algorithm, 

    Every element is considered as a potential match for the key and checked for the same.
    If any element is found equal to the key, the search is successful and the index of that element is returned.
    If no element is found equal to the key, the search yields “No match found”.
    
*/

import java.util.Scanner;

public class linearSearch {

    
    public static int linearSearch(int numbers[], int key){

        for(int i = 0; i < numbers.length; i++){
            if(numbers[i] == key){
                return i;
            }
        }
        return -1;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        int numbers[] = {2,4,6,8,10,12,14,16};
        int key = 10;
        
        int index = linearSearch(numbers, key);
        if(index == -1){
            System.out.println("Not found");
        } else {
            System.out.println("Key is at index : " +  index);
        }

        sc.close();
    }
}
