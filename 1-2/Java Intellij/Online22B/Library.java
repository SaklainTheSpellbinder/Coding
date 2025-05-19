
public class Library {
    private final Book[] books;
    int totalbooks;
    int bookscount;

    public Library(int totalbooks){
        this.totalbooks=totalbooks;
        books=new Book[totalbooks];
        bookscount=0;
    }

    public void addBooks(Book book){
        books[bookscount++]=book;
    }

    public void display(String title){
        int i;
        for(i=0;i<totalbooks;i++){
            if(title.equals(books[i].getTitle())){
                books[i].display();
                break;
            }
        }
        if(i==totalbooks){
            System.out.println("This book doesn't exist");
        }
    }
}