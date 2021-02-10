package sk.stuba.fei.project_4.WarMachinesWebApp.components.chassis;

import sk.stuba.fei.project_4.WarMachinesWebApp.components.Component;

public abstract class Chassis extends Component {
    private double bearingCapacity;
    private double rotationSpeed;
    private double maxSpeed;

    public Chassis(String name, double bearingCapacity, double rotationSpeed, double maxSpeed) {
        super(name);
        setBearingCapacity(bearingCapacity);
        setRotationSpeed(rotationSpeed);
        setMaxSpeed(maxSpeed);
    }

    public void setBearingCapacity(double bearingCapacity) {
        this.bearingCapacity = bearingCapacity;
    }

    public void setRotationSpeed(double rotationSpeed) {
        this.rotationSpeed = rotationSpeed;
    }

    public void setMaxSpeed(double maxSpeed) {
        this.maxSpeed = maxSpeed;
    }

    public double getBearingCapacity() {
        return this.bearingCapacity;
    }

    public double getRotationSpeed() {
        return this.rotationSpeed;
    }

    public double getMaxSpeed() {
        return this.maxSpeed;
    }

    @Override
    public String toString() {
        return "Chassis{" +
                super.toString()+
                "bearingCapacity=" + bearingCapacity +
                ", rotationSpeed=" + rotationSpeed +
                ", maxSpeed=" + maxSpeed +
                '}';
    }
}
