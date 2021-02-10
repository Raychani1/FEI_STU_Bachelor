package sk.stuba.fei.Seminar_4.CombatGame.Player;

import sk.stuba.fei.Seminar_4.CombatGame.Weapon.Bow;

public class Ranger extends Player<Bow> {
    private double block ;
    boolean ability_activated;
    int number_of_attacks;

    public Ranger(int player_number,int health,Bow weapon) {
        super(player_number,health,weapon);
        setBlock();
    }

    public void setBlock(){
        this.block=0;
    }

    @Override
    public int getNumber_of_attacks() {
        return this.number_of_attacks;
    }

    @Override
    public double get_all_Damage() {
        if(this.ability_activated){
            return this.getWeapon().getDamage()*2;
        }
        return this.getWeapon().getDamage();
    }

    @Override
    public double getBlockChance() {
        return this.block;
    }
}
