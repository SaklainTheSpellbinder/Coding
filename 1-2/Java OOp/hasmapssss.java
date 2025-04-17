import java.util.HashMap;

public class hasmapssss {
    public static void main(String[] args){
        HashMap<String, Integer> examScores =new HashMap<>();

        examScores.put("Math",75);
        examScores.put("Sociology",85);
        examScores.put("English",100);

        System.out.println(examScores.toString());

        System.out.println(examScores.get("English"));

        examScores.putIfAbsent("Math",90);
        System.out.println(examScores.toString());

        System.out.println(examScores.get("tintin"));//null print hobe
        System.out.println(examScores.getOrDefault("tintin",-1));//-1 print hobe

        System.out.println(examScores.size());

        examScores.forEach((subject, score) ->{
            System.out.println(subject + "-" + score);
            examScores.replace(subject,score-10);
        });

        examScores.remove("English");

        System.out.println(examScores.containsKey("Math"));
        System.out.println(examScores.containsValue(100));


        examScores.clear();
        System.out.println(examScores.toString());

        System.out.println(examScores.isEmpty());
    }
}
