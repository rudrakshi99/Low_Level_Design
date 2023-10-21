public class VehicalFactory {

    static Vehical getVehicleObject(String typeOfVehicle) {
        if("Car".equals(typeOfVehicle)) {
            return new Car();
        }

        return new NullVehical();
    }
}
