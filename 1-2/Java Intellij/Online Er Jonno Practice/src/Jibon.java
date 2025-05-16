class ArrayHelper{
    public static int findMax(int[] arr){
        int max=arr[0];
        for(int x: arr){
            if(x>max)
                max=x;
        }
        return max;
    }
}

public class Jibon {
    public static void main(String[] args){
        int[] numbers={2,7,4,9,5};
        System.out.println("Max = "+ArrayHelper.findMax(numbers));
    }
}
