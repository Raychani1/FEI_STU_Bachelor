package sk.stuba.fei.Seminar_3.Computer;

public class Power extends Component{

    public Power(String name) {
        this.name=name;
        this.type=Type.values()[5];
    }

    @Override
    public String toString() {
        return "Power{" +
                " type=" + type +
                " , name='" + name + '\'' +
                " , energy cons=" + type.getEnergy() +
                '}';
    }

    @Override
    public double getPowerConsumption() {
       return this.type.getEnergy();
    }
}
