package collections;
import java.util.*;
import java.util.concurrent.CopyOnWriteArrayList;
import java.util.function.Predicate;
import java.util.stream.Collectors;

/**
 * COMPREHENSIVE GUIDE TO ARRAYLIST, LINKEDLIST, AND VECTOR
 *
 * This guide covers all major methods and operations for these three
 * fundamental Java Collection Framework implementations of the List interface.
 *
 * KEY DIFFERENCES:
 * - ArrayList: Resizable array implementation, fast random access, slower insertions/deletions in middle
 * - LinkedList: Doubly-linked list implementation, fast insertions/deletions, slower random access
 * - Vector: Legacy synchronized ArrayList, thread-safe but slower performance
 */
public class CollectionsGuide {

    public static void main(String[] args) {
        System.out.println("=== COMPREHENSIVE COLLECTIONS GUIDE ===\n");

        // Demonstrate each collection type
        demonstrateArrayList();
        demonstrateLinkedList();
        demonstrateVector();
        demonstrateComparisons();
        demonstrateAdvancedOperations();
    }

    /**
     * ARRAYLIST COMPLETE DEMONSTRATION
     * ArrayList is a resizable array implementation of List interface
     * - Allows duplicate elements and maintains insertion order
     * - Not synchronized (not thread-safe)
     * - Good for frequent access, poor for frequent insertions/deletions in middle
     */
    public static void demonstrateArrayList() {
        System.out.println("=== ARRAYLIST COMPREHENSIVE GUIDE ===\n");

        // 1. CREATION AND INITIALIZATION
        System.out.println("1. CREATION AND INITIALIZATION:");

        // Default constructor - initial capacity of 10
        ArrayList<String> list1 = new ArrayList<>();
        System.out.println("Empty ArrayList created: " + list1);

        // Constructor with initial capacity
        ArrayList<Integer> list2 = new ArrayList<>(20);
        System.out.println("ArrayList with capacity 20: " + list2);

        // Constructor from another collection
        List<String> sourceList = Arrays.asList("A", "B", "C");
        ArrayList<String> list3 = new ArrayList<>(sourceList);
        System.out.println("ArrayList from collection: " + list3);

        // Using Collections utility methods
        ArrayList<String> list4 = new ArrayList<>(Collections.nCopies(5, "Hello"));
        System.out.println("ArrayList with repeated elements: " + list4);

        System.out.println();

        // 2. BASIC OPERATIONS
        System.out.println("2. BASIC OPERATIONS:");
        ArrayList<String> fruits = new ArrayList<>();

        // add(E element) - Appends element to end, returns boolean
        boolean added = fruits.add("Apple");
        fruits.add("Banana");
        fruits.add("Orange");
        System.out.println("After adding fruits: " + fruits + ", add returned: " + added);

        // add(int index, E element) - Inserts element at specific position
        fruits.add(1, "Mango"); // Inserts at index 1, shifts others
        System.out.println("After inserting Mango at index 1: " + fruits);

        // get(int index) - Returns element at specified position
        String firstFruit = fruits.get(0);
        System.out.println("First fruit: " + firstFruit);

        // set(int index, E element) - Replaces element, returns old element
        String oldFruit = fruits.set(2, "Grape");
        System.out.println("Replaced " + oldFruit + " with Grape: " + fruits);

        // size() - Returns number of elements
        System.out.println("Size of list: " + fruits.size());

        // isEmpty() - Returns true if list contains no elements
        System.out.println("Is list empty? " + fruits.isEmpty());

        System.out.println();

        // 3. SEARCH AND QUERY OPERATIONS
        System.out.println("3. SEARCH AND QUERY OPERATIONS:");

        // contains(Object o) - Returns true if list contains specified element
        boolean hasApple = fruits.contains("Apple");
        System.out.println("Contains Apple? " + hasApple);

        // indexOf(Object o) - Returns first occurrence index, -1 if not found
        int appleIndex = fruits.indexOf("Apple");
        System.out.println("Index of Apple: " + appleIndex);

        // lastIndexOf(Object o) - Returns last occurrence index
        fruits.add("Apple"); // Add duplicate
        int lastAppleIndex = fruits.lastIndexOf("Apple");
        System.out.println("Last index of Apple: " + lastAppleIndex);
        System.out.println("List with duplicate: " + fruits);

        System.out.println();

        // 4. REMOVAL OPERATIONS
        System.out.println("4. REMOVAL OPERATIONS:");

        // remove(int index) - Removes element at index, returns removed element
        String removedByIndex = fruits.remove(1);
        System.out.println("Removed by index 1: " + removedByIndex + ", List: " + fruits);

        // remove(Object o) - Removes first occurrence, returns boolean
        boolean removedByObject = fruits.remove("Grape");
        System.out.println("Removed Grape: " + removedByObject + ", List: " + fruits);

        // clear() - Removes all elements
        ArrayList<String> tempList = new ArrayList<>(fruits);
        tempList.clear();
        System.out.println("After clear(): " + tempList);

        System.out.println();

        // 5. BULK OPERATIONS
        System.out.println("5. BULK OPERATIONS:");

        // addAll(Collection c) - Adds all elements from collection
        List<String> moreFruits = Arrays.asList("Kiwi", "Pineapple");
        fruits.addAll(moreFruits);
        System.out.println("After addAll: " + fruits);

        // addAll(int index, Collection c) - Inserts all elements at specified position
        fruits.addAll(2, Arrays.asList("Strawberry", "Blueberry"));
        System.out.println("After addAll at index 2: " + fruits);

        // containsAll(Collection c) - Returns true if contains all elements
        boolean hasAll = fruits.containsAll(Arrays.asList("Apple", "Banana"));
        System.out.println("Contains Apple and Banana? " + hasAll);

        // removeAll(Collection c) - Removes all elements that are in specified collection
        ArrayList<String> copy1 = new ArrayList<>(fruits);
        copy1.removeAll(Arrays.asList("Apple", "Banana"));
        System.out.println("After removeAll(Apple, Banana): " + copy1);

        // retainAll(Collection c) - Retains only elements in specified collection
        ArrayList<String> copy2 = new ArrayList<>(fruits);
        copy2.retainAll(Arrays.asList("Apple", "Orange", "Kiwi"));
        System.out.println("After retainAll(Apple, Orange, Kiwi): " + copy2);

        System.out.println();

        // 6. ARRAY CONVERSION
        System.out.println("6. ARRAY CONVERSION:");

        // toArray() - Returns Object array
        Object[] objArray = fruits.toArray();
        System.out.println("Object array: " + Arrays.toString(objArray));

        // toArray(T[] a) - Returns typed array
        String[] stringArray = fruits.toArray(new String[0]);
        System.out.println("String array: " + Arrays.toString(stringArray));

        // Alternative with pre-sized array
        String[] preSizedArray = fruits.toArray(new String[fruits.size()]);
        System.out.println("Pre-sized array: " + Arrays.toString(preSizedArray));

        System.out.println();

        // 7. ARRAYLIST SPECIFIC METHODS
        System.out.println("7. ARRAYLIST SPECIFIC METHODS:");

        // ensureCapacity(int minCapacity) - Increases capacity if necessary
        ArrayList<Integer> numbers = new ArrayList<>();
        numbers.ensureCapacity(100); // Ensures capacity of at least 100
        System.out.println("Capacity ensured for 100 elements");

        // trimToSize() - Trims capacity to current size
        for (int i = 0; i < 5; i++) {
            numbers.add(i);
        }
        numbers.trimToSize(); // Reduces capacity to actual size
        System.out.println("Trimmed to size, numbers: " + numbers);

        // clone() - Returns shallow copy
        @SuppressWarnings("unchecked")
        ArrayList<String> clonedList = (ArrayList<String>) fruits.clone();
        System.out.println("Cloned list: " + clonedList);

        System.out.println();

        // 8. ITERATION METHODS
        System.out.println("8. ITERATION METHODS:");

        // Enhanced for loop
        System.out.print("Enhanced for loop: ");
        for (String fruit : fruits) {
            System.out.print(fruit + " ");
        }
        System.out.println();

        // Iterator
        System.out.print("Iterator: ");
        Iterator<String> iter = fruits.iterator();
        while (iter.hasNext()) {
            System.out.print(iter.next() + " ");
        }
        System.out.println();

        // ListIterator (bidirectional)
        System.out.print("ListIterator (reverse): ");
        ListIterator<String> listIter = fruits.listIterator(fruits.size());
        while (listIter.hasPrevious()) {
            System.out.print(listIter.previous() + " ");
        }
        System.out.println();

        // forEach with lambda (Java 8+)
        System.out.print("forEach with lambda: ");
        fruits.forEach(fruit -> System.out.print(fruit + " "));
        System.out.println();

        System.out.println("\n");
    }

    /**
     * LINKEDLIST COMPLETE DEMONSTRATION
     * LinkedList is a doubly-linked list implementation of List and Deque interfaces
     * - Allows duplicate elements and maintains insertion order
     * - Not synchronized (not thread-safe)
     * - Good for frequent insertions/deletions, poor for random access
     */
    public static void demonstrateLinkedList() {
        System.out.println("=== LINKEDLIST COMPREHENSIVE GUIDE ===\n");

        // 1. CREATION AND INITIALIZATION
        System.out.println("1. CREATION AND INITIALIZATION:");

        // Default constructor
        LinkedList<String> list1 = new LinkedList<>();
        System.out.println("Empty LinkedList: " + list1);

        // Constructor from collection
        LinkedList<String> list2 = new LinkedList<>(Arrays.asList("X", "Y", "Z"));
        System.out.println("LinkedList from collection: " + list2);

        System.out.println();

        // 2. BASIC LIST OPERATIONS (Same as ArrayList)
        System.out.println("2. BASIC LIST OPERATIONS:");
        LinkedList<String> animals = new LinkedList<>();

        // All basic List operations work the same as ArrayList
        animals.add("Dog");
        animals.add("Cat");
        animals.add("Bird");
        animals.add(1, "Fish");
        System.out.println("After basic operations: " + animals);
        System.out.println("Get index 0: " + animals.get(0));
        System.out.println("Size: " + animals.size());

        System.out.println();

        // 3. LINKEDLIST SPECIFIC METHODS (Deque interface)
        System.out.println("3. LINKEDLIST SPECIFIC METHODS:");

        // First element operations
        animals.addFirst("Tiger"); // Adds to beginning
        System.out.println("After addFirst(Tiger): " + animals);

        String firstElement = animals.getFirst(); // Gets first element
        System.out.println("First element: " + firstElement);

        String removedFirst = animals.removeFirst(); // Removes and returns first
        System.out.println("Removed first: " + removedFirst + ", List: " + animals);

        // Last element operations
        animals.addLast("Lion"); // Adds to end (same as add())
        System.out.println("After addLast(Lion): " + animals);

        String lastElement = animals.getLast(); // Gets last element
        System.out.println("Last element: " + lastElement);

        String removedLast = animals.removeLast(); // Removes and returns last
        System.out.println("Removed last: " + removedLast + ", List: " + animals);

        System.out.println();

        // 4. QUEUE OPERATIONS (FIFO - First In, First Out)
        System.out.println("4. QUEUE OPERATIONS (FIFO):");

        LinkedList<String> queue = new LinkedList<>();

        // offer(E e) - Adds element to end (same as add)
        queue.offer("First");
        queue.offer("Second");
        queue.offer("Third");
        System.out.println("Queue after offers: " + queue);

        // peek() - Returns first element without removing, null if empty
        String peeked = queue.peek();
        System.out.println("Peeked element: " + peeked + ", Queue: " + queue);

        // poll() - Removes and returns first element, null if empty
        String polled = queue.poll();
        System.out.println("Polled element: " + polled + ", Queue: " + queue);

        // element() - Returns first element, throws exception if empty
        String element = queue.element();
        System.out.println("Element: " + element);

        // remove() - Removes and returns first element, throws exception if empty
        String removed = queue.remove();
        System.out.println("Removed: " + removed + ", Queue: " + queue);

        System.out.println();

        // 5. STACK OPERATIONS (LIFO - Last In, First Out)
        System.out.println("5. STACK OPERATIONS (LIFO):");

        LinkedList<String> stack = new LinkedList<>();

        // push(E e) - Adds element to front (same as addFirst)
        stack.push("Bottom");
        stack.push("Middle");
        stack.push("Top");
        System.out.println("Stack after pushes: " + stack);

        // pop() - Removes and returns first element (same as removeFirst)
        String popped = stack.pop();
        System.out.println("Popped: " + popped + ", Stack: " + stack);

        System.out.println();

        // 6. DEQUE OPERATIONS (Double-ended queue)
        System.out.println("6. DEQUE OPERATIONS:");

        LinkedList<Integer> deque = new LinkedList<>();

        // Adding to both ends
        deque.offerFirst(2);
        deque.offerLast(3);
        deque.offerFirst(1);
        deque.offerLast(4);
        System.out.println("Deque after offers: " + deque);

        // Peeking both ends
        System.out.println("Peek first: " + deque.peekFirst());
        System.out.println("Peek last: " + deque.peekLast());

        // Polling both ends
        System.out.println("Poll first: " + deque.pollFirst());
        System.out.println("Poll last: " + deque.pollLast());
        System.out.println("Deque after polls: " + deque);

        System.out.println();

        // 7. SEARCH OPERATIONS
        System.out.println("7. SEARCH OPERATIONS:");

        LinkedList<String> searchList = new LinkedList<>(Arrays.asList("A", "B", "C", "B", "D"));

        // indexOf and lastIndexOf work same as ArrayList
        System.out.println("List: " + searchList);
        System.out.println("First index of B: " + searchList.indexOf("B"));
        System.out.println("Last index of B: " + searchList.lastIndexOf("B"));

        // removeFirstOccurrence and removeLastOccurrence
        LinkedList<String> copy1 = new LinkedList<>(searchList);
        copy1.removeFirstOccurrence("B");
        System.out.println("After removeFirstOccurrence(B): " + copy1);

        LinkedList<String> copy2 = new LinkedList<>(searchList);
        copy2.removeLastOccurrence("B");
        System.out.println("After removeLastOccurrence(B): " + copy2);

        System.out.println();

        // 8. ADVANCED ITERATION
        System.out.println("8. ADVANCED ITERATION:");

        LinkedList<String> iterList = new LinkedList<>(Arrays.asList("One", "Two", "Three"));

        // Descendingiterator - iterates in reverse order
        System.out.print("Descending iterator: ");
        Iterator<String> descIter = iterList.descendingIterator();
        while (descIter.hasNext()) {
            System.out.print(descIter.next() + " ");
        }
        System.out.println();

        // ListIterator with modifications
        System.out.println("ListIterator modifications:");
        ListIterator<String> listIter = iterList.listIterator();
        while (listIter.hasNext()) {
            String current = listIter.next();
            if ("Two".equals(current)) {
                listIter.set("Modified"); // Replace current element
                listIter.add("Inserted"); // Insert after current
            }
        }
        System.out.println("After modifications: " + iterList);

        System.out.println("\n");
    }

    /**
     * VECTOR COMPLETE DEMONSTRATION
     * Vector is a synchronized resizable array implementation (legacy class)
     * - Thread-safe but with performance overhead
     * - Similar to ArrayList but with synchronization
     * - Contains some legacy methods not in ArrayList
     */
    public static void demonstrateVector() {
        System.out.println("=== VECTOR COMPREHENSIVE GUIDE ===\n");

        // 1. CREATION AND INITIALIZATION
        System.out.println("1. CREATION AND INITIALIZATION:");

        // Default constructor - initial capacity 10, increment 0 (doubles when needed)
        Vector<String> vector1 = new Vector<>();
        System.out.println("Default vector: " + vector1);

        // Constructor with initial capacity
        Vector<Integer> vector2 = new Vector<>(20);
        System.out.println("Vector with capacity 20");

        // Constructor with capacity and increment
        Vector<String> vector3 = new Vector<>(10, 5); // capacity 10, increment by 5
        System.out.println("Vector with capacity 10, increment 5");

        // Constructor from collection
        Vector<String> vector4 = new Vector<>(Arrays.asList("A", "B", "C"));
        System.out.println("Vector from collection: " + vector4);

        System.out.println();

        // 2. BASIC OPERATIONS (Same as ArrayList)
        System.out.println("2. BASIC OPERATIONS:");

        Vector<String> colors = new Vector<>();
        colors.add("Red");
        colors.add("Green");
        colors.add("Blue");
        colors.add(1, "Yellow");
        System.out.println("After basic operations: " + colors);

        // All ArrayList methods work the same way
        System.out.println("Element at index 0: " + colors.get(0));
        System.out.println("Size: " + colors.size());
        System.out.println("Contains Red: " + colors.contains("Red"));

        System.out.println();

        // 3. VECTOR SPECIFIC METHODS (Legacy methods)
        System.out.println("3. VECTOR SPECIFIC METHODS:");

        // addElement(E obj) - Legacy version of add()
        colors.addElement("Purple");
        System.out.println("After addElement(Purple): " + colors);

        // insertElementAt(E obj, int index) - Legacy version of add(index, element)
        colors.insertElementAt("Orange", 2);
        System.out.println("After insertElementAt(Orange, 2): " + colors);

        // elementAt(int index) - Legacy version of get()
        String element = colors.elementAt(1);
        System.out.println("elementAt(1): " + element);

        // setElementAt(E obj, int index) - Legacy version of set()
        colors.setElementAt("Pink", 3);
        System.out.println("After setElementAt(Pink, 3): " + colors);

        // removeElement(Object obj) - Legacy version of remove()
        boolean removed = colors.removeElement("Green");
        System.out.println("removeElement(Green): " + removed + ", Vector: " + colors);

        // removeElementAt(int index) - Legacy version of remove(index)
        colors.removeElementAt(1);
        System.out.println("After removeElementAt(1): " + colors);

        // removeAllElements() - Legacy version of clear()
        Vector<String> temp = new Vector<>(colors);
        temp.removeAllElements();
        System.out.println("After removeAllElements(): " + temp);

        System.out.println();

        // 4. VECTOR CAPACITY METHODS
        System.out.println("4. VECTOR CAPACITY METHODS:");

        Vector<Integer> numbers = new Vector<>(5, 3);

        // capacity() - Returns current capacity
        System.out.println("Initial capacity: " + numbers.capacity());

        // Add elements to trigger capacity increase
        for (int i = 0; i < 10; i++) {
            numbers.add(i);
        }
        System.out.println("After adding 10 elements, capacity: " + numbers.capacity());
        System.out.println("Size: " + numbers.size());

        // ensureCapacity(int minCapacity) - Ensures minimum capacity
        numbers.ensureCapacity(20);
        System.out.println("After ensureCapacity(20): " + numbers.capacity());

        // setSize(int newSize) - Sets the size (unique to Vector)
        Vector<String> sizeVector = new Vector<>();
        sizeVector.add("A");
        sizeVector.add("B");
        System.out.println("Before setSize: " + sizeVector + ", size: " + sizeVector.size());

        sizeVector.setSize(5); // Increases size, fills with null
        System.out.println("After setSize(5): " + sizeVector + ", size: " + sizeVector.size());

        sizeVector.setSize(1); // Decreases size, removes elements
        System.out.println("After setSize(1): " + sizeVector + ", size: " + sizeVector.size());

        // trimToSize() - Reduces capacity to size
        numbers.trimToSize();
        System.out.println("After trimToSize, capacity: " + numbers.capacity() + ", size: " + numbers.size());

        System.out.println();

        // 5. ENUMERATION (Legacy iteration)
        System.out.println("5. ENUMERATION (Legacy iteration):");

        Vector<String> enumVector = new Vector<>(Arrays.asList("First", "Second", "Third"));

        // elements() - Returns Enumeration (legacy Iterator)
        System.out.print("Enumeration: ");
        Enumeration<String> enumeration = enumVector.elements();
        while (enumeration.hasMoreElements()) {
            System.out.print(enumeration.nextElement() + " ");
        }
        System.out.println();

        System.out.println();

        // 6. SEARCH OPERATIONS
        System.out.println("6. SEARCH OPERATIONS:");

        Vector<String> searchVector = new Vector<>(Arrays.asList("Apple", "Banana", "Cherry", "Banana"));

        // Standard search methods work same as ArrayList
        System.out.println("Vector: " + searchVector);
        System.out.println("indexOf(Banana): " + searchVector.indexOf("Banana"));
        System.out.println("lastIndexOf(Banana): " + searchVector.lastIndexOf("Banana"));

        System.out.println();

        // 7. SYNCHRONIZATION DEMONSTRATION
        System.out.println("7. SYNCHRONIZATION:");

        Vector<Integer> syncVector = new Vector<>();

        // Vector methods are synchronized, making it thread-safe
        // This is a simple demonstration - in real applications, you'd use proper threading
        System.out.println("Vector is thread-safe (all methods are synchronized)");
        System.out.println("For better performance in single-threaded apps, use ArrayList");
        System.out.println("For thread-safety with better performance, consider Collections.synchronizedList()");

        // Alternative: Collections.synchronizedList with ArrayList
        List<String> syncList = Collections.synchronizedList(new ArrayList<>());
        System.out.println("Synchronized ArrayList alternative created");

        System.out.println("\n");
    }

    /**
     * PERFORMANCE AND USAGE COMPARISONS
     */
    public static void demonstrateComparisons() {
        System.out.println("=== PERFORMANCE AND USAGE COMPARISONS ===\n");

        System.out.println("WHEN TO USE EACH:\n");

        System.out.println("ARRAYLIST:");
        System.out.println("✓ Frequent random access by index");
        System.out.println("✓ More memory efficient");
        System.out.println("✓ Better cache performance");
        System.out.println("✗ Slow insertions/deletions in middle");
        System.out.println("✗ Not thread-safe");

        System.out.println("\nLINKEDLIST:");
        System.out.println("✓ Frequent insertions/deletions");
        System.out.println("✓ Implements Queue and Deque");
        System.out.println("✓ No capacity management needed");
        System.out.println("✗ Slow random access");
        System.out.println("✗ More memory overhead (node objects)");
        System.out.println("✗ Not thread-safe");

        System.out.println("\nVECTOR:");
        System.out.println("✓ Thread-safe operations");
        System.out.println("✓ Legacy code compatibility");
        System.out.println("✗ Slower due to synchronization overhead");
        System.out.println("✗ Generally superseded by ArrayList + synchronization");

        System.out.println();

        // Simple performance demonstration
        demonstratePerformanceDifferences();
    }

    /**
     * ADVANCED COLLECTION OPERATIONS
     * Demonstrates Java 8+ features and advanced operations
     */
    public static void demonstrateAdvancedOperations() {
        System.out.println("=== ADVANCED OPERATIONS (Java 8+) ===\n");

        // Create sample data
        ArrayList<Integer> numbers = new ArrayList<>(Arrays.asList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10));
        LinkedList<String> words = new LinkedList<>(Arrays.asList("apple", "banana", "cherry", "date", "elderberry"));
        Vector<Person> people = new Vector<>(Arrays.asList(
                new Person("Alice", 25),
                new Person("Bob", 30),
                new Person("Charlie", 35),
                new Person("Diana", 28)
        ));

        System.out.println("1. STREAM OPERATIONS:");

        // Filter, map, collect
        List<Integer> evenNumbers = numbers.stream()
                .filter(n -> n % 2 == 0)
                .collect(Collectors.toList());
        System.out.println("Even numbers: " + evenNumbers);

        List<String> upperCaseWords = words.stream()
                .map(String::toUpperCase)
                .collect(Collectors.toList());
        System.out.println("Uppercase words: " + upperCaseWords);

        // Complex operations
        double averageAge = people.stream()
                .mapToInt(Person::getAge)
                .average()
                .orElse(0.0);
        System.out.println("Average age: " + averageAge);

        System.out.println();

        // 2. LAMBDA OPERATIONS
        System.out.println("2. LAMBDA OPERATIONS:");

        // forEach with lambda
        System.out.print("Numbers doubled: ");
        numbers.forEach(n -> System.out.print((n * 2) + " "));
        System.out.println();

        // removeIf with lambda
        ArrayList<Integer> mutableNumbers = new ArrayList<>(numbers);
        mutableNumbers.removeIf(n -> n > 5);
        System.out.println("After removeIf (>5): " + mutableNumbers);

        // replaceAll with lambda
        LinkedList<String> mutableWords = new LinkedList<>(words);
        mutableWords.replaceAll(s -> s + "!");
        System.out.println("After replaceAll (add !): " + mutableWords);

        System.out.println();

        // 3. SORTING AND SEARCHING
        System.out.println("3. SORTING AND SEARCHING:");

        // Sort with Comparator
        ArrayList<String> sortWords = new ArrayList<>(words);
        sortWords.sort(String::compareToIgnoreCase);
        System.out.println("Sorted words: " + sortWords);

        // Sort custom objects
        Vector<Person> sortedPeople = new Vector<>(people);
        sortedPeople.sort(Comparator.comparing(Person::getAge));
        System.out.println("People sorted by age: " + sortedPeople);

        // Binary search (requires sorted list)
        Collections.sort(numbers);
        int index = Collections.binarySearch(numbers, 5);
        System.out.println("Binary search for 5: index " + index);

        System.out.println();

        // 4. UTILITY OPERATIONS
        System.out.println("4. UTILITY OPERATIONS:");

        // Reverse
        ArrayList<String> reverseWords = new ArrayList<>(words);
        Collections.reverse(reverseWords);
        System.out.println("Reversed words: " + reverseWords);

        // Shuffle
        ArrayList<Integer> shuffleNumbers = new ArrayList<>(numbers);
        Collections.shuffle(shuffleNumbers);
        System.out.println("Shuffled numbers: " + shuffleNumbers);

        // Rotate
        ArrayList<String> rotateWords = new ArrayList<>(words);
        Collections.rotate(rotateWords, 2);
        System.out.println("Rotated words (by 2): " + rotateWords);

        // Fill
        ArrayList<String> fillList = new ArrayList<>(Collections.nCopies(5, ""));
        Collections.fill(fillList, "FILLED");
        System.out.println("Filled list: " + fillList);

        // Min and Max
        System.out.println("Min number: " + Collections.min(numbers));
        System.out.println("Max number: " + Collections.max(numbers));

        // Frequency
        ArrayList<String> repeated = new ArrayList<>(Arrays.asList("a", "b", "a", "c", "a"));
        System.out.println("Frequency of 'a': " + Collections.frequency(repeated, "a"));

        System.out.println();

        // 5. THREAD-SAFE ALTERNATIVES
        System.out.println("5. THREAD-SAFE ALTERNATIVES:");

        // Synchronized wrappers
        List<String> syncArrayList = Collections.synchronizedList(new ArrayList<>());
        List<String> syncLinkedList = Collections.synchronizedList(new LinkedList<>());
        System.out.println("Created synchronized ArrayList and LinkedList wrappers");

        // Note: When iterating synchronized collections, manual synchronization needed
        synchronized (syncArrayList) {
            // Safe iteration block
            syncArrayList.add("Safe");
            syncArrayList.forEach(System.out::print);
        }
        System.out.println();

        // Concurrent alternatives (better performance)
        CopyOnWriteArrayList<String> concurrentList = new CopyOnWriteArrayList<>();
        concurrentList.add("Thread");
        concurrentList.add("Safe");
        System.out.println("CopyOnWriteArrayList: " + concurrentList);

        System.out.println();

        // 6. CUSTOM OPERATIONS
        System.out.println("6. CUSTOM OPERATIONS:");

        // Custom predicate
        Predicate<Integer> isEven = n -> n % 2 == 0;
        long evenCount = numbers.stream().filter(isEven).count();
        System.out.println("Count of even numbers: " + evenCount);

        // Custom comparator
        Comparator<String> byLength = Comparator.comparing(String::length);
        Optional<String> longestWord = words.stream().max(byLength);
        System.out.println("Longest word: " + longestWord.orElse("none"));

        // Partitioning
        Map<Boolean, List<Integer>> partitioned = numbers.stream()
                .collect(Collectors.partitioningBy(n -> n > 5));
        System.out.println("Numbers partitioned (>5): " + partitioned);

        // Grouping
        Map<Integer, List<String>> groupedByLength = words.stream()
                .collect(Collectors.groupingBy(String::length));
        System.out.println("Words grouped by length: " + groupedByLength);

        System.out.println();

        // 7. PARALLEL OPERATIONS
        System.out.println("7. PARALLEL OPERATIONS:");

        // Parallel stream processing
        List<Integer> largeList = new ArrayList<>();
        for (int i = 0; i < 1000; i++) {
            largeList.add(i);
        }

        long parallelSum = largeList.parallelStream()
                .filter(n -> n % 2 == 0)
                .mapToLong(n -> n * n)
                .sum();
        System.out.println("Parallel sum of squares of even numbers: " + parallelSum);

        System.out.println();

        // 8. IMMUTABLE OPERATIONS (Java 9+)
        System.out.println("8. IMMUTABLE OPERATIONS:");

        // Create immutable lists (Java 9+)
        try {
            // List.of creates immutable lists
            List<String> immutableList = List.of("A", "B", "C");
            System.out.println("Immutable list: " + immutableList);

            // Copying to immutable
            List<Integer> immutableNumbers = List.copyOf(numbers);
            System.out.println("Immutable copy: " + immutableNumbers.subList(0, 5) + "...");

        } catch (Exception e) {
            System.out.println("Note: List.of() requires Java 9+");
        }

        // Alternative for older Java versions
        List<String> unmodifiableList = Collections.unmodifiableList(new ArrayList<>(words));
        System.out.println("Unmodifiable list: " + unmodifiableList);

        System.out.println("\n");
    }

    /**
     * Performance demonstration with timing
     */
    private static void demonstratePerformanceDifferences() {
        System.out.println("PERFORMANCE DEMONSTRATION:\n");

        final int OPERATIONS = 10000;

        // Test random access performance
        System.out.println("Random Access Performance (10,000 operations):");

        // Prepare lists with data
        ArrayList<Integer> arrayList = new ArrayList<>();
        LinkedList<Integer> linkedList = new LinkedList<>();
        Vector<Integer> vector = new Vector<>();

        for (int i = 0; i < 1000; i++) {
            arrayList.add(i);
            linkedList.add(i);
            vector.add(i);
        }

        // ArrayList random access
        long start = System.nanoTime();
        for (int i = 0; i < OPERATIONS; i++) {
            arrayList.get(i % arrayList.size());
        }
        long arrayListTime = System.nanoTime() - start;

        // LinkedList random access
        start = System.nanoTime();
        for (int i = 0; i < OPERATIONS; i++) {
            linkedList.get(i % linkedList.size());
        }
        long linkedListTime = System.nanoTime() - start;

        // Vector random access
        start = System.nanoTime();
        for (int i = 0; i < OPERATIONS; i++) {
            vector.get(i % vector.size());
        }
        long vectorTime = System.nanoTime() - start;

        System.out.printf("ArrayList: %.2f ms\n", arrayListTime / 1_000_000.0);
        System.out.printf("LinkedList: %.2f ms\n", linkedListTime / 1_000_000.0);
        System.out.printf("Vector: %.2f ms\n", vectorTime / 1_000_000.0);

        System.out.println("\nInsertion at Beginning Performance (1,000 operations):");

        // Test insertion performance
        ArrayList<Integer> arrayList2 = new ArrayList<>();
        LinkedList<Integer> linkedList2 = new LinkedList<>();
        Vector<Integer> vector2 = new Vector<>();

        // ArrayList insertion at beginning
        start = System.nanoTime();
        for (int i = 0; i < 1000; i++) {
            arrayList2.add(0, i);
        }
        long arrayListInsertTime = System.nanoTime() - start;

        // LinkedList insertion at beginning
        start = System.nanoTime();
        for (int i = 0; i < 1000; i++) {
            linkedList2.add(0, i);
        }
        long linkedListInsertTime = System.nanoTime() - start;

        // Vector insertion at beginning
        start = System.nanoTime();
        for (int i = 0; i < 1000; i++) {
            vector2.add(0, i);
        }
        long vectorInsertTime = System.nanoTime() - start;

        System.out.printf("ArrayList: %.2f ms\n", arrayListInsertTime / 1_000_000.0);
        System.out.printf("LinkedList: %.2f ms\n", linkedListInsertTime / 1_000_000.0);
        System.out.printf("Vector: %.2f ms\n", vectorInsertTime / 1_000_000.0);

        System.out.println();
    }

    /**
     * Helper class for demonstration
     */
    static class Person {
        private String name;
        private int age;

        public Person(String name, int age) {
            this.name = name;
            this.age = age;
        }

        public String getName() {
            return name;
        }

        public int getAge() {
            return age;
        }

        @Override
        public String toString() {
            return name + "(" + age + ")";
        }

        @Override
        public boolean equals(Object obj) {
            if (this == obj) return true;
            if (obj == null || getClass() != obj.getClass()) return false;
            Person person = (Person) obj;
            return age == person.age && Objects.equals(name, person.name);
        }

        @Override
        public int hashCode() {
            return Objects.hash(name, age);
        }
    }
}

/**
 * ADDITIONAL IMPORTANT CONCEPTS AND BEST PRACTICES:
 *
 * 1. MEMORY CONSIDERATIONS:
 *    - ArrayList: Continuous memory, good cache locality
 *    - LinkedList: Scattered memory, each node has object overhead
 *    - Vector: Same as ArrayList but with synchronization overhead
 *
 * 2. THREAD SAFETY:
 *    - ArrayList & LinkedList: NOT thread-safe
 *    - Vector: Thread-safe but with performance cost
 *    - Use Collections.synchronizedList() or concurrent collections for better performance
 *
 * 3. WHEN TO USE WHICH:
 *    - ArrayList: Default choice for most use cases
 *    - LinkedList: When frequent insertions/deletions in middle, or when using as Queue/Deque
 *    - Vector: Legacy code or when simple thread-safety is needed
 *
 * 4. BEST PRACTICES:
 *    - Prefer ArrayList over Vector for new code
 *    - Use generics to ensure type safety
 *    - Initialize with appropriate capacity if size is known
 *    - Use enhanced for-loop for simple iteration
 *    - Use ListIterator for bidirectional iteration with modifications
 *    - Consider CopyOnWriteArrayList for concurrent read-heavy scenarios
 *
 * 5. COMMON OPERATIONS TIME COMPLEXITY:
 *
 *    ArrayList:
 *    - get(index): O(1)
 *    - add(element): O(1) amortized, O(n) worst case
 *    - add(index, element): O(n)
 *    - remove(index): O(n)
 *    - contains(element): O(n)
 *
 *    LinkedList:
 *    - get(index): O(n)
 *    - add(element): O(1)
 *    - add(index, element): O(n) for random index, O(1) for ends
 *    - remove(index): O(n) for random index, O(1) for ends
 *    - contains(element): O(n)
 *
 *    Vector:
 *    - Same as ArrayList but with synchronization overhead
 *
 * 6. MEMORY USAGE:
 *    - ArrayList: ~4 bytes per element + array overhead
 *    - LinkedList: ~24 bytes per element (object overhead + pointers)
 *    - Vector: Same as ArrayList + synchronization overhead
 *
 * 7. FAIL-FAST ITERATORS:
 *    - All three use fail-fast iterators
 *    - Throw ConcurrentModificationException if modified during iteration
 *    - Use Iterator.remove() for safe removal during iteration
 *
 * 8. SERIALIZATION:
 *    - All three implement Serializable
 *    - ArrayList and Vector serialize the array
 *    - LinkedList serializes each node
 *
 * This comprehensive guide covers virtually all aspects of these three
 * fundamental Java collections. Practice with these examples to master
 * collection handling in Java!
 */