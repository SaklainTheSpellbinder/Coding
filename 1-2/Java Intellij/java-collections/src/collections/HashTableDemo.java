package collections;

import java.util.Enumeration;
import java.util.Hashtable;
import java.util.Iterator;
import java.util.Map;

class HashTableDemo {

    public static void main(String args[]) {
        Hashtable<String, Double> balance = new Hashtable<>();

        balance.put("John Doe", 3434.34);
        balance.put("Tom Smith", 123.22);
        //balance.put("Jane Baker", null); // error
        //balance.put(null, new Double(0)); // error
        balance.put("Jane Baker", 1378.00);
        balance.put("Tod Hall", 99.22);
        balance.put("Ralph Smith", -19.08);

        // Iterate through all the keys and print the values
        for (String key : balance.keySet()) {
            System.out.println("Key: " + key + ", Value: " + balance.get(key));
        }
        System.out.println();

        Enumeration<String> itr=balance.keys();
        while(itr.hasMoreElements()){
            String str=itr.nextElement();
            System.out.println(str+ " " +balance.get(str) );
        }

        String key = "John Doe";
        // Deposit 1,000 into John Doe's account
        double bal = balance.get(key);
        balance.put(key, bal + 1000);
        System.out.println(key + "'s new balance: " + balance.get(key));

        for (Map.Entry<String, Double> entry : balance.entrySet()) {
            System.out.println("Key: " + entry.getKey() + ", Value: " + entry.getValue());
        }

        balance.forEach((key1, value) ->
                System.out.println("Key: " + key1 + ", Value: " + value)
        );

        for (Double value : balance.values()) {
            System.out.println("Value: " + value);
        }

        Iterator<Map.Entry<String, Double>> iterator = balance.entrySet().iterator();
        while (iterator.hasNext()) {
            Map.Entry<String, Double> entry = iterator.next();
            System.out.println("Key: " + entry.getKey() + ", Value: " + entry.getValue());
        }

        balance.entrySet().stream()
                .filter(entry -> entry.getValue() > 0)
                .forEach(entry ->
                        System.out.println(entry.getKey() + ": " + entry.getValue())
                );
    }
}
