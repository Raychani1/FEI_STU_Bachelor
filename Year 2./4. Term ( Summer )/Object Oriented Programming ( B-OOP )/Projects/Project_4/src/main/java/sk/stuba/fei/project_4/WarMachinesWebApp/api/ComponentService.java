package sk.stuba.fei.project_4.WarMachinesWebApp.api;

import org.springframework.stereotype.Service;
import sk.stuba.fei.project_4.WarMachinesWebApp.components.Component;

import java.util.HashMap;
import java.util.Map;

@Service
public class ComponentService implements IAPI<Component> {
    private final Map<String ,Component> components;

    public ComponentService(){
        this.components = new HashMap<>();
    }

    @Override
    public void add(Component component) {
        this.components.put(component.getId(),component);
    }

    @Override
    public Map<String, Component> all() {
        return this.components;
    }

    @Override
    public Component byID(String id) {
        return this.components.get(id);
    }
}
