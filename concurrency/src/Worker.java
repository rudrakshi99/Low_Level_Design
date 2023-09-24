public class Worker implements Runnable {

    private final IntStore store;

    public Worker(IntStore store) {
        this.store = store;
    }

    @Override
    public void run() {
        for (int i=0; i< 100000 ; i++) {
            store.incr();
        }
    }
}
