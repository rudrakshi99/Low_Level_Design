// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    public static void main(String[] args) {

        LogProcessor logObject = new InfoLogProcessor(new DebugLogProcessor(new ErrorLogProcessor(null)));

        logObject.log(LogProcessor.ERROR, "exception message");
        logObject.log(LogProcessor.DEBUG, "debug message");
        logObject.log(LogProcessor.INFO, "info message");
    }
}