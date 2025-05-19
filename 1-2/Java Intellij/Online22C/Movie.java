public class Movie{
    private String title;
    private String genre;
    private double rating;
    private int total_copies;
    private int rented_copies;
    private int available;

    public Movie(String title,String genre,double rating,int total_copies,int rented_copies){
        this.title=title;
        this.genre=genre;
        this.rating=rating;
        this.total_copies=total_copies;
        this.rented_copies=rented_copies;
        this.available = total_copies-rented_copies;
    }

    public String getTitle(){
        return title;
    }

    public String getGenre(){
        return genre;
    }

    public double getRating(){
        return rating;
    }

    public int getTotalCopies(){
        return total_copies;
    }

    public int getRentedCopies(){
        return rented_copies;
    }

    public int getAvailable(){
        return available;
    }

    public void decreaseRentedCopies(){
        rented_copies--;
        available--;
    }

    public void display(){
        System.out.println("\nMovie details: ");
        System.out.println("- Title: "+title);
        System.out.println("- Genre: "+genre);
        System.out.println("- Rating: "+rating);
        System.out.println("- Available copies: "+available);
    }
}