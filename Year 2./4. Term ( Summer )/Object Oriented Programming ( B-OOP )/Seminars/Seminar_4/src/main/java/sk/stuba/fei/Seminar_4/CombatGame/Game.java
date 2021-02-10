package sk.stuba.fei.Seminar_4.CombatGame;


import sk.stuba.fei.Seminar_4.CombatGame.Player.*;
import sk.stuba.fei.Seminar_4.CombatGame.Weapon.*;

import static sk.stuba.fei.Seminar_4.CombatGame.KeyboardInput.readString;

public class Game {
    public static Player<?> choice(int player_number) {
        System.out.println("\n======================================================\nType the command you wish to execute, choose wisely:" +
                "\nInfo : You can get information about the warrior types you can choose from" +
                "\nKnight: You want to be a knight" +
                "\nBarbarian: You want to be a barbarian" +
                "\nRanger: You want to be a ranger");
        String choice = readString("\nYour choice");
        while (true) {
            switch (choice) {
                case ("Info"):
                case ("info"):
                    System.out.println("Knight: Your weapon will be a sword, your block ability will be 0.2 and you will " +
                            "have a special ability : In your next turn you will have a higher probability to block " +
                            "incoming attack" +
                            "\nBarbarian:Your weapon will be an axe, your block ability will be between 0.1-0.2 and you will " +
                            "have a special ability : In your next turn you may attack twice" +
                            "\nRanger:Your weapon will be a bow, your block ability is 0, you have a special ability :" +
                            " In the next turn you may deal double damage");
                    choice = readString("Your choice");
                    break;
                case ("Knight"):
                case ("knight"):
                    System.out.println("Your choice is to be a knight");
                    return new Knight(player_number, 100, new Sword(10, 5));
                case ("Barbarian"):
                case ("barbarian"):
                    System.out.println("Your choice is to be a barbarian");
                    return new Barbarian(player_number, 100, new Axe(5, 10));
                case ("Ranger"):
                case ("ranger"):
                    System.out.println("Your choice is to be a ranger");
                    return new Ranger(player_number, 100, new Bow(5, 10));
            }
        }
    }

    public static boolean first_player() {
        return (Math.random() * (-1) + 1) % 2 == 0;
    }

    public static void turn(Player<?> attacker, Player<?> defender) throws Exception {
        System.out.println("################################################\nIt's " + attacker.getName() + "'s turn\n" +
                "[ " + attacker.getName() + " " + attacker.getHealth() + " ]\n[ " + defender.getName() + " " + defender.getHealth() + " ]" +
                "\n===================================================");
        if (!attacker.isAbility_activated()) {
            System.out.println(attacker.getName() + " do you want to (attack) or (activate) your special ability?\n");
            String answer = readString("Action");
            switch (answer) {
                case ("Attack"):
                case ("attack"):
                    int dealt_damage = (int) (attacker.get_all_Damage() * (1 - defender.getBlockChance()));
                    System.out.println("You damaged " + defender.getName() + " " + dealt_damage + " points");
                    try {
                        defender.setHealth((int) (defender.getHealth() - dealt_damage));
                    } catch (IllegalArgumentException e) {
                        System.out.println(attacker.getName() + " wins");
                        throw new Exception();
                    }
                    break;
                case ("Activate"):
                case ("activate"):
                    attacker.setAbility_activity(true);
                    break;
            }
        } else {
            System.out.println("You've got active ability, you may only attack");
            for (int i = 0; i < attacker.getNumber_of_attacks(); ++i) {
                int dealt_damage = (int) (attacker.get_all_Damage() * (1 - defender.getBlockChance()));
                System.out.println("You damaged " + defender.getName() + " " + dealt_damage + " points");
                try {
                    defender.setHealth((int) (defender.getHealth() - dealt_damage));
                } catch (IllegalArgumentException e) {
                    System.out.println(attacker.getName() + " wins");
                    throw new Exception();
                }
            }
            attacker.setAbility_activity(false);

        }
    }

    public static void game() {
        System.out.println("Welcome to the arena warriors! Today you will fight against each other. Player1 you go first.");
        Player<?> player1 = choice(1);
        System.out.println(player1.toString());
        System.out.println("Player2 now it's your turn.");
        Player<?> player2 = choice(2);
        System.out.println(player2.toString());
        Player<?> first, second;
        if (first_player()) {
            first = player1;
            second = player2;
        } else {
            first = player2;
            second = player1;
        }
        System.out.println(first.getName() + " will go first " + second.getName() + " will go after him/her ");

        while (true) {
            try {
                turn(first, second);
                turn(second, first);
            } catch (Exception i) {
                break;
            }
        }
    }
}
