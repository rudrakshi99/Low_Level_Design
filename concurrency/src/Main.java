import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String[] args) throws InterruptedException {
        //System.out.println(Thread.currentThread().getName());
        //scheduling is non deterministic
//        Thread t1 = new Thread(new MyRunnable("first"));
//        Thread t2 = new Thread(new MyRunnable("second"));
//        Thread t3 = new Thread(new MyRunnable("third"));
//        t1.start();
//        t2.start();
//        t3.start();
//        t1.join();
//        t2.join();
//        t3.join();
//        System.out.println("Bye....");
//        IntStore store = new IntStore(); //shared data
//        Thread t1 = new Thread(new Worker(store));
//        Thread t2 = new Thread(new Worker(store));
//        t1.start();
//        t2.start();
//        t1.join();
//        t2.join();
//        System.out.println(store.getX());
        List<Integer> nums = new ArrayList<>();
        Thread t1 = new Thread(new Worker1(nums, 5));
        Thread t2 = new Thread(new Worker1(nums, 5));
        t1.start();
        t2.start();
        t1.join();
        t2.join();
        System.out.println(nums.size());

    }
}