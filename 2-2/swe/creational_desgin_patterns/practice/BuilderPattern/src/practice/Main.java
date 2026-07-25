package practice;

class HolidayPackage{
    private String flight;
    private String hotel;
    private String dailyActivity;

    public String getHotel() {
        return hotel;
    }

    public void setHotel(String hotel) {
        this.hotel = hotel;
    }

    public String getFlight() {
        return flight;
    }

    public void setFlight(String flight) {
        this.flight = flight;
    }

    public String getDailyActivity() {
        return dailyActivity;
    }

    public void setDailyActivity(String dailyActivity) {
        this.dailyActivity = dailyActivity;
    }
}

interface HolidayPackageBuilder{
    void buildFlight();
    void buildHotel();
    void buildActivity();

    HolidayPackage getPackage();
}

class RelaxationPackageBuilder implements HolidayPackageBuilder{
    private final HolidayPackage holidayPackage=new HolidayPackage();

    @Override
    public void buildActivity() {
        holidayPackage.setDailyActivity("");
    }

    @Override
    public void buildFlight() {

    }

    @Override
    public void buildHotel() {

    }

    @Override
    public HolidayPackage getPackage() {
        return null;
    }
}



public class Main {
}
