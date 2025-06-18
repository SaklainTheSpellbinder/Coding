package firstproblem;

public class TransportManager {
    private static int transportcount=0;
    private static Transport[] transports=new Transport[20];
    TransportManager(int ID,String DriverName,int capacity,String type){
        if(transportcount==transports.length){
            System.out.println("not enough memory");
        }
        else{
            if(type.equals("Bus")) {
                transports[transportcount++]=new Bus(ID,DriverName,capacity);
            }
            else if(type.equals("Car")) {
                transports[transportcount++]=new Car(ID,DriverName,capacity);
            }
            else if(type.equals("RickshawVan")) {
                transports[transportcount++]=new RickshawVan(ID,DriverName,capacity);
            }
        }
    }

    public static void printTransports(){
        for(int i=0;i<transportcount;i++){
            System.out.println(transports[i].getID()+" "+transports[i].getDriverName()+" "+transports[i].getCapacity());
        }
    }
}
