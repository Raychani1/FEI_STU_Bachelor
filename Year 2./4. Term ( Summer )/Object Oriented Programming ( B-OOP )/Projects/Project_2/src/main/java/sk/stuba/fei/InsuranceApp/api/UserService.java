package sk.stuba.fei.InsuranceApp.api;

import java.util.*;

import sk.stuba.fei.InsuranceApp.users.User;

public class UserService extends API<User> {
    private final Map<Long, User> users;

    public UserService() {
        this.users = new HashMap<>();
    }

    @Override
    public void add(User user) {
        if (this.users.containsKey(user.getUserID()))
            throw new IllegalArgumentException(("(UserService) : This ID is already taken."));
        else {
            this.users.put(user.getUserID(), user);
        }
    }

    @Override
    public void edit(User user) {
        if (!(this.users.containsKey(user.getUserID()))) {
            throw new IllegalArgumentException("(UserService) : This ID does not exist in the User Database.");
        } else if (!(this.users.get(user.getUserID()).getPersonalNumber().equals(user.getPersonalNumber()))) {
            throw new IllegalArgumentException("(UserService) : You can not change the Personal Number");
        } else {
            this.users.replace(user.getUserID(), user);
        }
    }

    @Override
    public Map<Long, User> getAll() {
        return this.users;
    }

    @Override
    public List<User> getByID(long id) {
        List<User> user = new ArrayList<>();
        user.add(this.users.get(id));
        return user;
    }

    @Override
    public long generateNextID() {
        return this.users.size() + 1;
    }

    public User getUserByID(long id) {
        return getByID(id).get(0);
    }

}