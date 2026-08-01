# Creational Patterns: UML, Intuition, Java, Detection, and Memory Guide

The PDF covers four creational patterns:

1. Factory Method
    
2. Abstract Factory
    
3. Builder
    
4. Singleton
    

All four are concerned with **object creation**, but they solve different creation problems.

The central question is:

> **What is difficult about creating the object?**

- Choosing **which subtype** to create → Factory Method
    
- Creating a **matching family of objects** → Abstract Factory
    
- Constructing **one complicated object step by step** → Builder
    
- Ensuring **only one object exists** → Singleton
    

---

# Part 1: The UML You Need for These Patterns

You do not need all of UML. You mainly need class boxes and six relationships.

The PDF introduces generalization, dependency, aggregation, and composition.

---

## 1. UML class box

A class is usually drawn as a rectangle divided into three sections:

```text
+----------------------------+
|          ClassName         |
+----------------------------+
| - field1 : Type            |
| # field2 : Type            |
+----------------------------+
| + method() : ReturnType    |
| - helper() : void          |
+----------------------------+
```

The sections mean:

1. Class name
    
2. Fields
    
3. Methods
    

Example:

```text
+----------------------------+
|          Computer          |
+----------------------------+
| - cpu : String             |
| - ram : int                |
+----------------------------+
| + getCpu() : String        |
| + getRam() : int           |
+----------------------------+
```

Equivalent Java:

```java
class Computer {
    private String cpu;
    private int ram;

    public String getCpu() {
        return cpu;
    }

    public int getRam() {
        return ram;
    }
}
```

---

## 2. Visibility symbols

|UML symbol|Java meaning|
|---|---|
|`+`|`public`|
|`-`|`private`|
|`#`|`protected`|
|`~`|package-private/default|

Example:

```text
- instance : Singleton
+ getInstance() : Singleton
```

means:

```java
private static Singleton instance;

public static Singleton getInstance() {
    ...
}
```

---

## 3. Underlined members mean `static`

In the Singleton UML on page 37, `instance` and `getInstance()` are underlined. That means they are static members.

```text
--------------------------------
- instance : Singleton
--------------------------------
+ getInstance() : Singleton
--------------------------------
```

Equivalent Java:

```java
private static Singleton instance;

public static Singleton getInstance() {
    ...
}
```

This matters because you must access the Singleton before you already have a Singleton object:

```java
Singleton object = Singleton.getInstance();
```

---

## 4. Interface notation

An interface may be written as:

```text
+---------------------+
|    <<interface>>    |
|       Product       |
+---------------------+
| + use() : void      |
+---------------------+
```

Equivalent Java:

```java
interface Product {
    void use();
}
```

A concrete class implements it:

```java
class ConcreteProduct implements Product {
    @Override
    public void use() {
        System.out.println("Using product");
    }
}
```

---

# 5. Generalization: class inheritance

A **solid line with a hollow triangular arrowhead** means inheritance.

```text
ConcreteCreator ─────────▷ Creator
```

The arrow points toward the parent.

Java:

```java
class ConcreteCreator extends Creator {
}
```

Remember:

> **The triangle points to the more general class.**

For example:

```text
RoadLogistics ─────────▷ Logistics
```

means:

```java
class RoadLogistics extends Logistics {
}
```

---

# 6. Realization: implementing an interface

A **dashed line with a hollow triangular arrowhead** means a class implements an interface.

```text
Truck - - - - - - - -▷ Transport
```

Java:

```java
class Truck implements Transport {
}
```

Again, the triangle points to the abstraction.

```text
Concrete class - - -▷ Interface
```

---

## Generalization versus realization

```text
Solid line + triangle  = extends
Dashed line + triangle = implements
```

That is one of the most important UML distinctions for these patterns.

---

# 7. Dependency: “uses”

A dashed arrow without a triangular inheritance arrowhead usually represents a dependency.

```text
Client - - - - -> Factory
```

It means the client temporarily uses the factory, perhaps through:

- a parameter,
    
- a local variable,
    
- a method call,
    
- or object creation.
    

Example:

```java
void createScreen(GUIFactory factory) {
    Button button = factory.createButton();
}
```

The client uses `GUIFactory`, but it does not necessarily permanently store it.

---

# 8. Association

A plain solid line generally means one class knows or stores another class.

```text
Director ------------- Builder
```

Example:

```java
class Director {
    private Builder builder;
}
```

Association usually means:

> One object has a reference to another object.

---

# 9. Aggregation: hollow diamond

```text
Director ◇------------- Builder
```

The hollow diamond means a weak whole-part relationship.

The diamond is placed on the side of the **whole**.

It suggests:

- `Director` has a `Builder`.
    
- The builder may exist without the director.
    
- The builder can be passed to another director.
    

Java:

```java
class Director {
    private Builder builder;

    public Director(Builder builder) {
        this.builder = builder;
    }
}
```

The director did not necessarily create the builder and does not necessarily control its lifetime.

---

# 10. Composition: filled diamond

```text
House ◆------------- Room
```

Composition is a stronger whole-part relationship.

The part is considered owned by the whole.

Example:

```java
class House {
    private final List<Room> rooms = new ArrayList<>();
}
```

Conceptually, if the house is destroyed, its internal room objects are no longer meaningful as parts of that house.

For these four patterns, composition is not the most important relationship, but it may appear between:

- a product and its parts,
    
- a complex object and its internal components.
    

---

# 11. Multiplicity

Numbers near UML lines show how many objects participate.

|UML|Meaning|
|---|---|
|`1`|Exactly one|
|`0..1`|Zero or one|
|`*`|Many|
|`1..*`|One or more|

Example:

```text
Director 1 -------- 1 Builder
```

One director currently uses one builder.

```text
Order 1 -------- * Item
```

One order contains many items.

---

# 12. The UML symbols you should memorize

```text
Class extends class:
Child ─────────▷ Parent

Class implements interface:
Class - - - - -▷ Interface

Uses temporarily:
A - - - - -> B

Has a reference:
A ----------- B

Weak whole-part:
Whole ◇------ Part

Strong whole-part:
Whole ◆------ Part
```

For your CT, the most common mistakes are:

- drawing the inheritance arrow in the wrong direction,
    
- using a solid line for `implements`,
    
- forgetting that the diamond belongs on the whole side,
    
- confusing dependency with inheritance.
    

---

# Part 2: Factory Method

# 1. Core idea

Factory Method means:

> A parent creator defines the general workflow, but subclasses decide which concrete product gets created.

The PDF’s formal intent is to define a creation interface while allowing subclasses to choose the instantiated class.

A simple memory sentence:

> **Factory Method delegates one creation decision to a creator subclass.**

---

# 2. Intuitive example

Suppose a logistics company delivers goods.

The general process is always:

1. Create a transport.
    
2. Load the goods.
    
3. Deliver the goods.
    

But the actual transport varies:

- road logistics creates a truck,
    
- sea logistics creates a ship.
    

The general delivery workflow belongs in the parent `Logistics` class.

The product decision belongs in the subclasses.

---

# 3. Factory Method UML

```text
                       <<interface>>
+------------------+      Product
|     Creator      | - - - - - - - - ->
+------------------+          △
| + operation()    |          :
| # createProduct(): Product  :
+------------------+          :
          △                    :
          |                    :
+------------------+    +------------------+
| ConcreteCreator  |    | ConcreteProduct  |
+------------------+    +------------------+
| + createProduct(): Product  |
+------------------+    implements Product
```

More specifically:

```text
RoadLogistics ─────────▷ Logistics
SeaLogistics  ─────────▷ Logistics

Truck - - - - - - - -▷ Transport
Ship  - - - - - - - -▷ Transport

RoadLogistics - -creates-> Truck
SeaLogistics  - -creates-> Ship
```

---

# 4. Participants

## Product

The common interface used by the creator:

```java
interface Transport {
    void deliver();
}
```

## Concrete products

Actual objects:

```java
class Truck implements Transport
class Ship implements Transport
```

## Creator

Contains:

- the factory method,
    
- and usually some meaningful business operation that uses the created product.
    

```java
abstract class Logistics {
    protected abstract Transport createTransport();

    public void planDelivery() {
        Transport transport = createTransport();
        transport.deliver();
    }
}
```

## Concrete creators

Override the factory method:

```java
class RoadLogistics extends Logistics {
    protected Transport createTransport() {
        return new Truck();
    }
}
```

---

# 5. Complete Java example

```java
interface Transport {
    void deliver();
}

class Truck implements Transport {
    @Override
    public void deliver() {
        System.out.println("Delivering cargo by road in a truck.");
    }
}

class Ship implements Transport {
    @Override
    public void deliver() {
        System.out.println("Delivering cargo by sea in a ship.");
    }
}

abstract class Logistics {

    // Factory Method
    protected abstract Transport createTransport();

    // Common workflow that uses the product
    public void planDelivery() {
        Transport transport = createTransport();

        System.out.println("Preparing the cargo...");
        transport.deliver();
    }
}

class RoadLogistics extends Logistics {
    @Override
    protected Transport createTransport() {
        return new Truck();
    }
}

class SeaLogistics extends Logistics {
    @Override
    protected Transport createTransport() {
        return new Ship();
    }
}

public class Main {
    public static void main(String[] args) {
        Logistics logistics;

        String deliveryType = "SEA";

        if (deliveryType.equals("ROAD")) {
            logistics = new RoadLogistics();
        } else {
            logistics = new SeaLogistics();
        }

        logistics.planDelivery();
    }
}
```

---

# 6. Follow the execution carefully

Suppose:

```java
Logistics logistics = new SeaLogistics();
logistics.planDelivery();
```

`planDelivery()` is inherited from `Logistics`.

Inside it:

```java
Transport transport = createTransport();
```

Because the actual object is `SeaLogistics`, Java executes:

```java
SeaLogistics.createTransport()
```

That returns:

```java
new Ship()
```

Then:

```java
transport.deliver();
```

executes:

```java
Ship.deliver()
```

So the parent owns the algorithm, but the subclass supplies the product.

---

# 7. How to recognize Factory Method in a problem

Look for these ideas:

- There is one common product interface.
    
- Several implementations of that product exist.
    
- A base class contains a common workflow.
    
- Different subclasses should create different product implementations.
    
- The statement says “let subclasses decide.”
    
- The statement describes a framework that users must extend.
    
- Creation differs, but the rest of the process remains similar.
    

The logistics example in the PDF describes code initially coupled to trucks and needing to support ships and future transport types without spreading type conditions throughout the application.

Typical clues:

> “Different subclasses should provide their own notification object.”

> “Each type of store creates a different payment processor.”

> “A framework should allow clients to override how buttons are created.”

> “The workflow is fixed, but one object used inside the workflow varies.”

---

# 8. Important terminology issue in the slides

The slides include two related but structurally different ideas.

## True Factory Method

The true GoF structure contains:

```text
Creator
    factoryMethod()

ConcreteCreator
    overrides factoryMethod()
```

The `Dialog` example follows this structure:

```text
WindowsDialog creates WindowsButton
WebDialog creates HTMLButton
```

The slides explicitly describe overriding `createButton()` in a creator subclass.

## Simple Factory

The slide’s `ShapeFactory` example uses:

```java
getShape("CIRCLE")
getShape("RECTANGLE")
getShape("SQUARE")
```

with an `if/else` chain inside one factory class.

That is commonly called a **Simple Factory**, not the full GoF Factory Method pattern.

```java
class ShapeFactory {
    public Shape getShape(String type) {
        if (type.equals("CIRCLE")) {
            return new Circle();
        }

        if (type.equals("RECTANGLE")) {
            return new Rectangle();
        }

        return new Square();
    }
}
```

The critical difference:

```text
Simple Factory:
One factory method uses if/switch to choose a product.

Factory Method:
Creator subclasses override the factory method.
```

---

# 9. How to remember the class order

Write Factory Method in this order:

```text
1. Product interface
2. ConcreteProduct classes
3. Creator abstract class
4. ConcreteCreator classes
5. Client
```

Mnemonic:

> **Product first, Creator second.**

Because the creator’s method must return the product abstraction.

```text
Transport
Truck, Ship
Logistics
RoadLogistics, SeaLogistics
Main
```

---

# 10. Factory Method skeleton to memorize

```java
interface Product {
    void use();
}

class ProductA implements Product {
    public void use() { }
}

abstract class Creator {
    protected abstract Product createProduct();

    public void operation() {
        Product p = createProduct();
        p.use();
    }
}

class CreatorA extends Creator {
    protected Product createProduct() {
        return new ProductA();
    }
}
```

The signature to remember is:

```java
protected abstract Product createProduct();
```

---

# Part 3: Abstract Factory

# 1. Core idea

Abstract Factory means:

> Create an entire family of related objects that are designed to work together.

The PDF defines it as an interface for creating families of related or dependent objects without exposing their concrete classes.

Simple memory sentence:

> **Factory Method chooses one product. Abstract Factory chooses one family.**

---

# 2. Think of a grid

Abstract Factory becomes easy when you imagine a table.

Suppose a UI system supports:

- Windows
    
- macOS
    

And each platform needs:

- Button
    
- Checkbox
    

The product grid is:

|Family|Button|Checkbox|
|---|---|---|
|Windows|`WinButton`|`WinCheckbox`|
|Mac|`MacButton`|`MacCheckbox`|

Rows are **families**.

Columns are **product types**.

```text
                 Product types
              Button       Checkbox
Windows     WinButton     WinCheckbox
Mac         MacButton     MacCheckbox
```

Each concrete factory creates one complete row:

```text
WinFactory → WinButton + WinCheckbox
MacFactory → MacButton + MacCheckbox
```

This grid is the best way to remember Abstract Factory.

---

# 3. Why is a normal factory not enough?

Suppose you separately request:

```java
Button button = buttonFactory.getButton("WINDOWS");
Checkbox box = checkboxFactory.getCheckbox("MAC");
```

You may accidentally mix product families:

```text
Windows button + Mac checkbox
```

Abstract Factory avoids that by giving the client one family-specific factory.

```java
GUIFactory factory = new WinFactory();

Button button = factory.createButton();
Checkbox box = factory.createCheckbox();
```

Both products necessarily belong to the Windows family.

The furniture example in the PDF uses matching chairs, sofas, and coffee tables; a modern sofa should not be accidentally mixed with Victorian chairs.

---

# 4. Abstract Factory UML

```text
                    <<interface>>
+------------------------------------------------+
|                GUIFactory                      |
+------------------------------------------------+
| + createButton() : Button                      |
| + createCheckbox() : Checkbox                  |
+------------------------------------------------+
             △                         △
             :                         :
+------------------------+   +------------------------+
|      WinFactory        |   |      MacFactory        |
+------------------------+   +------------------------+
| + createButton()       |   | + createButton()       |
| + createCheckbox()     |   | + createCheckbox()     |
+------------------------+   +------------------------+

       <<interface>>                 <<interface>>
           Button                        Checkbox
             △                              △
        .....|.....                    ......|......
        :         :                    :           :
   WinButton   MacButton          WinCheckbox  MacCheckbox
```

The client depends on:

```text
GUIFactory
Button
Checkbox
```

It should not depend directly on:

```text
WinButton
MacButton
WinCheckbox
MacCheckbox
```

The GUI example and its UML are shown in the PDF with `WinFactory`, `MacFactory`, `Button`, and `Checkbox`.

---

# 5. Participants

## Abstract products

One interface for each product category:

```java
interface Button
interface Checkbox
```

## Concrete products

One implementation per family:

```java
WinButton
MacButton

WinCheckbox
MacCheckbox
```

## Abstract factory

Contains one creation method for each product category:

```java
interface GUIFactory {
    Button createButton();
    Checkbox createCheckbox();
}
```

## Concrete factories

Each creates one family:

```java
class WinFactory implements GUIFactory
class MacFactory implements GUIFactory
```

## Client

Receives an abstract factory and creates products only through it.

---

# 6. Complete Java example

```java
interface Button {
    void paint();
}

interface Checkbox {
    void paint();
}

class WinButton implements Button {
    @Override
    public void paint() {
        System.out.println("Painting a Windows button.");
    }
}

class MacButton implements Button {
    @Override
    public void paint() {
        System.out.println("Painting a macOS button.");
    }
}

class WinCheckbox implements Checkbox {
    @Override
    public void paint() {
        System.out.println("Painting a Windows checkbox.");
    }
}

class MacCheckbox implements Checkbox {
    @Override
    public void paint() {
        System.out.println("Painting a macOS checkbox.");
    }
}

interface GUIFactory {
    Button createButton();
    Checkbox createCheckbox();
}

class WinFactory implements GUIFactory {
    @Override
    public Button createButton() {
        return new WinButton();
    }

    @Override
    public Checkbox createCheckbox() {
        return new WinCheckbox();
    }
}

class MacFactory implements GUIFactory {
    @Override
    public Button createButton() {
        return new MacButton();
    }

    @Override
    public Checkbox createCheckbox() {
        return new MacCheckbox();
    }
}

class Application {
    private final Button button;
    private final Checkbox checkbox;

    public Application(GUIFactory factory) {
        button = factory.createButton();
        checkbox = factory.createCheckbox();
    }

    public void paintUI() {
        button.paint();
        checkbox.paint();
    }
}

public class Main {
    public static void main(String[] args) {
        GUIFactory factory;

        String operatingSystem = "WINDOWS";

        if (operatingSystem.equals("WINDOWS")) {
            factory = new WinFactory();
        } else {
            factory = new MacFactory();
        }

        Application application = new Application(factory);
        application.paintUI();
    }
}
```

---

# 7. Why is the `if` in `main` acceptable?

You may notice:

```java
if (operatingSystem.equals("WINDOWS")) {
    factory = new WinFactory();
} else {
    factory = new MacFactory();
}
```

There is still one condition.

That condition exists at the application’s **configuration or startup point**.

After this choice, the entire application uses only:

```java
GUIFactory
Button
Checkbox
```

The condition is not scattered across every screen.

The PDF similarly selects the concrete factory at startup according to the operating system and then supplies it to the application.

---

# 8. How to recognize Abstract Factory

Look for:

- The word **family**.
    
- Multiple product categories.
    
- Products must be compatible or match.
    
- Themes, platforms, brands, operating systems, database vendors.
    
- The entire family should be replaceable.
    
- The client should not know concrete product classes.
    

Typical descriptions:

> “The application supports Windows and macOS UI components. Every platform needs a button, menu, and checkbox.”

> “A car model requires a compatible engine and transmission.”

> “The system supports MySQL and PostgreSQL families of connection, command, and transaction objects.”

> “Furniture from one style must match.”

The PDF says the pattern is appropriate when code works with different families of related products while avoiding direct dependency on their concrete classes.

---

# 9. Adding a new family versus adding a new product type

This is an important Abstract Factory exam point.

## Adding a new family is easy

Suppose we add Linux.

Create:

```java
class LinuxButton implements Button
class LinuxCheckbox implements Checkbox
class LinuxFactory implements GUIFactory
```

Existing client code remains unchanged.

## Adding a new product category is harder

Suppose we add a `Menu` product.

You must modify:

```java
interface GUIFactory {
    Button createButton();
    Checkbox createCheckbox();
    Menu createMenu();       // new
}
```

Then modify:

```java
WinFactory
MacFactory
LinuxFactory
```

Each must implement `createMenu()`.

That is why the slides state that supporting new product types is difficult.

So Abstract Factory is:

```text
Good at adding new families.
Less convenient at adding new product categories.
```

---

# 10. How to remember Abstract Factory code order

Write it in this order:

```text
1. Product interfaces
2. Concrete products
3. Abstract factory interface
4. Concrete factories
5. Client/Application
6. Main/configuration
```

Mnemonic:

> **Products before factories.**

Why?

Because factory methods must return product interfaces.

```text
Button, Checkbox
WinButton, MacButton, WinCheckbox, MacCheckbox
GUIFactory
WinFactory, MacFactory
Application
Main
```

---

# 11. Abstract Factory skeleton

```java
interface ProductA { }
interface ProductB { }

class A1 implements ProductA { }
class B1 implements ProductB { }

class A2 implements ProductA { }
class B2 implements ProductB { }

interface AbstractFactory {
    ProductA createA();
    ProductB createB();
}

class Factory1 implements AbstractFactory {
    public ProductA createA() {
        return new A1();
    }

    public ProductB createB() {
        return new B1();
    }
}

class Factory2 implements AbstractFactory {
    public ProductA createA() {
        return new A2();
    }

    public ProductB createB() {
        return new B2();
    }
}
```

Memory:

```text
Factory1 creates A1 + B1
Factory2 creates A2 + B2
```

Never mix:

```text
Factory1 creates A1 + B2   ← wrong family
```

---

# Part 4: Builder

Builder is often the most confusing because there are **two common forms**.

1. GoF Builder with `Director`, `Builder`, and `ConcreteBuilder`
    
2. Static nested Builder commonly used in Java
    

Both are called Builder, but they emphasize different problems.

---

# A. GoF Builder Pattern

# 1. Core idea

GoF Builder means:

> Construct a complicated object through several steps, while separating the construction process from the final representation.

The PDF states that the same construction process may create different representations.

Simple memory sentence:

> **Builder controls how an object is assembled step by step.**

---

# 2. Intuitive example

A vehicle may require these steps:

1. Build body.
    
2. Add engine.
    
3. Add wheels.
    
4. Add lights.
    

A car and motorcycle follow similar broad construction steps, but each step produces different details.

```text
Car:
body + car engine + 4 wheels + 2 headlights

Motorcycle:
body + bike engine + 2 wheels + 1 headlight
```

The sequence can be reused.

The representation differs.

---

# 3. GoF Builder UML

```text
+------------------+       +-------------------------+
|     Director     |------>|       <<interface>>     |
+------------------+       |         Builder         |
| - builder        |       +-------------------------+
| + construct()    |       | + buildBody()           |
+------------------+       | + buildEngine()         |
                           | + buildWheels()          |
                           | + buildLights()          |
                           +-------------------------+
                                      △
                                      :
                           +-------------------------+
                           |     ConcreteBuilder     |
                           +-------------------------+
                           | - product : Product     |
                           | + buildBody()           |
                           | + buildEngine()         |
                           | + getResult(): Product  |
                           +-------------------------+
                                      |
                                      | creates
                                      v
                                +-----------+
                                |  Product  |
                                +-----------+
```

The PDF’s UML contains `Director`, `Builder`, `ConcreteBuilder`, and `Product`.

---

# 4. Participants

## Product

The final complex object.

```java
class Vehicle
```

## Builder interface

Declares construction steps.

```java
interface VehicleBuilder {
    void buildBody();
    void addEngine();
    void addWheels();
    void addLights();
    Vehicle getResult();
}
```

## Concrete builder

- stores the unfinished product,
    
- implements each step,
    
- returns the completed result.
    

```java
class CarBuilder implements VehicleBuilder
```

## Director

Knows the **recipe or sequence**.

```java
class Director {
    void constructVehicle(VehicleBuilder builder) {
        builder.buildBody();
        builder.addEngine();
        builder.addWheels();
        builder.addLights();
    }
}
```

## Client

Chooses the concrete builder.

---

# 5. Complete GoF Builder Java example

```java
import java.util.ArrayList;
import java.util.List;

class Vehicle {
    private final List<String> parts = new ArrayList<>();

    public void addPart(String part) {
        parts.add(part);
    }

    public void show() {
        for (String part : parts) {
            System.out.println(part);
        }
    }
}

interface VehicleBuilder {
    void buildBody();
    void addEngine();
    void addWheels();
    void addLights();
    Vehicle getResult();
}

class CarBuilder implements VehicleBuilder {
    private final Vehicle vehicle = new Vehicle();

    @Override
    public void buildBody() {
        vehicle.addPart("Car body");
    }

    @Override
    public void addEngine() {
        vehicle.addPart("Car engine");
    }

    @Override
    public void addWheels() {
        vehicle.addPart("Four wheels");
    }

    @Override
    public void addLights() {
        vehicle.addPart("Two headlights");
    }

    @Override
    public Vehicle getResult() {
        return vehicle;
    }
}

class MotorcycleBuilder implements VehicleBuilder {
    private final Vehicle vehicle = new Vehicle();

    @Override
    public void buildBody() {
        vehicle.addPart("Motorcycle body");
    }

    @Override
    public void addEngine() {
        vehicle.addPart("Motorcycle engine");
    }

    @Override
    public void addWheels() {
        vehicle.addPart("Two wheels");
    }

    @Override
    public void addLights() {
        vehicle.addPart("One headlight");
    }

    @Override
    public Vehicle getResult() {
        return vehicle;
    }
}

class Director {
    public void constructVehicle(VehicleBuilder builder) {
        builder.buildBody();
        builder.addEngine();
        builder.addWheels();
        builder.addLights();
    }
}

public class Main {
    public static void main(String[] args) {
        Director director = new Director();

        VehicleBuilder carBuilder = new CarBuilder();
        director.constructVehicle(carBuilder);
        Vehicle car = carBuilder.getResult();

        System.out.println("Car:");
        car.show();

        VehicleBuilder bikeBuilder = new MotorcycleBuilder();
        director.constructVehicle(bikeBuilder);
        Vehicle motorcycle = bikeBuilder.getResult();

        System.out.println("\nMotorcycle:");
        motorcycle.show();
    }
}
```

This mirrors the vehicle Builder structure shown in the PDF, where the director executes body, wheel, and headlight steps on either a car or motorcycle builder.

---

# 6. What exactly does the Director do?

The Director does **not** normally build the product itself.

It does not contain:

```java
new Vehicle()
vehicle.addPart(...)
```

The concrete builder does that.

The Director only knows:

> Which steps should be called, and in which order?

```java
class Director {
    public void constructVehicle(VehicleBuilder builder) {
        builder.buildBody();
        builder.addEngine();
        builder.addWheels();
        builder.addLights();
    }
}
```

Think of a restaurant:

- **Customer** chooses what meal is wanted.
    
- **Cashier/director** tells the kitchen which steps to perform.
    
- **Kitchen/builder** prepares the actual food.
    
- **Meal** is the product.
    

The PDF similarly shows a customer, cashier/director, and restaurant crew/builder.

---

# 7. Can the same builder create different products?

Yes, depending on the design.

For example, the Director can have multiple recipes:

```java
class Director {

    public void constructBasicVehicle(VehicleBuilder builder) {
        builder.buildBody();
        builder.addEngine();
        builder.addWheels();
    }

    public void constructFullVehicle(VehicleBuilder builder) {
        builder.buildBody();
        builder.addEngine();
        builder.addWheels();
        builder.addLights();
    }
}
```

Then:

```java
CarBuilder builder = new CarBuilder();

director.constructBasicVehicle(builder);
```

creates a basic car.

A different recipe could create a full car.

The responsibilities are:

```text
Director decides the recipe.
ConcreteBuilder decides the representation.
```

That distinction is crucial.

---

# 8. Is the Director compulsory?

No.

The client can call the builder directly:

```java
VehicleBuilder builder = new CarBuilder();

builder.buildBody();
builder.addEngine();
builder.addWheels();

Vehicle car = builder.getResult();
```

Use a Director when:

- standard recipes must be reused,
    
- construction order matters,
    
- several clients need the same construction sequence.
    

Without a Director, the client itself acts as the Director.

---

# 9. How to recognize GoF Builder

Look for:

- One object has many parts.
    
- Construction requires multiple steps.
    
- The order of steps matters.
    
- Different representations can follow similar steps.
    
- The statement mentions assembly, construction, stages, parts, or configuration.
    
- You need control over partial or complete construction.
    
- A huge constructor is becoming difficult.
    
- The same recipe should produce different outcomes through different builders.
    

The PDF emphasizes varying internal representation, isolating construction from representation, and gaining finer control over construction.

Typical questions:

> “Construct different types of vehicles using the same sequence.”

> “Build different report formats from the same parsed data.”

> “Create a meal by assembling a main item, drink, dessert, and toy.”

> “Construct a computer with selected processor, storage, RAM, and graphics card.”

---

# 10. How to remember GoF Builder class order

Write it in this order:

```text
1. Product
2. Builder interface
3. ConcreteBuilder classes
4. Director
5. Client
```

Mnemonic:

> **Product → Builder → Builder implementations → Director → Client**

Or:

```text
P B C D C
```

Remember the main ownership rule:

```text
ConcreteBuilder has Product.
Director has Builder.
Client chooses ConcreteBuilder.
```

---

# B. Static Nested Builder in Java

This is the form you said you learned.

It is commonly used when one class has:

- many constructor parameters,
    
- many optional fields,
    
- immutable fields,
    
- or several valid configurations.
    

There is usually:

- no builder interface,
    
- no concrete builder hierarchy,
    
- no separate Director.
    

Instead, the product contains a nested static `Builder` class.

---

# 1. The problem it solves

Consider:

```java
Computer computer = new Computer(
        "Intel i7",
        16,
        1000,
        "RTX 4060",
        true,
        false,
        true
);
```

What do these values mean?

```text
true, false, true
```

This is hard to read.

You may create overloaded constructors:

```java
Computer(cpu, ram)
Computer(cpu, ram, storage)
Computer(cpu, ram, storage, gpu)
Computer(cpu, ram, storage, gpu, wifi)
```

This is called the **telescoping constructor problem**.

A static nested Builder gives named, readable steps.

---

# 2. Static nested Builder UML

A simplified UML:

```text
+--------------------------------------+
|              Computer                |
+--------------------------------------+
| - cpu : String                       |
| - ram : int                          |
| - storage : int                      |
| - gpu : String                       |
+--------------------------------------+
| - Computer(builder : Builder)        |
+--------------------------------------+
|       <<static nested class>>         |
|               Builder                |
+--------------------------------------+
| - cpu : String                       |
| - ram : int                          |
| - storage : int                      |
| - gpu : String                       |
+--------------------------------------+
| + storage(value) : Builder           |
| + gpu(value) : Builder               |
| + build() : Computer                 |
+--------------------------------------+
```

The nested class can also be named in UML as:

```text
Computer::Builder
```

---

# 3. Complete static nested Builder example

```java
public final class Computer {
    private final String cpu;
    private final int ram;
    private final int storage;
    private final String gpu;
    private final boolean wifi;
    private final boolean bluetooth;

    private Computer(Builder builder) {
        this.cpu = builder.cpu;
        this.ram = builder.ram;
        this.storage = builder.storage;
        this.gpu = builder.gpu;
        this.wifi = builder.wifi;
        this.bluetooth = builder.bluetooth;
    }

    public static class Builder {
        // Required fields
        private final String cpu;
        private final int ram;

        // Optional fields with defaults
        private int storage = 256;
        private String gpu = "Integrated";
        private boolean wifi = false;
        private boolean bluetooth = false;

        public Builder(String cpu, int ram) {
            this.cpu = cpu;
            this.ram = ram;
        }

        public Builder storage(int storage) {
            this.storage = storage;
            return this;
        }

        public Builder gpu(String gpu) {
            this.gpu = gpu;
            return this;
        }

        public Builder wifi(boolean wifi) {
            this.wifi = wifi;
            return this;
        }

        public Builder bluetooth(boolean bluetooth) {
            this.bluetooth = bluetooth;
            return this;
        }

        public Computer build() {
            return new Computer(this);
        }
    }

    @Override
    public String toString() {
        return "Computer{" +
                "cpu='" + cpu + '\'' +
                ", ram=" + ram +
                ", storage=" + storage +
                ", gpu='" + gpu + '\'' +
                ", wifi=" + wifi +
                ", bluetooth=" + bluetooth +
                '}';
    }
}
```

Client:

```java
public class Main {
    public static void main(String[] args) {
        Computer computer =
                new Computer.Builder("Intel i7", 16)
                        .storage(1000)
                        .gpu("RTX 4060")
                        .wifi(true)
                        .bluetooth(true)
                        .build();

        System.out.println(computer);
    }
}
```

---

# 4. Why do builder methods return `this`?

Example:

```java
public Builder storage(int storage) {
    this.storage = storage;
    return this;
}
```

`this` is the current Builder object.

Returning it enables method chaining:

```java
new Computer.Builder("Intel i7", 16)
        .storage(1000)
        .gpu("RTX 4060")
        .wifi(true)
        .build();
```

Without `return this`, you would need:

```java
Computer.Builder builder =
        new Computer.Builder("Intel i7", 16);

builder.storage(1000);
builder.gpu("RTX 4060");
builder.wifi(true);

Computer computer = builder.build();
```

Both work, but chaining is more readable.

---

# 5. Why is the Builder static?

Because creating the builder should not require an existing `Computer`.

Wrong logical situation:

```java
Computer computer = ...;
Computer.Builder builder = computer.new Builder();
```

You need the builder in order to create the computer, so requiring a computer first would be circular.

Therefore:

```java
public static class Builder
```

allows:

```java
new Computer.Builder(...)
```

without an existing `Computer`.

---

# 6. Why is the `Computer` constructor private?

```java
private Computer(Builder builder)
```

This prevents clients from bypassing the builder.

Clients must use:

```java
new Computer.Builder(...).build();
```

The Builder can therefore:

- apply defaults,
    
- validate values,
    
- create an immutable object,
    
- prevent incomplete construction.
    

---

# 7. Validation in `build()`

```java
public Computer build() {
    if (ram <= 0) {
        throw new IllegalStateException(
                "RAM must be positive"
        );
    }

    if (storage <= 0) {
        throw new IllegalStateException(
                "Storage must be positive"
        );
    }

    return new Computer(this);
}
```

The Builder temporarily collects configuration.

The product is created only after validation succeeds.

---

# 8. GoF Builder versus static nested Builder

|Question|GoF Builder|Static nested Builder|
|---|---|---|
|Main problem|Separate construction process from representation|Avoid complex/telescoping constructors|
|Product types|May produce different representations|Usually produces one class|
|Builder interface|Usually yes|Usually no|
|Concrete builders|Usually several|Usually one nested builder|
|Director|Often present|Usually absent|
|Construction|Standard sequence of steps|Fluent optional configuration|
|Example|Car and motorcycle|One `Computer` with optional fields|

The static nested form is not the exact class diagram shown in the slides, but it follows the same broad principle:

> Separate the gradual collection of construction information from creation of the final object.

---

# Part 5: Singleton

# 1. Core idea

Singleton means:

> Exactly one instance of a class should exist, and the class provides a global access method to that instance.

That is the intent given in the PDF.

Simple memory sentence:

> **One class, one object, one access method.**

---

# 2. Singleton UML

```text
+----------------------------------+
|            Singleton             |
+----------------------------------+
| - instance : Singleton           |  static
+----------------------------------+
| - Singleton()                    |
| + getInstance() : Singleton      |  static
+----------------------------------+
```

In formal UML, the static field and static method are underlined.

Important elements:

```text
private static instance
private constructor
public static getInstance()
```

---

# 3. Basic lazy Singleton Java code

```java
public final class DatabaseManager {
    private static DatabaseManager instance;

    private DatabaseManager() {
        System.out.println("DatabaseManager created.");
    }

    public static DatabaseManager getInstance() {
        if (instance == null) {
            instance = new DatabaseManager();
        }

        return instance;
    }

    public void connect() {
        System.out.println("Connected to database.");
    }
}
```

Client:

```java
public class Main {
    public static void main(String[] args) {
        DatabaseManager first =
                DatabaseManager.getInstance();

        DatabaseManager second =
                DatabaseManager.getInstance();

        System.out.println(first == second); // true

        first.connect();
    }
}
```

The PDF’s database connection example uses the same private constructor, static instance field, and static access method.

---

# 4. Why each part is necessary

## Static field

```java
private static DatabaseManager instance;
```

Stores the one shared object.

It must be static because the object must be retrievable without already possessing an object.

## Private constructor

```java
private DatabaseManager() {
}
```

Prevents:

```java
new DatabaseManager();
```

outside the class.

Only the Singleton class itself can call its constructor.

## Public static getter

```java
public static DatabaseManager getInstance()
```

Provides controlled global access.

## Null check

```java
if (instance == null) {
    instance = new DatabaseManager();
}
```

Creates the object only on the first request.

This is **lazy initialization**.

The PDF’s implementation steps similarly specify a private static field, public static access method, lazy creation, and private constructor.

---

# 5. A thread-safe examination version

The basic version can create two objects if two threads enter the null check simultaneously.

A straightforward thread-safe version is:

```java
public final class DatabaseManager {
    private static DatabaseManager instance;

    private DatabaseManager() {
    }

    public static synchronized DatabaseManager getInstance() {
        if (instance == null) {
            instance = new DatabaseManager();
        }

        return instance;
    }
}
```

For most handwritten pattern questions, the simpler lazy version is likely enough unless thread safety is explicitly mentioned.

---

# 6. How to recognize Singleton

Look for:

- “Only one instance.”
    
- “Single shared object.”
    
- “Global access.”
    
- “Central configuration manager.”
    
- “One logging service.”
    
- “One cache manager.”
    
- “One resource coordinator.”
    
- “The constructor must be restricted.”
    
- “Creation should happen only on first use.”
    

The PDF describes controlling access to a shared resource such as a database or file and providing a protected global access point.

---

# 7. When Singleton is not automatically appropriate

Do not use Singleton merely because:

> “Many classes need this object.”

An object can instead be created once and passed through constructors:

```java
class Service {
    private final Database database;

    Service(Database database) {
        this.database = database;
    }
}
```

Singleton introduces global state, which can make testing and dependency management harder.

Use it when the **one-instance constraint is part of the actual requirement**, not just for convenience.

---

# 8. Singleton memory order

Write it in this exact order:

```text
1. private static instance
2. private constructor
3. public static getInstance()
4. ordinary business methods
```

Mnemonic:

> **Static – Private – Getter**

```text
S P G
```

Code shape:

```java
class Singleton {
    private static Singleton instance;

    private Singleton() { }

    public static Singleton getInstance() {
        if (instance == null) {
            instance = new Singleton();
        }
        return instance;
    }
}
```

---

# Part 6: How to Differentiate All Four Patterns

# 1. Fast decision tree

Use this during the CT:

```text
Does the problem require exactly one shared instance?
        |
       Yes → Singleton
        |
       No
        v
Is one complicated object built through many steps/options?
        |
       Yes → Builder
        |
       No
        v
Are several related product types created as a matching family?
        |
       Yes → Abstract Factory
        |
       No
        v
Does a creator subclass decide which one product subtype to create?
        |
       Yes → Factory Method
```

---

# 2. Core comparison table

|Pattern|Main creation problem|Usually creates|Main classes|
|---|---|---|---|
|Factory Method|Which subtype should be created?|One product|Product, Creator, ConcreteCreator|
|Abstract Factory|Which compatible family should be created?|Several related products|Product interfaces, AbstractFactory, ConcreteFactories|
|Builder|How should one complicated object be assembled?|One complex product|Product, Builder, ConcreteBuilder, Director|
|Singleton|How do we restrict the number of objects?|One shared instance|Singleton class only|

---

# 3. Object-count intuition

```text
Factory Method:
Choose one object from one product hierarchy.

Abstract Factory:
Create several objects from one matching family.

Builder:
Combine several values or parts into one final object.

Singleton:
Allow exactly one shared object.
```

---

# 4. Keyword guide

|Problem wording|Pattern|
|---|---|
|“subclass decides which object to instantiate”|Factory Method|
|“framework should be extensible”|Factory Method|
|“families of related products”|Abstract Factory|
|“products must be compatible/matching”|Abstract Factory|
|“Windows/Mac, light/dark, MySQL/PostgreSQL”|Abstract Factory|
|“step by step”|Builder|
|“many optional parameters”|Builder|
|“same process, different representation”|Builder|
|“exactly one instance”|Singleton|
|“global access point”|Singleton|
|“private constructor”|Singleton|

---

# Part 7: Builder versus Abstract Factory

This is your most important comparison.

Both can involve many components, so focus on the **result and the purpose**.

---

## Abstract Factory creates a collection of related objects

Example:

```java
GUIFactory factory = new WinFactory();

Button button = factory.createButton();
Checkbox checkbox = factory.createCheckbox();
```

You receive two separate objects:

```text
Button
Checkbox
```

They belong to the same family.

The important issue is:

> Compatibility among products.

---

## Builder creates one final complex object

Example:

```java
Computer computer =
        new Computer.Builder("Intel i7", 16)
                .storage(1000)
                .gpu("RTX 4060")
                .build();
```

You receive one final object:

```text
Computer
```

The important issue is:

> Gradual assembly and configuration.

---

## The easiest rule

```text
Abstract Factory:
Many related final objects.

Builder:
One final object made from many parts or options.
```

---

# 1. Computer example: when it is Builder

Problem:

> A customer customizes one computer by selecting RAM, processor, storage, GPU, Wi-Fi, and cooling. Some fields are optional.

Use Builder.

Why?

Because:

- the result is one `Computer`,
    
- it has many configuration options,
    
- it is created progressively.
    

```text
CPU \
RAM  \
GPU   ---> one Computer
SSD  /
WiFi/
```

---

# 2. Computer example: when it is Abstract Factory

Problem:

> The company supports Intel and AMD hardware families. An Intel motherboard must be paired with an Intel-compatible processor and cooler. An AMD motherboard must be paired with AMD-compatible components.

Use Abstract Factory.

Why?

Because the system creates several separate but compatible objects:

```text
IntelFactory:
    IntelProcessor
    IntelMotherboard
    IntelCooler

AMDFactory:
    AMDProcessor
    AMDMotherboard
    AMDCooler
```

The key is not step-by-step construction.

The key is compatible families.

---

# 3. They can work together

These patterns are not mutually exclusive.

```text
Abstract Factory supplies compatible parts.
Builder assembles those parts into one computer.
```

Example:

```java
HardwareFactory partsFactory = new IntelFactory();

Computer computer =
        new ComputerBuilder(partsFactory)
                .addProcessor()
                .addMotherboard()
                .addCooler()
                .build();
```

Abstract Factory answers:

> Which compatible parts?

Builder answers:

> How do we assemble the final computer?

---

# Part 8: Factory Method versus Abstract Factory

|Factory Method|Abstract Factory|
|---|---|
|Usually one creation method|Usually several creation methods|
|One product hierarchy|Several product hierarchies|
|Uses creator inheritance|Usually uses factory object composition|
|Subclass chooses product|Concrete factory chooses family|
|`createTransport()`|`createButton()`, `createCheckbox()`|

Factory Method:

```java
abstract class Logistics {
    abstract Transport createTransport();
}
```

Abstract Factory:

```java
interface GUIFactory {
    Button createButton();
    Checkbox createCheckbox();
}
```

Fast visual test:

```text
One create method → probably Factory Method.

Several create methods returning different product interfaces
→ probably Abstract Factory.
```

That is not an absolute law, but it is a strong exam clue.

---

# Part 9: Factory Method versus Builder

## Factory Method

Creation is normally one operation:

```java
Transport transport = createTransport();
```

The product is returned immediately.

## Builder

Creation occurs through several calls:

```java
builder.buildBody();
builder.addEngine();
builder.addWheels();
Vehicle vehicle = builder.getResult();
```

Rule:

```text
Choose a subtype → Factory Method.
Assemble through steps → Builder.
```

---

# Part 10: Simple Factory versus Factory Method

This distinction is frequently tested.

## Simple Factory

```java
class ShapeFactory {
    Shape createShape(String type) {
        if (type.equals("CIRCLE")) {
            return new Circle();
        }

        return new Rectangle();
    }
}
```

Characteristics:

- one factory class,
    
- conditional selection,
    
- no creator inheritance,
    
- adding a type usually modifies the factory.
    

## Factory Method

```java
abstract class Dialog {
    abstract Button createButton();
}

class WindowsDialog extends Dialog {
    Button createButton() {
        return new WindowsButton();
    }
}
```

Characteristics:

- creator hierarchy,
    
- subclasses override creation,
    
- adding a variant usually adds a creator subclass.
    

Memory:

```text
Simple Factory chooses with if/switch.
Factory Method chooses with polymorphism.
```

---

# Part 11: Class-Writing Order for the CT

When nervous, do not start writing random classes. Follow a fixed sequence.

---

## Factory Method

```text
Product interface
↓
Concrete products
↓
Creator abstract class
↓
Concrete creators
↓
Client
```

Example:

```text
Transport
Truck, Ship
Logistics
RoadLogistics, SeaLogistics
Main
```

---

## Abstract Factory

```text
Product interfaces
↓
Concrete product variants
↓
Abstract factory
↓
Concrete factories
↓
Client
```

Example:

```text
Button, Checkbox
WinButton, MacButton, WinCheckbox, MacCheckbox
GUIFactory
WinFactory, MacFactory
Application
```

---

## GoF Builder

```text
Product
↓
Builder interface
↓
Concrete builders
↓
Director
↓
Client
```

Example:

```text
Vehicle
VehicleBuilder
CarBuilder, MotorcycleBuilder
Director
Main
```

---

## Static nested Builder

Inside the Product:

```text
Product fields
↓
private Product(Builder builder)
↓
static Builder class
↓
Builder fields
↓
Builder methods return this
↓
build() returns new Product(this)
```

---

## Singleton

```text
private static instance
↓
private constructor
↓
public static getInstance()
↓
ordinary operations
```

---

# Part 12: Handwritten Memory Templates

## Factory Method memory shape

```java
interface P { }

class A implements P { }

abstract class Creator {
    abstract P create();
}

class CreatorA extends Creator {
    P create() {
        return new A();
    }
}
```

Think:

> **Subclass returns concrete product as abstract type.**

---

## Abstract Factory memory shape

```java
interface A { }
interface B { }

interface Factory {
    A createA();
    B createB();
}

class Factory1 implements Factory {
    public A createA() { return new A1(); }
    public B createB() { return new B1(); }
}
```

Think:

> **One factory equals one row of the family grid.**

---

## GoF Builder memory shape

```java
class Product { }

interface Builder {
    void step1();
    void step2();
    Product getResult();
}

class ConcreteBuilder implements Builder {
    private Product product = new Product();

    public void step1() { }
    public void step2() { }

    public Product getResult() {
        return product;
    }
}

class Director {
    void construct(Builder b) {
        b.step1();
        b.step2();
    }
}
```

Think:

> **Director calls; builder builds; product results.**

---

## Static nested Builder memory shape

```java
class Product {
    private Product(Builder b) {
        // copy fields
    }

    static class Builder {
        Builder option(...) {
            ...
            return this;
        }

        Product build() {
            return new Product(this);
        }
    }
}
```

Think:

> **Builder collects; Product copies.**

---

## Singleton memory shape

```java
class Singleton {
    private static Singleton instance;

    private Singleton() { }

    public static Singleton getInstance() {
        if (instance == null) {
            instance = new Singleton();
        }

        return instance;
    }
}
```

Think:

> **Static field, private constructor, static getter.**

---

# Final One-Line Identification Rules

```text
Factory Method:
“Which one product subclass should this creator create?”

Abstract Factory:
“Which matching family of products should the application use?”

Builder:
“How should this one complex object be assembled?”

Singleton:
“How do I guarantee that only one instance exists?”
```

The final mental picture should be:

```text
Factory Method  = one PRODUCT decision
Abstract Factory = one FAMILY decision
Builder          = one ASSEMBLY process
Singleton        = one INSTANCE
```