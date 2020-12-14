//secret agent time travel calculations


bool is_leap(int year) {
    return !(year % 400) || !(year % 4) && (year % 100);
}

int get_days(int days, int month, int year) {

    int i;
    int y_days = 0;
    int m_days = 0;

    for (i = 0; i < year; i++) {
        if (is_leap(i) || i < 1752 && !(i % 4)) {
            y_days += 366;
        }
        else {
            y_days += 365;
        }
    }

    for (i = 0; i < month - 1; i++) {
        if (i == 1) {
            if (is_leap(year)) { m_days += 29; }
            else { m_days += 28; }
        }
        else if (i % 2) {
            if (i >= 7) { m_days += 31; }
            else { m_days += 30; }
        }
        else {
            if (i >= 7) { m_days += 30; }
            else { m_days += 31; }
        }
    }

    int date = y_days + m_days + days;

    if (date < 640165) {
        return date + 11;
    }

    return date;
}

int days(int date, int month, int year){
  cout << date << " " << month << " " << year << endl;
  int now = get_days(24,3,2437);
  int b4  = get_days(date, month, year);
  
  return now - b4;
}