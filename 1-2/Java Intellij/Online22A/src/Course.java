public class Course {
    private String name;
    private double creditHour;
    private int marks;

    public Course(String name,double creditHour){
        this.name=name;
        this.creditHour=creditHour;
        marks=0;
    }

    public String getName(){
        return name;
    }

    public double getCreditHour(){
        return creditHour;
    }

    public void setName(String name){
        this.name=name;
    }

    public void setCreditHour(double creditHour){
        this.creditHour=creditHour;
    }

    public void setMarks(int marks){
        this.marks=marks;
    }

    public int getMarks(){
        return marks;
    }

}
