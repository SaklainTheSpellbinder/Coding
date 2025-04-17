
import java.time.LocalDate;

class MyDate{
    private int day;
    private int month;
    private int year;

    MyDate(String str){
        LocalDate date=LocalDate.parse(str);
        this.day=date.getDayOfMonth();
        this.month=date.getMonthValue();
        this.year=date.getYear();
    }

    MyDate(int newday, int newMonth, int newYear){
        this.day=newday;
        this.month=newMonth;
        this.year=newYear;
    }

    public void showMyDate(){
        System.out.println(day+ "/" + month + "/" + year);
    }

    public int getDay() {
        return day;
    }

    public void setDay(int day) {
        this.day = day;
    }

    public int getMonth() {
        return month;
    }

    public void setMonth(int month) {
        this.month = month;
    }

    public int getYear() {
        return year;
    }

    public void setYear(int year) {
        this.year = year;
    }
}

public class Polymorphism {
    public static void main(String[] args){
        MyDate sDate= new MyDate("2024-04-12");
        MyDate iDate= new MyDate(23,4,2025);

        sDate.showMyDate();
        iDate.showMyDate();
    }
}
