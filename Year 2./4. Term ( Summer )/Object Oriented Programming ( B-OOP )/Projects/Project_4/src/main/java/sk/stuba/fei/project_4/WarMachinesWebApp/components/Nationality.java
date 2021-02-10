package sk.stuba.fei.project_4.WarMachinesWebApp.components;

public enum Nationality {
    USA("United States of America"),
    USSR("Union of Soviet Socialist Republics"),
    GERMANY("Germany"),
    GREAT_BRITAIN("Great Britain");

    private String nationality;

    Nationality(String nationality){
        this.nationality = nationality;
    }

    public String getNationality() {
        return this.nationality;
    }
}
