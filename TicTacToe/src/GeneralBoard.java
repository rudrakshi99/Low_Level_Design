public class GeneralBoard implements Board {

    private final char[][] board;

    public GeneralBoard() {
        this.board = new char[3][3];
        for (int i=0;i<3;i++) {
            for (int j=0;j<3;j++) {
                this.board[i][j] = '.';
            }
        }
    }

    @Override
    public void applyMove(Move move, char symbol) {
        this.board[move.getX()][move.getY()] = symbol;
    }

    @Override
    public boolean isFull() {
        for (int i=0;i<3;i++) {
            for (int j=0;j<3;j++) {
                if (this.board[i][j] == '.') {
                    return false;
                }
            }
        }
        return true;
    }

    @Override
    public boolean hasWinningLine(char symbol) {
        return hasHorizWinningLine(symbol) || hasVertWinningLine(symbol) || hasDiagWinningLine(symbol);
    }

    @Override
    public int getDimension() {
        return this.board.length;
    }

    private boolean hasHorizWinningLine(char symbol) {
        for (int i=0;i<3;i++) {
            if (this.board[i][0] == symbol && this.board[i][1] == symbol && this.board[i][2] == symbol) {
                return true;
            }
        }
        return false;
    }

    private boolean hasVertWinningLine(char symbol) {
        for (int i=0;i<3;i++) {
            if (this.board[i][0] == symbol && this.board[1][i] == symbol && this.board[2][i] == symbol) {
                return true;
            }
        }
        return false;
    }

    private boolean hasDiagWinningLine(char symbol) {
        return (this.board[0][0] == symbol && this.board[1][1] == symbol && this.board[2][2] == symbol) ||
                (this.board[0][2] == symbol && this.board[1][1] == symbol && this.board[2][0] == symbol);
    }
}
