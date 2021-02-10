package sk.stuba.fei.project_3.InsuranceWebApp.api;

import java.util.Map;

public abstract class API<T> {

    public abstract void add(T t);

    public abstract void edit(T t, String ID);

    public abstract Map<String, T> getAll();

}