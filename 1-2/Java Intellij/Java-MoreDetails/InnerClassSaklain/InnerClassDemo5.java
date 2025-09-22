package InnerClassSaklain;

class Parent extends Grandparent{
    @Override
    public void f1(){
        System.out.println("f1() in parent");
    }
}

class InnerBase{
    public void f1(){
        System.out.println("f1() in InnerBase");
    }
}

public class InnerClassDemo5 extends Parent{
    @Override
    public void f1(){
        System.out.println("f1() in InnerClassDemo5 (Outer Class)");
    }

    class HawaiianGreeting extends InnerBase{
        @Override
        public void f1(){
            System.out.println("f1() in HawaiianGreeting(Inner Class)");
        }

        public void callAllVersions(){
            System.out.println("\n--- Calling all f1() versions from inside HawaiianGreeting---");
            this.f1();// eta ei inner class tar f1 ke daake
            super.f1(); // eta ei inner class er super je...mane InnerBase class er f1 ke daake
            InnerClassDemo5.this.f1(); // innerclassdemo5 er f1 ke daake
            InnerClassDemo5.super.f1();//innerclassdemo5 er superclass er f1 ke daake
        }
    }
    public static void main(String[] args){
        InnerClassDemo5 tintin=new InnerClassDemo5();
        InnerClassDemo5.HawaiianGreeting greeting=tintin.new HawaiianGreeting();

        greeting.callAllVersions();
    }
}
