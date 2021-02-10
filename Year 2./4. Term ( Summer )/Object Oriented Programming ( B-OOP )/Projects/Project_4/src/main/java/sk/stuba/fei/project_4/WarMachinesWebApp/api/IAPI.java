package sk.stuba.fei.project_4.WarMachinesWebApp.api;

import java.util.Map;

public interface IAPI<T> {

    void add(T t);

    Map<String,T> all();

    T byID(String id);

}
