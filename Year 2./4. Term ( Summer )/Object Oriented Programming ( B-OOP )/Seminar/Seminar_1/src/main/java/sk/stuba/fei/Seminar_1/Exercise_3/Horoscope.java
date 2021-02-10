package sk.stuba.fei.Seminar_1.Exercise_3;

import sk.stuba.fei.Seminar_1.KeyboardInput;

public class Horoscope {
    public static int sign_number(int month, int day) {
        if (day > 0) {
            switch (month) {
                case 1:
                    if (day <= 20)
                        return 1;
                    else if (day <= 31)
                        return 2;

                case 2:
                    if (day <= 19)
                        return 2;
                    else if (day <= 29)
                        return 3;

                case 3:
                    if (day <= 20)
                        return 3;
                    else if (day <= 31)
                        return 4;

                case 4:
                    if (day <= 21)
                        return 4;
                    else if (day <= 30)
                        return 5;

                case 5:
                    if (day <= 21)
                        return 5;
                    else if (day <= 31)
                        return 6;

                case 6:
                    if (day <= 21)
                        return 6;
                    else if (day <= 30)
                        return 7;

                case 7:
                    if (day <= 22)
                        return 7;
                    else if (day <= 31)
                        return 8;

                case 8:
                    if (day <= 22)
                        return 8;
                    else if (day <= 31)
                        return 9;

                case 9:
                    if (day <= 22)
                        return 9;
                    else if (day <= 30)
                        return 10;

                case 10:
                    if (day <= 22)
                        return 10;
                    else if (day <= 31)
                        return 11;

                case 11:
                    if (day <= 21)
                        return 11;
                    else if (day <= 30)
                        return 12;

                case 12:
                    if (day <= 21)
                        return 12;
                    else if (day <= 31)
                        return 1;

            }
        }
        return 0;
    }

    public static String sign_string(int sign_number) {
        switch (sign_number) {
            case 1:
                return ("Capricorn");
            case 2:
                return ("Aquarius");
            case 3:
                return ("Pisces");
            case 4:
                return ("Aries");
            case 5:
                return ("Taurus");
            case 6:
                return ("Gemini");
            case 7:
                return ("Cancer");
            case 8:
                return ("Leo");
            case 9:
                return ("Virgo");
            case 10:
                return ("Libra");
            case 11:
                return ("Scorpio");
            case 12:
                return ("Sagittarius");
        }
        return ("Wrong data");
    }

    public static void horoscope() {
        do {
            int month = KeyboardInput.readInt("Month");
            int day = KeyboardInput.readInt("Day");
            System.out.println(Horoscope.sign_string(Horoscope.sign_number(month, day)));
            System.out.println("---------------------------------------------");

        } while ((KeyboardInput.readChar("Again? y/n") == 'y'));

    }

    public static void main(String[] args) {
        Horoscope.horoscope();
    }
}
