package sk.stuba.fei.InsuranceApp.api;

import java.util.Map;
import java.util.List;

public abstract class API<T> {

    public abstract void add(T t);

    public abstract void edit(T t);

    public abstract Map<Long, T> getAll();

    public abstract List<T> getByID(long id);

    public abstract long generateNextID();
}
