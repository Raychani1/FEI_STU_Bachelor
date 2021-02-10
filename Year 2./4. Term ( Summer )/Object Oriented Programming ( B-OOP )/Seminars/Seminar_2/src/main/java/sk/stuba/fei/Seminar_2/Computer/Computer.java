package sk.stuba.fei.Seminar_2.Computer;

public class Computer {
    private Processor processor;
    private Graphic_card graphic_card;
    private HDD_SSD hdd_ssd;
    private Motherboard motherboard;
    private RAM ram;
    private Power power;

    public Computer(Processor processor, Graphic_card graphic_card, HDD_SSD hdd_ssd, Motherboard motherboard, RAM ram, Power power) {
        this.processor = processor;
        this.graphic_card = graphic_card;
        this.hdd_ssd = hdd_ssd;
        this.motherboard = motherboard;
        this.ram = ram;
        this.power = power;
    }

    public String compatibilityCheck() {
        if (this.missingParts().equals("OK")) {
            if (motherboard.getDdr_memory() != ram.getDdr_type()) {
                return "Your motherboard supports DDR" + motherboard.getDdr_memory()
                        + " but you are using DDR" + ram.getDdr_type() + " which is not supported!";
            } else if (motherboard.getMax_ram_freq() < ram.getClock_frequency()) {
                return "Your motherboard supports RAM with max frequency " + motherboard.getMax_ram_freq()
                        + " but you are using RAM with frequency " + ram.getClock_frequency() + " which is not supported!";
            } else if (motherboard.getMax_ram_slot() < ram.getNum_of_ram()) {
                return "You are using " + ram.getNum_of_ram() + " RAMs on a motherboard which supports only " + motherboard.getMax_ram_slot() + " RAMs maximally";
            } else if (!motherboard.getSocket().equals(processor.getSocket())) {
                return processor.getSocket() + " the socket you want to use is unsupported by your motherboard, which is compatible only with "
                        + motherboard.getSocket() + " socket";
            }
            return "Compatible";
        } else
            return this.missingParts();
    }

    public double calculateEnergyCons() {
        if (this.missingParts().equals("OK")) {
            return this.processor.getEnergy_cons() + this.motherboard.getEnergy_cons()
                    + this.graphic_card.getEnergy_cons() + this.hdd_ssd.getEnergy_cons() + this.ram.getEnergy_cons();
        }
        return -1;
    }

    public String missingParts() {
        String missing_parts = "";
        if (this.power == null) {
            missing_parts = missing_parts + "\nYour power supply is missing";
        }

        if (this.graphic_card == null) {
            missing_parts = missing_parts + "\nYour graphic card is missing";
        }

        if (this.hdd_ssd == null) {
            missing_parts = missing_parts + "\nYour HDD/SSD is missing";
        }

        if (this.motherboard == null) {
            missing_parts = missing_parts + "\nYour motherboard is missing";
        }

        if (this.processor == null) {
            missing_parts = missing_parts + "\nYour processor is missing";
        }

        if (this.ram == null) {
            missing_parts = missing_parts + "\nYour RAM is missing";
        }

        if (!missing_parts.equals(""))
            return missing_parts;
        return "OK";
    }

    @Override
    public String toString() {
        return "Computer{" +
                "\n\tprocessor=" + processor +
                ", \n\tgraphic_card=" + graphic_card +
                ", \n\thdd_ssd=" + hdd_ssd +
                ", \n\tmotherboard=" + motherboard +
                ", \n\tram=" + ram +
                ", \n\tpower=" + power +
                "\n}";
    }

    public void turnOn() {
        System.out.println("Compatibility: " + this.compatibilityCheck());
        if (this.compatibilityCheck().equals("Compatible")) {
            if (this.power.getPower_watt() < this.calculateEnergyCons()) {
                System.out.println("Your PC can't be turned on because of low power, you need "
                        + (this.calculateEnergyCons() - this.power.getPower_watt()) + " more Watts");
            } else {
                System.out.println(this.toString() + "\nYour PC is turned on");
            }
        }
    }
}
