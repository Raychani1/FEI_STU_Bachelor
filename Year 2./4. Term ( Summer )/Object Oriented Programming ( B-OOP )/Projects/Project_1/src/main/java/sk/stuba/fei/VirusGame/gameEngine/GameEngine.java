package sk.stuba.fei.VirusGame.gameEngine;

import sk.stuba.fei.VirusGame.diseases.*;
import sk.stuba.fei.VirusGame.events.*;
import sk.stuba.fei.VirusGame.models.*;

import java.util.Locale;    // Double input - those parts of the program are still in development
import java.util.Scanner;   // User input - those parts of the program are still in development

public class GameEngine {
    private IVirus disease;
    private SIRModel sirModel;

    public GameEngine(IVirus disease, SIRModel sirModel) {
        setDisease(disease);
        setSIRModel(sirModel);
    }

    public GameEngine() {
        this(null, null);
    }

    public SIRModel getSIRModel() {
        return this.sirModel;
    }

    public IVirus getDisease() {
        return this.disease;
    }

    public void setDisease(IVirus disease) {
        this.disease = disease;
    }

    public void setSIRModel(SIRModel sirModel) {
        this.sirModel = sirModel;
    }

    public void saveGame() {
        // TODO
        // Coming soon (10.5)
    }

    public void loadGame() {
        // TODO
        // Coming soon (10.5)
    }

    public boolean checkEnd() {
        // TODO
        // Method in development
        return false;
    }

    public void chooseDisease() {
        // TODO
        // Method in development
        Scanner scanner = new Scanner(System.in);
        System.out.println("Choose a disease:\n(Write either the number or the name of the disease you wish to choose)" +
                "\n1 - Mumps\n2 - SheepPox\n3 - Rubella\n4 - WhoopingCough\n5 - Measels\n6 - Covid19");

        String input = scanner.nextLine();
        switch (input) {
            case ("1"):
            case ("Mumps"):
            case ("mumps"):
                setDisease(new Mumps());
                break;
            case ("2"):
            case ("SheepPox"):
            case ("sheepPox"):
                setDisease(new SheepPox());
                break;
            case ("3"):
            case ("Rubella"):
            case ("rubella"):
                setDisease(new Rubella());
                break;
            case ("4"):
            case ("WhoopingCough"):
            case ("whoopingCough"):
                setDisease(new WhoopingCough());
                break;
            case ("5"):
            case ("Measels"):
            case ("measels"):
                setDisease(new Measels());
                break;
            case ("6"):
            case ("Covid19"):
            case ("covid19"):
                setDisease(new Covid19());
        }
    }

    public void chooseModel() {
        // TODO
        // Method in development
        Scanner scanner = new Scanner(System.in);
        System.out.println("Choose a spreading model:\n(Write the name of the model you wish to choose)\nSIR\nSIRF");

        String input = scanner.nextLine();
        if (input.equals("SIR") || input.equals("sir"))
            setSIRModel(new SIR());
        else
            setSIRModel(new SIRf());

    }

    public void setSIRModelSusceptible() {
        // TODO
        // Method in development
        Scanner scanner = new Scanner(System.in).useLocale(Locale.US);
        System.out.println("Enter the number of Susceptible individuals");

        double input = scanner.nextDouble();
        sirModel.setSusceptible(input);
    }

    public void setSIRModelInfectious() {
        // TODO
        // Method in development
        Scanner scanner = new Scanner(System.in).useLocale(Locale.US);
        System.out.println("Enter the number of Infectious individuals");

        double input = scanner.nextDouble();
        sirModel.setInfectious(input);
    }

    public void setSIRModelRecovered() {
        // TODO
        // Method in development
        Scanner scanner = new Scanner(System.in).useLocale(Locale.US);
        System.out.println("Enter the number of Recovered individuals");

        double input = scanner.nextDouble();
        sirModel.setRecovered(input);
    }

    public void setSIRModelPopulation() {
        // TODO
        // Method in development
        sirModel.setPopulation();
    }

    public void setSIRfModelImmune() {
        // TODO
        // Method in development
        Scanner scanner = new Scanner(System.in).useLocale(Locale.US);
        System.out.println("Enter the percentage of Immune individuals");

        double input = scanner.nextDouble();
        ((SIRf) sirModel).setF(input);
    }

    public void setSIRModelValues() {
        // TODO
        // Method in development
        setSIRModelSusceptible();
        setSIRModelInfectious();
        setSIRModelRecovered();
        setSIRModelPopulation();
        if (this.sirModel instanceof SIRf) {
            setSIRfModelImmune();
            recalculatePopulation();
        }
    }

    private void recalculatePopulation() {
        // TODO
        // Method in development
        // We put every immune person from Susceptible to Recovered
        double immune = sirModel.getSusceptible() * (((SIRf) sirModel).getF() / 100);
        sirModel.setSusceptible(sirModel.getSusceptible() - immune);
        sirModel.setRecovered(sirModel.getSusceptible() + immune);
    }

    public void calculateNewSIRStates(double beta, double gamma) {
        // TODO
        // Method in development
        this.sirModel.calculateNewSusceptible(beta, gamma);
        this.sirModel.calculateNewInfectious(beta, gamma);
        this.sirModel.calculateNewRecovered(beta, gamma);
    }

    public void activateEvent(Event event) {
        // TODO
        // Method in development
        if (event instanceof AcceleratorEvent) {
            disease.setBeta(disease.getBeta() + event.getBetaModifier());
            disease.setR0(disease.calculateR0());
        } else if (event instanceof SlowingEvent) {
            disease.setBeta(disease.getBeta() - event.getBetaModifier());
            disease.setR0(disease.calculateR0());
        }
    }

    public void deactivateEvent(Event event) {
        // TODO
        // Method in development
        if (event instanceof AcceleratorEvent) {
            disease.setBeta(disease.getBeta() - event.getBetaModifier());
            disease.setR0(disease.calculateR0());
        } else if (event instanceof SlowingEvent) {
            disease.setBeta(disease.getBeta() + event.getBetaModifier());
            disease.setR0(disease.calculateR0());
        }
    }
}