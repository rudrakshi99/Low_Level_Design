import java.util.List;

public class Worker1 implements Runnable {
    private final List<Integer> nums;
    private final Integer i;

    public Worker1(List<Integer> nums, Integer i) {
        this.nums = nums;
        this.i = i;
    }

    @Override
    public void run() {
        synchronized (nums) {
            if (!nums.contains(i)) {
                for (int i=0;i<1000000;i++){}
                nums.add(i);
            }
        }
        //compound statements
    }
}
