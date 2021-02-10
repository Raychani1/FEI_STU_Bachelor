package sk.stuba.fei.project_4.WarMachinesWebApp.components;

import sk.stuba.fei.project_4.WarMachinesWebApp.components.cannons.Cannon;

public class Tower extends Component {
    private double rotationSpeed;
    private double lineOfSight;
    private Cannon cannon;


    public Tower(String name, double rotationSpeed, double lineOfSight,Cannon cannon){
        super(name);
        setRotationSpeed(rotationSpeed);
        setLineOfSight(lineOfSight);
        setCannon(cannon);
    }

    public void setRotationSpeed(double rotationSpeed) {
        this.rotationSpeed = rotationSpeed;
    }

    public void setLineOfSight(double lineOfSight) {
        this.lineOfSight = lineOfSight;
    }

    public void setCannon(Cannon cannon) {
        this.cannon = cannon;
    }

    public double getRotationSpeed() {
        return this.rotationSpeed;
    }

    public double getLineOfSight() {
        return this.lineOfSight;
    }

    public Cannon getCannon() {
        return cannon;
    }

    @Override
    public String toString() {
        return "Tower{" +
                super.toString()+
                "rotationSpeed=" + rotationSpeed +
                ", lineOfSight=" + lineOfSight +
                ", cannon=" + cannon +
                '}';
    }
}
