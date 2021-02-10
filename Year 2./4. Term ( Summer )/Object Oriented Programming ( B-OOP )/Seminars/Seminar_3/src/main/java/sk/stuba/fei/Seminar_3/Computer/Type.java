package sk.stuba.fei.Seminar_3.Computer;

public enum Type {
    RAM(0.1),
    HDD(10),
    CPU(10),
    GPU(10),
    MOTHER(100),
    ENERGY(100);

    private double energy;

    Type(double energy) {
        this.energy = energy;
    }

    public double getEnergy() {
        return energy;
    }
}
