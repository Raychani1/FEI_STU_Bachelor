package sk.stuba.fei.project_3.InsuranceWebApp.insurances.lifeinsurances.accidentinsurance;

import java.time.LocalDateTime;

import sk.stuba.fei.project_3.InsuranceWebApp.users.User;
import sk.stuba.fei.project_3.InsuranceWebApp.insurances.Insurance;

import javax.validation.constraints.NotNull;
import javax.validation.constraints.PositiveOrZero;

public class AccidentInsurance extends Insurance {
    private User insured;  // In the program I use select and the default value is type of User, so it will never be empty
    @PositiveOrZero(message = "Permanent Consequences Of Accident can not be a negative value")
    private double permanentConsequencesOfAccident;
    @PositiveOrZero(message = "Death In The Consequences Of Accident can not be a negative value")
    private double deathInTheConsequencesOfAccident;
    @PositiveOrZero(message = "Daily Compensation For Hospitalization can not be a negative value")
    private double dailyCompensationForHospitalization;
    private TerritorialValidity territorialValidity; // In the program I use select and the default value is type of TerritorialValidity, so it will never be empty

    public AccidentInsurance(String insuranceID, LocalDateTime dateOfCreation, User insurer, LocalDateTime dateOfStart, LocalDateTime dateOfEnd,
                             double grossAmountOfClaims, double monthlyPayment, User insured,
                             double permanentConsequencesOfAccident, double deathInTheConsequencesOfAccident,
                             double dailyCompensationForHospitalization, TerritorialValidity territorialValidity) {

        super(insuranceID, insurer, dateOfStart, dateOfEnd, grossAmountOfClaims, monthlyPayment);
        setInsured(insured);
        setPermanentConsequencesOfAccident(permanentConsequencesOfAccident);
        setDeathInTheConsequencesOfAccident(deathInTheConsequencesOfAccident);
        setDailyCompensationForHospitalization(dailyCompensationForHospitalization);
        setTerritorialValidity(territorialValidity);
    }

    public AccidentInsurance(){

    }

    public void setInsured(User insured) {
        this.insured = insured;
    }

    public void setPermanentConsequencesOfAccident(double permanentConsequencesOfAccident) {
        this.permanentConsequencesOfAccident = permanentConsequencesOfAccident;
    }

    public void setDeathInTheConsequencesOfAccident(double deathInTheConsequencesOfAccident) {
        this.deathInTheConsequencesOfAccident = deathInTheConsequencesOfAccident;
    }

    public void setDailyCompensationForHospitalization(double dailyCompensationForHospitalization) {
        this.dailyCompensationForHospitalization = dailyCompensationForHospitalization;
    }

    public void setTerritorialValidity(TerritorialValidity territorialValidity) {
        this.territorialValidity = territorialValidity;
    }

    public User getInsured() {
        return this.insured;
    }

    public double getPermanentConsequencesOfAccident() {
        return this.permanentConsequencesOfAccident;
    }

    public double getDeathInTheConsequencesOfAccident() {
        return this.deathInTheConsequencesOfAccident;
    }

    public double getDailyCompensationForHospitalization() {
        return this.dailyCompensationForHospitalization;
    }

    public TerritorialValidity getTerritorialValidity() {
        return this.territorialValidity;
    }

    @Override
    public String toString() {
        return "AccidentInsurance{" +
                super.toString() +
                "insured=" + insured +
                ", permanentConsequencesOfAccident=" + permanentConsequencesOfAccident +
                ", deathInTheConsequencesOfAccident=" + deathInTheConsequencesOfAccident +
                ", dailyCompensationForHospitalization=" + dailyCompensationForHospitalization +
                ", territorialValidity=" + territorialValidity.getTerritory() +
                '}';
    }
}