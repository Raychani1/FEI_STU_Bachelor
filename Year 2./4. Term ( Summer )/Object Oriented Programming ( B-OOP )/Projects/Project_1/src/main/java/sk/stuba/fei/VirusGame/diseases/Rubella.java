package sk.stuba.fei.VirusGame.diseases;

public class Rubella implements IVirus {
    private double beta;
    private double gamma;
    private double r0;

    public Rubella() {
        setBeta(Diseases.Rubella.getBeta());
        setGamma(Diseases.Rubella.getGamma());
        setR0(calculateR0());
    }

    public double getBeta() {
        return beta;
    }

    public double getGamma() {
        return gamma;
    }

    public double getR0() {
        return r0;
    }

    public void setBeta(double beta) {
        this.beta = beta;
    }

    public void setGamma(double gamma) {
        this.gamma = gamma;
    }

    public void setR0(double r0) {
        this.r0 = r0;
    }

    public double calculateR0() {
        return (this.beta / this.gamma);
    }
}
