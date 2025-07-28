package generics;

class Stats<T extends Number> {
    T[] nums;

    Stats(T[] o) {
        nums = o;
    }

    double average() {
        double sum = 0.0;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i].doubleValue();
        }
        return sum / nums.length;
    }

    <S extends Number> boolean sameAvg(Stats<S> obj) {//s1 object er jonno to T to integer hoye geche....ekhaneo S er bodole T use korle....jodi Double er stats pathai tahole to T etake dhorbe na
        if (average() == obj.average()) {
            return true;
        } else return false;
    }

    boolean sameAvgAny(Stats<?> obj) {//but wildcard any valid type nibe
        if (average() == obj.average()) {
            return true;
        } else return false;
    }
}

public class MyGenerics6 {
    public static void main(String[] args) {
        Integer[] n1 = {10, 20, 30, 40, 50};
        Stats<Integer> s1 = new Stats<>(n1);
        System.out.println(s1.average());
        Stats[] tintin0=new Stats[10];//raw use of class emon warning dey....but pera nai....we can literally assign different object types on different indices...
        Stats<Integer>[] tintin=new Stats[10];//unchecked assignment warning dey....but emne pera nai
        //Stats<Integer>[] tintin2=new Stats<Integer>[10];  //eta possible na
        Integer[] n2 = {50, 20, 40, 10, 30};
        Stats<Integer> s2 = new Stats<>(n2);
        System.out.println(s2.average());

        System.out.println(s1.sameAvg(s2));

        Double[] n3 = {50.0, 40.0, 30.0, 20.0, 10.0};
        Stats<Double> s3 = new Stats<>(n3);
        System.out.println(s3.average());

        System.out.println(s2.sameAvg(s3));
    }
}
