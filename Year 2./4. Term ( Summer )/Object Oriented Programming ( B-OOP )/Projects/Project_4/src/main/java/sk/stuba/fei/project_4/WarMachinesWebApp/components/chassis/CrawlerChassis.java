package sk.stuba.fei.project_4.WarMachinesWebApp.components.chassis;

public class CrawlerChassis extends Chassis {

    private double crawlerWidth;

    public CrawlerChassis(String name, double bearingCapacity, double rotationSpeed, double maxSpeed, double crawlerWidth) {
        super(name, bearingCapacity, rotationSpeed, maxSpeed);
        setCrawlerWidth(crawlerWidth);
    }

    public void setCrawlerWidth(double crawlerWidth) {
        this.crawlerWidth = crawlerWidth;
    }

    public double getCrawlerWidth() {
        return this.crawlerWidth;
    }

    @Override
    public String toString() {
        return "CrawlerChassis{" +
                super.toString()+
                "crawlerWidth=" + crawlerWidth +
                '}';
    }
}
