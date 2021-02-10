package sk.stuba.fei.project_4.WarMachinesWebApp.components.chassis;

public class WheelChassis extends  Chassis{
    private int wheels;

    public WheelChassis(String name, double bearingCapacity, double rotationSpeed, double maxSpeed, int wheels) {
        super(name, bearingCapacity, rotationSpeed, maxSpeed);
        setWheels(wheels);
    }

    public void setWheels(int wheels) {
        this.wheels = wheels;
    }

    public int getWheels() {
        return this.wheels;
    }

    @Override
    public String toString() {
        return "WheelChassis{" +
                super.toString()+
                "wheels=" + wheels +
                '}';
    }
}
