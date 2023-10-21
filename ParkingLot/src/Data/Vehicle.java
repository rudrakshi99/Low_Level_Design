public class Vehicle {

    private String vehicleNumber;
    private VehicleSize vehicleSize;

    public Vehicle(String vehicleNumber, VehicleSize vehicleSize) {
        this.vehicleNumber = vehicleNumber;
        this.vehicleSize = vehicleSize;
    }

    public VehicleSize getVehicleSize() {
        return vehicleSize;
    }

    public void setVehicleSize(VehicleSize vehicleSize) {
        this.vehicleSize = vehicleSize;
    }

    public String getVehicleNumber() {
        return vehicleNumber;
    }

    public void setVehicleNumber(String vehicleNumber) {
        this.vehicleNumber = vehicleNumber;
    }
}
