package p1;
public class SamePackage {
    SamePackage() {
        System.out.println("---SamePackage---");
        Protection p = new Protection();
        System.out.println(p.n);
        //System.out.println(p.nPrivate); //nPrivate has private access in p1.Protection
        System.out.println(p.nProtected);
        System.out.println(p.nPublic);
        Protection.Tingtong hola=p.new Tingtong();
        System.out.println(hola.a +" protected inner class er public jinish same package er non subclass theke use kortesi orreh");
        System.out.println(hola.b +" protected inner class er protected jinish same package er non subclass theke use kortesi....but private jinish ta use kora jacche na....hayre java");
    }

    public static void main(String[] args) {
        Protection ob1 = new Protection();
        DerivedProtection ob2 = new DerivedProtection();
        SamePackage ob3 = new SamePackage();


    }
}
