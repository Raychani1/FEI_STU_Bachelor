package sk.stuba.fei.Seminar_4.CombatGame.Player;

import sk.stuba.fei.Seminar_4.CombatGame.Weapon.Axe;

public class Barbarian extends Player<Axe> {
    private double block;


    public Barbarian(int player_number, int health, Axe weapon) {
        super(player_number, health, weapon);
        setBlock();
    }

    public void setBlock() {
        this.block = (Math.random() * (0.2 - 0.1)) + 0.1;
    }

    @Override
    public int getNumber_of_attacks() {
        if (ability_activated) {
            return this.number_of_attacks * 2;
        }
        return this.number_of_attacks;
    }

    @Override
    public double get_all_Damage() {
        return this.getWeapon().getDamage();
    }

    @Override
    public double getBlockChance() {
        return this.block;
    }
}
