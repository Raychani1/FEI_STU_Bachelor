package sk.stuba.fei.VirusGame.diseases;

public enum Diseases {
    Mumps(1, 0.2),              // Mumps
    SheepPox(0.6, 0.1),         // Ovčie kiahne
    Rubella(0.7, 0.1),          // Ružienka
    WhoopingCough(1.4, 0.1),    // Čierny kašel
    Measels(1.8, 0.1),          // Osýpky
    Covid19(0.6, 0.2);

    private double beta;
    private double gamma;

    Diseases(double beta, double gamma) {
        setBeta(beta);
        setGamma(gamma);
    }

    public void setBeta(double beta) {
        this.beta = beta;
    }

    public void setGamma(double gamma) {
        this.gamma = gamma;
    }

    public double getBeta() {
        return this.beta;
    }

    public double getGamma() {
        return this.gamma;
    }

}
