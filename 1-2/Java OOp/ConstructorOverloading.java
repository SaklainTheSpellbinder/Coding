// Example of Constructor Overloading in Java
class Book {
    String title;
    int pages;

    Book() {
        this("Untitled", 0); // Calls the two-arg constructor
    }

    Book(String t) {
        this(t, 100); // Calls the two-arg constructor
    }

    Book(String t, int p) {
        title = t;
        pages = p;
    }

    void show() {
        System.out.println(title + " has " + pages + " pages");
    }
}


public class ConstructorOverloading {

    private String name;
    private int age;

    // Default constructor
    public ConstructorOverloading() {
        this.name = "Unknown";
        this.age = 0;
    }
    

    // Constructor with one parameter
    public ConstructorOverloading(String name) {
        this.name = name;
        this.age = 0;
    }

    // Constructor with two parameters
    public ConstructorOverloading(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public void displayInfo() {
        System.out.println("Name: " + name + ", Age: " + age);
    }

    public static void main(String[] args) {
        ConstructorOverloading obj1 = new ConstructorOverloading();
        ConstructorOverloading obj2 = new ConstructorOverloading("Alice");
        ConstructorOverloading obj3 = new ConstructorOverloading("Bob", 25);

        obj1.displayInfo();
        obj2.displayInfo();
        obj3.displayInfo();

        Book book1 = new Book();
        Book book2 = new Book("Java Programming");
        Book book3 = new Book("Advanced Java", 500);
        System.out.println("Book 1: "); book1.show();
        System.out.println("Book 2: "); book2.show();
        System.out.println("Book 3: "); book3.show();                  
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
}