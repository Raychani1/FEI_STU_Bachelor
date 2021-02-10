package sk.stuba.fei.Seminar_2.Computer;

public class HDD_SSD {
    private String type;
    private int space;
    private int read_speed_mb_s;
    private int write_speed_mb_s;
    private int rpm;
    private double energy_cons;

    public HDD_SSD(String type, int space, int read_speed_mb_s, int write_speed_mb_s, int rpm, double energy_cons) {
        this.type = type;
        this.space = space;
        this.read_speed_mb_s = read_speed_mb_s;
        this.write_speed_mb_s = write_speed_mb_s;
        this.rpm = rpm;
        this.energy_cons = energy_cons;
    }

    public String getType() {
        return type;
    }

    public int getSpace() {
        return space;
    }

    public int getRead_speed_mb_s() {
        return read_speed_mb_s;
    }

    public int getWrite_speed_mb_s() {
        return write_speed_mb_s;
    }

    public int getRpm() {
        return rpm;
    }

    public double getEnergy_cons() {
        return energy_cons;
    }

    @Override
    public String toString() {
        return "HDD_SSD{" +
                "type='" + type + '\'' +
                ", space=" + space +
                ", read_speed_mb_s=" + read_speed_mb_s +
                ", write_speed_mb_s=" + write_speed_mb_s +
                ", rpm=" + rpm +
                ", energy_cons=" + energy_cons +
                '}';
    }
}