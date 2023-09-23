import java.util.Scanner;

public class HumanPlayer implements  Player {

    private final char symbol;

    public HumanPlayer(char symbol) {
        this.symbol = symbol;
    }

    @Override
    public Move play() {
        System.out.println("Fetching move from console....");
        Scanner scanner = new Scanner(System.in);
        int x = scanner.nextInt(), y = scanner.nextInt();
        //if(isValidMove(x,y))
        return new Move(x, y);
    }

    @Override
    public char getSymbol() {
        return this.symbol;
    }

    private boolean isValidMove(int x, int y) {
        // Check if the coordinates are within the bounds of a 3x3 board
        return x >= 0 && x <= 2 && y >= 0 && y <= 2;
    }
}
