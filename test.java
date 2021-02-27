
import java.util.*;



class test {
  public static void main(String[] args) {
    Stack<Integer> s;
    Deque<Integer> q;

    s = new Stack<>();
    q = new ArrayDeque<>();

    q.addLast(Integer.valueOf(1));
    q.addLast(Integer.valueOf(2));
    q.addLast(Integer.valueOf(3));
 
    System.out.println(q.removeFirst());
    System.out.println(q.poll());

    System.out.println(q.peek());
    System.out.println(q.remove());
  
    System.out.println(q.peek());
  }
}