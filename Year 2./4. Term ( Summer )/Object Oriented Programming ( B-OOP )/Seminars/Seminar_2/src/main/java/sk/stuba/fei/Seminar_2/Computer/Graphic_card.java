package sk.stuba.fei.Seminar_2.Computer;

public class Graphic_card {
    private String name;
    private int memory_gb;
    private double energy_cons;

    public Graphic_card(String name, int memory_gb, double energy_cons) {
        this.name = name;
        this.memory_gb = memory_gb;
        this.energy_cons = energy_cons;
    }

    public String getName() {
        return name;
    }

    public int getMemory_gb() {
        return memory_gb;
    }

    public double getEnergy_cons() {
        return energy_cons;
    }

    @Override
    public String toString() {
        return "Graphic_card{" +
                "name='" + name + '\'' +
                ", memory_gb=" + memory_gb +
                ", energy_cons=" + energy_cons +
                '}';
    }
}
