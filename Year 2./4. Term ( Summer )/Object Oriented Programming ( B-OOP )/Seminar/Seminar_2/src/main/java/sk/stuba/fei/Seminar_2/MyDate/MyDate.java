package sk.stuba.fei.Seminar_2.MyDate;

public class MyDate {
    private int day;
    private int month;
    private int year;
    private Months month_s;
    private Days day_s;

    public MyDate(int day, int month, int year) {
        this.day = day;
        this.month = month;
        this.year = year;
        this.month_s = Months.values()[month - 1];
        this.day_s = Days.values()[getDayOfWeek(day, month, year)];
    }

    public int getDay() {
        return day;
    }

    public int getMonth() {
        return month;
    }

    public int getYear() {
        return year;
    }

    public Months getMonth_s() {
        return month_s;
    }

    public void setDate(int day, int month, int year) {
        if (isValidDate(day, month, year)) {
            this.day = day;
            this.month = month;
            this.year = year;
            this.month_s = Months.values()[month - 1];
            this.day_s = Days.values()[getDayOfWeek(day, month, year)];
        }
    }

    public boolean isLeapYear(int year) {
        if (year % 4 == 0) {
            if (year % 100 == 0) {
                return year % 400 == 0;
            }
            return true;
        } else
            return false;
    }

    public boolean isValidDate(int day, int month, int year) {
        switch (month) {
            case 2:
                if (day > 0) {
                    if (isLeapYear(year) && day <= 29)
                        return true;
                    else return (day <= Months.Feb.getDays());
                }
                return false;

            default:
                return (day > 0 && day <= Months.values()[month - 1].getDays());
        }
    }

    public int getDayOfWeek(int day, int month, int year) {
        int[] month_code = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};

        int yy = year % 100;
        int year_code = (yy + (yy / 4)) % 7;

        int leap_year_code;
        if (isLeapYear(year)) {
            leap_year_code = 1;
        } else
            leap_year_code = 0;

        int century_number = 0;
        switch (year / 100) {
            case 17:
            case 21:
                century_number = 4;
                break;
            case 18:
            case 22:
                century_number = 2;
                break;
            case 19:
            case 23:
                century_number = 0;
                break;
            case 20:
                century_number = 6;
                break;
        }
        return (year_code + month_code[month - 1] + century_number + day - leap_year_code) % 7;
    }

    public MyDate nextDay() {
        int day = this.getDay(), month = this.getMonth(), year = this.getYear();
        Months month_s = this.getMonth_s();
        if (month == 12 && day + 1 > month_s.getDays() && isValidDate(1, 1, year + 1)) {
            day = 1;
            month = 1;
            year = year + 1;
        } else {
            if (month == 2 && isLeapYear(year) && day + 1 > month_s.getDays() && isValidDate(day + 1, month, year)) {
                day = day + 1;
            } else {
                if (day + 1 > month_s.getDays() && isValidDate(1, month + 1, year)) {
                    day = 1;
                    month = month + 1;
                } else {
                    if (isValidDate(day + 1, month, year)) {
                        day = day + 1;
                    }
                }
            }
        }
        return new MyDate(day, month, year);
    }

    public MyDate nextMonth() {
        int day = this.getDay(), month = this.getMonth(), year = this.getYear();
        if (month == 12 && isValidDate(day, 1, year + 1)) {
            month = 1;
            year = year + 1;
        } else {
            if (month == 1 && day > Months.values()[month].getDays() && isLeapYear(year)) {
                day = Months.values()[month].getDays() + 1;
                month = month + 1;
            } else {
                if (day > Months.values()[month].getDays()) {
                    day = Months.values()[month].getDays();
                    month = month + 1;
                } else {
                    if (isValidDate(day, month + 1, year))
                        month = month + 1;
                }
            }
        }
        return new MyDate(day, month, year);
    }

    public MyDate nextYear() {
        int day = this.getDay(), month = this.getMonth(), year = this.getYear();
        if (day > Months.values()[month - 1].getDays()) {
            day = Months.values()[month - 1].getDays();
            year = year + 1;
        } else {
            year = year + 1;
        }
        return new MyDate(day, month, year);
    }

    public MyDate previousDay() {
        int day = this.getDay(), month = this.getMonth(), year = this.getYear();
        if (month == 1 && day - 1 < 1 && isValidDate(31, 12, year - 1)) {
            day = 31;
            month = 12;
            year = year - 1;
        } else {
            if (month == 3 && isLeapYear(year) && day - 1 < 1 && isValidDate(29, month - 1, year)) {
                day = 29;
                month = month - 1;
            } else {
                if (day - 1 < 1 && isValidDate(Months.values()[month - 2].getDays(), month - 1, year)) {
                    day = Months.values()[month - 2].getDays();
                    month = month - 1;
                } else {
                    if (isValidDate(day - 1, month, year)) {
                        day = day - 1;
                    }
                }
            }
        }
        return new MyDate(day, month, year);
    }

    public MyDate previousMonth() {
        int day = this.getDay(), month = this.getMonth(), year = this.getYear();
        if (month == 1 && isValidDate(day, 12, year - 1)) {
            month = 12;
            year = year - 1;
        } else {
            if (month == 3 && day > Months.values()[month - 2].getDays() && isLeapYear(year)) {
                day = Months.values()[month - 2].getDays() + 1;
                month = month - 1;
            } else {
                if (day > Months.values()[month - 2].getDays()) {
                    day = Months.values()[month - 2].getDays();
                    month = month - 1;
                } else {
                    if (isValidDate(day, month - 1, year))
                        month = month - 1;
                }
            }
        }
        return new MyDate(day, month, year);
    }

    public MyDate previousYear() {
        int day = this.getDay(), month = this.getMonth(), year = this.getYear();
        if (day > Months.values()[month - 1].getDays()) {
            day = Months.values()[month - 1].getDays();
            year = year - 1;
        } else {
            year = year - 1;
        }
        return new MyDate(day, month, year);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        MyDate myDate = (MyDate) o;
        return day == myDate.day &&
                month == myDate.month &&
                year == myDate.year;
    }

    @Override
    public String toString() {
        return "MyDate{" +
                "day=" + day +
                ", month=" + month +
                ", year=" + year +
                ", month_s=" + month_s +
                ", day_s=" + day_s +
                '}';
    }
}
