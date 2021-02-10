package sk.stuba.fei.Seminar_2.MyDate;

public enum Months {
    Jan(31),
    Feb(28),
    Mar(31),
    Apr(30),
    May(31),
    Jun(30),
    Jul(31),
    Aug(31),
    Sep(30),
    Oct(31),
    Nov(30),
    Dec(31);

    private int days;

    Months(int days) {
        this.days = days;
    }

    public int getDays() {
        return days;
    }
}
