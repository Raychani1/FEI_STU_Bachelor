package sk.stuba.fei.project_4.WarMachinesWebApp.components.cannons;

public class SmallCaliberCannon extends Cannon{
    private int ammo;

    public SmallCaliberCannon(String name, double caliber, double cadence, double coneOfFireOn100Meters,int ammo) {
        super(name, caliber, cadence, coneOfFireOn100Meters);
        setAmmo(ammo);
    }

    public void setAmmo(int ammo) {
        this.ammo = ammo;
    }

    public int getAmmo() {
        return this.ammo;
    }

    @Override
    public String toString() {
        return "SmallCaliberCannon{" +
                super.toString() +
                "ammo=" + ammo +
                '}';
    }
}
