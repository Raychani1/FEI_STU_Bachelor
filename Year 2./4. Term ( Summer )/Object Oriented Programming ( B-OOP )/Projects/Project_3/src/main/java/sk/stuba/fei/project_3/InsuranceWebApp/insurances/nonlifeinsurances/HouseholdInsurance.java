package sk.stuba.fei.project_3.InsuranceWebApp.insurances.nonlifeinsurances;

import java.time.LocalDate;
import java.time.LocalDateTime;

import sk.stuba.fei.project_3.InsuranceWebApp.users.User;
import sk.stuba.fei.project_3.InsuranceWebApp.address.Address;

import javax.validation.constraints.PositiveOrZero;

public class HouseholdInsurance extends NonLifeInsurance {
    @PositiveOrZero(message = "Household Equipment Value can not be negative value")
    private double householdEquipmentValue;

    public HouseholdInsurance(String insuranceID, User insurer, LocalDateTime dateOfStart, LocalDateTime dateOfEnd,
                              double grossAmountOfClaims, double monthlyPayment, House houseType,
                              Address addressOfRealEstate, double valueOfRealEstate, double householdEquipmentValue) {

        super(insuranceID, insurer, dateOfStart, dateOfEnd, grossAmountOfClaims, monthlyPayment,
                houseType, addressOfRealEstate, valueOfRealEstate);
        setHouseholdEquipmentValue(householdEquipmentValue);
    }

    public HouseholdInsurance(){}

    public void setHouseholdEquipmentValue(double householdEquipmentValue) {
        this.householdEquipmentValue = householdEquipmentValue;
    }

    public double getHouseholdEquipmentValue() {
        return this.householdEquipmentValue;
    }

    @Override
    public String toString() {
        return "HouseholdInsurance{" +
                super.toString() +
                "householdEquipmentValue=" + householdEquipmentValue +
                '}';
    }
}