package sk.stuba.fei.VirusGame.models;

public class SIR extends SIRModel {

    public SIR(double susceptible, double infectious, double recovered) {
        super(susceptible, infectious, recovered);
    }

    public SIR() {
        this(0, 0, 0);
    }

}
