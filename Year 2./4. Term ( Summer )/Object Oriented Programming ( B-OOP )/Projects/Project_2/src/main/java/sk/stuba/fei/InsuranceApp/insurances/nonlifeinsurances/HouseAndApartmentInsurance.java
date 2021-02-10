package sk.stuba.fei.InsuranceApp.insurances.nonlifeinsurances;

import java.time.LocalDate;

import sk.stuba.fei.InsuranceApp.users.User;
import sk.stuba.fei.InsuranceApp.address.Address;

public class HouseAndApartmentInsurance extends NonLifeInsurance {

    private boolean garageInsurance;

    public HouseAndApartmentInsurance(long insuranceID, LocalDate dateOfCreation, User insurer, LocalDate dateOfStart, LocalDate dateOfEnd,
                                      double grossAmountOfClaims, double monthlyPayment, House houseType,
                                      Address addressOfRealEstate, double valueOfRealEstate, boolean garageInsurance) {

        super(insuranceID, dateOfCreation, insurer, dateOfStart, dateOfEnd, grossAmountOfClaims, monthlyPayment,
                houseType, addressOfRealEstate, valueOfRealEstate);
        setGarageInsurance(garageInsurance);
    }

    public void setGarageInsurance(boolean garageInsurance) {
        this.garageInsurance = garageInsurance;
    }

    public boolean isGarageInsurance() {
        return this.garageInsurance;
    }

    @Override
    public String toString() {
        return "HouseAndApartmentInsurance{" +
                super.toString() +
                "garageInsurance=" + garageInsurance +
                '}';
    }
}
