class Student {
    private String name;   // private field (hidden)
    private int age;

    // Getter
    public String getName() {
        return name;
    }

    // Setter
    public void setName(String newName) {
        this.name = newName;
    }

    // Getter
    public int getAge() {
        return age;
    }

    // Setter with validation
    public void setAge(int newAge) {
        if (newAge > 0)
            this.age = newAge;
        else
            System.out.println("Invalid age");
    }
}

class Employee {
    private int id;
    private String name;
    private double salary;

    public Employee(int id, String name, double salary) {
        if (id > 0 && salary >= 0) {
            this.id = id;
            this.name = name;
            this.salary = salary;
        } else {
            System.out.println("Invalid data");
        }
    }

    public int getId() { return id; }
    public String getName() { return name; }
    public double getSalary() { return salary; }

    public void setSalary(double salary) {
        if (salary >= 0)
            this.salary = salary;
    }
}



public class Enacapsulation {
    public static void main(String[] args) {
        Student s = new Student();
        s.setName("Utshav");
        s.setAge(21);
        Employee e=new Employee(0, null, 0);
        System.out.println(e.getId());

        System.out.println(s.getName() + " is " + s.getAge() + " years old.");
    }
}
