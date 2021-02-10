package sk.stuba.fei.project_3.InsuranceWebApp.insurances.nonlifeinsurances;

import java.time.LocalDate;
import java.time.LocalDateTime;

import sk.stuba.fei.project_3.InsuranceWebApp.users.User;
import sk.stuba.fei.project_3.InsuranceWebApp.address.Address;
import sk.stuba.fei.project_3.InsuranceWebApp.insurances.Insurance;

import javax.validation.Valid;
import javax.validation.constraints.NotNull;
import javax.validation.constraints.PositiveOrZero;

public abstract class NonLifeInsurance extends Insurance {
    @NotNull(message = "House Type is missing")
    private House houseType;  // In the program I use select and the default value is type of House, so it will never be empty
    @Valid
    private Address addressOfRealEstate;
    @PositiveOrZero(message = "Value of Real Estate can not be negative value")
    private double valueOfRealEstate;

    public NonLifeInsurance(String insuranceID, User insurer, LocalDateTime dateOfStart, LocalDateTime dateOfEnd,
                            double grossAmountOfClaims, double monthlyPayment, House houseType, Address addressOfRealEstate,
                            double valueOfRealEstate) {

        super(insuranceID, insurer, dateOfStart, dateOfEnd, grossAmountOfClaims, monthlyPayment);
        setHouseType(houseType);
        setAddressOfRealEstate(addressOfRealEstate);
        setValueOfRealEstate(valueOfRealEstate);

    }

    public NonLifeInsurance(){}

    public void setHouseType(House houseType) {
        this.houseType = houseType;
    }

    public void setAddressOfRealEstate(Address addressOfRealEstate) {
        this.addressOfRealEstate = addressOfRealEstate;
    }

    public void setValueOfRealEstate(double valueOfRealEstate) {
        this.valueOfRealEstate = valueOfRealEstate;
    }

    public House getHouseType() {
        return this.houseType;
    }

    public Address getAddressOfRealEstate() {
        return this.addressOfRealEstate;
    }

    public double getValueOfRealEstate() {
        return this.valueOfRealEstate;
    }

    @Override
    public String toString() {
        return "NonLifeInsurance{" +
                super.toString() +
                "houseType=" + houseType.getHouse() +
                ", addressOfRealEstate=" + addressOfRealEstate +
                ", valueOfRealEstate=" + valueOfRealEstate +
                '}';
    }
}
