package sk.stuba.fei.Seminar_2.Computer;

public class Processor {
    private String manufacturer;
    private String name;
    private int cores;
    private int threads;
    private double clock_speed;
    private double overclock_speed;
    private double energy_cons;
    private String socket;

    public Processor(String manufacturer, String name, int cores, int threads, double clock_speed, double overclock_speed, double energy_cons, String socket) {
        this.manufacturer = manufacturer;
        this.name = name;
        this.cores = cores;
        this.threads = threads;
        this.clock_speed = clock_speed;
        this.overclock_speed = overclock_speed;
        this.energy_cons = energy_cons;
        this.socket = socket;
    }

    public String getManufacturer() {
        return manufacturer;
    }

    public String getName() {
        return name;
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

    public double getEnergy_cons() {
        return energy_cons;
    }

    public String getSocket() {
        return socket;
    }

    @Override
    public String toString() {
        return "Processor{" +
                "manufacturer='" + manufacturer + '\'' +
                ", name='" + name + '\'' +
                ", cores=" + cores +
                ", threads=" + threads +
                ", clock_speed=" + clock_speed +
                ", overclock_speed=" + overclock_speed +
                ", energy_cons=" + energy_cons +
                ", socket='" + socket + '\'' +
                '}';
    }
}
