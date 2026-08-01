# Software Design Principles — Complete Explanation

This PDF moves from basic design ideas—encapsulation, interfaces, coupling—to the five **SOLID principles**. I will follow the PDF’s order and explain the diagrams and code using mostly Java-style examples. The slides are based mainly on _Dive Into Design Patterns_ and later reference Robert C. Martin’s work.

---

# 1. What is a software design principle?

A **design principle** is a general rule that helps us organize code so it is easier to:

- understand,
    
- test,
    
- change,
    
- extend,
    
- reuse,
    
- and debug.
    

A design principle is not the same as a design pattern.

A **design principle** says:

> “Try to design your classes this way.”

A **design pattern** says:

> “Here is a commonly used structure for solving a particular type of problem.”

For example:

- **Open/Closed Principle** is a principle.
    
- **Strategy Pattern** is one possible way to follow that principle.
    
- **Decorator Pattern** is another way.
    
- **Factory Method** can also support it.
    

The main problem these principles try to solve is this:

> A small change in one place should not force us to rewrite many unrelated parts of the program.

---

# 2. Encapsulation at method level

## 2.1 What encapsulation actually means

Many beginners understand encapsulation only as:

> “Make fields private and provide getters and setters.”

That is only one form of encapsulation.

A broader meaning is:

> Put a piece of knowledge or behaviour behind a clear boundary so the rest of the program does not need to know its internal details.

That boundary may be:

- a method,
    
- a class,
    
- an interface,
    
- a package,
    
- or an entire module.
    

---

## 2.2 Before refactoring

On page 2, `getOrderTotal()` does two different jobs:

1. It calculates the basic price of the order.
    
2. It determines the appropriate tax rate.
    

The method loops over line items, calculates `price × quantity`, and then checks whether the order is from the US or EU.

Equivalent Java-style code:

```java
double getOrderTotal(Order order) {
    double total = 0;

    for (LineItem item : order.getLineItems()) {
        total += item.getPrice() * item.getQuantity();
    }

    if (order.getCountry().equals("US")) {
        total += total * 0.07;
    } else if (order.getCountry().equals("EU")) {
        total += total * 0.20;
    }

    return total;
}
```

At first glance, the code looks acceptable. But there are two separate kinds of knowledge inside it:

- **Order-total knowledge**
    
- **Tax-rule knowledge**
    

Tax rules may become complicated:

```java
if (country.equals("US") && state.equals("California")) {
    ...
} else if (country.equals("US") && state.equals("Texas")) {
    ...
} else if (country.equals("Germany")) {
    ...
} else if (country.equals("France")) {
    ...
}
```

The total-calculation method gradually becomes polluted with tax-related conditions.

---

## 2.3 After method extraction

On page 3, the tax calculation is moved into a separate method named `getTaxRate()`.

```java
double getOrderTotal(Order order) {
    double total = 0;

    for (LineItem item : order.getLineItems()) {
        total += item.getPrice() * item.getQuantity();
    }

    total += total * getTaxRate(order.getCountry());

    return total;
}

double getTaxRate(String country) {
    if (country.equals("US")) {
        return 0.07;
    } else if (country.equals("EU")) {
        return 0.20;
    }

    return 0;
}
```

Now `getOrderTotal()` reads like a high-level recipe:

1. Calculate the subtotal.
    
2. Get the tax rate.
    
3. Add the tax.
    
4. Return the result.
    

The low-level tax decision is hidden inside another method.

## Intuitive analogy

Suppose you ask a cashier:

> “How much do I have to pay?”

The cashier does not explain every tax regulation. The cashier calls the tax system and gives you the final result.

Similarly:

```java
getTaxRate(country)
```

hides the details of tax selection.

---

## 2.4 Why method extraction is useful

### It improves readability

Compare:

```java
if (country.equals("US")) {
    ...
} else if (country.equals("EU")) {
    ...
}
```

with:

```java
double taxRate = getTaxRate(country);
```

The second version expresses the intention directly.

### It localizes change

When a tax rule changes, you know where to look:

```java
getTaxRate(...)
```

### It supports reuse

Another method may also need the tax rate:

```java
double calculateTaxOnly(Order order) {
    return order.getSubtotal() * getTaxRate(order.getCountry());
}
```

### It improves testing

You can test `getTaxRate()` separately:

```java
assertEquals(0.07, getTaxRate("US"));
assertEquals(0.20, getTaxRate("EU"));
assertEquals(0.00, getTaxRate("BD"));
```

---

## 2.5 Important limitation

Extracting a method does not completely solve the design problem.

If tax calculation becomes very large, then the class still contains two responsibilities:

- managing orders,
    
- understanding global tax systems.
    

At that point, method-level encapsulation is not enough. We should move to **class-level encapsulation**.

---

# 3. Encapsulation at class level

## 3.1 The original `Order` class

Page 4 shows an `Order` class containing:

- line items,
    
- country,
    
- state,
    
- city,
    
- many other fields,
    
- `getOrderTotal()`,
    
- `getTaxRate()`.
    

The class is responsible for both order processing and tax calculation.

Conceptually:

```java
class Order {
    private List<LineItem> lineItems;
    private String country;
    private String state;
    private String city;

    public double getOrderTotal() {
        // calculate items
        // calculate tax
    }

    public double getTaxRate() {
        // US tax
        // EU tax
        // Chinese tax
    }
}
```

This may become a **God class**: a class that knows or does too much.

---

## 3.2 Extracting `TaxCalculator`

Page 5 illustrates moving tax-related behaviour into a separate `TaxCalculator` class. Although the slide title again says “before,” the diagram itself represents the refactored separation.

```java
class TaxCalculator {

    public double getTaxRate(
            String country,
            String state,
            Product product) {

        if (country.equals("US")) {
            return getUSTax(state);
        }

        if (country.equals("EU")) {
            return getEUTax(country);
        }

        if (country.equals("China")) {
            return getChineseTax(product);
        }

        return 0;
    }

    private double getUSTax(String state) {
        return 0.07;
    }

    private double getEUTax(String country) {
        return 0.20;
    }

    private double getChineseTax(Product product) {
        return 0.10;
    }
}
```

The `Order` class delegates the tax-related work:

```java
class Order {
    private final List<LineItem> lineItems;
    private final TaxCalculator taxCalculator;

    public Order(
            List<LineItem> lineItems,
            TaxCalculator taxCalculator) {

        this.lineItems = lineItems;
        this.taxCalculator = taxCalculator;
    }

    public double getOrderTotal() {
        double total = 0;

        for (LineItem item : lineItems) {
            double subtotal =
                    item.getPrice() * item.getQuantity();

            double taxRate = taxCalculator.getTaxRate(
                    item.getCountry(),
                    item.getState(),
                    item.getProduct()
            );

            total += subtotal + subtotal * taxRate;
        }

        return total;
    }
}
```

---

## 3.3 What changed conceptually?

Before:

```text
Order
 ├── knows order information
 ├── calculates order total
 └── knows every tax rule
```

After:

```text
Order
 ├── knows order information
 ├── calculates order total
 └── asks TaxCalculator for tax information

TaxCalculator
 └── knows tax rules
```

`Order` no longer needs to understand how taxes are determined.

This is called **delegation**.

> Delegation means one object assigns part of its work to another object.

For example:

```java
taxCalculator.getTaxRate(...)
```

The `Order` delegates tax calculation to `TaxCalculator`.

---

## 3.4 Does this create more classes?

Yes.

Good design often produces more classes, but each class becomes smaller and more focused.

The goal is not:

> “Use as few classes as possible.”

The goal is:

> “Give every important responsibility a clear home.”

However, creating a new class for every three lines of code would be overengineering. Separation becomes useful when:

- the logic changes independently,
    
- the logic is complex,
    
- the logic is reused,
    
- or it has a clearly different responsibility.
    

---

# 4. Program to an interface, not an implementation

Page 6 compares a cat that can eat only a `Sausage` with a cat that can eat any `Food`. The slide also warns that introducing an abstraction may initially make the code more complicated, so it is most valuable where future extension is meaningful.

---

## 4.1 Depending on a concrete class

```java
class Cat {
    private int energy;

    public void eat(Sausage sausage) {
        energy += sausage.getNutrition();
    }
}
```

This cat accepts only:

```java
Sausage
```

It cannot directly eat:

- fish,
    
- chicken,
    
- cat food,
    
- meat,
    
- or milk.
    

Even though all of them may provide nutrition, the method is tied specifically to `Sausage`.

This is a concrete dependency.

---

## 4.2 Depending on an interface

```java
interface Food {
    int getNutrition();
}
```

```java
class Sausage implements Food {
    @Override
    public int getNutrition() {
        return 50;
    }

    public String getColor() {
        return "Red";
    }

    public LocalDate getExpirationDate() {
        return LocalDate.now().plusDays(5);
    }
}
```

```java
class Fish implements Food {
    @Override
    public int getNutrition() {
        return 35;
    }
}
```

Now:

```java
class Cat {
    private int energy;

    public void eat(Food food) {
        energy += food.getNutrition();
    }
}
```

Client code:

```java
Cat cat = new Cat();

Food sausage = new Sausage();
Food fish = new Fish();

cat.eat(sausage);
cat.eat(fish);
```

The cat depends only on the behaviour it needs:

```java
getNutrition()
```

It does not care whether the food is a sausage or fish.

---

## 4.3 Why the interface should contain only required behaviour

`Sausage` has methods such as:

```java
getNutrition()
getColor()
getExpirationDate()
```

But `Cat` only needs:

```java
getNutrition()
```

Therefore, the `Food` interface should expose only that required contract.

```java
interface Food {
    int getNutrition();
}
```

This is also related to the later **Interface Segregation Principle**.

---

## 4.4 Interface variable and concrete object

This is an important Java syntax:

```java
Food food = new Sausage();
```

The left side:

```java
Food food
```

is the abstraction used by the client.

The right side:

```java
new Sausage()
```

is the actual implementation.

You still need a concrete object at runtime. “Program to an interface” does not mean concrete classes disappear.

It means most business logic refers to the abstraction:

```java
Food
```

instead of being permanently tied to:

```java
Sausage
```

---

## 4.5 When not to introduce an interface

Suppose your program will definitely have only one tiny class:

```java
class TemperatureConverter {
    ...
}
```

Creating this immediately may be unnecessary:

```java
interface TemperatureConverterInterface {
    ...
}
```

An interface is particularly useful when:

- multiple implementations already exist,
    
- multiple implementations are likely,
    
- implementations need to be replaceable,
    
- the dependency is external,
    
- or testing requires a fake implementation.
    

The PDF explicitly notes that abstraction can initially make code more complicated, so it should usually represent a meaningful extension point.

---

# 5. Diamond problem in multiple inheritance

Page 7 shows the classic diamond-shaped inheritance structure:

```text
       SuperClass
       /        \
   ClassA      ClassB
       \        /
         ClassC
```

Both `ClassA` and `ClassB` define `doSomething()`.

Imagine:

```java
class SuperClass {
    void doSomething() {
        System.out.println("Super");
    }
}

class ClassA extends SuperClass {
    @Override
    void doSomething() {
        System.out.println("A");
    }
}

class ClassB extends SuperClass {
    @Override
    void doSomething() {
        System.out.println("B");
    }
}
```

Now suppose Java allowed this:

```java
class ClassC extends ClassA, ClassB {
}
```

Then:

```java
ClassC object = new ClassC();
object.doSomething();
```

Which version should execute?

```java
ClassA.doSomething()
```

or:

```java
ClassB.doSomething()
```

That ambiguity is the **diamond problem**.

---

## 5.1 Why Java does not allow multiple class inheritance

Java prevents this:

```java
class ClassC extends ClassA, ClassB
```

A Java class may extend only one class:

```java
class ClassC extends ClassA
```

This removes ambiguity over inherited state and implementation.

Java does allow multiple interfaces:

```java
class ClassC implements InterfaceA, InterfaceB
```

because interfaces traditionally describe contracts rather than carrying conflicting object state.

With default methods, Java may still detect a conflict and force the class to resolve it explicitly:

```java
interface A {
    default void show() {
        System.out.println("A");
    }
}

interface B {
    default void show() {
        System.out.println("B");
    }
}

class C implements A, B {
    @Override
    public void show() {
        A.super.show();
    }
}
```

Here, `C` explicitly chooses the implementation.

---

# 6. Tight coupling

## 6.1 Meaning of coupling

**Coupling** describes how strongly one class depends on another class.

### Tight coupling

Class A knows too many details about Class B.

A change in B may require changing A.

### Loose coupling

Class A depends on a stable abstraction or minimal contract.

B can be replaced with less effect on A.

---

## 6.2 Tightly coupled company example

On page 8, `Company` directly creates and uses:

- `Designer`,
    
- `Programmer`,
    
- `Tester`.
    

Equivalent Java:

```java
class Company {

    public void createSoftware() {
        Designer designer = new Designer();
        designer.designArchitecture();

        Programmer programmer = new Programmer();
        programmer.writeCode();

        Tester tester = new Tester();
        tester.testSoftware();
    }
}
```

The `Company` class knows:

- every employee class,
    
- how to construct each employee,
    
- which method each employee exposes,
    
- and the sequence in which they work.
    

The dependencies are concrete:

```java
Designer
Programmer
Tester
```

---

## 6.3 Problems with this design

### Adding a new worker requires editing `Company`

Suppose a security specialist is added:

```java
SecurityEngineer engineer = new SecurityEngineer();
engineer.auditSecurity();
```

`Company` must be modified.

### Different companies require different logic

A game development company may need:

- game designer,
    
- artist,
    
- programmer,
    
- tester.
    

An outsourcing company may need:

- programmer,
    
- tester,
    
- project manager.
    

The base `Company` cannot vary easily.

### Employee methods are inconsistent

```java
designArchitecture()
writeCode()
testSoftware()
```

The company needs to know the exact method of every employee type.

---

# 7. Removing tight coupling

Page 9 introduces a common `Employee` interface with `doWork()`. Different company subclasses provide different collections of employees. The base `Company` processes them uniformly.

```java
interface Employee {
    void doWork();
}
```

```java
class Designer implements Employee {
    @Override
    public void doWork() {
        System.out.println("Designing architecture");
    }
}

class Programmer implements Employee {
    @Override
    public void doWork() {
        System.out.println("Writing code");
    }
}

class Tester implements Employee {
    @Override
    public void doWork() {
        System.out.println("Testing software");
    }
}
```

Base company:

```java
abstract class Company {

    protected abstract List<Employee> getEmployees();

    public void createSoftware() {
        for (Employee employee : getEmployees()) {
            employee.doWork();
        }
    }
}
```

Specific company:

```java
class GameDevelopmentCompany extends Company {

    @Override
    protected List<Employee> getEmployees() {
        return List.of(
                new Designer(),
                new Programmer(),
                new Tester()
        );
    }
}
```

Another company:

```java
class OutsourcingCompany extends Company {

    @Override
    protected List<Employee> getEmployees() {
        return List.of(
                new Programmer(),
                new Tester()
        );
    }
}
```

---

## 7.1 Why this is less coupled

The base `Company` knows only:

```java
Employee
```

and:

```java
employee.doWork()
```

It does not care whether an employee is:

- a designer,
    
- a tester,
    
- a programmer,
    
- or a future security engineer.
    

New employee:

```java
class SecurityEngineer implements Employee {
    @Override
    public void doWork() {
        System.out.println("Auditing security");
    }
}
```

No change to the base `Company` algorithm is needed.

---

## 7.2 Important design-pattern connection

This structure resembles the **Factory Method pattern**.

The base class defines the general algorithm:

```java
createSoftware()
```

Subclasses decide which employees are created:

```java
getEmployees()
```

The method acting as the creation extension point is:

```java
getEmployees()
```

---

# 8. SOLID overview

SOLID represents five design principles:

- **S** — Single Responsibility Principle
    
- **O** — Open/Closed Principle
    
- **L** — Liskov Substitution Principle
    
- **I** — Interface Segregation Principle
    
- **D** — Dependency Inversion Principle
    

The PDF describes their goal as making designs more understandable, flexible, and maintainable, while also warning that applying them unnecessarily can make a program more complicated than required.

This warning matters:

> SOLID is not a command to create maximum abstraction.

SOLID is a tool for managing change.

A five-class abstraction around a program that prints `"Hello"` is not good design.

---

# 9. S — Single Responsibility Principle

## 9.1 Definition

> A class should have one reason to change.

The PDF also describes this as giving every class one responsibility and keeping that responsibility encapsulated.

This definition does **not** mean:

> A class may have only one method.

A class may have many methods if they all belong to one coherent responsibility.

---

## 9.2 What is a “reason to change”?

A reason to change usually means a separate source of requirements.

Consider:

```java
class Employee {
    private String name;

    public String getName() {
        return name;
    }

    public void printTimeSheetReport() {
        // format and print report
    }
}
```

This class may change because:

1. Employee information changes.
    
2. Timesheet report formatting changes.
    
3. The printing mechanism changes.
    
4. The report is exported to PDF instead.
    
5. The company changes its report layout.
    

Those are different reasons.

The slide separates report generation into `TimeSheetReport`.

```java
class Employee {
    private final String name;

    public Employee(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }
}
```

```java
class TimeSheetReport {

    public void print(Employee employee) {
        System.out.println(
                "Timesheet report for " + employee.getName()
        );
    }
}
```

Client:

```java
Employee employee = new Employee("Rahim");

TimeSheetReport report = new TimeSheetReport();
report.print(employee);
```

---

## 9.3 What is cohesion?

The PDF associates SRP with **high cohesion** and **low coupling**.

**Cohesion** means:

> How closely related the responsibilities inside one class are.

High cohesion:

```java
class ShoppingCart {
    addItem()
    removeItem()
    getItems()
    calculateSubtotal()
}
```

All methods are closely related to the cart.

Low cohesion:

```java
class ShoppingCart {
    addItem()
    sendEmail()
    connectToDatabase()
    resizeImage()
    calculateTax()
}
```

These behaviours do not belong together.

---

## 9.4 Low coupling versus high cohesion

They are different ideas.

### High cohesion

The things **inside one class** belong together.

### Low coupling

The class has minimal dependency on **other classes**.

A good design normally aims for:

```text
High cohesion inside classes
Low coupling between classes
```

---

## 9.5 Another SRP example

Bad design:

```java
class Invoice {

    public double calculateTotal() {
        return 5000;
    }

    public void saveToDatabase() {
        System.out.println("Saving invoice");
    }

    public void printInvoice() {
        System.out.println("Printing invoice");
    }

    public void emailInvoice() {
        System.out.println("Emailing invoice");
    }
}
```

Reasons to change:

- calculation rules change,
    
- database technology changes,
    
- print format changes,
    
- email system changes.
    

Refactored design:

```java
class Invoice {
    public double calculateTotal() {
        return 5000;
    }
}

class InvoiceRepository {
    public void save(Invoice invoice) {
        System.out.println("Saving invoice");
    }
}

class InvoicePrinter {
    public void print(Invoice invoice) {
        System.out.println("Printing invoice");
    }
}

class InvoiceEmailService {
    public void send(Invoice invoice) {
        System.out.println("Emailing invoice");
    }
}
```

---

## 9.6 Common SRP misconception

This is not automatically wrong:

```java
class BankAccount {
    deposit()
    withdraw()
    getBalance()
    transfer()
}
```

It contains several methods, but they all support one responsibility:

> Managing a bank account’s financial state and operations.

Do not split every method into a separate class.

---

# 10. O — Open/Closed Principle

## 10.1 Definition

> Software entities should be open for extension but closed for modification.

Page 12 shows an `Order` class whose shipping calculation contains conditions for ground and air shipping. Adding another shipping method would require editing the class.

“Open for extension” means:

> We can add new behaviour.

“Closed for modification” means:

> We should not need to repeatedly alter stable existing code to add that behaviour.

It does not mean existing code can literally never be edited.

Bug fixes and legitimate internal improvements still require modification.

---

## 10.2 OCP violation: conditional shipping logic

```java
class Order {
    private String shippingType;

    public double getShippingCost() {
        if (shippingType.equals("GROUND")) {
            if (getTotal() > 100) {
                return 0;
            }

            return Math.max(
                    10,
                    getTotalWeight() * 1.5
            );
        }

        if (shippingType.equals("AIR")) {
            return Math.max(
                    20,
                    getTotalWeight() * 3
            );
        }

        throw new IllegalArgumentException(
                "Unknown shipping type"
        );
    }
}
```

Now add:

- Sea shipping
    
- Drone shipping
    
- Express shipping
    
- International shipping
    

The method becomes:

```java
if (GROUND) ...
else if (AIR) ...
else if (SEA) ...
else if (DRONE) ...
else if (EXPRESS) ...
```

Each new feature modifies the same tested method.

---

## 10.3 Refactoring with a `Shipping` interface

Page 13 separates shipping algorithms behind a common interface, which is essentially the Strategy pattern.

```java
interface Shipping {
    double getCost(Order order);
    LocalDate getDate(Order order);
}
```

Ground shipping:

```java
class GroundShipping implements Shipping {

    @Override
    public double getCost(Order order) {
        if (order.getTotal() > 100) {
            return 0;
        }

        return Math.max(
                10,
                order.getTotalWeight() * 1.5
        );
    }

    @Override
    public LocalDate getDate(Order order) {
        return LocalDate.now().plusDays(5);
    }
}
```

Air shipping:

```java
class AirShipping implements Shipping {

    @Override
    public double getCost(Order order) {
        return Math.max(
                20,
                order.getTotalWeight() * 3
        );
    }

    @Override
    public LocalDate getDate(Order order) {
        return LocalDate.now().plusDays(2);
    }
}
```

Order:

```java
class Order {
    private Shipping shipping;

    public Order(Shipping shipping) {
        this.shipping = shipping;
    }

    public double getShippingCost() {
        return shipping.getCost(this);
    }

    public LocalDate getShippingDate() {
        return shipping.getDate(this);
    }
}
```

Client:

```java
Order order =
        new Order(new GroundShipping());

System.out.println(order.getShippingCost());
```

---

## 10.4 Adding a new shipping method

```java
class DroneShipping implements Shipping {

    @Override
    public double getCost(Order order) {
        return 50 + order.getTotalWeight() * 5;
    }

    @Override
    public LocalDate getDate(Order order) {
        return LocalDate.now().plusDays(1);
    }
}
```

Now:

```java
Order order =
        new Order(new DroneShipping());
```

We added a new class without changing:

```java
Order
GroundShipping
AirShipping
```

That is the key OCP idea.

---

# 11. OCP area-calculator example

Pages 14–17 develop OCP step by step.

---

## 11.1 Initial design: rectangles only

Page 14 shows:

```csharp
Area(Rectangle[] shapes)
```

The calculator directly accesses every rectangle’s width and height.

Java equivalent:

```java
class Rectangle {
    double width;
    double height;
}
```

```java
class AreaCalculator {

    public double area(Rectangle[] shapes) {
        double area = 0;

        for (Rectangle shape : shapes) {
            area += shape.width * shape.height;
        }

        return area;
    }
}
```

This works only for rectangles.

---

## 11.2 Adding circles badly

Page 15 changes the parameter to `object[]` and uses type checking.

Java equivalent:

```java
public double area(Object[] shapes) {
    double area = 0;

    for (Object shape : shapes) {
        if (shape instanceof Rectangle rectangle) {
            area += rectangle.width * rectangle.height;
        } else {
            Circle circle = (Circle) shape;
            area += Math.PI
                    * circle.radius
                    * circle.radius;
        }
    }

    return area;
}
```

Problems:

### Unsafe type assumption

The `else` branch assumes every non-rectangle is a circle.

What happens if a `String` is passed?

```java
Object[] shapes = {
        new Rectangle(),
        "not a shape"
};
```

The cast fails.

### OCP violation

Adding a triangle requires changing the calculator:

```java
else if (shape instanceof Triangle) {
    ...
}
```

Adding an ellipse requires another condition.

The calculator grows whenever a new shape is introduced.

---

## 11.3 Move area behaviour into shapes

Page 16 creates an abstract `Shape` class with an abstract `Area()` method. Rectangle and Circle calculate their own areas.

Java version:

```java
interface Shape {
    double area();
}
```

```java
class Rectangle implements Shape {
    private final double width;
    private final double height;

    public Rectangle(double width, double height) {
        this.width = width;
        this.height = height;
    }

    @Override
    public double area() {
        return width * height;
    }
}
```

```java
class Circle implements Shape {
    private final double radius;

    public Circle(double radius) {
        this.radius = radius;
    }

    @Override
    public double area() {
        return Math.PI * radius * radius;
    }
}
```

Calculator:

```java
class AreaCalculator {

    public double area(Shape[] shapes) {
        double total = 0;

        for (Shape shape : shapes) {
            total += shape.area();
        }

        return total;
    }
}
```

The calculator asks every shape:

```java
shape.area()
```

It does not need to know the formula.

---

## 11.4 Adding an ellipse

Page 17 shows that `Ellipse` can be added without modifying `AreaCalculator`.

```java
class Ellipse implements Shape {
    private final double majorRadius;
    private final double minorRadius;

    public Ellipse(
            double majorRadius,
            double minorRadius) {

        this.majorRadius = majorRadius;
        this.minorRadius = minorRadius;
    }

    @Override
    public double area() {
        return Math.PI
                * majorRadius
                * minorRadius;
    }
}
```

Client:

```java
Shape[] shapes = {
        new Rectangle(4, 5),
        new Circle(3),
        new Ellipse(4, 2)
};

AreaCalculator calculator =
        new AreaCalculator();

System.out.println(calculator.area(shapes));
```

`AreaCalculator` remains unchanged.

---

## 11.5 Why polymorphism solves the problem

The expression:

```java
shape.area()
```

executes different code depending on the actual object.

For a rectangle:

```java
Rectangle.area()
```

For a circle:

```java
Circle.area()
```

For an ellipse:

```java
Ellipse.area()
```

This is **runtime polymorphism**.

It replaces type-checking logic such as:

```java
if (shape instanceof Rectangle)
else if (shape instanceof Circle)
else if (shape instanceof Ellipse)
```

with dynamic method dispatch:

```java
shape.area()
```

---

# 12. L — Liskov Substitution Principle

## 12.1 Definition

> A subclass should be usable wherever its parent class is expected, without breaking the correctness of the program.

The PDF describes subclasses as needing to remain behaviourally compatible with their superclass so client code can substitute them safely.

This is more than syntactic compatibility.

A subclass may compile correctly but still violate expectations.

---

## 12.2 Basic substitution test

Suppose client code expects:

```java
void process(Document document) {
    document.open();
    document.save();
}
```

For every subtype of `Document`, both operations should behave according to the `Document` contract.

If a subclass cannot save and throws an exception whenever `save()` is called, it is not a valid replacement for the original writable `Document`.

---

# 13. LSP violation: read-only document

Page 19 shows this hierarchy:

```text
Document
 ├── open()
 └── save()

ReadOnlyDocument extends Document
 └── save() throws exception
```

The project must check whether a document is read-only before saving it.

Equivalent Java:

```java
class Document {

    public void open() {
        System.out.println("Opening document");
    }

    public void save() {
        System.out.println("Saving document");
    }
}
```

```java
class ReadOnlyDocument extends Document {

    @Override
    public void save() {
        throw new UnsupportedOperationException(
                "Cannot save a read-only document"
        );
    }
}
```

Client:

```java
List<Document> documents = List.of(
        new Document(),
        new ReadOnlyDocument()
);

for (Document document : documents) {
    document.save();
}
```

The second call fails.

---

## 13.1 Why this violates LSP

The parent contract implies:

> A `Document` can be saved.

But the subtype changes the meaning to:

> This document cannot be saved.

Therefore:

```java
ReadOnlyDocument
```

is not behaviourally substitutable for:

```java
Document
```

The client is forced to know the subtype:

```java
if (!(document instanceof ReadOnlyDocument)) {
    document.save();
}
```

This `instanceof` check is evidence that the inheritance hierarchy does not model the capabilities properly.

---

# 14. Correcting the document hierarchy

Page 20 moves `save()` out of the general document class. All documents can open, but only writable documents can save.

```java
class Document {

    public void open() {
        System.out.println("Opening document");
    }
}
```

```java
class WritableDocument extends Document {

    public void save() {
        System.out.println("Saving document");
    }
}
```

Now the project can maintain two collections:

```java
class Project {
    private final List<Document> allDocuments;
    private final List<WritableDocument> writableDocuments;

    public Project(
            List<Document> allDocuments,
            List<WritableDocument> writableDocuments) {

        this.allDocuments = allDocuments;
        this.writableDocuments = writableDocuments;
    }

    public void openAll() {
        for (Document document : allDocuments) {
            document.open();
        }
    }

    public void saveAll() {
        for (WritableDocument document
                : writableDocuments) {

            document.save();
        }
    }
}
```

No subtype check is required.

Every `WritableDocument` is a valid `Document`.

But not every `Document` promises to be writable.

---

## 14.1 The capability-oriented alternative

Interfaces can represent capabilities:

```java
interface Openable {
    void open();
}

interface Savable {
    void save();
}
```

Read-only document:

```java
class ReadOnlyDocument implements Openable {
    @Override
    public void open() {
        System.out.println("Opening read-only document");
    }
}
```

Writable document:

```java
class EditableDocument
        implements Openable, Savable {

    @Override
    public void open() {
        System.out.println("Opening document");
    }

    @Override
    public void save() {
        System.out.println("Saving document");
    }
}
```

A method requiring only opening accepts:

```java
Openable
```

A method requiring saving accepts:

```java
Savable
```

This design also relates strongly to ISP.

---

# 15. Practical LSP rules

To preserve substitutability, a subtype should not surprise clients.

## 15.1 Do not strengthen preconditions

Parent:

```java
class PaymentProcessor {
    void pay(double amount) {
        // amount must be positive
    }
}
```

Bad subtype:

```java
class PremiumPaymentProcessor
        extends PaymentProcessor {

    @Override
    void pay(double amount) {
        if (amount < 10_000) {
            throw new IllegalArgumentException();
        }
    }
}
```

The parent accepted any positive amount.

The subtype unexpectedly accepts only amounts above 10,000.

That is a stronger precondition.

---

## 15.2 Do not weaken postconditions

Parent promises:

```java
withdraw(amount)
```

will either deduct the amount or clearly report failure.

A subtype that silently does nothing violates that expected result.

---

## 15.3 Preserve meaningful invariants

If a parent object promises:

```text
balance can never be negative
```

a subtype should not permit a negative balance unless the original abstraction explicitly allows it.

---

## 15.4 Avoid unsupported inherited methods

A common sign of an LSP problem is:

```java
@Override
public void someMethod() {
    throw new UnsupportedOperationException();
}
```

It is not always wrong, but it often means the subtype should not inherit that method in the first place.

---

# 16. I — Interface Segregation Principle

## 16.1 Definition

> Clients should not be forced to depend on methods they do not use.

The PDF recommends narrow interfaces so implementing classes do not have to provide irrelevant behaviour.

A large interface containing unrelated operations is sometimes called a:

- fat interface,
    
- bloated interface,
    
- polluted interface.
    

---

# 17. ISP violation: cloud provider

Page 21 shows one large interface:

```text
CloudProvider
 ├── storeFile()
 ├── getFile()
 ├── createServer()
 ├── listServers()
 └── getCDNAddress()
```

Amazon supports all these capabilities, but Dropbox supports mainly file storage. Dropbox is forced to leave server and CDN operations unimplemented.

Java version:

```java
interface CloudProvider {
    void storeFile(String name);
    byte[] getFile(String name);

    void createServer(String region);
    List<String> listServers(String region);

    String getCDNAddress();
}
```

Dropbox:

```java
class Dropbox implements CloudProvider {

    @Override
    public void storeFile(String name) {
        System.out.println("Storing file");
    }

    @Override
    public byte[] getFile(String name) {
        return new byte[0];
    }

    @Override
    public void createServer(String region) {
        throw new UnsupportedOperationException();
    }

    @Override
    public List<String> listServers(String region) {
        throw new UnsupportedOperationException();
    }

    @Override
    public String getCDNAddress() {
        throw new UnsupportedOperationException();
    }
}
```

This is poor because the interface claims:

> Every `CloudProvider` supports all these operations.

But that statement is false.

---

# 18. Applying ISP

Page 22 divides the large interface into three focused interfaces.

```java
interface CloudStorageProvider {
    void storeFile(String name);
    byte[] getFile(String name);
}
```

```java
interface CloudHostingProvider {
    void createServer(String region);
    List<String> listServers(String region);
}
```

```java
interface CDNProvider {
    String getCDNAddress();
}
```

Amazon supports all three:

```java
class AmazonCloud
        implements CloudStorageProvider,
                   CloudHostingProvider,
                   CDNProvider {

    @Override
    public void storeFile(String name) {
        System.out.println("Amazon stores " + name);
    }

    @Override
    public byte[] getFile(String name) {
        return new byte[0];
    }

    @Override
    public void createServer(String region) {
        System.out.println(
                "Creating server in " + region
        );
    }

    @Override
    public List<String> listServers(String region) {
        return List.of("server-1");
    }

    @Override
    public String getCDNAddress() {
        return "cdn.amazon.example";
    }
}
```

Dropbox implements only storage:

```java
class Dropbox
        implements CloudStorageProvider {

    @Override
    public void storeFile(String name) {
        System.out.println("Dropbox stores " + name);
    }

    @Override
    public byte[] getFile(String name) {
        return new byte[0];
    }
}
```

No meaningless methods. No fake implementations.

---

## 18.1 ISP is about clients too

Suppose this service only uploads files:

```java
class BackupService {
    private final CloudStorageProvider storage;

    public BackupService(
            CloudStorageProvider storage) {

        this.storage = storage;
    }

    public void backup(String fileName) {
        storage.storeFile(fileName);
    }
}
```

It depends only on:

```java
CloudStorageProvider
```

It does not depend on irrelevant server-hosting or CDN operations.

This reduces coupling.

---

## 18.2 ISP does not mean one-method interfaces everywhere

This is not the objective:

```java
interface FileStorer {
    void storeFile();
}

interface FileGetter {
    void getFile();
}
```

Sometimes storing and retrieving files naturally belong together.

The principle says interfaces should be **cohesive**, not necessarily microscopic.

---

# 19. D — Dependency Inversion Principle

## 19.1 Definition

The PDF gives two central statements:

1. High-level classes should not depend directly on low-level classes; both should depend on abstractions.
    
2. Abstractions should not depend on implementation details; details should depend on abstractions.
    

Simplified:

> Depend on contracts, not fixed concrete implementations.

---

## 19.2 High-level and low-level modules

### High-level module

Contains business policy or major application decisions.

Examples:

- `OrderService`
    
- `PaymentService`
    
- `BudgetReport`
    
- `NotificationService`
    

### Low-level module

Handles technical details.

Examples:

- MySQL database access,
    
- file-system storage,
    
- email sending,
    
- printer interaction,
    
- third-party API calls.
    

High-level logic should not be permanently tied to one technical detail.

---

# 20. DIP database example

## 20.1 Before DIP

Page 23 shows a high-level `BudgetReport` directly depending on `MySQLDatabase`.

```java
class MySQLDatabase {

    public void insert(String data) {
        System.out.println("Insert into MySQL");
    }

    public void update(String data) {
        System.out.println("Update MySQL");
    }

    public void delete(String id) {
        System.out.println("Delete from MySQL");
    }
}
```

```java
class BudgetReport {
    private final MySQLDatabase database;

    public BudgetReport() {
        this.database = new MySQLDatabase();
    }

    public void save() {
        database.insert("budget data");
    }
}
```

The business-level `BudgetReport` is tied to MySQL.

To move to MongoDB, we must modify `BudgetReport`.

---

## 20.2 After DIP

Page 24 inserts a `Database` abstraction between `BudgetReport` and concrete database classes. MySQL and MongoDB depend on that contract.

```java
interface Database {
    void insert(String data);
    void update(String data);
    void delete(String id);
}
```

```java
class MySQLDatabase implements Database {
    @Override
    public void insert(String data) {
        System.out.println("Insert into MySQL");
    }

    @Override
    public void update(String data) {
        System.out.println("Update MySQL");
    }

    @Override
    public void delete(String id) {
        System.out.println("Delete from MySQL");
    }
}
```

```java
class MongoDatabase implements Database {
    @Override
    public void insert(String data) {
        System.out.println("Insert into MongoDB");
    }

    @Override
    public void update(String data) {
        System.out.println("Update MongoDB");
    }

    @Override
    public void delete(String id) {
        System.out.println("Delete from MongoDB");
    }
}
```

High-level class:

```java
class BudgetReport {
    private final Database database;

    public BudgetReport(Database database) {
        this.database = database;
    }

    public void save() {
        database.insert("budget data");
    }
}
```

Client chooses the implementation:

```java
Database database =
        new MySQLDatabase();

BudgetReport report =
        new BudgetReport(database);

report.save();
```

Or:

```java
Database database =
        new MongoDatabase();

BudgetReport report =
        new BudgetReport(database);
```

`BudgetReport` is unchanged.

---

# 21. Why the dependency is called “inverted”

Traditionally, the direction is:

```text
High-level business class
          ↓ depends on
Low-level technical class
```

Example:

```text
BudgetReport → MySQLDatabase
```

After inversion:

```text
BudgetReport → Database interface
MySQLDatabase → Database interface
MongoDatabase → Database interface
```

The detailed classes now conform to an abstraction required by the high-level business logic.

Page 25 visualizes a high-level module depending on abstract interfaces, while lower-level implementation modules implement those interfaces.

The dependency has not disappeared. It has been redirected toward a stable abstraction.

---

# 22. How DIP works step by step

The PDF explains the process as follows:

1. The high-level module defines or depends on an abstract interface representing the services it needs.
    
2. Low-level modules implement that interface.
    
3. At runtime, a low-level implementation performs the actual work.
    
4. Both sides depend on the abstraction rather than the high-level class depending directly on a concrete detail.
    

For example:

```text
BudgetReport needs:
    save budget data

Therefore define:
    Database.save(...)

Implementations:
    MySQLDatabase
    MongoDatabase
    FileDatabase
```

The abstraction should be shaped around the consumer’s needs, not merely copy every method from an existing vendor class.

---

# 23. Dependency Injection versus Dependency Inversion

These terms are related but different.

## Dependency Inversion Principle

A design rule:

```text
Depend on abstractions rather than concrete details.
```

## Dependency Injection

A technique for providing dependencies from outside.

Example:

```java
public BudgetReport(Database database) {
    this.database = database;
}
```

This is **constructor injection**.

The class does not create its database:

```java
new MySQLDatabase()
```

Instead, someone else supplies it.

Dependency injection is one common mechanism for implementing DIP.

---

# 24. DIP switch example — without DIP

Pages 27 and 28 show an electric switch directly coupled to a `LightBulb`.

Light bulb:

```java
class LightBulb {

    public void turnOn() {
        System.out.println(
                "LightBulb: Bulb turned on"
        );
    }

    public void turnOff() {
        System.out.println(
                "LightBulb: Bulb turned off"
        );
    }
}
```

Switch:

```java
class ElectricPowerSwitch {
    private final LightBulb lightBulb;
    private boolean on;

    public ElectricPowerSwitch(
            LightBulb lightBulb) {

        this.lightBulb = lightBulb;
        this.on = false;
    }

    public boolean isOn() {
        return on;
    }

    public void press() {
        if (isOn()) {
            lightBulb.turnOff();
            on = false;
        } else {
            lightBulb.turnOn();
            on = true;
        }
    }
}
```

The important dependency is:

```java
private final LightBulb lightBulb;
```

The switch works only with a light bulb.

It cannot control:

- a fan,
    
- a heater,
    
- a television,
    
- an air conditioner,
    
- or a motor.
    

Even though all of them could support on/off operations.

---

# 25. DIP switch example — abstractions

Page 29 introduces two interfaces.

```java
interface Switch {
    boolean isOn();
    void press();
}
```

```java
interface Switchable {
    void turnOn();
    void turnOff();
}
```

These interfaces represent different roles.

### `Switch`

Represents the controlling device.

```java
press()
isOn()
```

### `Switchable`

Represents anything that can be turned on and off.

```java
turnOn()
turnOff()
```

This is a useful separation.

---

# 26. Refactored `ElectricPowerSwitch`

Page 30 changes the field type from `LightBulb` to `Switchable`.

```java
class ElectricPowerSwitch implements Switch {
    private final Switchable client;
    private boolean on;

    public ElectricPowerSwitch(
            Switchable client) {

        this.client = client;
        this.on = false;
    }

    @Override
    public boolean isOn() {
        return on;
    }

    @Override
    public void press() {
        if (isOn()) {
            client.turnOff();
            on = false;
        } else {
            client.turnOn();
            on = true;
        }
    }
}
```

The switch does not know what `client` really is.

It only knows the contract:

```java
turnOn()
turnOff()
```

---

# 27. Multiple switchable devices

Page 31 shows both `Fan` and `LightBulb` implementing `Switchable`.

```java
class Fan implements Switchable {

    @Override
    public void turnOn() {
        System.out.println("Fan turned on");
    }

    @Override
    public void turnOff() {
        System.out.println("Fan turned off");
    }
}
```

```java
class LightBulb implements Switchable {

    @Override
    public void turnOn() {
        System.out.println("Bulb turned on");
    }

    @Override
    public void turnOff() {
        System.out.println("Bulb turned off");
    }
}
```

Client:

```java
public class Main {
    public static void main(String[] args) {
        Switchable bulb = new LightBulb();
        Switch bulbSwitch =
                new ElectricPowerSwitch(bulb);

        bulbSwitch.press();
        bulbSwitch.press();

        Switchable fan = new Fan();
        Switch fanSwitch =
                new ElectricPowerSwitch(fan);

        fanSwitch.press();
        fanSwitch.press();
    }
}
```

Output:

```text
Bulb turned on
Bulb turned off
Fan turned on
Fan turned off
```

The same switch class controls both devices.

---

# 28. Exactly where DIP appears in the switch example

Without DIP:

```java
class ElectricPowerSwitch {
    private LightBulb lightBulb;
}
```

High-level switch logic depends on a concrete low-level device:

```text
ElectricPowerSwitch → LightBulb
```

With DIP:

```java
class ElectricPowerSwitch {
    private Switchable client;
}
```

Both concrete devices implement the abstraction:

```text
ElectricPowerSwitch → Switchable
LightBulb          → Switchable
Fan                → Switchable
```

That is dependency inversion.

---

# 29. Relationship among the SOLID principles

The five principles overlap.

## SRP

Separates different responsibilities.

```text
Employee information
Timesheet reporting
```

become separate classes.

## OCP

Allows new behaviour by adding implementations rather than modifying stable logic.

```text
Shipping
 ├── GroundShipping
 ├── AirShipping
 └── DroneShipping
```

## LSP

Ensures implementations can safely stand in for their base type.

```text
Every Shipping must honour the Shipping contract.
```

## ISP

Keeps contracts narrow and relevant.

```text
CloudStorageProvider
CloudHostingProvider
CDNProvider
```

instead of one huge `CloudProvider`.

## DIP

Makes high-level code depend on those abstractions.

```text
Order → Shipping
BudgetReport → Database
Switch → Switchable
```

---

# 30. How SOLID works together in one example

Suppose we design a notification system.

Bad design:

```java
class OrderService {

    public void completeOrder(Order order) {
        // save order

        EmailSender sender = new EmailSender();
        sender.sendEmail(order.getCustomerEmail());

        // create invoice PDF
        // write log file
    }
}
```

Problems:

- order processing,
    
- email,
    
- PDF generation,
    
- logging are mixed,
    
- `OrderService` directly depends on `EmailSender`,
    
- adding SMS requires editing `OrderService`.
    

A stronger design:

```java
interface NotificationService {
    void notifyCustomer(Order order);
}
```

```java
class EmailNotification
        implements NotificationService {

    @Override
    public void notifyCustomer(Order order) {
        System.out.println(
                "Emailing " + order.getCustomerEmail()
        );
    }
}
```

```java
class SMSNotification
        implements NotificationService {

    @Override
    public void notifyCustomer(Order order) {
        System.out.println(
                "Sending SMS to "
                        + order.getCustomerPhone()
        );
    }
}
```

```java
class OrderService {
    private final NotificationService notification;

    public OrderService(
            NotificationService notification) {

        this.notification = notification;
    }

    public void completeOrder(Order order) {
        System.out.println("Completing order");
        notification.notifyCustomer(order);
    }
}
```

How SOLID appears:

- **SRP:** notification is separated from order processing.
    
- **OCP:** add WhatsApp notification through a new class.
    
- **LSP:** every notification implementation must work wherever `NotificationService` is expected.
    
- **ISP:** the interface exposes only the notification operation needed by the client.
    
- **DIP:** `OrderService` depends on `NotificationService`, not `EmailNotification`.
    

---

# 31. Important distinctions for exams

## Encapsulation versus abstraction

### Encapsulation

Hides internal data or implementation details.

```java
private double balance;
```

and:

```java
public void withdraw(double amount) {
    // validation hidden here
}
```

### Abstraction

Exposes the essential behaviour while hiding unnecessary details.

```java
interface PaymentMethod {
    void pay(double amount);
}
```

A caller knows how to request payment, not how each payment system processes it.

---

## Inheritance versus composition

### Inheritance

```java
class Dog extends Animal
```

Means:

```text
Dog is an Animal
```

### Composition

```java
class Car {
    private Engine engine;
}
```

Means:

```text
Car has an Engine
```

Many SOLID-friendly designs prefer composition for varying behaviour:

```java
class Order {
    private Shipping shipping;
}
```

instead of creating many subclasses such as:

```java
GroundOrder
AirOrder
DroneOrder
InternationalOrder
```

---

## Interface versus abstract class

### Interface

Best for defining a capability or contract:

```java
interface Switchable {
    void turnOn();
    void turnOff();
}
```

A class may implement multiple interfaces.

### Abstract class

Useful when related subclasses share:

- fields,
    
- constructor logic,
    
- common method implementations,
    
- or a strong “is-a” relationship.
    

```java
abstract class Shape {
    public abstract double area();
}
```

Either can support OCP, LSP, and DIP when used properly.

---

# 32. Fast diagnosis guide

When reading a code-design question, look for these symptoms.

|Symptom|Likely principle|
|---|---|
|One class performs many unrelated jobs|SRP|
|Every new type requires another `if` or `switch` branch|OCP|
|A subclass throws “unsupported operation” for inherited methods|LSP|
|Implementing classes contain empty or meaningless interface methods|ISP|
|Business logic directly constructs database, email, or device classes|DIP|
|One method contains a large independent block of logic|Method-level encapsulation|
|One class contains a whole separate subsystem’s rules|Class-level encapsulation|
|A class knows exact methods of many concrete classes|Tight coupling|

---

# 33. One-sentence memory rules

### Encapsulation

> Hide details behind meaningful methods and classes.

### Interface over implementation

> Refer to the capability you need, not one specific object type.

### Low coupling

> A class should know as little as reasonably possible about other classes.

### High cohesion

> Everything inside a class should contribute to one coherent purpose.

### SRP

> One class, one primary reason to change.

### OCP

> Add new behaviour through new implementations rather than repeated edits to stable code.

### LSP

> Every subtype must behave like a valid version of its parent type.

### ISP

> Do not force classes or clients to depend on operations they do not need.

### DIP

> High-level policy and low-level details should meet through abstractions.

---

# 34. Final conceptual picture

The entire PDF is teaching one broad lesson:

```text
Bad design:
Business logic
   ↓ knows and controls
Many concrete implementation details
```

```text
Better design:
Business logic
   ↓ depends on
Small, meaningful abstractions
   ↑ implemented by
Replaceable concrete classes
```

That gives you code where:

- tax calculation can change without rewriting order logic,
    
- new employee types can be added without changing the company workflow,
    
- new shapes can calculate their own area,
    
- read-only documents are not forced to pretend they can save,
    
- Dropbox is not forced to implement server hosting,
    
- a report can switch from MySQL to MongoDB,
    
- and one electric switch can control either a bulb or a fan.
    

The PDF ends by referencing Robert C. Martin’s _Agile Software Development, Principles, Patterns, and Practices_.