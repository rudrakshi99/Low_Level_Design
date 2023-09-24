import java.util.ArrayList;
import java.util.List;

public class URL {

    private final String name; // apple.com
    private final List<URL> internalURLs; //apple.com/i-phone


    public URL(String name) {
        this.name = name;
        this.internalURLs = new ArrayList<>();
    }

    public void addURL(URL url) {
        this.internalURLs.add(url);
    }

    public String getName() {
        return name;
    }

    public List<URL> getInternalURLs() {
        return internalURLs;
    }
}
