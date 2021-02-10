package sk.stuba.fei.project_4.WarMachinesWebApp.warmachines;

import sk.stuba.fei.project_4.WarMachinesWebApp.components.Nationality;

import java.util.UUID;

public abstract class WarMachine {
    private String id;
    private String name;
    private Nationality nationality;
    private double price;

    public WarMachine(String name, Nationality nationality,double price){
        setId();
        setName(name);
        setNationality(nationality);
        setPrice(price);
    }

    public String getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public Nationality getNationality() {
        return nationality;
    }

    public double getPrice() {
        return price;
    }

    public void setId() {
        this.id = UUID.randomUUID().toString();
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setNationality(Nationality nationality) {
        this.nationality = nationality;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    @Override
    public String toString() {
        return "WarMachine{" +
                "id='" + id + '\'' +
                ", name='" + name + '\'' +
                ", nationality=" + nationality +
                ", price=" + price +
                '}';
    }
}
