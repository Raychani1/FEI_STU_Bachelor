package sk.stuba.fei.VirusGame.models;

public abstract class SIRModel {
    private double susceptible;
    private double infectious;
    private double recovered;
    private int population;

    public SIRModel(double susceptible, double infectious, double recovered) {
        setSusceptible(susceptible);
        setInfectious(infectious);
        setRecovered(recovered);
        setPopulation();
    }

    public double getSusceptible() {
        return this.susceptible;
    }

    public double getInfectious() {
        return this.infectious;
    }

    public double getRecovered() {
        return this.recovered;
    }

    public int getPopulation() {
        return this.population;
    }

    public void setSusceptible(double susceptible) {
        this.susceptible = susceptible;
    }

    public void setInfectious(double infectious) {
        this.infectious = infectious;
    }

    public void setRecovered(double recovered) {
        this.recovered = recovered;
    }

    public void setPopulation() {
        this.population = (int) Math.round(this.susceptible) + (int) Math.round(this.infectious) + (int) Math.round(this.recovered);
    }

    public void calculateNewSusceptible(double beta, double gamma) {
        // TODO
        // Method in development
    }

    public void calculateNewInfectious(double beta, double gamma) {
        // TODO
        // Method in development
    }

    public void calculateNewRecovered(double beta, double gamma) {
        // TODO
        // Method in development
    }
}
