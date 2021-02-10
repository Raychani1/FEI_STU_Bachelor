package sk.stuba.fei.VirusGame.events;

public class SlowingEvent extends Event {
    public SlowingEvent(double betaModifier, double gammaModifier) {
        super(betaModifier, gammaModifier);
    }
}
