
public class Book{
    private String title;
    private String author;
    private String ISBN;
    private int total_copies;
    private int borrowed_copies;

    public Book(String title,String author,String ISBN,int total_copies,int borrowed_copies){
        this.title=title;
        this.author=author;
        this.ISBN=ISBN;
        this.total_copies=total_copies;
        this.borrowed_copies=borrowed_copies;
    }

    public void setTitle(String title){
        this.title=title;
    }

    public void setAuthor(String author){
        this.author=author;
    }

    public void setISBN(String ISBN){
        this.ISBN=ISBN;
    }    

    public void setTotalCopies(int total_copies){
        this.total_copies=total_copies;
    }

    public void setBorrowedCopies(int borrowed_copies){
        this.borrowed_copies=borrowed_copies;
    }

    public String getTitle(){
        return title;
    }

    public String getAuthor(){
        return author;
    }

    public String getISBN(){
        return ISBN;
    }

    public int getTotalCopies(){
        return total_copies;
    }

    public int getBorrowedCopies(){
        return borrowed_copies;
    }

    public void display(){
        System.out.println("\nBook details: ");
        System.out.println("- Title: "+title);
        System.out.println("- Author: "+author);
        System.out.println("- ISBN: "+ISBN);
        System.out.println("- Available: "+(total_copies-borrowed_copies));
        if((total_copies-borrowed_copies)==0){
            System.out.println("Status: All copies are currently borrowed.");
        }
    }
}