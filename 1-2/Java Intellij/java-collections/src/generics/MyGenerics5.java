package generics;

interface iStack<T extends Number> {
    void push(T e);
    T pop();
    T top();
    boolean isEmpty();
}

class MyStack<T extends Number> implements iStack<T> {//implements er por call kore okhane T extends likhle hobe na to
    T s[];
    int top;

    MyStack(T[] s) {
        this.s = s;
        top = -1;
    }

    public void push(T e) {
        s[++top] = e;
    }

    public T pop() {
        return s[top--];
    }

    public boolean isEmpty() {
        return top == -1;
    }

    public T top() {
        return s[top];
    }
}

public class MyGenerics5 {
    public static void main(String args[]) {//direct T er jaygay T[] na likheo direct T er jaygay array pass kora jabe....but kono kaj er thake na rki.....but T exnteds Number ba kichu dile to hobe na karon array object ta to r Number ke extend kore na
        String[] strings = new String[20];
//        iStack<String> mss = new MyStack<>(strings);
//        mss.push("A");
//        mss.push("B");
//        mss.push("C");
//        mss.push("D");
//        mss.push("E");
//        System.out.println(mss.top());
//        while (!mss.isEmpty()) {
//            System.out.println(mss.pop());
//        }
        Integer[] integers = new Integer[20];
        iStack<Integer> msi = new MyStack<>(integers);
        msi.push(50);
        msi.push(40);
        msi.push(30);
        msi.push(20);
        msi.push(10);
        System.out.println(msi.top());
        while (!msi.isEmpty()) {
            System.out.println(msi.pop());
        }
    }
}


