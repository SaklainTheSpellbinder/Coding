import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        if(args.length>0){
            System.out.println("Parsing command line arguments...");
            System.out.println("Number of students: "+args[0]);
            System.out.println("Number of courses: "+args[1]);
            System.out.println("---");
            Scanner sc=new Scanner(System.in);
            int coursescount=Integer.parseInt(args[1]);
            int studentcount=Integer.parseInt(args[0]);
            Course[] courses=new Course[coursescount];
            Student[] students=new Student[studentcount];
            for(int i=0;i<coursescount;i++){
                System.out.println("\nCourse "+(i+1));
                System.out.print("Enter course name: ");
                String name=sc.nextLine();
                System.out.print("Enter course credit: ");
                double credit=sc.nextDouble();
                sc.nextLine();
                courses[i]=new Course(name, credit);
            }
            System.out.println("---\n");
            for(int i=0;i<studentcount;i++){
                System.out.print("\nEnter name of student "+(i+1)+": ");
                String name=sc.nextLine();
                students[i]=new Student(name, coursescount);
                for(int j=0;j<coursescount;j++){
                    System.out.print("Enter marks for "+courses[j].getName()+": ");
                    int marks=sc.nextInt();
                    sc.nextLine();
                    students[i].addCourse(courses[j], marks);
                }
            }
            System.out.println("---\n");

            while(true){ 
                System.out.print("Enter command: ");  
                String commandinp=sc.nextLine();
                String[] parts=commandinp.split(" ");
                if(parts[0].equals("display")){
                    if(parts[1].equals("all")){
                        for(int i=0;i<studentcount;i++){
                            students[i].display();
                        }
                    }
                    else{
                        int i;
                        for(i=0;i<studentcount;i++){
                            if(students[i].getName().equals(parts[1])){
                                students[i].display();
                                break;
                            }
                        }
                        if(i==studentcount){
                            System.out.println("Student "+parts[1]+" does not exist.");
                        }
                    }
                }
                else if(parts[0].equals("delete")){
                    int i;
                    for(i=0;i<studentcount;i++){
                        if(students[i].getName().equals(parts[1])){
                            break;
                        }
                    }
                    if(i==studentcount){
                        System.out.println("Student "+parts[1]+" does not exist.");
                    }
                    else{
                        System.out.println("Success, student "+parts[1]+" deleted.");
                        for(int j=i+1;j<studentcount;j++){
                            students[j-1]=students[j];
                        }
                        studentcount--;
                    }
                }
                else if(parts[0].equals("exit")){
                    System.out.println("Terminating...");
                    break;
                }
                System.out.println("---\n");
            }
            sc.close();
        }
        else{
            System.out.println("Usage: java Main <file>");
        }
    }
}