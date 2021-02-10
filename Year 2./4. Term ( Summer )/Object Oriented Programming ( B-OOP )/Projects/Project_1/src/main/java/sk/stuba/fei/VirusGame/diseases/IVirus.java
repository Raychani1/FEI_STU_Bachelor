package sk.stuba.fei.VirusGame.diseases;

public interface IVirus {
    double calculateR0();

    double getBeta();

    double getGamma();

    double getR0();

    void setBeta(double beta);

    void setGamma(double gamma);

    void setR0(double R0);
    // More methods will be here if necessary
}
