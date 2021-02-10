package sk.stuba.fei.project_3.InsuranceWebApp.address;

import javax.validation.constraints.NotBlank;

public class Address {
    @NotBlank(message = "Zipcode is missing")
    private String zipCode;
    @NotBlank(message = "Town/City Name is missing")
    private String townCityName;
    @NotBlank(message = "Street Name is missing")
    private String streetName;
    @NotBlank(message = "House Number is missing")
    private String houseNumber;

    public Address(String zipCode, String streetName, String townCityName, String houseNumber) {
        setZipCode(zipCode);
        setStreetName(streetName);
        setTownCityName(townCityName);
        setHouseNumber(houseNumber);
    }

    public Address() {

    }

    public void setZipCode(String zipCode) {
        this.zipCode = zipCode;
    }

    public void setTownCityName(String townCityName) {
        this.townCityName = townCityName;
    }

    public void setStreetName(String streetName) {
        this.streetName = streetName;
    }

    public void setHouseNumber(String houseNumber) {
       this.houseNumber = houseNumber;
    }

    public String getZipCode() {
        return this.zipCode;
    }

    public String getTownCityName() {
        return this.townCityName;
    }

    public String getStreetName() {
        return this.streetName;
    }

    public String getHouseNumber() {
        return this.houseNumber;
    }

    @Override
    public String toString() {
        return zipCode + ", "  +townCityName + ", " + streetName + ", " +houseNumber;
    }
}