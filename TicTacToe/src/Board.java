public interface Board {

    void applyMove(Move move, char symbol);

    boolean isFull();

    boolean hasWinningLine(char symbol);

    int getDimension();
}
