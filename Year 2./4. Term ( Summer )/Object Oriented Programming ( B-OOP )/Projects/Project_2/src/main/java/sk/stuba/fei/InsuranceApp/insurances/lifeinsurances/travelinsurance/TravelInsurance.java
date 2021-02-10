package sk.stuba.fei.InsuranceApp.insurances.lifeinsurances.travelinsurance;

import java.time.LocalDate;

import sk.stuba.fei.InsuranceApp.users.User;
import sk.stuba.fei.InsuranceApp.insurances.Insurance;

public class TravelInsurance extends Insurance {
    private User insuree;
    private boolean withinEU;
    private Purpose purpose;

    public TravelInsurance(long insuranceID, LocalDate dateOfCreation, User insurer, LocalDate dateOfStart, LocalDate dateOfEnd,
                           double grossAmountOfClaims, double monthlyPayment, User insuree,
                           boolean withinEU, Purpose purpose) {

        super(insuranceID, dateOfCreation, insurer, dateOfStart, dateOfEnd, grossAmountOfClaims, monthlyPayment);
        setInsuree(insuree);
        setWithinEU(withinEU);
        setPurpose(purpose);
    }

    public void setInsuree(User insuree) {
        if (insuree == null)
            throw new IllegalArgumentException("(Insurance) : Insuree is missing.");
        this.insuree = insuree;
    }

    public void setWithinEU(boolean withinEU) {
        this.withinEU = withinEU;
    }

    public void setPurpose(Purpose purpose) {
        this.purpose = purpose;
    }

    public User getInsuree() {
        return this.insuree;
    }

    public boolean isWithinEU() {
        return this.withinEU;
    }

    public String getPurpose() {
        return this.purpose.getPurpose();
    }

    @Override
    public String toString() {
        return "TravelInsurance{" +
                super.toString() +
                "insuree=" + insuree +
                ", withinEU=" + withinEU +
                ", purpose=" + purpose.getPurpose() +
                '}';
    }
}
