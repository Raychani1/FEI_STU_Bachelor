package sk.stuba.fei.InsuranceApp.address;

public class Address {
    private String zipCode;
    private String streetName;
    private String townCityName;
    private String houseNumber;

    public Address(String zipCode, String streetName, String townCityName, String houseNumber) {
        setZipCode(zipCode);
        setStreetName(streetName);
        setTownCityName(townCityName);
        setHouseNumber(houseNumber);
    }

    public void setZipCode(String zipCode) {
        if (zipCode == null || zipCode.trim().isEmpty())
            throw new IllegalArgumentException("(Address) : ZIP Code is missing.");
        this.zipCode = zipCode;
    }

    public void setStreetName(String streetName) {
        if (streetName == null || streetName.trim().isEmpty())
            throw new IllegalArgumentException("(Address) : Street Name is missing.");
        this.streetName = streetName;
    }

    public void setTownCityName(String townCityName) {
        if (townCityName == null || townCityName.trim().isEmpty())
            throw new IllegalArgumentException("(Address) : Town Name is missing.");
        this.townCityName = townCityName;
    }

    public void setHouseNumber(String houseNumber) {
        if (houseNumber == null || houseNumber.trim().isEmpty())
            throw new IllegalArgumentException("(Address) : House Number is missing.");
        this.houseNumber = houseNumber;
    }

    public String getZipCode() {
        return this.zipCode;
    }

    public String getStreetName() {
        return this.streetName;
    }

    public String getTownCityName() {
        return this.townCityName;
    }

    public String getHouseNumber() {
        return this.houseNumber;
    }

    @Override
    public String toString() {
        return "Address{" +
                "zipCode='" + zipCode + '\'' +
                ", streetName='" + streetName + '\'' +
                ", townCityName='" + townCityName + '\'' +
                ", houseNumber=" + houseNumber +
                '}';
    }
}
