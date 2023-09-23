public class ComputerPlayer implements Player {

    private final char symbol;

    public ComputerPlayer(char symbol) {
        this.symbol = symbol;
    }

    @Override
    public Move play() {
        int x = (int)Math.random() , y = (int) Math.random();
        return new Move(x%3, y%3);
    }

    @Override
    public char getSymbol() {
        return this.symbol;
    }
}
