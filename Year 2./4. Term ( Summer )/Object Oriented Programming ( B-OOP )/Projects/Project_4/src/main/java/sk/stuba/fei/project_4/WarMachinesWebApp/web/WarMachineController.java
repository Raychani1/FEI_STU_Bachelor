package sk.stuba.fei.project_4.WarMachinesWebApp.web;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import sk.stuba.fei.project_4.WarMachinesWebApp.api.WarMachineService;

@Controller
@RequestMapping("/war-machines")
public class WarMachineController {

    private final WarMachineService warMachineService;

    @Autowired
    public WarMachineController(WarMachineService warMachineService){
        this.warMachineService = warMachineService;
    }

    @GetMapping("/")
    public String getAllWarMachines(Model model){
        model.addAttribute("warmachines", warMachineService.all());
        return "warmachines/all";
    }

    @GetMapping("/id/{id}")
    public String warMachineInfo(@PathVariable String id, Model model){
        model.addAttribute("warmachine",warMachineService.byID(id));
        return "warmachines/info";
    }

}
