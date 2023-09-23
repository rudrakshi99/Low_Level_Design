public class CustomBoard implements Board{

    private final char[][] board;

    public CustomBoard(int n) {
        this.board = new char[n][n];
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                this.board[i][j] = '.';
            }
        }
    }


    @Override
    public void applyMove(Move move, char symbol) {

    }

    @Override
    public boolean isFull() {
        return false;
    }

    @Override
    public boolean hasWinningLine(char symbol) {
        return false;
    }

    @Override
    public int getDimension() {
        return 0;
    }
}
