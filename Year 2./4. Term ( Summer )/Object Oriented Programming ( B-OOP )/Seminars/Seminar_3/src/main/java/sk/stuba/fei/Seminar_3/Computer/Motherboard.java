package sk.stuba.fei.Seminar_3.Computer;

public class Motherboard extends Component{

    private int ddr_memory;
    private int max_ram_slot;
    private int max_ram_freq;
    private String socket;

    public Motherboard(String name, int ddr_memory, int max_ram_slot, int max_ram_freq, String socket) {
        this.type=Type.values()[4];
        this.name=name;
        this.ddr_memory = ddr_memory;
        this.max_ram_slot = max_ram_slot;
        this.max_ram_freq = max_ram_freq;
        this.socket = socket;
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

    @Override
    public String toString() {
        return "Motherboard{" +
                " type=" + type +
                ", ddr_memory=" + ddr_memory +
                ", max_ram_slot=" + max_ram_slot +
                ", max_ram_freq=" + max_ram_freq +
                ", socket='" + socket + '\'' +
                ", name='" + name + '\'' +
                " , energy cons=" + type.getEnergy() +
                '}';
    }

    @Override
    public double getPowerConsumption() {
        return this.type.getEnergy();
    }
}
