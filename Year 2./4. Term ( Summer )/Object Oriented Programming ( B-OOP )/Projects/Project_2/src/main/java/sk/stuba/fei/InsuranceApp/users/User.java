package sk.stuba.fei.InsuranceApp.users;

import java.util.*;

import sk.stuba.fei.InsuranceApp.address.Address;
import sk.stuba.fei.InsuranceApp.insurances.Insurance;

public class User {
    private long userID;
    private String firstName;
    private String lastName;
    private String personalNumber;
    private String email;
    private Address permanentAddress;
    private Address addressOfCorrespondence;
    private List<Insurance> insurances;

    public User(long userID, String firstName, String lastName, String personalNumber, String email, Address permanentAddress, Address addressOfCorrespondence, List<Insurance> insurances) {
        setUserID(userID);
        setFirstName(firstName);
        setLastName(lastName);
        setPersonalNumber(personalNumber);
        setEmail(email);
        setPermanentAddress(permanentAddress);
        setAddressOfCorrespondence(addressOfCorrespondence);
        setInsurances(insurances);
    }

    public User(long userID, String firstName, String lastName, String personalNumber, String email, Address permanentAddress, Address addressOfCorrespondence) {
        this(userID, firstName, lastName, personalNumber, email, permanentAddress, addressOfCorrespondence, new ArrayList<Insurance>());
    }

    public User(long userID, String firstName, String lastName, String personalNumber, String email, Address permanentAddress, List<Insurance> insurances) {
        this(userID, firstName, lastName, personalNumber, email, permanentAddress, null, insurances);
    }

    public User(long userID, String firstName, String lastName, String personalNumber, String email, Address permanentAddress) {
        this(userID, firstName, lastName, personalNumber, email, permanentAddress, null, new ArrayList<Insurance>());
    }

    private void setUserID(long userID) {
        this.userID = userID;
    }

    public void setFirstName(String firstName) {
        if (firstName == null || firstName.trim().isEmpty())
            throw new IllegalArgumentException("(User) : First Name is missing.");
        this.firstName = firstName;
    }

    public void setLastName(String lastName) {
        if (lastName == null || lastName.trim().isEmpty())
            throw new IllegalArgumentException("(User) : Last Name is missing.");
        this.lastName = lastName;
    }

    private void setPersonalNumber(String personalNumber) {
        if (personalNumber == null || personalNumber.trim().isEmpty())
            throw new IllegalArgumentException("(User) : Personal Number is missing.");
        this.personalNumber = personalNumber;
    }

    public void setEmail(String email) {
        if (email == null || email.trim().isEmpty())
            throw new IllegalArgumentException("(User) : E-Mail is missing.");
        this.email = email;
    }

    public void setPermanentAddress(Address permanentAddress) {
        if (permanentAddress == null)
            throw new IllegalArgumentException("(User) : Permanent Address is missing.");
        this.permanentAddress = permanentAddress;
    }

    public void setAddressOfCorrespondence(Address addressOfCorrespondence) {
        if (addressOfCorrespondence == null) {
            this.addressOfCorrespondence = this.permanentAddress;
        } else {
            this.addressOfCorrespondence = addressOfCorrespondence;
        }
    }

    public void setInsurances(List<Insurance> insurances) {
        this.insurances = insurances;
    }

    public void addInsurance(Insurance insurance) {
        this.insurances.add(insurance);
    }

    public long getUserID() {
        return this.userID;
    }

    public String getFirstName() {
        return this.firstName;
    }

    public String getLastName() {
        return this.lastName;
    }

    public String getPersonalNumber() {
        return this.personalNumber;
    }

    public String getEmail() {
        return this.email;
    }

    public Address getPermanentAddress() {
        return this.permanentAddress;
    }

    public Address getAddressOfCorrespondence() {
        return this.addressOfCorrespondence;
    }

    public List<Insurance> getInsurances() {
        return this.insurances;
    }


    @Override
    public String toString() {
        return "User{" +
                "userID=" + userID +
                ", firstName='" + firstName + '\'' +
                ", lastName='" + lastName + '\'' +
                ", personalNumber='" + personalNumber + '\'' +
                ", email='" + email + '\'' +
                ", permanentAddress=" + permanentAddress +
                ", addressOfCorrespondence=" + addressOfCorrespondence +
                '}';
    }
}