public class IntStore {

    private int x=0;

    public void incr() {
        x++;
    }

    public synchronized int getX() {
        return x;
    }
}
