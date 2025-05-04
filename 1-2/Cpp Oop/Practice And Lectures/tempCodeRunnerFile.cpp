MyClass ob1(10);        // OK: direct initialization using explicit constructor
    // //MyClass ob2 = 20;       // **Error**: copy initialization using `explicit` constructor (not allowed)
    // MyClass ob3("40");      // OK: implicit conversion from `const char*` to `Myclass`
    // MyClass ob4 = "60";  
