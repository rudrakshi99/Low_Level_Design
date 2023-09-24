import java.util.List;

public class WebClient {

    public List<URL> parseAndGet(URL url) {
        /**
         * parsing work (like html, css)....
         */
        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
        return url.getInternalURLs();
    }
}
