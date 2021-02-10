package sk.stuba.fei.project_3.InsuranceWebApp.insurances.lifeinsurances.accidentinsurance;

public enum TerritorialValidity {
    SLOVAKIA("Slovakia"),
    WORLD("World"),
    WORLDANDSLOVAKIA("World + Slovakia");

    private final String territory;

    TerritorialValidity(String territory) {
        this.territory = territory;
    }

    public String getTerritory() {
        return territory;
    }
}