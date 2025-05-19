import java.util.Scanner;
public class Main {
    public static void main(String[] args){
        if(args.length>0){
            System.out.println("Number of movies from command line argument: "+args[0]);
            Scanner sc=new Scanner(System.in);
            int totalmovies=Integer.parseInt(args[0]);
            MovieCollection mb=new MovieCollection(totalmovies);
            for(int i=0;i<totalmovies;i++){
                System.out.println("\nEnter details for movie "+(i+1)+": ");
                System.out.print("Title: ");
                String title=sc.nextLine();
                System.out.print("Genre: ");
                String genre=sc.nextLine();
                System.out.print("Rating (out of 10): ");
                double rating=sc.nextDouble();
                sc.nextLine();
                while(rating<0 || rating>10){
                    System.out.print("Invalid value, please try again: ");
                    rating=sc.nextDouble();
                    sc.nextLine();
                }
                System.out.print("Total copies: ");
                int total_copies=sc.nextInt();
                sc.nextLine();
                System.out.print("Rented copies: ");
                int rented_copies=sc.nextInt();
                sc.nextLine();
                while(rented_copies>total_copies){
                    System.out.print("Invalid value, please try again: ");
                    rented_copies=sc.nextInt();
                    sc.nextLine();
                }
                Movie movie=new Movie(title, genre, rating, total_copies, rented_copies);
                mb.addMovie(movie);
            }
            System.out.println("---\nCommands:");
            System.out.println("- search <title>: Search for a movie by title and display details.");
            System.out.println("- rent <title>: Attempt to rent a movie by title, increasing rented copies if available.\n---");

            while (true) { 
                System.out.print("\nEnter command: ");
                String command=sc.nextLine();
                String[] parts=command.split(" ",2);
                if(parts[0].equals("search")){
                    mb.Search(parts[1]);
                }
                else if(parts[0].equals("rent")){
                    mb.rent(parts[1]);
                }
                else{
                    System.out.println("mara kha");
                    break;
                }
            }
            sc.close();
        }

    }
}
