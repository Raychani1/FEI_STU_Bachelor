package sk.stuba.fei.project_3.InsuranceWebApp.insurances.nonlifeinsurances;

import java.time.LocalDate;
import java.time.LocalDateTime;

import sk.stuba.fei.project_3.InsuranceWebApp.users.User;
import sk.stuba.fei.project_3.InsuranceWebApp.address.Address;

public class HouseAndApartmentInsurance extends NonLifeInsurance {

    private boolean garageInsurance;

    public HouseAndApartmentInsurance(String insuranceID, User insurer, LocalDateTime dateOfStart, LocalDateTime dateOfEnd,
                                      double grossAmountOfClaims, double monthlyPayment, House houseType,
                                      Address addressOfRealEstate, double valueOfRealEstate, boolean garageInsurance) {

        super(insuranceID, insurer, dateOfStart, dateOfEnd, grossAmountOfClaims, monthlyPayment,
                houseType, addressOfRealEstate, valueOfRealEstate);
        setGarageInsurance(garageInsurance);
    }
    public HouseAndApartmentInsurance(){}

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