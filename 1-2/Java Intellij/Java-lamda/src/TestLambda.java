@FunctionalInterface  //functional interface mane exactly ekta abstract method thakbe
interface MyNumber {
    double getValue();
}

@FunctionalInterface
interface NumericTest {
    boolean test(int n);
}

@FunctionalInterface
interface NumericTest2 {
    boolean test(int n1, int n2);
}

@FunctionalInterface
interface NumericFunction {
    int func(int n);
}

@FunctionalInterface
interface StringFunction {
    String func(String n);
}

public class TestLambda {
    public static void main(String[] args) {
        MyNumber myNumber;
        myNumber = () -> 102.45;
        System.out.println(myNumber.getValue());
        myNumber = () -> Math.random() * 100;
        System.out.println(myNumber.getValue());

        NumericTest numericTest;
        numericTest = (n) -> n % 2 == 0;
        System.out.println(numericTest.test(107));
        numericTest = n -> n >= 0;
        System.out.println(numericTest.test(-10));

        NumericTest2 numericTest2;
        numericTest2 = (n1, n2) -> (n1 + n2) % 2 == 0;
        System.out.println(numericTest2.test(107, 5));
        numericTest2 = (n1, n2) -> (n1 + n2) >= 0;
        System.out.println(numericTest2.test(-20, 10));

        NumericFunction factorial;
        factorial = (n) -> {
            int result = 1;
            for (int i = 1; i <= n; i++) {
                result = result * i;
            }
            return result;
        };
        System.out.println(factorial.func(8));

        StringFunction stringFunction;
        stringFunction = (n) -> {
            String result = "";
            for (int i = n.length() - 1; i >= 0; i--) {
                result = result + n.charAt(i);
            }
            return result;
        };
        System.out.println(stringFunction.func("hello world"));

        StringFunction sf=new StringFunction() {//anonymous class object
            @Override
            public String func(String n) {
                return "Cholo ekshate doore thaki";
            }
        }; //semicolon dite bhulbe naaaaaaaaaaaaaaaa

        //egula to interface tai just hoy oije instance niye pashe lekha lagbe ba ebhabe anonymous class...

        System.out.println(sf.func("Helloo"));

        StringFunction sf2=n->"cholo more jaiiiiiiiiiiiiiiiiiiiiiiiiiii";
        System.out.println(sf2.func("rfrfrfrf"));

        //but thread start er shomoy jevabe likhi oivabe lekha possible na karon....eta thread to class...r egula to interface
        new Thread(()-> System.out.println("cholo shobai")).start();
        //eta thread class bole...mainly constructor e amra new runnable interface er lamda likhe pass korsi....bujhco???

        NumericFunction nm1=(n)->12; //evaabe likhle oije return lekha jabe...return likhle third bracket diye likhte hobe
    }
}