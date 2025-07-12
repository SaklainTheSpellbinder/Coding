import java.util.ArrayList;
import java.util.List;

class HoldingAreaManager{
    int capacity;
    int count=0;
    boolean flightA=false;
    boolean flightB=true;
    String lastFlight="FlightA";

    public HoldingAreaManager(int capacity) {
        this.capacity = capacity;
    }

    synchronized void enter(String name,String flight){
        if(!lastFlight.equals(flight)){
            try {
                wait();
            } catch (InterruptedException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
        }
        else if(count==capacity){
            //print
            //boarding
        }
        else{

        }
    }

}

class Plane extends Thread{

}

public class FlightBoardingGateStimulation {
    public static void main(String[] args) throws InterruptedException {
        // Create shared holding area with max capacity 4
        HoldingAreaManager holdingArea = new HoldingAreaManager(4);


        // Create shared runway controller
        Runway runway = new Runway();


        // Predefined passenger list for two flights
        String[] passengers = {
            "P1:A", "P2:A", "P3:A", "P4:A", "P5:A",
            "P6:B", "P7:B", "P8:B", "P9:B", "P10:B"
        };


        // Group passengers by flight
        List<String> flightA = new ArrayList<>();
        List<String> flightB = new ArrayList<>();


        for (String entry : passengers) {
            String[] split = entry.split(":");
            String name = split[0];
            String flight = split[1];
            if (flight.equals("A")) flightA.add(name);
            else flightB.add(name);
        }


        // Start plane threads
        Plane planeA = new Plane("Flight A", flightA, holdingArea, runway);
        Plane planeB = new Plane("Flight B", flightB, holdingArea, runway);
        planeA.start();
        planeB.start();

        

        // Start passengers
        for (String entry : passengers) {
            String[] split = entry.split(":");
            String name = split[0];
            String flight = split[1];
            Passenger p = new Passenger(name, flight, holdingArea);
            p.start();
            Thread.sleep(300); // stagger arrivals
        }
    }
}



