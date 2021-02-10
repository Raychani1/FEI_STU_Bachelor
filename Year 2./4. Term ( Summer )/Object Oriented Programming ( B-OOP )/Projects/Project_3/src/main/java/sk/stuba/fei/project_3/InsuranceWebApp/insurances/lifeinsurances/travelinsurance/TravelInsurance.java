package sk.stuba.fei.project_3.InsuranceWebApp.insurances.lifeinsurances.travelinsurance;

import java.time.LocalDate;
import java.time.LocalDateTime;

import sk.stuba.fei.project_3.InsuranceWebApp.users.User;
import sk.stuba.fei.project_3.InsuranceWebApp.insurances.Insurance;

import javax.validation.constraints.NotNull;

public class TravelInsurance extends Insurance {
    private User insured; // In the program I use select and the default value is type of User, so it will never be empty
    private boolean withinEU;
    private Purpose purpose; // In the program I use select and the default value is type of Purpose, so it will never be empty

    public TravelInsurance(String insuranceID, User insurer, LocalDateTime dateOfStart, LocalDateTime dateOfEnd,
                           double grossAmountOfClaims, double monthlyPayment, User insured,
                           boolean withinEU, Purpose purpose) {

        super(insuranceID, insurer, dateOfStart, dateOfEnd, grossAmountOfClaims, monthlyPayment);
        setInsured(insured);
        setWithinEU(withinEU);
        setPurpose(purpose);
    }
    public TravelInsurance(){

    }
    public void setInsured(User insured) {
        this.insured = insured;
    }

    public void setWithinEU(boolean withinEU) {
        this.withinEU = withinEU;
    }

    public void setPurpose(Purpose purpose) {
        this.purpose = purpose;
    }

    public User getInsured() {
        return this.insured;
    }

    public boolean isWithinEU() {
        return this.withinEU;
    }

    public Purpose getPurpose() {
        return this.purpose;
    }

    @Override
    public String toString() {
        return "TravelInsurance{" +
                super.toString() +
                "insuree=" + insured +
                ", withinEU=" + withinEU +
                ", purpose=" + purpose.getPurpose()+
                '}';
    }
}
