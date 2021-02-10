package sk.stuba.fei.project_3;

import java.util.Map;
import javax.validation.Valid;

import org.springframework.ui.Model;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;
import org.springframework.boot.SpringApplication;
import org.springframework.validation.BindingResult;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import sk.stuba.fei.project_3.InsuranceWebApp.users.User;
import sk.stuba.fei.project_3.InsuranceWebApp.api.UserService;
import sk.stuba.fei.project_3.InsuranceWebApp.api.InsuranceService;
import sk.stuba.fei.project_3.InsuranceWebApp.insurances.Insurance;
import sk.stuba.fei.project_3.InsuranceWebApp.insurances.nonlifeinsurances.*;
import sk.stuba.fei.project_3.InsuranceWebApp.insurances.lifeinsurances.travelinsurance.*;
import sk.stuba.fei.project_3.InsuranceWebApp.insurances.lifeinsurances.accidentinsurance.*;

@Controller
@SpringBootApplication
public class Project3Application {
    private UserService userService = new UserService();
    private InsuranceService insuranceService = new InsuranceService();

    public static void main(String[] args) {
        SpringApplication.run(Project3Application.class, args);
    }

    @GetMapping("/")
    public String index(Model model) {
        model.addAttribute("users", userService.getAll());
        return "index";
    }

    @GetMapping("/users/")
    public String allUsers(Model model) {
        model.addAttribute("users", userService.getAll());
        return "user/all";
    }

    @GetMapping("/users/add")
    public String addUser(Model model) {
        model.addAttribute("user", new User());
        return "user/add";
    }

    @PostMapping("/users/submit")
    public String submitted(@ModelAttribute @Valid User user, BindingResult bindingResult) {
        try {
            userService.add(user);
        } catch (Exception e) {
            bindingResult.rejectValue("personalNumber", "user", e.getMessage());
        }
        if (bindingResult.hasErrors()) {
            return "user/add";
        }
        return "redirect:/users/";
    }

    @GetMapping("/users/id/{id}")
    public String userByID(@PathVariable String id, Model model) {
        model.addAttribute("user", userService.getByID(id));
        return "user/one";
    }

    @GetMapping("/users/edit/{id}")
    public String editUser(@PathVariable String id, Model model) {
        model.addAttribute("user", userService.getByID(id));
        return "user/edit";
    }

    @PostMapping("/users/edit/{id}/submit")
    public String submittedEdit(@ModelAttribute @Valid User user, BindingResult bindingResult, @PathVariable String id) {
        User oldUser = userService.getByID(id);
        try {
            userService.edit(user, id);
        } catch (Exception e) {
            bindingResult.rejectValue("personalNumber", "user", e.getMessage());
        }
        if (bindingResult.hasErrors()) {
            return "user/edit";
        }
        for (Map.Entry<String, Insurance> entry : insuranceService.getAll().entrySet()) {
            if (entry.getValue().getInsurer().equals(oldUser)) {
                entry.getValue().setInsurer(user);
            }
            if (entry.getValue() instanceof AccidentInsurance) {
                if (((AccidentInsurance) entry.getValue()).getInsured().equals(oldUser)) {
                    ((AccidentInsurance) entry.getValue()).setInsured(user);
                }
            } else if (entry.getValue() instanceof TravelInsurance) {
                if (((TravelInsurance) entry.getValue()).getInsured().equals(oldUser)) {
                    ((TravelInsurance) entry.getValue()).setInsured(user);
                }
            }
        }
        return "redirect:/users/";
    }

    @GetMapping("/users/id/{id}/insurances/add-accident-insurance")
    public String addAccidentInsurance(@PathVariable String id, Model model) {
        model.addAttribute("users", userService.getAll());
        model.addAttribute("insurer", userService.getByID(id));
        model.addAttribute("accidentInsurance", new AccidentInsurance());
        model.addAttribute("territorialvalidity", TerritorialValidity.values());
        return "insurance/add/addaccidentinsurance";
    }

    @PostMapping("/users/id/{id}/insurances/add-accident-insurance/submit")
    public String submitNewAccidentInsurance(@ModelAttribute @Valid AccidentInsurance accidentInsurance, BindingResult bindingResult, @PathVariable String id, Model model) {
        if (bindingResult.hasErrors()) {
            model.addAttribute("users", userService.getAll());
            model.addAttribute("insurer", userService.getByID(id));
            model.addAttribute("accidentInsurance", accidentInsurance);
            model.addAttribute("territorialvalidity", TerritorialValidity.values());
            return "insurance/add/addaccidentinsurance";
        }
        accidentInsurance.setInsurer(userService.getByID(id));
        accidentInsurance.setInsured(userService.getByID(accidentInsurance.getInsured().getUserID()));
        insuranceService.add(accidentInsurance);
        return "redirect:/users/";
    }

    @GetMapping("/users/id/{id}/insurances/add-travel-insurance")
    public String addTravelInsurance(@PathVariable String id, Model model) {
        model.addAttribute("purpose", Purpose.values());
        model.addAttribute("users", userService.getAll());
        model.addAttribute("insurer", userService.getByID(id));
        model.addAttribute("travelInsurance", new TravelInsurance());
        return "insurance/add/addtravelinsurance";
    }

    @PostMapping("/users/id/{id}/insurances/add-travel-insurance/submit")
    public String submitNewTravelInsurance(@ModelAttribute @Valid TravelInsurance travelInsurance, BindingResult bindingResult, @PathVariable String id, Model model) {
        if (bindingResult.hasErrors()) {
            model.addAttribute("purpose", Purpose.values());
            model.addAttribute("users", userService.getAll());
            model.addAttribute("insurer", userService.getByID(id));
            model.addAttribute("travelInsurance", travelInsurance);

            return "insurance/add/addtravelinsurance";
        }
        travelInsurance.setInsurer(userService.getByID(id));
        travelInsurance.setInsured(userService.getByID(travelInsurance.getInsured().getUserID()));
        insuranceService.add(travelInsurance);
        return "redirect:/users/";
    }

    @GetMapping("/users/id/{id}/insurances/add-house-and-apartment-insurance")
    public String addHouseAndApartmentInsurance(@PathVariable String id, Model model) {
        model.addAttribute("house", House.values());
        model.addAttribute("insurer", userService.getByID(id));
        model.addAttribute("houseAndApartmentInsurance", new HouseAndApartmentInsurance());
        return "insurance/add/addhouseandapartmentinsurance";
    }

    @PostMapping("/users/id/{id}/insurances/add-house-and-apartment-insurance/submit")
    public String submitHouseAndApartmentInsurance(@ModelAttribute @Valid HouseAndApartmentInsurance houseAndApartmentInsurance, BindingResult bindingResult, @PathVariable String id, Model model) {
        if (bindingResult.hasErrors()) {
            model.addAttribute("house", House.values());
            model.addAttribute("insurer", userService.getByID(id));
            model.addAttribute("houseAndApartmentInsurance", houseAndApartmentInsurance);
            return "insurance/add/addhouseandapartmentinsurance";
        }
        houseAndApartmentInsurance.setInsurer(userService.getByID(id));
        insuranceService.add(houseAndApartmentInsurance);
        return "redirect:/users/";
    }

    @GetMapping("/users/id/{id}/insurances/add-household-insurance")
    public String addHouseholdInsurance(@PathVariable String id, Model model) {
        model.addAttribute("house", House.values());
        model.addAttribute("insurer", userService.getByID(id));
        model.addAttribute("householdInsurance", new HouseholdInsurance());
        return "insurance/add/addhouseholdinsurance";
    }

    @PostMapping("/users/id/{id}/insurances/add-household-insurance/submit")
    public String submitHouseholdInsurance(@ModelAttribute @Valid HouseholdInsurance householdInsurance, BindingResult bindingResult, @PathVariable String id, Model model) {
        if (bindingResult.hasErrors()) {
            model.addAttribute("house", House.values());
            model.addAttribute("insurer", userService.getByID(id));
            model.addAttribute("householdInsurance", householdInsurance);
            return "insurance/add/addhouseholdinsurance";
        }
        householdInsurance.setInsurer(userService.getByID(id));
        insuranceService.add(householdInsurance);
        return "redirect:/users/";
    }

    @GetMapping("/users/id/{user_id}/insurances/id/{insurance_id}")
    public String showInsurance(@PathVariable String user_id, @PathVariable String insurance_id, Model model) {
        model.addAttribute("insurance", insuranceService.getByID(insurance_id));
        if (insuranceService.getByID(insurance_id) instanceof AccidentInsurance)
            return "insurance/info/accidentinsuranceinfo";
        else if (insuranceService.getByID(insurance_id) instanceof TravelInsurance)
            return "insurance/info/travelinsuranceinfo";
        else if (insuranceService.getByID(insurance_id) instanceof HouseholdInsurance)
            return "insurance/info/householdinsuranceinfo";
        else
            return "insurance/info/houseandapartmentinsuranceinfo";
    }

    @GetMapping("/users/id/{user_id}/insurances/id/{insurance_id}/edit-insurance")
    public String editInsurance(@PathVariable String user_id, @PathVariable String insurance_id, Model model) {
        Insurance insurance = insuranceService.getByID(insurance_id);

        if (insurance instanceof AccidentInsurance) {
            model.addAttribute("users", userService.getAll());
            model.addAttribute("accidentInsurance", insurance);
            model.addAttribute("insurer", insurance.getInsurer());
            model.addAttribute("territorialvalidity", TerritorialValidity.values());
            return "insurance/edit/editaccidentinsurance";
        } else if (insurance instanceof TravelInsurance) {
            model.addAttribute("purpose", Purpose.values());
            model.addAttribute("travelInsurance", insurance);
            model.addAttribute("users", userService.getAll());
            model.addAttribute("insurer", insurance.getInsurer());
            return "insurance/edit/edittravelinsurance";
        } else if (insurance instanceof HouseAndApartmentInsurance) {
            model.addAttribute("house", House.values());
            model.addAttribute("insurer", insurance.getInsurer());
            model.addAttribute("houseAndApartmentInsurance", insurance);
            return "insurance/edit/edithouseandapartmentinsurance";
        } else {
            model.addAttribute("house", House.values());
            model.addAttribute("householdInsurance", insurance);
            model.addAttribute("insurer", insurance.getInsurer());
            return "insurance/edit/edithouseholdinsurance";
        }
    }

    @PostMapping("/users/id/{user_id}/insurances/id/{insurance_id}/edit-accident-insurance/submit")
    public String editAccidentInsuranceSubmit(@ModelAttribute @Valid AccidentInsurance accidentInsurance, BindingResult bindingResult, @PathVariable String user_id, @PathVariable String insurance_id, Model model) {
        accidentInsurance.setInsurer(userService.getByID(user_id));
        accidentInsurance.setInsured(userService.getByID(accidentInsurance.getInsured().getUserID()));
        accidentInsurance.setInsuranceID(insurance_id);
        if (bindingResult.hasErrors()) {
            model.addAttribute("users", userService.getAll());
            model.addAttribute("accidentInsurance", accidentInsurance);
            model.addAttribute("insurer", accidentInsurance.getInsurer());
            model.addAttribute("territorialvalidity", TerritorialValidity.values());
            return "insurance/edit/editaccidentinsurance";
        }
        insuranceService.edit(accidentInsurance, insurance_id);
        userService.updateInsurances(user_id, insuranceService.getByUser(userService.getByID(user_id)));
        return "redirect:/users/";
    }

    @PostMapping("/users/id/{user_id}/insurances/id/{insurance_id}/edit-travel-insurance/submit")
    public String editTravelInsuranceSubmit(@ModelAttribute @Valid TravelInsurance travelInsurance, BindingResult bindingResult, @PathVariable String user_id, @PathVariable String insurance_id, Model model) {
        travelInsurance.setInsurer(userService.getByID(user_id));
        travelInsurance.setInsured(userService.getByID(travelInsurance.getInsured().getUserID()));
        travelInsurance.setInsuranceID(insurance_id);
        if (bindingResult.hasErrors()) {
            model.addAttribute("purpose", Purpose.values());
            model.addAttribute("users", userService.getAll());
            model.addAttribute("travelInsurance", travelInsurance);
            model.addAttribute("insurer", travelInsurance.getInsurer());
            return "insurance/edit/edittravelinsurance";
        }
        insuranceService.edit(travelInsurance, insurance_id);
        userService.updateInsurances(user_id, insuranceService.getByUser(userService.getByID(user_id)));
        return "redirect:/users/";
    }

    @PostMapping("/users/id/{user_id}/insurances/id/{insurance_id}/edit-house-and-apartment-insurance/submit")
    public String editHouseAndApartmentInsuranceSubmit(@ModelAttribute @Valid HouseAndApartmentInsurance houseAndApartmentInsurance, BindingResult bindingResult, @PathVariable String user_id, @PathVariable String insurance_id, Model model) {
        houseAndApartmentInsurance.setInsurer(userService.getByID(user_id));
        houseAndApartmentInsurance.setInsuranceID(insurance_id);
        if (bindingResult.hasErrors()) {
            model.addAttribute("house", House.values());
            model.addAttribute("users", userService.getAll());
            model.addAttribute("insurer", houseAndApartmentInsurance.getInsurer());
            model.addAttribute("houseAndApartmentInsurance", houseAndApartmentInsurance);
            return "insurance/edit/edithouseandapartmentinsurance";
        }
        insuranceService.edit(houseAndApartmentInsurance, insurance_id);
        userService.updateInsurances(user_id, insuranceService.getByUser(userService.getByID(user_id)));
        return "redirect:/users/";
    }

    @PostMapping("/users/id/{user_id}/insurances/id/{insurance_id}/edit-household-insurance/submit")
    public String editHouseholdInsuranceSubmit(@ModelAttribute @Valid HouseholdInsurance householdInsurance, BindingResult bindingResult, @PathVariable String user_id, @PathVariable String insurance_id, Model model) {
        householdInsurance.setInsurer(userService.getByID(user_id));
        householdInsurance.setInsuranceID(insurance_id);
        if (bindingResult.hasErrors()) {
            model.addAttribute("house", House.values());
            model.addAttribute("users", userService.getAll());
            model.addAttribute("householdInsurance", householdInsurance);
            model.addAttribute("insurer", householdInsurance.getInsurer());
            return "insurance/edit/edithouseholdinsurance";
        }
        insuranceService.edit(householdInsurance, insurance_id);
        userService.updateInsurances(user_id, insuranceService.getByUser(userService.getByID(user_id)));
        return "redirect:/users/";
    }
}
