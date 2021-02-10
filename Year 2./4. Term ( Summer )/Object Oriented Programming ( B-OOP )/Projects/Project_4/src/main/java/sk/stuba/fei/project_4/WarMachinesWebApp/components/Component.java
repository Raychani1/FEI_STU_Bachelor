package sk.stuba.fei.project_4.WarMachinesWebApp.components;

import java.util.UUID;

public abstract class Component {
    private String id;
    private String name;

    public Component(String name){
        setId();
        setName(name);
    }

    public void setId() {
        this.id = UUID.randomUUID().toString();
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getId() {
        return this.id;
    }

    public String getName() {
        return this.name;
    }

    @Override
    public String toString() {
        return "Component{" +
                "id='" + id + '\'' +
                ", name='" + name + '\'' +
                '}';
    }
}
