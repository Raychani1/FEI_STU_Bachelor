package sk.stuba.fei.Seminar_2;

import sk.stuba.fei.Seminar_2.Computer.*;
import sk.stuba.fei.Seminar_2.MyDate.MyDate;

public class Seminar_2 {
    public static void main(String[] args) {
        Processor proc = new Processor("AMD", "RYZEN 5 2600", 6, 12, 3.4, 3.9, 65, "AMD AM4");
        RAM ram = new RAM("HyperX", 4, 4, 16, 2666, 1.2);
        Power pow = new Power("Corsair", "Battery", 1000);
        Motherboard moth = new Motherboard("ABC", 4, 4, 3000, "AMD AM4", 200);
        HDD_SSD hdd = new HDD_SSD("HDD", 10000, 1500, 1500, 6000, 300);
        Graphic_card graph = new Graphic_card("1080Ti", 16, 100);
        Computer my_pc = new Computer(proc, graph, hdd, moth, ram, pow);

        my_pc.turnOn();


        MyDate today = new MyDate(2, 3, 2020);
        today.setDate(5, 3, 2020);
        System.out.println(today.toString());

    }
}
