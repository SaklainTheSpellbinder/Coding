import java.util.Scanner;
public class Main2 {
    public static void main(String[] args){
        if(args.length>0){
            System.out.println("Number of books provided from command line: "+args[0]);
            int bookscount=Integer.parseInt(args[0]);
            Library lb=new Library(bookscount);
            Scanner sc=new Scanner(System.in);
            for(int i=0;i<bookscount;i++){
                System.out.println("\nEnter details for book "+(i+1)+": ");
                System.out.print("Title: ");
                String title=sc.nextLine();
                System.out.print("Author: ");
                String author=sc.nextLine();
                System.out.print("ISBN: ");
                String ISBN=sc.nextLine();
                System.out.print("Total copies: ");
                int total_copies=sc.nextInt();
                sc.nextLine();
                System.out.print("Borrowed copies: ");
                int borrowed_copies=sc.nextInt();
                sc.nextLine();
                while(borrowed_copies>total_copies){
                    System.out.print("Invalid value, please try again: ");
                    borrowed_copies=sc.nextInt();
                    sc.nextLine();
                }
                Book book=new Book(title,author,ISBN,total_copies,borrowed_copies);
                lb.addBooks(book);
            }
            System.out.println("\nSearch for a book by title: 1984");
            lb.display("1984");
            System.out.println("\nSearch for a book by title: To Kill a Mockingbird");
            lb.display("To Kill a Mockingbird");
            sc.close();
        }
    }
}
