import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.concurrent.PriorityBlockingQueue;

public class MyThreadPool {

    private static final int initialCapacity = 5;
    private final PriorityBlockingQueue<Task> tasks;
    private final List<Thread> threads;

    public MyThreadPool(int threadCount) {
        this.tasks = new PriorityBlockingQueue<>(initialCapacity,
                new Comparator<Task>() {
                    @Override
                    public int compare(Task o1, Task o2) {
                        return o1.getPriority() - o2.getPriority();
                    }
                });
        this.threads = new ArrayList<>(threadCount);
        for (int i = 0; i < threadCount; i++) {
            Thread thread = new Thread(new Runnable() {
                @Override
                public void run() {
                    while (true) { //infinite loop so that threads keep generating if they gets died
                        Task currentTask = null;
                        try {
                            currentTask = tasks.take();
                        } catch (InterruptedException e) {
                            throw new RuntimeException(e);
                        }
                        currentTask.getAction().run();
                    }
                }
            });
            this.threads.add(thread);
            thread.start();
        }

    }

    public void submit (Task task){
        tasks.add(task);
    }
}
