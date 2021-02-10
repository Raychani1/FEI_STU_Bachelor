package sk.stuba.fei.project_3.InsuranceWebApp.insurances.nonlifeinsurances;

public enum House {
    Flat("Flat"),
    Familyhouse_brick("Familyhouse - Brick"),
    Familyhouse_wooden("Familyhouse - Wooden");

    private final String house;

    House(String house) {
        this.house = house;
    }

    public String getHouse() {
        return this.house;
    }
}
