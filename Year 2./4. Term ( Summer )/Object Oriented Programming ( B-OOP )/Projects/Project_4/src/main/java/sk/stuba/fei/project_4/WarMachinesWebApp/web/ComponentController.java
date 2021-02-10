package sk.stuba.fei.project_4.WarMachinesWebApp.web;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import sk.stuba.fei.project_4.WarMachinesWebApp.api.ComponentService;

@Controller
@RequestMapping("/components")
public class ComponentController {
    private final ComponentService componentService;

    @Autowired
    public ComponentController(ComponentService componentService) {
        this.componentService = componentService;
    }

    @GetMapping("/")
    public String showAllComponents(Model model){

        model.addAttribute("components",componentService.all());
        return "components/all";
    }

    @GetMapping("/id/{id}")
    public String warMachineInfo(@PathVariable String id, Model model){
        model.addAttribute("component",componentService.byID(id));
        return "components/info";
    }

}

