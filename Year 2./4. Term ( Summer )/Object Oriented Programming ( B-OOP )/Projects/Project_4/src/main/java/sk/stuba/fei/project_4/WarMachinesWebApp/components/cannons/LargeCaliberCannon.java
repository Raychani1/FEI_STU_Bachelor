package sk.stuba.fei.project_4.WarMachinesWebApp.components.cannons;

public class LargeCaliberCannon extends Cannon{
    private double blastRadius;

    public LargeCaliberCannon(String name, double caliber, double cadence, double coneOfFireOn100Meters, double blastRadius) {
        super(name, caliber, cadence, coneOfFireOn100Meters);
        setBlastRadius(blastRadius);
    }

    public void setBlastRadius(double blastRadius) {
        this.blastRadius = blastRadius;
    }

    public double getBlastRadius() {
        return this.blastRadius;
    }

    @Override
    public String toString() {
        return "LargeCaliberCannon{" +
                super.toString() +
                "blastRadius=" + blastRadius +
                '}';
    }
}
