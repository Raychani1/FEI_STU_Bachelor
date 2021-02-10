package sk.stuba.fei.Seminar_4.CombatGame.Weapon;

public class Sword extends Weapon {
    private double length;
    private double weight;
    private double damage;

    public Sword(double length, double weight) {
        setLength(length);
        setWeight(weight);
        setDamage();
    }

    public void setLength(double length) {
        if (length <= 0) {
            throw new IllegalArgumentException("Length can't be 0 or below");
        }
        this.length = length;
    }

    public void setWeight(double weight) {
        if (weight <= 0) {
            throw new IllegalArgumentException("Weight can't be 0 or below");
        }
        this.weight = weight;
    }

    public void setDamage() {
        this.damage = this.length * this.weight;
    }

    @Override
    public double getDamage() {
        return this.damage;
    }

    @Override
    public String toString() {
        return "Sword{" +
                "length=" + length +
                ", weight=" + weight +
                ", damage=" + damage +
                '}';
    }
}
