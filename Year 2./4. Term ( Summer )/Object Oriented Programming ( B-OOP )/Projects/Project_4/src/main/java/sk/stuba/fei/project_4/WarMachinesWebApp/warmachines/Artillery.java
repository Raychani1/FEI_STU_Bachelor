package sk.stuba.fei.project_4.WarMachinesWebApp.warmachines;

import sk.stuba.fei.project_4.WarMachinesWebApp.components.Nationality;
import sk.stuba.fei.project_4.WarMachinesWebApp.components.cannons.LargeCaliberCannon;
import sk.stuba.fei.project_4.WarMachinesWebApp.components.chassis.CrawlerChassis;

public class Artillery extends WarMachine{
    private CrawlerChassis crawlerChassis;
    private LargeCaliberCannon largeCaliberCannon;

    public Artillery(String name, Nationality nationality, double price, CrawlerChassis crawlerChassis, LargeCaliberCannon largeCaliberCannon) {
        super(name, nationality, price);
        setCrawlerChassis(crawlerChassis);
        setLargeCaliberCannon(largeCaliberCannon);
    }

    public void setCrawlerChassis(CrawlerChassis crawlerChassis) {
        this.crawlerChassis = crawlerChassis;
    }

    public void setLargeCaliberCannon(LargeCaliberCannon largeCaliberCannon) {
        this.largeCaliberCannon = largeCaliberCannon;
    }

    public CrawlerChassis getCrawlerChassis() {
        return this.crawlerChassis;
    }

    public LargeCaliberCannon getLargeCaliberCannon() {
        return this.largeCaliberCannon;
    }

    @Override
    public String toString() {
        return "Artillery{" +
                super.toString() +
                "crawlerChassis=" + crawlerChassis +
                ", largeCaliberCannon=" + largeCaliberCannon +
                '}';
    }
}
