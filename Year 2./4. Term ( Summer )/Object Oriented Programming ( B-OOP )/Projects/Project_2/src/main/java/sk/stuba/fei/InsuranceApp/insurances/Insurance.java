package sk.stuba.fei.InsuranceApp.insurances;

import java.time.LocalDate;

import sk.stuba.fei.InsuranceApp.users.User;

public abstract class Insurance {
    private long insuranceID;
    private LocalDate dateOfCreation;
    private User insurer;
    private LocalDate dateOfStart;
    private LocalDate dateOfEnd;
    private double grossAmountOfClaims;
    private double monthlyPayment;

    public Insurance(long insuranceID, LocalDate dateOfCreation, User insurer, LocalDate dateOfStart, LocalDate dateOfEnd, double grossAmountOfClaims, double monthlyPayment) {
        setInsuranceID(insuranceID);
        setDateOfCreation(dateOfCreation);
        setInsurer(insurer);
        setDateOfStart(dateOfStart);
        setDateOfEnd(dateOfEnd);
        setGrossAmountOfClaims(grossAmountOfClaims);
        setMonthlyPayment(monthlyPayment);
    }

    private void setInsuranceID(long insuranceID) {
        if (insuranceID <= 0) {
            throw new IllegalArgumentException("(Insurance) : Insurance ID must be greater than 0.");
        }
        this.insuranceID = insuranceID;
    }

    public void setDateOfCreation(LocalDate dateOfCreation) {
        if (dateOfCreation == null)
            throw new IllegalArgumentException("(Insurance) : Date of Creation is missing.");
        this.dateOfCreation = dateOfCreation;
    }

    public void setInsurer(User insurer) {
        if (insurer == null) {
            throw new IllegalArgumentException("(Insurance) : Insurer is missing.");
        }
        this.insurer = insurer;
    }

    public void setDateOfStart(LocalDate dateOfStart) {
        if (dateOfStart == null)
            throw new IllegalArgumentException("(Insurance) : Date of Start is missing.");
        this.dateOfStart = dateOfStart;
    }

    public void setDateOfEnd(LocalDate dateOfEnd) {
        if (dateOfEnd == null)
            throw new IllegalArgumentException("(Insurance) : Date of End is missing.");
        this.dateOfEnd = dateOfEnd;
    }

    public void setGrossAmountOfClaims(double grossAmountOfClaims) {
        if (grossAmountOfClaims < 0)
            throw new IllegalArgumentException("(Insurance) : Gross Amount of Claims can not be a negative value");
        this.grossAmountOfClaims = grossAmountOfClaims;
    }

    public void setMonthlyPayment(double monthlyPayment) {
        if (monthlyPayment < 0)
            throw new IllegalArgumentException("(Insurance) : Monthly Payment can not be a negative value");
        this.monthlyPayment = monthlyPayment;
    }

    public long getInsuranceID() {
        return this.insuranceID;
    }

    public LocalDate getDateOfCreation() {
        return this.dateOfCreation;
    }

    public User getInsurer() {
        return this.insurer;
    }

    public LocalDate getDateOfStart() {
        return this.dateOfStart;
    }

    public LocalDate getDateOfEnd() {
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
                ", grossAmountOfClaims=" + grossAmountOfClaims +
                ", monthlyPayment=" + monthlyPayment +
                '}';
    }
}
