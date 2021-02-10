package sk.stuba.fei.Seminar_4.CombatGame.Weapon;

public class Bow extends Weapon {
    private double fire_rate;
    private int arrow_damage;
    private double damage;

    public Bow(double fire_rate, int arrow_damage) {
        setFire_rate(fire_rate);
        setArrow_damage(arrow_damage);
        setDamage();
    }

    public void setArrow_damage(int arrow_damage) {
        if (arrow_damage <= 0) {
            throw new IllegalArgumentException("Arrow damage can't be 0 or below");
        }
        this.arrow_damage = arrow_damage;
    }

    public void setFire_rate(double fire_rate) {
        if (fire_rate <= 0) {
            throw new IllegalArgumentException("Fire rate can't be 0 or below");
        }
        this.fire_rate = fire_rate;
    }

    public void setDamage() {
        this.damage = this.arrow_damage * this.fire_rate;
    }

    @Override
    public double getDamage() {
        return this.damage;
    }

    @Override
    public String toString() {
        return "Bow{" +
                "fire_rate=" + fire_rate +
                ", arrow_damage=" + arrow_damage +
                ", damage=" + damage +
                '}';
    }
}
