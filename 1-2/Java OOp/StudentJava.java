import java.util.Scanner;

class Student{
    private String name;
    private int rollno;
    private double cgpa;

    //setter-getter
    public void setName(String N){name=N;}
    public String getName(){return name;}
    public void setRollno(int R){rollno=R;}
    public int getRollno(){return rollno;}
    public void setCGPA(double CGPA){cgpa=CGPA;}
    public double getCGPA(){return cgpa;}
}

public class StudentJava {
    public static void main(String[] args){
        Student std=new Student();
        String iname;
        try (Scanner scanner = new Scanner(System.in)) {
            int irollno;
            double icgpa;
            
            System.out.print("Enter your name: ");
            iname=scanner.nextLine();
            std.setName(iname);
            
            System.out.print("Enter roll no: ");
            irollno=scanner.nextInt();
            std.setRollno(irollno);
            
            System.out.print("Enter your cgpa: ");
            icgpa=scanner.nextDouble();
            std.setCGPA(icgpa);
            
            System.out.println("Name : "+ std.getName() + " Roll No: " + std.getRollno() + " CGPA : " + std.getCGPA());
        }
    }
}
