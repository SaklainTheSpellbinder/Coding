public class EnumDemo4 {
    public static void main(String[] args){
        Apple ap1,ap2,ap3;
        System.out.println("Here are all apple constants" +
                "and their ordinal values: " );
        for(Apple a: Apple.values()){
            System.out.println(a+" "+ a.ordinal());
        }

        ap1=Apple.RedDel;
        ap2=Apple.GoldenDel;
        ap3=Apple.RedDel;

        System.out.println();

        if(ap1.compareTo(ap2)<0){
            System.out.println(ap1 +" comes before "+ ap2);
        }

        if(ap1.compareTo(ap2)>0){
            System.out.println(ap2 +" comes before "+ ap1);
        }

        if(ap1.compareTo(ap2)==0){
            System.out.println(ap2 +" equals "+ ap1);
        }

        System.out.println();

        if(ap1.equals(ap2)){
            System.out.println("Error!");
        }

        if(ap1.equals(ap3)){
            System.out.println(ap1+" equals "+ ap3);
        }

        if(ap1==ap3){
            System.out.println(ap1+" == "+ap3);
        }
    }
}
