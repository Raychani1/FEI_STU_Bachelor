package sk.stuba.fei.project_3.InsuranceWebApp.users;

import java.util.*;
import java.util.concurrent.atomic.AtomicLong;

import org.springframework.lang.NonNull;
import sk.stuba.fei.project_3.InsuranceWebApp.address.Address;
import sk.stuba.fei.project_3.InsuranceWebApp.insurances.Insurance;

import javax.validation.Valid;
import javax.validation.constraints.Email;
import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotEmpty;
import javax.validation.constraints.NotNull;

public class User {
    private String userID;
    @NotBlank(message = "First Name is missing")
    private String firstName;
    @NotBlank(message = "Last Name is missing")
    private String lastName;
    @NotBlank(message = "Personal Number is missing")
    private String personalNumber;
    @NotBlank(message = "Email is missing")
    @Email(message = "Email is not valid")
    private String email;
    @Valid
    private Address permanentAddress;
    private Address addressOfCorrespondence;
    private List<Insurance> insurances = new ArrayList<>();

    public User(String firstName, String lastName, String personalNumber, String email, Address permanentAddress, Address addressOfCorrespondence, List<Insurance> insurances) {
        setFirstName(firstName);
        setLastName(lastName);
        setPersonalNumber(personalNumber);
        setEmail(email);
        setPermanentAddress(permanentAddress);
        setAddressOfCorrespondence(addressOfCorrespondence);
        setInsurances(insurances);
        setUserID(UUID.randomUUID().toString());
    }

    public User(String firstName, String lastName, String personalNumber, String email, Address permanentAddress, Address addressOfCorrespondence) {
        this(firstName, lastName, personalNumber, email, permanentAddress, addressOfCorrespondence, new ArrayList<Insurance>());
    }

    public User(String firstName, String lastName, String personalNumber, String email, Address permanentAddress, List<Insurance> insurances) {
        this(firstName, lastName, personalNumber, email, permanentAddress, null, insurances);
    }

    public User(String firstName, String lastName, String personalNumber, String email, Address permanentAddress) {
        this(firstName, lastName, personalNumber, email, permanentAddress, null, new ArrayList<Insurance>());
    }

    public User() {
        setUserID(UUID.randomUUID().toString());
    }

    public void setUserID(String userID) {
        this.userID = userID;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public void setLastName(String lastName) {
       this.lastName = lastName;
    }

    public void setPersonalNumber(String personalNumber) {
        this.personalNumber = personalNumber;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public void setPermanentAddress(Address permanentAddress) {
        this.permanentAddress = permanentAddress;
    }

    public void setAddressOfCorrespondence(Address addressOfCorrespondence) {
            this.addressOfCorrespondence = addressOfCorrespondence;
    }

    public void setInsurances(List<Insurance> insurances) {
        this.insurances = insurances;
    }

    public void addInsurance(Insurance insurance) {
        this.insurances.add(insurance);
    }

    public String getUserID() {
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