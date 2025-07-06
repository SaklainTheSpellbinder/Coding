public class MoreJai {
    public static void main(String[] args){
        String s1=new String("Ami Saklain. Amar cheye noob keo nei");
        String s2=s1.substring(4);
        String s3=s1.substring(4,11);
        String s4=s1;
        String s5="Ami Saklain. Amar cheye noob keo nei";
        String s6="Ami Saklain. Amar cheye noob keo nei";
        System.out.println(s1);
        System.out.println(s2);
        System.out.println(s3);
        System.out.println(s1==s4);//karon direct etai to dilam
        System.out.println(s5==s1);//s1 new diye lekhay oita alada....oita alada kore create hoy
        System.out.println(s4==s5);
        System.out.println(s5.equals(s4));
        System.out.println(s5==s6);//string pool check korbe....string literal same dekhe s6 r notun toiri hobe na...same ta kei point korbe
    }
}
