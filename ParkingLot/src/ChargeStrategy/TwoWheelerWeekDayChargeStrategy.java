public class TwoWheelerWeekDayChargeStrategy implements ParkingChargeStrategy {

    @Override
    public int getCharge(int parkHours) {
        if (parkHours < 1) {
            return 10;
        }
        return parkHours * 10;
    }
}