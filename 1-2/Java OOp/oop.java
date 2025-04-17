import java.time.LocalDate;
import java.time.Period;
import java.util.ArrayList;

class Book{
    public String title;
    public String author;

    Book(String title, String author){
        this.title=title;
        this.author=author;
    }

    @Override
    public String toString(){
        return String.format("%s by %s",this.title,this.author);
    }
}

class AudioBook extends Book{
    private int runTime;

    AudioBook(String title,String author,int runTime){
        super(title,author);
        this.runTime=runTime;
    }

    public int getRunTime() {
        return runTime;
    }

    public void setRunTime(int runTime) {
        this.runTime = runTime;
    }
}

class User{
    public String name;
    public LocalDate birthDay;
    public ArrayList<Book>books= new ArrayList<>();

    User(String name,String birthDay){
        this.name=name;
        this.birthDay=LocalDate.parse(birthDay);
    }

    public void borrow(Book book){
        this.books.add(book);
    }

    public String getName(){
        return this.name;
    }

    public String getBirthDay(){
        return this.birthDay.toString();
    }

    public int age(){
        int age = Period.between(this.birthDay,LocalDate.now()).getYears();
        return age;
    }

    public String borrowedBooks(){
        return this.books.toString();
    }
}

public class oop {
    public static void main(String[] args){
        User youngeruser = new User("Saklain", "2004-11-06");
        //User olderuser = new User("tintin", "1975-11-06");

        Book book = new Book("Kite Runner","Khaled Hosseini");

        youngeruser.borrow(book);

        AudioBook audiobook=new AudioBook("Dracula","Bran Stoker" , 30000);
        youngeruser.borrow(audiobook);
        

        // System.out.printf("%s was born back in %s. He is %d years old\n",youngeruser.name,youngeruser.birthDay.toString(),youngeruser.age());
        // System.out.printf("%s was born back in %s. He is %d years old\n",olderuser.name,olderuser.birthDay.toString(),olderuser.age());

        System.out.printf("%s has borrowed these books: %s\n",youngeruser.getName(),youngeruser.borrowedBooks());
    }
}
