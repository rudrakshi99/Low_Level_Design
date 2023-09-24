import java.util.HashSet;
import java.util.Set;
import java.util.concurrent.*;

public class WebCrawler {

    private static final ExecutorService executorService =
            Executors.newFixedThreadPool(3);

    private static final BlockingQueue<URL> urlsToProcess =
            new LinkedBlockingQueue<>();

    private static URL getSeed() {
        //it forms directed graph
        URL url = new URL("apple.com");
        URL url1 = new URL("apple.com/i-phone15");
        URL url2 = new URL("apple.com/products");
        URL url3 = new URL("apple.com/iphones");
        URL url4 = new URL("apple.com/iphone-11");
        URL url5 = new URL("apple.com/i-phone-11/pro");
        URL url6 = new URL("apple.com/i-phone-11/mini");
        url6.addURL(url5);
        url4.addURL(url6);
        url3.addURL(url4);url3.addURL(url6);
        url1.addURL(url2);url1.addURL(url5);
        url2.addURL(url5);url2.addURL(url4);
        url.addURL(url1);url.addURL(url2);url.addURL(url3);url.addURL(url4);
        return url;
    }

    //multithreaded web crawler
    public static void main(String[] args) throws InterruptedException {
        URL seed = getSeed();
        urlsToProcess.put(seed);
        Set<String> pickedURLS = new HashSet<>();
        WebClient webClient = new WebClient();
        Object lock = new Object();
        while (true) {
            URL currentURL = urlsToProcess.take();
            executorService.submit(new Worker(currentURL, pickedURLS, webClient,
                    lock, urlsToProcess));
        }
    }
}
