package sk.stuba.fei.Seminar_1.Exercise_2;

import sk.stuba.fei.Seminar_1.KeyboardInput;

public class Compare {
    public static int compare(int a, int b) {
        if (a > b)
            return 1;
        else if (b > a)
            return -1;
        else
            return 0;
    }

    public static void compare() {
        int a = KeyboardInput.readInt("First number");
        int b = KeyboardInput.readInt("Second number");
        System.out.println(Compare.compare(a, b));
    }

    public static void main(String[] args) {
        Compare.compare();
    }
}
