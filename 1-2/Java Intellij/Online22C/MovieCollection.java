public class MovieCollection {
    private int totalmovies;
    private int moviecount;
    private Movie[] movies;

    public MovieCollection(int totalmovies){
        this.totalmovies=totalmovies;
        moviecount=0;
        movies=new Movie[totalmovies];
    }

    public void addMovie(Movie movie){
        movies[moviecount++]=movie;
    }

    public void Search(String title){
        int i;
        for(i=0;i<totalmovies;i++){
            if(title.equals(movies[i].getTitle())){
                movies[i].display();
                break;
            }
        }
        if(i==totalmovies){
            System.out.println("Sorry "+title+" is not available.");
        }
    }

    public void rent(String title){
        int i;
        for(i=0;i<totalmovies;i++){
            if(title.equals(movies[i].getTitle())){
                if(movies[i].getAvailable()>0){
                    movies[i].decreaseRentedCopies();
                    System.out.println("Rent successful! Available copies for "+title+": "+movies[i].getAvailable());
                }
                else{
                    System.out.println("Error: All copies of \""+title+"\" are currently rented out.");
                }
                break;
            }
        }
        if(i==totalmovies){
            System.out.println("Sorry "+title+" is not available.");
        }
    }

}
