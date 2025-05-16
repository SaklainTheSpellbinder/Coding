class hehe {
    static {
        System.out.println("Class loaded");
    }
    static void greet() {
        System.out.println("Hello");
    }
}

public class Test{
    public static void main(String[] args) {
        hehe.greet();//static dekhe emon daaka jay....but non static func hole daaka jeto na
    }
}
