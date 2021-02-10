package sk.stuba.fei.InsuranceApp;

import java.util.*;
import java.time.LocalDate;

import sk.stuba.fei.InsuranceApp.api.*;
import sk.stuba.fei.InsuranceApp.users.User;
import sk.stuba.fei.InsuranceApp.address.Address;
import sk.stuba.fei.InsuranceApp.insurances.Insurance;
import sk.stuba.fei.InsuranceApp.insurances.nonlifeinsurances.*;
import sk.stuba.fei.InsuranceApp.insurances.lifeinsurances.accidentinsurance.*;

public class Main {
    public static void main(String[] args) {
        UserService userService = new UserService();
        InsuranceService insuranceService = new InsuranceService();
        try {
            // Add new User
            userService.add(new User(userService.generateNextID(), "Jozef", "Mak",
                    "19981223/1234", "jozef.mak@gmail.com",
                    new Address("932 01", "Bratislavská", "Veľký Meder", "60")));

            userService.add(new User(userService.generateNextID(), "Martin", "Groš",
                    "19981231/1234", "martin.gros@gmail.com",
                    new Address("930 36", "Main", "Dunajská Streda", "69")));

            userService.add(new User(userService.generateNextID(), "Peter", "Šikovný",
                    "19990305/1234", "peter.sikovny@gmail.com",
                    new Address("931 01", "Senecká", "Šamorín", "420")));

            // Get All Users
            Map<Long, User> users = userService.getAll();
            System.out.println("=================================================================================================== ALL USERS ========================================================================================================");
            for (Long key : users.keySet()) {
                System.out.println(key + " : " + users.get(key));
            }
            System.out.println("======================================================================================================================================================================================================================\n");

            // Add new Insurance
            insuranceService.add(new AccidentInsurance(insuranceService.generateNextID(),
                    LocalDate.of(2020, 1, 10), userService.getUserByID(1),
                    LocalDate.of(2020, 1, 13), LocalDate.of(2020, 11, 13),
                    2000.0, 200, userService.getUserByID(2), 100, 200,
                    300, TerritorialValidity.WORLDANDSLOVAKIA));

            insuranceService.add(new HouseholdInsurance(insuranceService.generateNextID(),
                    LocalDate.of(2020, 2, 10), userService.getUserByID(2),
                    LocalDate.of(2020, 2, 13), LocalDate.of(2020, 11, 13),
                    2000.0, 300, House.Familyhouse_brick,
                    new Address("930 39", "Main", "Bratislava", "115"),
                    2000, 400));

            // Edit existing User
            userService.edit(new User(1, "Filip", "Múdry",
                    userService.getUserByID(1).getPersonalNumber(), "filip.mudry@gmail.com",
                    new Address("040 01", "Hlavná", "Košice", "420"),
                    userService.getUserByID(1).getInsurances()));

            // Get the details about User
            User user = userService.getUserByID(1);
            System.out.println("=================================================================================================== USER [ID:1] AFTER EDIT ========================================================================================================");
            System.out.println(user);
            System.out.println("==========================================================================================================================================================================================================================================\n");


            insuranceService.add(new HouseAndApartmentInsurance(insuranceService.generateNextID(),
                    LocalDate.of(2013, 10, 10), userService.getUserByID(1),
                    LocalDate.of(2013, 10, 12), LocalDate.of(2014, 10, 11),
                    4000, 400, House.Familyhouse_wooden,
                    new Address("999 99", "Forest", "Forester", "69"),
                    6000, true));

            long id = 1;
            // Get all the insurances based on UserID
            List<Insurance> usersInsurances = insuranceService.getByID(id);
            System.out.println("=================================================================================================== ALL INSURANCES OF USER [ID:" + id + "] ========================================================================================================");
            System.out.println(usersInsurances);
            System.out.println("==========================================================================================================================================================================================================================================\n");

            // Get all insurances
            Map<Long, Insurance> insurances = insuranceService.getAll();
            System.out.println("=================================================================================================== ALL INSURANCES ========================================================================================================");
            for (Long key : insurances.keySet()) {
                System.out.println(key + " : " + insurances.get(key));
            }
            System.out.println("===========================================================================================================================================================================================================================\n");

            // Edit existing Insurance
            insuranceService.edit(new HouseAndApartmentInsurance(3,
                    LocalDate.of(2011, 12, 30), userService.getUserByID(2),
                    LocalDate.of(2012, 1, 11), LocalDate.of(2014, 10, 11),
                    4000, 400, House.Familyhouse_wooden,
                    new Address("999 99", "Forest", "Forester", "69"),
                    6000, true));
            insurances = insuranceService.getAll();
            System.out.println("=================================================================================================== ALL INSURANCES AFTER EDIT ========================================================================================================");
            for (Long key : insurances.keySet()) {
                System.out.println(key + " : " + insurances.get(key));
            }
            System.out.println("======================================================================================================================================================================================================================================\n");
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}