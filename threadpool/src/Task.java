public class Task {
    private final int priority;
    private final Runnable action;


    public Task(int priority, Runnable action) {
        this.priority = priority;
        this.action = action;
    }

    public int getPriority() {
        return priority;
    }

    public Runnable getAction() {
        return action;
    }
}
