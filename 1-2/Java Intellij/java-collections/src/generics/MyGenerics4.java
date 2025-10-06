package generics;

class Person implements Comparable<Person>{
    String name;

    Person(String name){
        this.name=name;
    }

    @Override
    public boolean equals(Object obj){
        if (this==obj) return true;

        if (obj == null || !(obj instanceof Person)) return false;

        Person other=(Person) obj;
        return this.name.equals(other.name);
    }

    @Override
    public int compareTo(Person other){
        return this.name.compareTo(other.name);
    }

    @Override
    public String toString(){
        return "Person[name=" + name+"]";
    }
}

class Student extends Person{
    int studentId;
    Student(String name,int id){
        super(name);
        this.studentId=id;
    }

    @Override
    public String toString(){
        return "Student[name="+name+", id="+studentId+"]";
    }
}

class GenCons {
    private double val;

    public <T extends Number> GenCons(T arg) {
        val = arg.doubleValue();
    }

    void showVal() {
        System.out.println("val: " + val);
    }

    public static <T extends Comparable<T>,V extends T> boolean isIn(T x, V[] a) {
        for (V t : a) {
            if (x==t) return true; //x.equals dite hobe tahole parent er equals onujayi compare korbe...but t.equals dile jodi child e equals abar override kora thake...tahole oita onujayi check korbe
        }
        return false;
    }

    public static <T extends Comparable<T>, V extends T> boolean isValueIn(T x, V[] a) {
        for (V elementInArray : a) {
            if (x.equals(elementInArray)) {
                return true;
            }
        }
        return false;
    }

    public <V> boolean isIn2(V x, V[] a) {
        for (V t : a) {
            if (t==x) return true;
        }
        return false;
    }
}

public class MyGenerics4 {
    public static void main(String args[]) {
        GenCons test = new <Integer>GenCons(100);//bracket er bhitor na likheo no pera
        GenCons test2 = new GenCons(123.5d);
        test.showVal();
        test2.showVal();
        Integer [] iArray = {1, 2, 3, 4, 5};
        System.out.println(GenCons.isIn(1, iArray));//not necessarily  <> eta dewa lagbe
        System.out.println(test.<Integer>isIn2(1, iArray));

        Student[] studentArray = {
                new Student("Alice", 101),
                new Student("Bob", 102),
                new Student("Charlie", 103)
        };

        Person searchPerson = new Person("Bob");
        Person searchPersonReference = studentArray[1];

        System.out.println("Searching for: " + searchPerson);
        System.out.println("---");

        boolean foundWithEqualsEquals = GenCons.isIn(searchPerson, studentArray);
        System.out.println("Found using your original method (==)?  " + foundWithEqualsEquals);

        boolean foundWithReference = GenCons.isIn(searchPersonReference, studentArray);
        System.out.println("Found using reference (==)?             " + foundWithReference);

        boolean foundWithDotEquals = GenCons.isValueIn(searchPerson, studentArray);
        System.out.println("Found using corrected method (.equals())? " + foundWithDotEquals);
    }
}