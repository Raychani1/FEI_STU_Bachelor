package sk.stuba.fei.InsuranceApp.insurances.lifeinsurances.accidentinsurance;

import java.time.LocalDate;

import sk.stuba.fei.InsuranceApp.users.User;
import sk.stuba.fei.InsuranceApp.insurances.Insurance;

public class AccidentInsurance extends Insurance {
    private User insuree;
    private double permanentConsequencesOfAccident;
    private double deathInTheConsequencesOfAccident;
    private double dailyCompensationForHospitalization;
    private TerritorialValidity territorialValidity;

    public AccidentInsurance(long insuranceID, LocalDate dateOfCreation, User insurer, LocalDate dateOfStart, LocalDate dateOfEnd,
                             double grossAmountOfClaims, double monthlyPayment, User insuree,
                             double permanentConsequencesOfAccident, double deathInTheConsequencesOfAccident,
                             double dailyCompensationForHospitalization, TerritorialValidity territorialValidity) {

        super(insuranceID, dateOfCreation, insurer, dateOfStart, dateOfEnd, grossAmountOfClaims, monthlyPayment);
        setInsuree(insuree);
        setPermanentConsequencesOfAccident(permanentConsequencesOfAccident);
        setDeathInTheConsequencesOfAccident(deathInTheConsequencesOfAccident);
        setDailyCompensationForHospitalization(dailyCompensationForHospitalization);
        setTerritorialValidity(territorialValidity);
    }

    public void setInsuree(User insuree) {
        if (insuree == null)
            throw new IllegalArgumentException("(Insurance) : Insuree is missing.");
        this.insuree = insuree;
    }

    public void setPermanentConsequencesOfAccident(double permanentConsequencesOfAccident) {
        if (permanentConsequencesOfAccident < 0) {
            throw new IllegalArgumentException("(Insurance) : The value of Permanent Consequences of Accident can not be a negative value");
        }
        this.permanentConsequencesOfAccident = permanentConsequencesOfAccident;
    }

    public void setDeathInTheConsequencesOfAccident(double deathInTheConsequencesOfAccident) {
        if (deathInTheConsequencesOfAccident < 0) {
            throw new IllegalArgumentException("(Insurance) : The value of Death in the Consequences of Accident can not be a negative value");
        }
        this.deathInTheConsequencesOfAccident = deathInTheConsequencesOfAccident;
    }

    public void setDailyCompensationForHospitalization(double dailyCompensationForHospitalization) {
        if (dailyCompensationForHospitalization < 0) {
            throw new IllegalArgumentException("(Insurance) : The value of Daily Compensation for Hospitalization can not be a negative value");
        }
        this.dailyCompensationForHospitalization = dailyCompensationForHospitalization;
    }

    public void setTerritorialValidity(TerritorialValidity territorialValidity) {
        this.territorialValidity = territorialValidity;
    }

    public User getInsuree() {
        return this.insuree;
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

    public String getTerritorialValidity() {
        return this.territorialValidity.getTerritory();
    }

    @Override
    public String toString() {
        return "AccidentInsurance{" +
                super.toString() +
                "insuree=" + insuree +
                ", permanentConsequencesOfAccident=" + permanentConsequencesOfAccident +
                ", deathInTheConsequencesOfAccident=" + deathInTheConsequencesOfAccident +
                ", dailyCompensationForHospitalization=" + dailyCompensationForHospitalization +
                ", territorialValidity=" + territorialValidity.getTerritory() +
                '}';
    }
}
