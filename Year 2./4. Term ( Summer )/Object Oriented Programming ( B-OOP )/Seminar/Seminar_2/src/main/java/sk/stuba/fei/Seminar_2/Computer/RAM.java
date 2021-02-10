package sk.stuba.fei.Seminar_2.Computer;

public class RAM {
    private String name;
    private int num_of_ram;
    private int ddr_type;
    private int capacity_gb;
    private int clock_frequency;
    private double energy_cons;

    public RAM(String name, int num_of_ram, int ddr_type, int capacity_gb, int clock_frequency, double energy_cons) {
        this.name = name;
        this.num_of_ram = num_of_ram;
        this.ddr_type = ddr_type;
        this.capacity_gb = capacity_gb;
        this.clock_frequency = clock_frequency;
        this.energy_cons = energy_cons;
    }

    public String getName() {
        return name;
    }

    public int getNum_of_ram() {
        return num_of_ram;
    }

    public int getDdr_type() {
        return ddr_type;
    }

    public int getCapacity_gb() {
        return capacity_gb;
    }

    public int getClock_frequency() {
        return clock_frequency;
    }

    public double getEnergy_cons() {
        return energy_cons;
    }

    @Override
    public String toString() {
        return "RAM{" +
                "name='" + name + '\'' +
                ", num_of_ram=" + num_of_ram +
                ", ddr_type=" + ddr_type +
                ", capacity_gb=" + capacity_gb +
                ", clock_frequency=" + clock_frequency +
                ", energy_cons=" + energy_cons +
                '}';
    }
}
