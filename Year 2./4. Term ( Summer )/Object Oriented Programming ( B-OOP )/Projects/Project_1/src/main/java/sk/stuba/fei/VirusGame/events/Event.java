package sk.stuba.fei.VirusGame.events;

public abstract class Event {
    private double betaModifier;
    private double gammaModifier;

    public Event(double betaModifier, double gammaModifier) {
        setBetaModifier(betaModifier);
        setGammaModifier(gammaModifier);
    }

    public Event() {
        this(0.0, 0.0);
    }

    public double getBetaModifier() {
        return this.betaModifier;
    }

    public void setBetaModifier(double betaModifier) {
        this.betaModifier = betaModifier;
    }

    public double getGammaModifier() {
        return this.gammaModifier;
    }

    public void setGammaModifier(double gammaModifier) {
        this.gammaModifier = gammaModifier;
    }

}
