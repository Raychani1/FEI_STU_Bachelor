package sk.stuba.fei.InsuranceApp.insurances.nonlifeinsurances;

import java.time.LocalDate;

import sk.stuba.fei.InsuranceApp.users.User;
import sk.stuba.fei.InsuranceApp.address.Address;
import sk.stuba.fei.InsuranceApp.insurances.Insurance;

public abstract class NonLifeInsurance extends Insurance {
    private House houseType;
    private Address addressOfRealEstate;
    private double valueOfRealEstate;

    public NonLifeInsurance(long insuranceID, LocalDate dateOfCreation, User insurer, LocalDate dateOfStart, LocalDate dateOfEnd,
                            double grossAmountOfClaims, double monthlyPayment, House houseType, Address addressOfRealEstate,
                            double valueOfRealEstate) {

        super(insuranceID, dateOfCreation, insurer, dateOfStart, dateOfEnd, grossAmountOfClaims, monthlyPayment);
        setHouseType(houseType);
        setAddressOfRealEstate(addressOfRealEstate);
        setValueOfRealEstate(valueOfRealEstate);

    }

    protected void setHouseType(House houseType) {
        this.houseType = houseType;
    }

    public void setAddressOfRealEstate(Address addressOfRealEstate) {
        if (addressOfRealEstate == null)
            throw new IllegalArgumentException("(Insurance) : Address of Real Estate is missing");
        this.addressOfRealEstate = addressOfRealEstate;
    }

    public void setValueOfRealEstate(double valueOfRealEstate) {
        if (valueOfRealEstate < 0)
            throw new IllegalArgumentException("(Insurance) : The Value of Real Estate can not be a negative value");
        this.valueOfRealEstate = valueOfRealEstate;
    }

    public String getHouseType() {
        return this.houseType.getHouse();
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
