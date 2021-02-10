package sk.stuba.fei.Seminar_4.CombatGame.Player;

import sk.stuba.fei.Seminar_4.CombatGame.Weapon.Weapon;

import static sk.stuba.fei.Seminar_4.CombatGame.KeyboardInput.readString;

public abstract class Player<T extends Weapon> {
    private String name;
    private int health;
    boolean ability_activated;
    int number_of_attacks;
    private T weapon;

    public abstract double getBlockChance();

    public Player(int player_number, int health, T weapon) {
        setName(readString("Player" + player_number + " name your warrior"));
        setWeapon(weapon);
        setHealth(health);
        setAbility_activity(false);
        setNumber_of_attacks();
    }


    public void setName(String name) {
        if (name.isEmpty())
            throw new IllegalArgumentException("Illegal name");
        this.name = name;
    }

    public void setHealth(int health) {
        if (health <= 0)
            throw new IllegalArgumentException("Health can't be 0 or below");
        this.health = health;
    }

    public void setAbility_activity(boolean active) {
        this.ability_activated = active;
    }

    public void setNumber_of_attacks() {
        this.number_of_attacks = 1;
    }

    public void setWeapon(T weapon) {
        this.weapon = weapon;
    }

    public String getName() {
        return name;
    }

    public double getHealth() {
        return health;
    }

    public boolean isAbility_activated() {
        return ability_activated;
    }

    public abstract int getNumber_of_attacks();

    public abstract double get_all_Damage();

    public T getWeapon() {
        return weapon;
    }

    @Override
    public String toString() {
        return "Player{" +
                "name='" + name + '\'' +
                ", health=" + health +
                ", block=" + this.getBlockChance() +
                ", weapon=" + weapon +
                '}';
    }
}
