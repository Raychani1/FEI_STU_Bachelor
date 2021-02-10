package sk.stuba.fei.Seminar_2.Computer;

public class Power {
    private String manufacturer;
    private String name;
    private double power_watt;

    public Power(String manufacturer, String name, double power_watt) {
        this.manufacturer = manufacturer;
        this.name = name;
        this.power_watt = power_watt;
    }

    public String getManufacturer() {
        return manufacturer;
    }

    public String getName() {
        return name;
    }

    public double getPower_watt() {
        return power_watt;
    }

    @Override
    public String toString() {
        return "Power{" +
                "manufacturer='" + manufacturer + '\'' +
                ", name='" + name + '\'' +
                ", power_watt=" + power_watt +
                '}';
    }
}
