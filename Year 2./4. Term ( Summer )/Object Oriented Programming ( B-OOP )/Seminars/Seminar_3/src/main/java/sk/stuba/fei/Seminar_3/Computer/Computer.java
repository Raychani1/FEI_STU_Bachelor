package sk.stuba.fei.Seminar_3.Computer;

import java.util.Arrays;

public class Computer {
    private Component[] components;

    public Computer(Component[] components) {
        this.components = components;
    }

    public int num_of_component (Type component_type) {
        int number_of_comp = 0;
        for(Component component : this.components){
            if(component.type==component_type)
                number_of_comp++;
        }
        return number_of_comp;
    }

    public String missingParts(){
        String missing_parts ="";
        if(num_of_component(Type.ENERGY)==0){
            missing_parts = missing_parts + "\nYour power supply is missing";
        }

        if(num_of_component(Type.GPU)==0){
            missing_parts = missing_parts + "\nYour graphic card is missing";
        }

        if(num_of_component(Type.HDD)==0){
            missing_parts = missing_parts + "\nYour HDD/SSD is missing";
        }

        if(num_of_component(Type.MOTHER)==0){
            missing_parts = missing_parts + "\nYour motherboard is missing";
        }

        if(num_of_component(Type.CPU)==0){
            missing_parts = missing_parts + "\nYour processor is missing";
        }

        if(num_of_component(Type.RAM)==0){
            missing_parts = missing_parts + "\nYour RAM is missing";
        }

        if(!missing_parts.equals(""))
            return missing_parts;
        return "OK";
    }

    public RAM get_ram(){
        for(Component component : this.components){
            if(component.type==Type.values()[0])
                return (RAM)component;
        }
        return null;
    }
    public HDD_SSD get_hdd(){
        for(Component component : this.components){
            if(component.type==Type.values()[1])
                return (HDD_SSD)component;
        }
        return null;
    }
    public Processor get_cpu(){
        for(Component component : this.components){
            if(component.type==Type.values()[2])
                return (Processor)component;
        }
        return null;
    }
    public Graphic_card get_graphic_card(){
        for(Component component : this.components){
            if(component.type==Type.values()[3])
                return (Graphic_card)component;
        }
        return null;
    }
    public Motherboard get_moterboard(){
        for(Component component : this.components){
            if(component.type==Type.values()[4])
                return (Motherboard)component;
        }
        return null;
    }
    public Power get_energy_supply(){
        for(Component component : this.components){
            if(component.type==Type.values()[5])
                return (Power) component;
        }
        return null;
    }



    public String compatibilityCheck(){
        Motherboard motherboard = get_moterboard();
        RAM ram = get_ram();
        Processor processor = get_cpu();

        if(this.missingParts().equals("OK")) {
            if (motherboard.getDdr_memory()!= ram.getDdr_type()) {
                return "Your motherboard supports DDR" + motherboard.getDdr_memory()
                        + " but you are using DDR" + ram.getDdr_type() + " which is not supported!";
            } else if (motherboard.getMax_ram_freq() < ram.getClock_frequency()) {
                return "Your motherboard supports RAM with max frequency " + motherboard.getMax_ram_freq()
                        + " but you are using RAM with frequency " + ram.getClock_frequency() + " which is not supported!";
            } else if (motherboard.getMax_ram_slot() < num_of_component(Type.RAM)) {
                return "You are using " + num_of_component(Type.RAM) + " RAMs on a motherboard which supports only " + motherboard.getMax_ram_slot() + " RAMs maximally";
            } else if (!motherboard.getSocket().equals(processor.getSocket())) {
                return processor.getSocket() + " the socket you want to use is unsupported by your motherboard, which is compatible only with "
                        + motherboard.getSocket() + " socket";
            }
            return "Compatible";
        }
        else
            return this.missingParts();
    }
    public double calculateEnergyCons(){
        if(this.missingParts().equals("OK")) {
            return get_cpu().getPowerConsumption() + get_moterboard().getPowerConsumption()
                    + get_graphic_card().getPowerConsumption() + get_hdd().getPowerConsumption() + get_ram().getPowerConsumption();
        }
        return -1;
    }
    public void turnOn(){
        System.out.println("Compatibility: "+this.compatibilityCheck());
        if(this.compatibilityCheck().equals("Compatible")){
            if(get_energy_supply().getPowerConsumption()<this.calculateEnergyCons()){
                System.out.println("Your PC can't be turned on because of low power, you need "
                        +(this.calculateEnergyCons()-get_energy_supply().getPowerConsumption()) + " more Watts");
            }
            else
            {
                System.out.println(this.toString() + "\nYour PC is turned on");
            }
        }
    }

    @Override
    public String toString() {
        return "Computer{" +
                "components=" + Arrays.toString(components) +
                '}';
    }
}
