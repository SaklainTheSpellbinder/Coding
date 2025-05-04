public class Main {
    public static void main(String[] args) {
        MyClass[] ob=new MyClass[5];

        for(int i=0;i<ob.length;i++){
            if(i%2!=0){
                ob[i]=new MyClass();
            }
            else{
                ob[i]=new MyClass(i+1);
            }
        }


        for(int i=0;i<ob.length;i++){
            System.out.print(ob[i].getX()+" ");
        }

        System.out.println();


        Rectangle r=new Rectangle(4,5);
        Triangle t=new Triangle(4,3);
        Figure figeref;

        figeref=r;
        figeref.show();
        figeref=t;
        figeref.show();

        System.out.println("Total args: "+args.length);

        for(int i=0;i<args.length;i++){
            System.out.println("Arg "+i+": "+args[i]);
        }
    }

}