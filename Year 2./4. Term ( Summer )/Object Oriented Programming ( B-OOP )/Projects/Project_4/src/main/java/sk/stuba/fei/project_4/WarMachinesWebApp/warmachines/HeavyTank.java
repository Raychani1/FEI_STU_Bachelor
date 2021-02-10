package sk.stuba.fei.project_4.WarMachinesWebApp.warmachines;

import sk.stuba.fei.project_4.WarMachinesWebApp.components.Nationality;
import sk.stuba.fei.project_4.WarMachinesWebApp.components.Tower;
import sk.stuba.fei.project_4.WarMachinesWebApp.components.cannons.SmallCaliberCannon;
import sk.stuba.fei.project_4.WarMachinesWebApp.components.chassis.CrawlerChassis;

public class HeavyTank extends WarMachine {
    private CrawlerChassis crawlerChassis;
    private Tower tower;

    public HeavyTank(String name, Nationality nationality, double price, CrawlerChassis crawlerChassis,Tower tower) {
        super(name, nationality, price);
        setCrawlerChassis(crawlerChassis);
        setTower(tower);
    }

    public void setCrawlerChassis(CrawlerChassis crawlerChassis) {
        this.crawlerChassis = crawlerChassis;
    }

    public void setTower(Tower tower) {
        if(tower.getCannon() instanceof SmallCaliberCannon){
            this.tower = null;
            System.out.println("You can't put a small caliber cannon on a heavy tank");
        }
        this.tower = tower;
    }

    public CrawlerChassis getCrawlerChassis() {
        return this.crawlerChassis;
    }

    public Tower getTower() {
        return this.tower;
    }

    @Override
    public String toString() {
        return "HeavyTank{" +
                super.toString() +
                "crawlerChassis=" + crawlerChassis +
                ", tower=" + tower +
                '}';
    }
}
