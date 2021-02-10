package sk.stuba.fei.project_3.InsuranceWebApp.insurances.lifeinsurances.travelinsurance;

public enum Purpose {
    BUSINESS("Business"),
    Recreational("Recreational"),
    Sport("Sport");

    private final String purpose;

    Purpose(String purpose) {
        this.purpose = purpose;
    }

    public String getPurpose() {
        return this.purpose;
    }
}