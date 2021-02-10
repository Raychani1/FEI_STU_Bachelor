package sk.stuba.fei.InsuranceApp.api;

import java.util.*;

import sk.stuba.fei.InsuranceApp.insurances.Insurance;
import sk.stuba.fei.InsuranceApp.insurances.nonlifeinsurances.HouseholdInsurance;
import sk.stuba.fei.InsuranceApp.insurances.nonlifeinsurances.HouseAndApartmentInsurance;
import sk.stuba.fei.InsuranceApp.insurances.lifeinsurances.travelinsurance.TravelInsurance;
import sk.stuba.fei.InsuranceApp.insurances.lifeinsurances.accidentinsurance.AccidentInsurance;

public class InsuranceService extends API<Insurance> {
    private final Map<Long, Insurance> insurances;

    public InsuranceService() {
        this.insurances = new HashMap<>();
    }

    @Override
    public void add(Insurance insurance) {
        if (this.insurances.containsKey(insurance.getInsuranceID()))
            throw new IllegalArgumentException(("(InsuranceService) : This Insurance ID is already taken."));
        else {
            insurance.getInsurer().addInsurance(insurance);
            this.insurances.put(insurance.getInsuranceID(), insurance);
        }
    }

    @Override
    public void edit(Insurance insurance) {
        if (!(this.insurances.containsKey(insurance.getInsuranceID()))) {
            throw new IllegalArgumentException("(InsuranceService) : This ID does not exist in the Insurance Database.");
        }
        Insurance oldInsurance = this.insurances.get(insurance.getInsuranceID());
        if ((oldInsurance instanceof AccidentInsurance && insurance instanceof AccidentInsurance) ||
                (oldInsurance instanceof TravelInsurance && insurance instanceof TravelInsurance) ||
                (oldInsurance instanceof HouseAndApartmentInsurance && insurance instanceof HouseAndApartmentInsurance) ||
                (oldInsurance instanceof HouseholdInsurance && insurance instanceof HouseholdInsurance)) {
            this.insurances.replace(insurance.getInsuranceID(), insurance);
        } else {
            throw new IllegalArgumentException("(InsuranceService) : You can not change the type of Insurance.");
        }
    }

    @Override
    public Map<Long, Insurance> getAll() {
        return this.insurances;
    }

    @Override
    public List<Insurance> getByID(long id) {
        List<Insurance> insurancesOfInsurer = new ArrayList<>();
        for (long i = 1; i < insurances.size(); ++i) {
            if (id == insurances.get(i).getInsurer().getUserID()) {
                insurancesOfInsurer = insurances.get(i).getInsurer().getInsurances();
                break;
            }
        }
        return insurancesOfInsurer;
    }

    @Override
    public long generateNextID() {
        return this.insurances.size() + 1;
    }
}
