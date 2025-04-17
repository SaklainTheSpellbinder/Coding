// class Parent {
//     static void show() {
//         System.out.println("Parent");
//     }
// }

// class Child extends Parent {
//     static void show() {
//         System.out.println("Child");
//     }
// }
// // This is an example of static binding, not dynamic binding (overriding).
// // In Java, static methods are not overridden, they are hidden. 
// // The method that gets called is determined at compile time based on the reference type, not the object type.
// // So, even though we create an object of Child, the static method show() of Parent is called.
// // This is an example of static binding, not dynamic binding (overriding).
// // In this case, the output will be "Parent" because static methods are not polymorphic in Java.
// // The method that gets called is determined at compile time based on the reference type, not the object type.
// // So, even though we create an object of Child, the static method show() of Parent is called.
// // This is an example of static binding, not dynamic binding (overriding).



// public class overridentest {
//     public static void main(String[] args){
//         Parent p = new Child();
//         p.show();  // Output: Parent — static binding!
//     }
// }
