
import java.util.HashMap;
import java.util.Objects;

public class Movie {
    private String title;
    private int releasseYear;
    private String productionCompany;
    private int runningTime;

    public Movie(String title,int releasseYear,String productionCompany,int runningTime) {
        this.productionCompany = productionCompany;
        this.releasseYear = releasseYear;
        this.runningTime = runningTime;
        this.title = title;
    }


    @Override
    public int hashCode() {
        return Objects.hash(title,releasseYear,runningTime);
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (!(obj instanceof Movie))
            return false;
        Movie other = (Movie) obj;
        if(this.title.equals(other.title) && this.releasseYear==other.releasseYear && this.runningTime==other.runningTime){
            return true;
        }
        return false;
    }

    public static void main(String[] args) {
        Movie m1=new Movie("The Lord of the Rings",2001,"New Line Cinema",178);
        Movie m2=new Movie("The Lord of the Rings",2001,"WingNut Films",178);
        System.out.println(m1==m2);
        System.out.println(m1.equals(m2));
        HashMap map=new HashMap<>();
        map.put(m1,93);
        System.out.println(map.get(m2));
    }
}
