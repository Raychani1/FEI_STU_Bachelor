package sk.stuba.fei.project_3.InsuranceWebApp.api;

import java.util.*;

import sk.stuba.fei.project_3.InsuranceWebApp.insurances.Insurance;
import sk.stuba.fei.project_3.InsuranceWebApp.insurances.nonlifeinsurances.HouseholdInsurance;
import sk.stuba.fei.project_3.InsuranceWebApp.insurances.nonlifeinsurances.HouseAndApartmentInsurance;
import sk.stuba.fei.project_3.InsuranceWebApp.insurances.lifeinsurances.travelinsurance.TravelInsurance;
import sk.stuba.fei.project_3.InsuranceWebApp.insurances.lifeinsurances.accidentinsurance.AccidentInsurance;
import sk.stuba.fei.project_3.InsuranceWebApp.users.User;

public class InsuranceService extends API<Insurance> {
    private final Map<String, Insurance> insurances;

    public InsuranceService() {
        this.insurances = new HashMap<>();
    }

    @Override
    public void add(Insurance insurance) {
        insurance.getInsurer().addInsurance(insurance);
        this.insurances.put(insurance.getInsuranceID(), insurance);
    }

    @Override
    public void edit(Insurance insurance, String oldID) {
        Insurance oldInsurance = insurances.get(oldID);
        if (!(this.insurances.containsKey(oldID))) {
            throw new IllegalArgumentException("This ID does not exist in the Insurance Database.");
        }
        if ((oldInsurance instanceof AccidentInsurance && insurance instanceof AccidentInsurance) ||
                (oldInsurance instanceof TravelInsurance && insurance instanceof TravelInsurance) ||
                (oldInsurance instanceof HouseAndApartmentInsurance && insurance instanceof HouseAndApartmentInsurance) ||
                (oldInsurance instanceof HouseholdInsurance && insurance instanceof HouseholdInsurance)) {
            this.insurances.replace(oldID, oldInsurance, insurance);
            insurance.setDateOfCreation(oldInsurance.getDateOfCreation());

        } else {
            throw new IllegalArgumentException("You can not change the type of Insurance.");
        }
    }

    @Override
    public Map<String, Insurance> getAll() {
        return this.insurances;
    }

    public Insurance getByID(String insuranceID) {
        return this.insurances.get(insuranceID);
    }

    public List<Insurance> getByUser(User insurer) {
        List<Insurance> userInsurances = new ArrayList<>();
        for (Map.Entry<String, Insurance> insurance : insurances.entrySet()) {
            if (insurance.getValue().getInsurer().equals(insurer))
                userInsurances.add(insurance.getValue());
        }
        return userInsurances;
    }

}