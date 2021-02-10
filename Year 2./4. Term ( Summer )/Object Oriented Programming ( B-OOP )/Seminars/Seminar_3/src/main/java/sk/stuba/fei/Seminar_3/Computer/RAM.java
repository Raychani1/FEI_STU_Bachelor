package sk.stuba.fei.Seminar_3.Computer;

public class RAM extends Component {
    private int ddr_type;
    private int capacity_gb;
    private int clock_frequency;

    public RAM(String name,int ddr_type, int capacity_gb, int clock_frequency){
        this.name=name;
        this.ddr_type=ddr_type;
        this.capacity_gb =capacity_gb;
        this.clock_frequency=clock_frequency;
        this.type=Type.values()[0];
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

    public void setDdr_type(int ddr_type) {
        this.ddr_type = ddr_type;
    }

    public void setCapacity_gb(int capacity_gb) {
        this.capacity_gb = capacity_gb;
    }

    public void setClock_frequency(int clock_frequency) {
        this.clock_frequency = clock_frequency;
    }

    @Override
    public String toString() {
        return "RAM{" +
                " type=" + type +
                " , name=" + name +
                " , ddr_type=" + ddr_type +
                " , capacity_gb=" + capacity_gb +
                " , clock_frequency=" + clock_frequency +
                " }";
    }

    @Override
    public double getPowerConsumption() {
        return this.type.getEnergy();
    }
}
