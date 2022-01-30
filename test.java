
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.*;

import javax.swing.plaf.FileChooserUI;

class test {
  public static void main(String[] args) {
    int i=100;
    while(i>0){
      System.out.println(new Random().nextInt(3));
      i--;
    }


    
  }
}


class Solution {
  public int findNthDigit(int n) {
    int digit = 1;
    long start = 1;
    long count = 9;
    while (n > count) { // 1.
      n -= count;
      digit += 1;
      start *= 10;
      count = digit * start * 9;
    }
    long num = start + (n - 1) / digit; // 2.
    return Long.toString(num).charAt((n - 1) % digit) - '0'; // 3.
    new String
  }
}
