package sk.stuba.fei.project_4;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import sk.stuba.fei.project_4.WarMachinesWebApp.api.ComponentService;
import sk.stuba.fei.project_4.WarMachinesWebApp.api.WarMachineService;
import sk.stuba.fei.project_4.WarMachinesWebApp.components.Nationality;
import sk.stuba.fei.project_4.WarMachinesWebApp.components.Tower;
import sk.stuba.fei.project_4.WarMachinesWebApp.components.cannons.LargeCaliberCannon;
import sk.stuba.fei.project_4.WarMachinesWebApp.components.chassis.CrawlerChassis;
import sk.stuba.fei.project_4.WarMachinesWebApp.warmachines.HeavyTank;

@SpringBootApplication
public class Project4Application {
    private WarMachineService warMachineService;
    private ComponentService componentService;

    public Project4Application(WarMachineService warMachineService, ComponentService componentService){
        this.warMachineService = warMachineService;
        this.componentService = componentService;
    }
    public static void main(String[] args) {
        SpringApplication.run(Project4Application.class, args);
    }


    public void run(String... args) throws Exception {
        CrawlerChassis crawlerChassis = new CrawlerChassis("IS-3M",10,10,10,10);
        this.componentService.add(crawlerChassis);
        LargeCaliberCannon largeCaliberCannon = new LargeCaliberCannon("122 mm BL-9",122,10,10,10);
        this.componentService.add(largeCaliberCannon);
        Tower tower = new Tower("IS-3",10,10,largeCaliberCannon);
        this.componentService.add(tower);

        this.warMachineService.add(new HeavyTank("IS-3", Nationality.GREAT_BRITAIN,10,crawlerChassis,tower));
    }
}
