package sk.stuba.fei.Seminar_3.Computer;

public class HDD_SSD extends Component{

    private int space;
    private int read_speed_mb_s;
    private int write_speed_mb_s;
    private int rpm;

    public HDD_SSD(String name, int space, int read_speed_mb_s, int write_speed_mb_s, int rpm) {
        this.name=name;
        this.type=Type.values()[1];
        this.space = space;
        this.read_speed_mb_s = read_speed_mb_s;
        this.write_speed_mb_s = write_speed_mb_s;
        this.rpm = rpm;
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

    @Override
    public String toString() {
        return "HDD_SSD{" +
                " type=" + type +
                ", space=" + space +
                ", read_speed_mb_s=" + read_speed_mb_s +
                ", write_speed_mb_s=" + write_speed_mb_s +
                ", rpm=" + rpm +
                ", name='" + name + '\'' +
                " , energy cons=" + type.getEnergy() +
                '}';
    }

    @Override
    public double getPowerConsumption() {
        return this.type.getEnergy();
    }
}
