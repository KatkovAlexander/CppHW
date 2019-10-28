#ifndef DATE_DATE_H
#define DATE_DATE_H

class Date {
public:
    explicit Date(int year, int month, int day) {
        this->year = year;
        this->month = month;
        this->day = day;
    }

    bool IsLeap() const {
        if (this->year % 4 == 0) {
            if (this->year % 100 != 0 || this->year % 400 == 0) return true;
        } else {
            return false;
        }
        return false;
    }

    std::string ToString() const {
        if (year >= 1000) {
            if (day < 10) {
                if (month < 10)
                    return "0" + std::to_string(day) + ".0" + std::to_string(month) +
                           "." + std::to_string(year);
                else
                    return "0" + std::to_string(day) + "." + std::to_string(month) + "." +
                           std::to_string(year);
            } else {
                if (month < 10)
                    return std::to_string(day) + ".0" + std::to_string(month) + "." +
                           std::to_string(year);
                else
                    return std::to_string(day) + "." + std::to_string(month) + "." +
                           std::to_string(year);
            }
        } else if (year < 1000 && year >= 100) {
            if (day < 10) {
                if (month < 10)
                    return "0" + std::to_string(day) + ".0" + std::to_string(month) +
                           ".0" + std::to_string(year);
                else
                    return "0" + std::to_string(day) + "." + std::to_string(month) +
                           ".0" + std::to_string(year);
            } else {
                if (month < 10)
                    return std::to_string(day) + ".0" + std::to_string(month) + ".0" +
                           std::to_string(year);
                else
                    return std::to_string(day) + "." + std::to_string(month) + ".0" +
                           std::to_string(year);
            }
        } else if (year < 100 && year >= 10) {
            if (day < 10) {
                if (month < 10)
                    return "0" + std::to_string(day) + ".0" + std::to_string(month) +
                           ".00" + std::to_string(year);
                else
                    return "0" + std::to_string(day) + "." + std::to_string(month) +
                           ".00" + std::to_string(year);
            } else {
                if (month < 10)
                    return std::to_string(day) + ".0" + std::to_string(month) + ".00" +
                           std::to_string(year);
                else
                    return std::to_string(day) + "." + std::to_string(month) + ".00" +
                           std::to_string(year);
            }
        } else if (year < 10) {
            if (day < 10) {
                if (month < 10)
                    return "0" + std::to_string(day) + ".0" + std::to_string(month) +
                           ".000" + std::to_string(year);
                else
                    return "0" + std::to_string(day) + "." + std::to_string(month) +
                           ".000" + std::to_string(year);
            } else {
                if (month < 10)
                    return std::to_string(day) + ".0" + std::to_string(month) + ".000" +
                           std::to_string(year);
                else
                    return std::to_string(day) + "." + std::to_string(month) + ".000" +
                           std::to_string(year);
            }
        }
        return std::to_string(this->day);
    }

    Date DaysLater(int days) const {
        Date ymd = Date(this->year, this->month, this->day);

        int64_t a = (14 - ymd.month) / 12;
        int64_t y = ymd.year + 4800 - a;
        int64_t m = ymd.month + 12 * a - 3;
        int64_t jdn = ymd.day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 +
                   y / 400 - 32045 + days;

        a = jdn + 32044;
        int64_t b = (4 * a + 3) / 146097;
        int64_t c = a - (146097 * b) / 4;
        int64_t d = (4 * c + 3) / 1461;
        int64_t e = c - (1461 * d) / 4;
        m = (5 * e + 2) / 153;

        ymd.day = e - (153 * m + 2) / 5 + 1;
        ymd.month = m + 3 - 12 * (m / 10);
        ymd.year = 100 * b + d - 4800 + (m / 10);

        return ymd;
    }

    int DaysLeft(const Date& date) const {
        int64_t a = (14 - date.month) / 12;
        int64_t y = date.year + 4800 - a;
        int64_t m = date.month + 12 * a - 3;
        int64_t jdn1 = date.day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 +
                    y / 400 - 32045;

        a = (14 - month) / 12;
        y = year + 4800 - a;
        m = month + 12 * a - 3;
        int64_t jdn2 =
                day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;

        return jdn1 - jdn2;
    }

private:
    int year;
    int month;
    int day;
};
#endif  // DATE_DATE_H
