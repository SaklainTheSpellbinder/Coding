
import java.util.Scanner;

public class conditional {
    public static void main(String[] args){
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.print("Enter the first number: ");
            double number1= scanner.nextDouble();
            System.out.print("Enter the second number: ");
            double number2=scanner.nextDouble();
            scanner.nextLine();
            System.out.print("which operation: ");
            String operation=scanner.nextLine();
            switch (operation) {
                case "sum" -> System.out.printf("%f + %f = %f\n",number1,number2,number1+number2);
                case "sub" -> System.out.printf("%f - %f = %f\n",number1,number2,number1-number2);
                case "multiply" -> System.out.printf("%f * %f = %f\n",number1,number2,number1*number2);
                case "div" -> System.out.printf("%f / %f = %f\n",number1,number2,number1/number2);
                default -> System.out.printf("%s is not suppoerted\n",operation);
            }
            // if(operation.equals("sum")){
            //     System.out.printf("%f + %f = %f\n",number1,number2,number1+number2);
            // }
            // else if (operation.equals("sub")) {
            //     System.out.printf("%f - %f = %f\n",number1,number2,number1-number2);
            // }
            // else if (operation.equals("multiply")) {
            //     System.out.printf("%f * %f = %f\n",number1,number2,number1*number2);
            // }
            // else if (operation.equals("div")) {
            //     System.out.printf("%f / %f = %f\n",number1,number2,number1/number2);
            // }
            // else{
            //     System.out.printf("%s is not suppoerted\n",operation);
            // }
        }
    }
}
