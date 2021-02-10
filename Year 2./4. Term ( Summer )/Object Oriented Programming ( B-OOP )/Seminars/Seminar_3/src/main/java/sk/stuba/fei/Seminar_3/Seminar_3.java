package sk.stuba.fei.Seminar_3;

import sk.stuba.fei.Seminar_3.Computer.*;

public class Seminar_3 {
    Component[] components = {new Graphic_card("1080", 8), new RAM("abc", 4, 16, 2600),
            new RAM("abc", 4, 16, 2600),
            new HDD_SSD("ssd", 1000, 1500, 1500, 6000),
            new Motherboard("mots", 4, 1, 3000, "abx"), new Power("pow"),
            new Processor("Ryzen 9", "AMD", 8, 16, 2000, 3900, "abc")};
    Computer pc = new Computer(components);
    pc.turnOn();
}
