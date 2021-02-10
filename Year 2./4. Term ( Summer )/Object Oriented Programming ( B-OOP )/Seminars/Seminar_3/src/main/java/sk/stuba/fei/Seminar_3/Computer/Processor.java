package sk.stuba.fei.Seminar_3.Computer;

public class Processor extends Component {
    private String manufacturer;
    private int cores;
    private int threads;
    private double clock_speed;
    private double overclock_speed;
    private String socket;

    public Processor(String name, String manufacturer, int cores, int threads, double clock_speed, double overclock_speed, String socket) {
        this.name=name;
        this.type=Type.values()[2];
        this.manufacturer = manufacturer;
        this.cores = cores;
        this.threads = threads;
        this.clock_speed = clock_speed;
        this.overclock_speed = overclock_speed;
        this.socket = socket;
    }

    public String getManufacturer() {
        return manufacturer;
    }

    public int getCores() {
        return cores;
    }

    public int getThreads() {
        return threads;
    }

    public double getClock_speed() {
        return clock_speed;
    }

    public double getOverclock_speed() {
        return overclock_speed;
    }

    public String getSocket() {
        return socket;
    }

    @Override
    public String toString() {
        return "Processor{" +
                " type=" + type +
                ", manufacturer='" + manufacturer + '\'' +
                ", cores=" + cores +
                ", threads=" + threads +
                ", clock_speed=" + clock_speed +
                ", overclock_speed=" + overclock_speed +
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

