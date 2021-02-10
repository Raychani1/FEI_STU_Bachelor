package sk.stuba.fei.project_3.InsuranceWebApp.api;

import java.util.*;

import sk.stuba.fei.project_3.InsuranceWebApp.users.User;
import sk.stuba.fei.project_3.InsuranceWebApp.insurances.Insurance;

public class UserService extends API<User> {
    private final Map<String, User> users;

    public UserService() {
        this.users = new HashMap<>();
    }

    @Override
    public void add(User user) {
        if (user.getAddressOfCorrespondence().getZipCode().trim().isEmpty() ||
                user.getAddressOfCorrespondence().getTownCityName().trim().isEmpty() ||
                user.getAddressOfCorrespondence().getStreetName().trim().isEmpty() ||
                user.getAddressOfCorrespondence().getHouseNumber().trim().isEmpty()) {
            user.setAddressOfCorrespondence(user.getPermanentAddress());
        }
        if (!(user.getPersonalNumber().trim().isEmpty())) {
            checkPersonalNumber(user.getPersonalNumber());
            this.users.put(user.getUserID(), user);
        }
    }

    @Override
    public void edit(User user, String oldID) {
        User oldValue = users.get(oldID);
        user.setUserID(oldID);
        if (!(user.getPersonalNumber().equals(oldValue.getPersonalNumber()))) {
            throw new IllegalArgumentException("Personal Number can not be changed");
        } else {
            this.users.replace(oldID, oldValue, user);
            user.setInsurances(oldValue.getInsurances());
        }
    }

    @Override
    public Map<String, User> getAll() {
        return this.users;
    }

    public User getByID(String id) {
        return users.get(id);
    }

    public void checkPersonalNumber(String personalNumber) {
        for (Map.Entry<String, User> entry : users.entrySet()) {
            if (entry.getValue().getPersonalNumber().equals(personalNumber))
                throw new IllegalArgumentException("This Personal Number is already in the Database");
        }
    }

    public void updateInsurances(String userID, List<Insurance> insurances) {
        users.get(userID).setInsurances(insurances);
    }

}