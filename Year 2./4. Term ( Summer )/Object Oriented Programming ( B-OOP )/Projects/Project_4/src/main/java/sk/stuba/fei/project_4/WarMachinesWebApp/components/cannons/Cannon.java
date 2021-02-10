package sk.stuba.fei.project_4.WarMachinesWebApp.components.cannons;

import sk.stuba.fei.project_4.WarMachinesWebApp.components.Component;

public abstract class Cannon extends Component {
    private double caliber;
    private double cadence;
    private double coneOfFireOn100Meters;

    public Cannon(String name,double caliber, double cadence, double coneOfFireOn100Meters){
        super(name);
        setCaliber(caliber);
        setCadence(cadence);
        setConeOfFireOn100Meters(coneOfFireOn100Meters);
    }

    public void setCaliber(double caliber) {
        this.caliber = caliber;
    }

    public void setCadence(double cadence) {
        this.cadence = cadence;
    }

    public void setConeOfFireOn100Meters(double coneOfFireOn100Meters) {
        this.coneOfFireOn100Meters = coneOfFireOn100Meters;
    }
    public double getConeOfFireOn100Meters() {
        return coneOfFireOn100Meters;
    }

    public double getCaliber() {
        return caliber;
    }

    public double getCadence() {
        return cadence;
    }

    @Override
    public String toString() {
        return "Cannon{" +
                super.toString() +
                "caliber=" + caliber +
                ", cadence=" + cadence +
                ", coneOfFireOn100Meters=" + coneOfFireOn100Meters +
                '}';
    }
}
