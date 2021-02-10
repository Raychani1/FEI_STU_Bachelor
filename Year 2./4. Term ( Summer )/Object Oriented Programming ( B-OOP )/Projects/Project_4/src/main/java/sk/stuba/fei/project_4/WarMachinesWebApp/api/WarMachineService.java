package sk.stuba.fei.project_4.WarMachinesWebApp.api;

import org.springframework.stereotype.Service;
import sk.stuba.fei.project_4.WarMachinesWebApp.warmachines.WarMachine;

import java.util.HashMap;
import java.util.Map;

@Service
public class WarMachineService implements IAPI<WarMachine> {
    private final Map<String , WarMachine> warMachines;

    public WarMachineService(){
        this.warMachines = new HashMap<>();
    }

    @Override
    public void add(WarMachine warMachine) {
        warMachines.put(warMachine.getId(),warMachine);
    }

    @Override
    public Map<String, WarMachine> all() {
        return this.warMachines;
    }

    @Override
    public WarMachine byID(String id){
        return this.warMachines.get(id);
    }
}
