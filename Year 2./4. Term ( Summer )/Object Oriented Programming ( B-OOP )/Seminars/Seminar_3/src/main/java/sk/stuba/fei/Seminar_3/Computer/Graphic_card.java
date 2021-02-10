package sk.stuba.fei.Seminar_3.Computer;

public class Graphic_card extends Component {
    private int memory_gb;

    public Graphic_card(String name,int memory_gb) {
        this.name=name;
        this.memory_gb=memory_gb;
        this.type=Type.values()[3];
    }

    public int getMemory_gb() {
        return memory_gb;
    }

    @Override
    public String toString() {
        return "Graphic_card{" +
                " type=" + type +
                " , name='" + name  + '\''+
                " , memory_gb=" + memory_gb +
                " , energy cons=" + type.getEnergy() +
                " }";
    }

    @Override
    public double getPowerConsumption() {
       return this.type.getEnergy();
    }
}
