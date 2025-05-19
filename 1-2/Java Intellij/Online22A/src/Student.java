public class Student {
    private String name;
    private Course[] courses;
    private double[] grades;
    private int addcoursecount=0;

    public Student(String name,int coursescount){
        this.name=name;
        courses=new Course[coursescount];
        grades=new double[coursescount];
    }

    public void addCourse(Course course,int marks){
        courses[addcoursecount]=course;
        courses[addcoursecount].setMarks(marks);
        grades[addcoursecount]=getGrade(marks);
        addcoursecount++;
    }

    public String getName(){
        return name;
    }
    
    public double getGrade(int marks){
        if(marks>=80 && marks<=100){
            return 4.00;
        }
        else if(marks>=70){
            return 3.75;
        }
        else if(marks>=60){
            return 3.5;
        }
        else if(marks>=50){
            return 3.0;
        }
        else if(marks>=40){
            return 2.5;
        }
        return 0.0;
    }

    public double getGPA(){
        double totalcg=0.0;
        double totalcredit=0.0;
        for(int i=0;i<addcoursecount;i++){
            totalcredit+=courses[i].getCreditHour();
            totalcg+=(courses[i].getCreditHour()*grades[i]);
        }
        return totalcg/totalcredit;
    }

    public void display(){
        System.out.println("\nGrades for "+name+": ");
        for(int i=0;i<addcoursecount;i++){
            System.out.println("- Course:"+courses[i].getName()+", Grade: "+grades[i]);
        }
        System.out.println("- CGPA: "+getGPA());
    }

}