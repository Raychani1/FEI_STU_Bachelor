package sk.stuba.fei.VirusGame.models;

public class SIRf extends SIRModel {
    private double f;

    public SIRf(double susceptible, double infectious, double recovered, double f) {
        super(susceptible - (susceptible * (f / 100)), infectious, recovered + (susceptible * (f / 100)));
        setF(f);
    }

    public SIRf() {
        this(0, 0, 0, 0);
    }

    public double getF() {
        return f;
    }

    public void setF(double f) {
        this.f = f;
    }

}
