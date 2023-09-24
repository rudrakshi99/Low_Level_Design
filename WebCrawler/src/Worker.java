import java.util.Set;
import java.util.concurrent.BlockingQueue;

public class Worker implements Runnable{

    private final URL assignedURL; //child nodes
    private final Set<String> pickedURLs;

    private final WebClient webClient;

    private final Object lock;
    private final BlockingQueue<URL> urlToProcess;

    public Worker(URL assignedURL, Set<String> pickedURLs, WebClient webClient,
                  Object lock, BlockingQueue<URL> urlToProcess) {
        this.assignedURL = assignedURL;
        this.pickedURLs = pickedURLs;
        this.webClient = webClient;
        this.lock = lock;
        this.urlToProcess = urlToProcess;
    }

    @Override
    public void run() {
        synchronized (lock) {
            if (pickedURLs.contains(assignedURL.getName())) {
                return;
            }
            pickedURLs.add(assignedURL.getName());
        }
        /**
         * Crawling job
         */
        System.out.println(Thread.currentThread().getId() + " crawling " +
                assignedURL.getName() + "......");
        for (URL url : webClient.parseAndGet(assignedURL)) {
            try {
                this.urlToProcess.put(url);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }
}
