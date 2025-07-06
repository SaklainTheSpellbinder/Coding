public class IndexOfExample {
    public static void main(String[] args) {
        String str = "Hello, World!";
        
        // Find the index of the first occurrence of 'o'
        int index1 = str.indexOf('o');
        System.out.println("Index of 'o': " + index1);  // Output will be: 4
        
        // Find the index of the first occurrence of "World"
        int index2 = str.indexOf("World");
        System.out.println("Index of 'World': " + index2);  // Output will be: 7
        
        // Find the index of 'o' starting from index 5
        int index3 = str.indexOf('o', 5);
        System.out.println("Index of 'o' after index 5: " + index3);  // Output will be: 8
        
        // Find the index of "earth" (not found)
        int index4 = str.indexOf("earth");
        System.out.println("Index of 'earth': " + index4);  // Output will be: -1
    }
}
