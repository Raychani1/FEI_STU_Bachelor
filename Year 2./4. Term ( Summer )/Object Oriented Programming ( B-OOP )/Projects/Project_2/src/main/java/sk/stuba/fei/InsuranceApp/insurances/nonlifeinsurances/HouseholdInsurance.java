package sk.stuba.fei.InsuranceApp.insurances.nonlifeinsurances;

import java.time.LocalDate;

import sk.stuba.fei.InsuranceApp.users.User;
import sk.stuba.fei.InsuranceApp.address.Address;

public class HouseholdInsurance extends NonLifeInsurance {
    private double householdEquipmentValue;

    public HouseholdInsurance(long insuranceID, LocalDate dateOfCreation, User insurer, LocalDate dateOfStart, LocalDate dateOfEnd,
                              double grossAmountOfClaims, double monthlyPayment, House houseType,
                              Address addressOfRealEstate, double valueOfRealEstate, double householdEquipmentValue) {

        super(insuranceID, dateOfCreation, insurer, dateOfStart, dateOfEnd, grossAmountOfClaims, monthlyPayment,
                houseType, addressOfRealEstate, valueOfRealEstate);
        setHouseholdEquipmentValue(householdEquipmentValue);
    }

    public void setHouseholdEquipmentValue(double householdEquipmentValue) {
        if (householdEquipmentValue < 0)
            throw new IllegalArgumentException("(Insurance) : The value of Household Equipment can not be a negative value");
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
