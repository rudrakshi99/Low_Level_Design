public class TicTacToeSimulator {

    public static void main(String[] args) {
        Game ticTacToe = new TicTacToe(new HumanPlayer('X'), new ComputerPlayer('0'), new GeneralBoard());
        Result result = ticTacToe.start();
        if (result.isDraw()) {
            System.out.println("The match ended in a draw");
        }
        else {
            System.out.println("Player with symbol : " + result.getWinner().getSymbol() + "won......");
        }
    }
}
