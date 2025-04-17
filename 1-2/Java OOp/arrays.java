import java.util.Arrays;

public class arrays {
    public static void main(String[] args){
        // char vowels[]=new char[5];

        // vowels[0]='a';
        // vowels[1]='e';
        // vowels[2]='i';
        // vowels[3]='o';
        // vowels[4]='u';
        // //vowels[5]='x';   not allowed

        char vowels[]={'u','e','o','i','a'};

        System.out.println(vowels.length);

        int startingIndex=1;
        int endingIndex=4;

        Arrays.sort(vowels,startingIndex,endingIndex);

        char key='o';

        int foundIndex=Arrays.binarySearch(vowels, key);//successful hole index dibe nahoy....negative value return korbe..
        //int foundIndex=Arrays.binarySearch(vowels,startingIndex,endingIndex,key);           //eta hocche starting r ending index er majhe check kore       

        System.out.println(Arrays.toString(vowels));
        System.out.println(foundIndex);

        Arrays.fill(vowels,startingIndex,endingIndex,'x');
        System.out.println(Arrays.toString(vowels));

        int numbers[]={1,2,3,4,5};
        int copyofnumbers[]=numbers;
        int copy[]=Arrays.copyOf(numbers,numbers.length);//data copy hoy array r//ekhane number.length er bodole jodi 10 ba beshi kono length use kora hoy.args..tahole main array copy hobe and erporer index gulate 0 boshbe..and..abar kom dile joddur dise toddur copy hobe 
        int copyrange[]=Arrays.copyOfRange(numbers,startingIndex,endingIndex);
        Arrays.fill(numbers,0);//but etay dui array tei change hoy tar maane....ekhane ashole kono data copy hoynai....copyofnumbers o same array kei point kore

        System.out.println(Arrays.toString(numbers));
        System.out.println(Arrays.toString(copyofnumbers));
        System.out.println(Arrays.toString(copy));
        System.out.println(Arrays.toString(copyrange));
    }
}
