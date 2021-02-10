package sk.stuba.fei.Seminar_4.CombatGame.Player;

import sk.stuba.fei.Seminar_4.CombatGame.Weapon.Sword;

public class Knight extends Player<Sword> {
    private double block;

    public Knight(int player_number, int health, Sword weapon) {
        super(player_number, health, weapon);
        setBlock();
    }

    public void setBlock() {
        this.block = 0.2;
    }

    @Override
    public int getNumber_of_attacks() {
        return this.number_of_attacks;
    }

    @Override
    public double get_all_Damage() {
        return this.getWeapon().getDamage();
    }

    @Override
    public double getBlockChance() {
        if (this.ability_activated)
            return this.block * 2;
        return this.block;
    }


}
