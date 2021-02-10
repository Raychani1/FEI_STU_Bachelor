package sk.stuba.fei.project_4.WarMachinesWebApp.warmachines;

import sk.stuba.fei.project_4.WarMachinesWebApp.components.Nationality;
import sk.stuba.fei.project_4.WarMachinesWebApp.components.Tower;
import sk.stuba.fei.project_4.WarMachinesWebApp.components.cannons.LargeCaliberCannon;
import sk.stuba.fei.project_4.WarMachinesWebApp.components.chassis.WheelChassis;

public class LightTank extends WarMachine {
    private WheelChassis wheelChassis;
    private Tower tower;

    public LightTank(String name, Nationality nationality, double price, WheelChassis wheelChassis, Tower tower) {
        super(name, nationality, price);
        setWheelChassis(wheelChassis);
        setTower(tower);
    }

    public void setWheelChassis(WheelChassis wheelChassis) {
        this.wheelChassis = wheelChassis;
    }

    public void setTower(Tower tower) {
        if(tower.getCannon() instanceof LargeCaliberCannon){
            this.tower = null;
            System.out.println("You can't put a large caliber cannon on a heavy tank");
        }
        this.tower = tower;
    }

    public WheelChassis getWheelChassis() {
        return wheelChassis;
    }

    public Tower getTower() {
        return this.tower;
    }


    @Override
    public String toString() {
        return "LightTank{" +
                super.toString()+
                " wheelChassis=" + wheelChassis +
                ", tower=" + tower +
                '}';
    }
}
