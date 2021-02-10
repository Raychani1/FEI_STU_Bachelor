package sk.stuba.fei.Seminar_4.CombatGame.Weapon;

public class Axe extends Weapon {
    public double weight;
    public double mobility;
    public double damage;

    public Axe(double weight, double mobility) {
        setWeight(weight);
        setMobility(mobility);
        setDamage();
    }

    public void setWeight(double weight) {
        if (weight <= 0) {
            throw new IllegalArgumentException("Weight can't be 0 or below");
        }
        this.weight = weight;
    }

    public void setMobility(double mobility) {
        if (mobility <= 0) {
            throw new IllegalArgumentException("Mobility can't be 0 or below");
        }
        this.mobility = mobility;
    }

    public void setDamage() {
        this.damage = this.weight * this.mobility;
    }

    @Override
    public double getDamage() {
        return this.damage;
    }

    @Override
    public String toString() {
        return "Axe{" +
                "weight=" + weight +
                ", mobility=" + mobility +
                ", damage=" + damage +
                '}';
    }
}
