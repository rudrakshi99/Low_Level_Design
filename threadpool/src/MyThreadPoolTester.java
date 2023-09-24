public class MyThreadPoolTester {

    public static void main(String[] args) {
        MyThreadPool pool = new MyThreadPool(5);
        pool.submit(new Task(5, new Runnable() {
            @Override
            public void run() {
                System.out.println(Thread.currentThread().getName() + " I was first Task");
            }
        }));

        pool.submit(new Task(10, new Runnable() {
            @Override
            public void run() {
                System.out.println(Thread.currentThread().getName() + " I was second Task");
            }
        }));

        pool.submit(new Task(2, new Runnable() {
            @Override
            public void run() {
                System.out.println(Thread.currentThread().getName() + " I was third Task");
            }
        }));

        pool.submit(new Task(12, new Runnable() {
            @Override
            public void run() {
                System.out.println(Thread.currentThread().getName() + " I was fourth Task");
            }
        }));

        pool.submit(new Task(15, new Runnable() {
            @Override
            public void run() {
                System.out.println(Thread.currentThread().getName() + " I was fifth Task");
            }
        }));

        pool.submit(new Task(9, new Runnable() {
            @Override
            public void run() {
                System.out.println(Thread.currentThread().getName() + " I was sixth Task");
            }
        }));

        pool.submit(new Task(1, new Runnable() {
            @Override
            public void run() {
                System.out.println(Thread.currentThread().getName() + " I was seventh Task");
            }
        }));
    }
}
