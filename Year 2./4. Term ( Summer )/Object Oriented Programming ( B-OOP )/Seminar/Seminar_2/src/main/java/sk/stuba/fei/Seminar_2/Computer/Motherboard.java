package sk.stuba.fei.Seminar_2.Computer;

public class Motherboard {
    private String name;
    private int ddr_memory;
    private int max_ram_slot;
    private int max_ram_freq;
    private String socket;
    private double energy_cons;

    public Motherboard(String name, int ddr_memory, int max_ram_slot, int max_ram_freq, String socket, double energy_cons) {
        this.name = name;
        this.ddr_memory = ddr_memory;
        this.max_ram_slot = max_ram_slot;
        this.max_ram_freq = max_ram_freq;
        this.socket = socket;
        this.energy_cons = energy_cons;
    }

    public String getName() {
        return name;
    }

    public int getDdr_memory() {
        return ddr_memory;
    }

    public int getMax_ram_slot() {
        return max_ram_slot;
    }

    public int getMax_ram_freq() {
        return max_ram_freq;
    }

    public String getSocket() {
        return socket;
    }

    public double getEnergy_cons() {
        return energy_cons;
    }

    @Override
    public String toString() {
        return "Motherboard{" +
                "name='" + name + '\'' +
                ", ddr_memory=" + ddr_memory +
                ", max_ram_slot=" + max_ram_slot +
                ", max_ram_freq=" + max_ram_freq +
                ", socket='" + socket + '\'' +
                ", energy_cons=" + energy_cons +
                '}';
    }
}