package sk.stuba.fei.project_3.InsuranceWebApp.insurances;

import java.time.LocalDate;
import java.time.LocalDateTime;
import java.util.UUID;

import sk.stuba.fei.project_3.InsuranceWebApp.users.User;

import javax.validation.constraints.*;

public abstract class Insurance {
    private String insuranceID = UUID.randomUUID().toString();
    private LocalDateTime dateOfCreation ; // In the program when creating a new insurance it's automatically generated with LocalDateTime.now()
    private User insurer; // In the program when creating a new insurance it's automatically given to a User
    @NotNull(message = "Date of Start is missing")
    private LocalDateTime dateOfStart;
    @NotNull(message = "Date of End is missing")
    private LocalDateTime dateOfEnd;
    @PositiveOrZero(message = "Gross Amount Of Claims can not be negative value")
    private double grossAmountOfClaims;
    @PositiveOrZero(message = "Monthly Payment can not be negative value")
    private double monthlyPayment;

    public Insurance(String insuranceID,  User insurer, LocalDateTime dateOfStart, LocalDateTime dateOfEnd, double grossAmountOfClaims, double monthlyPayment) {
        setInsuranceID(insuranceID);
        setDateOfCreation(LocalDateTime.now());
        setInsurer(insurer);
        setDateOfStart(dateOfStart);
        setDateOfEnd(dateOfEnd);
        setGrossAmountOfClaims(grossAmountOfClaims);
        setMonthlyPayment(monthlyPayment);
    }

    public Insurance(){
        setInsuranceID(UUID.randomUUID().toString());
        setDateOfCreation(LocalDateTime.now());
    }

    public void setInsuranceID(String insuranceID) {
        this.insuranceID = insuranceID;
    }

    public void setDateOfCreation(LocalDateTime dateOfCreation) {
        this.dateOfCreation = dateOfCreation;
    }

    public void setInsurer(User insurer) {
        this.insurer = insurer;
    }

    public void setDateOfStart(LocalDateTime dateOfStart) {
        this.dateOfStart = dateOfStart;
    }

    public void setDateOfEnd(LocalDateTime dateOfEnd) {
        this.dateOfEnd = dateOfEnd;
    }

    public void setGrossAmountOfClaims(double grossAmountOfClaims) {
        this.grossAmountOfClaims = grossAmountOfClaims;
    }

    public void setMonthlyPayment(double monthlyPayment) {
        this.monthlyPayment = monthlyPayment;
    }

    public String  getInsuranceID() {
        return this.insuranceID;
    }

    public LocalDateTime getDateOfCreation() {
        return this.dateOfCreation;
    }

    public User getInsurer() {
        return this.insurer;
    }

    public LocalDateTime getDateOfStart() {
        return this.dateOfStart;
    }

    public LocalDateTime getDateOfEnd() {
        return this.dateOfEnd;
    }

    public double getGrossAmountOfClaims() {
        return this.grossAmountOfClaims;
    }

    public double getMonthlyPayment() {
        return this.monthlyPayment;
    }

    @Override
    public String toString() {
        return "Insurance{" +
                "insuranceID=" + insuranceID +
                ", dateOfCreation=" + dateOfCreation +
                ", insurer=" + insurer +
                ", dateOfStart=" + dateOfStart +
                ", dateOfEnd=" + dateOfEnd +
                ", grossAmmountOfClaims=" + grossAmountOfClaims +
                ", monthlyPayment=" + monthlyPayment +
                '}';
    }
}