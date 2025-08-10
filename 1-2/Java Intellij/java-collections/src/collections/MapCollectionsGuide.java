package collections;

import java.util.*;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.ConcurrentMap;

/**
 * COMPLETE GUIDE TO HASHMAP, HASHTABLE, AND CONCURRENTHASHMAP
 *
 * This comprehensive guide covers all three map implementations with:
 * - All available methods and their usage
 * - Key differences and when to use each
 * - Thread safety considerations
 * - Performance characteristics
 * - Best practices and common pitfalls
 */
public class MapCollectionsGuide {

    public static void main(String[] args) {
        System.out.println("=== COMPLETE MAP COLLECTIONS GUIDE ===\n");

        // Demonstrate each map type
        demonstrateHashMap();
        demonstrateHashtable();
        demonstrateConcurrentHashMap();
        demonstrateDifferences();
        demonstrateCollectionsOperations();
    }

    /**
     * HASHMAP COMPREHENSIVE DEMONSTRATION
     *
     * HashMap is:
     * - NOT thread-safe (fastest for single-threaded operations)
     * - Allows one null key and multiple null values
     * - Uses array + linked list/red-black tree structure
     * - O(1) average time complexity for basic operations
     * - Insertion order is NOT maintained
     */
    public static void demonstrateHashMap() {
        System.out.println("========== HASHMAP DEMONSTRATION ==========");

        // 1. CREATING HASHMAPS - Different constructors
        HashMap<String, Integer> map1 = new HashMap<>(); // Default capacity 16, load factor 0.75
        HashMap<String, Integer> map2 = new HashMap<>(32); // Custom initial capacity
        HashMap<String, Integer> map3 = new HashMap<>(32, 0.8f); // Custom capacity and load factor
        HashMap<String, Integer> map4 = new HashMap<>(map1); // Copy constructor

        // Map from another map type
        Map<String, Integer> sourceMap = new TreeMap<>();
        HashMap<String, Integer> map5 = new HashMap<>(sourceMap);

        System.out.println("Created HashMap with default settings");

        // 2. BASIC OPERATIONS - put, get, remove

        // put(K key, V value) - Returns previous value or null
        Integer previousValue = map1.put("apple", 10);
        System.out.println("Put 'apple':10, previous value: " + previousValue); // null

        previousValue = map1.put("apple", 15); // Overwrites existing
        System.out.println("Put 'apple':15, previous value: " + previousValue); // 10

        map1.put("banana", 20);
        map1.put("cherry", null); // Null values are allowed
        map1.put(null, 100); // Null key is allowed (only one)

        // get(Object key) - Returns value or null if not found
        Integer appleValue = map1.get("apple");
        System.out.println("Value for 'apple': " + appleValue); // 15

        Integer unknownValue = map1.get("unknown");
        System.out.println("Value for 'unknown': " + unknownValue); // null

        // getOrDefault(Object key, V defaultValue) - Returns default if key not found
        Integer orangeValue = map1.getOrDefault("orange", 0);
        System.out.println("Value for 'orange' with default: " + orangeValue); // 0

        // 3. CHECKING EXISTENCE

        // containsKey(Object key) - Returns true if key exists
        boolean hasApple = map1.containsKey("apple");
        System.out.println("Contains key 'apple': " + hasApple); // true

        // containsValue(Object value) - Returns true if value exists (slower O(n))
        boolean hasValue20 = map1.containsValue(20);
        System.out.println("Contains value 20: " + hasValue20); // true

        // isEmpty() - Returns true if map has no entries
        boolean empty = map1.isEmpty();
        System.out.println("Map is empty: " + empty); // false

        // size() - Returns number of key-value pairs
        int size = map1.size();
        System.out.println("Map size: " + size); // 4

        // 4. CONDITIONAL OPERATIONS (Java 8+)

        // putIfAbsent(K key, V value) - Only puts if key doesn't exist
        Integer result = map1.putIfAbsent("grape", 25);
        System.out.println("PutIfAbsent 'grape':25, previous: " + result); // null

        result = map1.putIfAbsent("grape", 30); // Won't overwrite
        System.out.println("PutIfAbsent 'grape':30, previous: " + result); // 25

        // replace(K key, V value) - Only replaces if key exists
        Integer replaced = map1.replace("grape", 35);
        System.out.println("Replace 'grape' with 35, previous: " + replaced); // 25

        Integer notReplaced = map1.replace("kiwi", 40); // Key doesn't exist
        System.out.println("Replace 'kiwi' with 40, previous: " + notReplaced); // null

        // replace(K key, V oldValue, V newValue) - Only replaces if current value matches
        boolean replaceSuccess = map1.replace("apple", 15, 18);
        System.out.println("Replace 'apple' 15->18 success: " + replaceSuccess); // true

        boolean replaceFailure = map1.replace("apple", 15, 20); // Current value is 18, not 15
        System.out.println("Replace 'apple' 15->20 success: " + replaceFailure); // false

        // 5. REMOVAL OPERATIONS

        // remove(Object key) - Removes and returns value
        Integer removedValue = map1.remove("cherry");
        System.out.println("Removed 'cherry', value was: " + removedValue); // null

        // remove(Object key, Object value) - Only removes if value matches
        boolean removeSuccess = map1.remove("banana", 20);
        System.out.println("Remove 'banana':20 success: " + removeSuccess); // true

        boolean removeFailure = map1.remove("apple", 15); // Value is 18, not 15
        System.out.println("Remove 'apple':15 success: " + removeFailure); // false

        // 6. COMPUTE OPERATIONS (Java 8+)

        // compute(K key, BiFunction) - Computes new value for key
        map1.compute("apple", (key, value) -> {
            System.out.println("Computing for key: " + key + ", current value: " + value);
            return value == null ? 1 : value * 2; // Double existing value or set to 1
        });

        // computeIfAbsent(K key, Function) - Computes only if key absent
        map1.computeIfAbsent("mango", key -> {
            System.out.println("Computing absent key: " + key);
            return key.length() * 5; // Value based on key length
        });

        // computeIfPresent(K key, BiFunction) - Computes only if key present
        map1.computeIfPresent("grape", (key, value) -> {
            System.out.println("Computing present key: " + key + ", value: " + value);
            return value + 10; // Add 10 to existing value
        });

        // 7. MERGE OPERATION (Java 8+)

        // merge(K key, V value, BiFunction) - Merges value with existing or puts if absent
        map1.merge("apple", 5, (existingValue, newValue) -> {
            System.out.println("Merging apple: existing=" + existingValue + ", new=" + newValue);
            return existingValue + newValue; // Sum existing and new values
        });

        map1.merge("pear", 30, (existingValue, newValue) -> {
            System.out.println("Merging pear: existing=" + existingValue + ", new=" + newValue);
            return existingValue + newValue; // Key doesn't exist, so just puts 30
        });

        // 8. VIEWING COLLECTIONS

        // keySet() - Returns Set view of keys (backed by map)
        Set<String> keys = map1.keySet();
        System.out.println("Keys: " + keys);
        // Modifying this set affects the original map

        // values() - Returns Collection view of values (backed by map)
        Collection<Integer> values = map1.values();
        System.out.println("Values: " + values);
        // Can contain duplicates, modifications affect original map

        // entrySet() - Returns Set view of key-value pairs (backed by map)
        Set<Map.Entry<String, Integer>> entries = map1.entrySet();
        System.out.println("Entries: " + entries);
        // Most efficient way to iterate over map

        // 9. ITERATION METHODS

        System.out.println("\n--- Iteration Methods ---");

        // Traditional iteration using entrySet (most efficient)
        for (Map.Entry<String, Integer> entry : map1.entrySet()) {
            System.out.println("Traditional: " + entry.getKey() + " = " + entry.getValue());
        }

        // Java 8 forEach with lambda
        map1.forEach((key, value) -> {
            System.out.println("Lambda forEach: " + key + " = " + value);
        });

        // Stream operations
        map1.entrySet().stream()
                .filter(entry -> entry.getValue() != null && entry.getValue() > 30)
                .forEach(entry -> System.out.println("Stream filtered: " + entry));

        // 10. CLONING AND COPYING

        // clone() - Creates shallow copy (HashMap specific method)
        HashMap<String, Integer> clonedMap = (HashMap<String, Integer>) map1.clone();
        System.out.println("Cloned map size: " + clonedMap.size());

        // clear() - Removes all entries
        HashMap<String, Integer> tempMap = new HashMap<>(map1);
        tempMap.clear();
        System.out.println("Cleared map size: " + tempMap.size()); // 0

        // putAll(Map) - Copies all entries from another map
        tempMap.putAll(map1);
        System.out.println("After putAll, size: " + tempMap.size());

        System.out.println("Final HashMap: " + map1);
        System.out.println();
    }

    /**
     * HASHTABLE COMPREHENSIVE DEMONSTRATION
     *
     * Hashtable is:
     * - Thread-safe (synchronized methods)
     * - Does NOT allow null keys or null values
     * - Legacy class from Java 1.0
     * - Slower than HashMap due to synchronization overhead
     * - Uses same hash table structure as HashMap
     * - Enumeration support (legacy iteration)
     */
    public static void demonstrateHashtable() {
        System.out.println("========== HASHTABLE DEMONSTRATION ==========");

        // 1. CREATING HASHTABLES
        Hashtable<String, Integer> table1 = new Hashtable<>(); // Default capacity 11
        Hashtable<String, Integer> table2 = new Hashtable<>(20); // Custom capacity
        Hashtable<String, Integer> table3 = new Hashtable<>(20, 0.8f); // Custom capacity and load factor

        System.out.println("Created Hashtable with default settings");

        // 2. BASIC OPERATIONS (Same as HashMap but synchronized)

        // put(K key, V value) - Thread-safe, no null keys/values allowed
        try {
            table1.put("apple", 10);
            table1.put("banana", 20);
            // table1.put(null, 30); // Would throw NullPointerException
            // table1.put("cherry", null); // Would throw NullPointerException
            System.out.println("Added entries to Hashtable");
        } catch (NullPointerException e) {
            System.out.println("Cannot add null keys or values to Hashtable");
        }

        // All HashMap methods work the same way but are synchronized
        Integer appleValue = table1.get("apple");
        System.out.println("Apple value: " + appleValue);

        boolean hasApple = table1.containsKey("apple");
        System.out.println("Contains apple: " + hasApple);

        // 3. HASHTABLE-SPECIFIC METHODS (Legacy)

        // elements() - Returns Enumeration of values (legacy)
        Enumeration<Integer> valueEnum = table1.elements();
        System.out.print("Values via Enumeration: ");
        while (valueEnum.hasMoreElements()) {
            System.out.print(valueEnum.nextElement() + " ");
        }
        System.out.println();

        // keys() - Returns Enumeration of keys (legacy)
        Enumeration<String> keyEnum = table1.keys();
        System.out.print("Keys via Enumeration: ");
        while (keyEnum.hasMoreElements()) {
            System.out.print(keyEnum.nextElement() + " ");
        }
        System.out.println();

        // 4. THREAD SAFETY DEMONSTRATION
        table1.put("thread1", 100);
        table1.put("thread2", 200);
        table1.put("thread3", 300);

        // All operations are automatically synchronized
        // Multiple threads can safely access this Hashtable simultaneously

        System.out.println("Hashtable contents: " + table1);
        System.out.println();
    }

    /**
     * CONCURRENTHASHMAP COMPREHENSIVE DEMONSTRATION
     *
     * ConcurrentHashMap is:
     * - Thread-safe with better performance than Hashtable
     * - Uses segment-based locking (Java 7) or CAS operations (Java 8+)
     * - Does NOT allow null keys or null values
     * - Provides additional atomic operations
     * - Better scalability for concurrent access
     * - Supports parallel operations
     */
    public static void demonstrateConcurrentHashMap() {
        System.out.println("========== CONCURRENTHASHMAP DEMONSTRATION ==========");

        // 1. CREATING CONCURRENTHASHMAPS
        ConcurrentHashMap<String, Integer> cmap1 = new ConcurrentHashMap<>();
        ConcurrentHashMap<String, Integer> cmap2 = new ConcurrentHashMap<>(16); // Initial capacity
        ConcurrentHashMap<String, Integer> cmap3 = new ConcurrentHashMap<>(16, 0.75f); // Capacity and load factor
        ConcurrentHashMap<String, Integer> cmap4 = new ConcurrentHashMap<>(16, 0.75f, 4); // Include concurrency level

        System.out.println("Created ConcurrentHashMap");

        // 2. BASIC OPERATIONS (Thread-safe, high performance)
        cmap1.put("apple", 10);
        cmap1.put("banana", 20);
        cmap1.put("cherry", 30);
        // cmap1.put(null, 40); // NullPointerException
        // cmap1.put("date", null); // NullPointerException

        System.out.println("Added entries to ConcurrentHashMap");

        // 3. CONCURRENTHASHMAP-SPECIFIC ATOMIC OPERATIONS

        // putIfAbsent - Atomic operation
        Integer previous = cmap1.putIfAbsent("grape", 40);
        System.out.println("PutIfAbsent grape:40, previous: " + previous); // null

        // replace operations - Atomic
        boolean replaced = cmap1.replace("apple", 10, 15);
        System.out.println("Replace apple 10->15: " + replaced); // true

        // remove operations - Atomic
        boolean removed = cmap1.remove("banana", 20);
        System.out.println("Remove banana:20: " + removed); // true

        // 4. SEARCH OPERATIONS (Java 8+)

        // search(parallelismThreshold, BiFunction) - Parallel search
        String foundKey = cmap1.search(1, (key, value) -> {
            return value != null && value > 25 ? key : null;
        });
        System.out.println("Found key with value > 25: " + foundKey);

        // searchKeys(parallelismThreshold, Function)
        String foundKeyByName = cmap1.searchKeys(1, key -> {
            return key != null && key.startsWith("c") ? key : null;
        });
        System.out.println("Found key starting with 'c': " + foundKeyByName);

        // searchValues(parallelismThreshold, Function)
        Integer foundValue = cmap1.searchValues(1, value -> {
            return value != null && value % 10 == 0 ? value : null;
        });
        System.out.println("Found value divisible by 10: " + foundValue);

        // 5. REDUCTION OPERATIONS (Java 8+)

        cmap1.put("date", 50);
        cmap1.put("elderberry", 60);

        // reduce(parallelismThreshold, BiFunction, BinaryOperator)
        Integer sum = cmap1.reduce(1, (key, value) -> value, (v1, v2) -> v1 + v2);
        System.out.println("Sum of all values: " + sum);

        // reduceKeys(parallelismThreshold, Function, BinaryOperator)
        String longestKey = cmap1.reduceKeys(1, key -> key, (k1, k2) ->
                k1.length() > k2.length() ? k1 : k2);
        System.out.println("Longest key: " + longestKey);

        // reduceValues(parallelismThreshold, Function, BinaryOperator)
        Integer maxValue = cmap1.reduceValues(1, value -> value, Integer::max);
        System.out.println("Maximum value: " + maxValue);

        // 6. FOREACH OPERATIONS (Java 8+)

        // forEach(parallelismThreshold, BiConsumer) - Parallel iteration
        System.out.println("Parallel forEach:");
        cmap1.forEach(1, (key, value) -> {
            System.out.println("  " + key + " = " + value + " [Thread: " +
                    Thread.currentThread().getName() + "]");
        });

        // forEachKey(parallelismThreshold, Consumer)
        System.out.println("Keys only:");
        cmap1.forEachKey(1, key -> System.out.println("  Key: " + key));

        // forEachValue(parallelismThreshold, Consumer)
        System.out.println("Values only:");
        cmap1.forEachValue(1, value -> System.out.println("  Value: " + value));

        // 7. MAPPING OPERATIONS (Java 8+)

        // mappingCount() - Returns number of mappings (may be faster than size())
        long mappingCount = cmap1.mappingCount();
        System.out.println("Mapping count: " + mappingCount);

        // 8. CONCURRENTMAP INTERFACE METHODS

        // Cast to ConcurrentMap to access interface methods
        ConcurrentMap<String, Integer> concurrentView = cmap1;

        // Additional atomic operations available through ConcurrentMap interface
        Integer computedValue = concurrentView.compute("fig", (key, value) -> {
            return value == null ? 70 : value * 2;
        });
        System.out.println("Computed value for fig: " + computedValue);

        System.out.println("Final ConcurrentHashMap: " + cmap1);
        System.out.println();
    }

    /**
     * COMPARISON OF ALL THREE MAP TYPES
     * Demonstrates key differences in behavior, performance, and thread safety
     */
    public static void demonstrateDifferences() {
        System.out.println("========== KEY DIFFERENCES COMPARISON ==========");

        // 1. NULL HANDLING
        System.out.println("--- Null Handling ---");

        HashMap<String, Integer> hashMap = new HashMap<>();
        Hashtable<String, Integer> hashtable = new Hashtable<>();
        ConcurrentHashMap<String, Integer> concurrentMap = new ConcurrentHashMap<>();

        // HashMap allows nulls
        hashMap.put(null, null);
        hashMap.put("key", null);
        System.out.println("HashMap with nulls: " + hashMap);

        // Hashtable and ConcurrentHashMap don't allow nulls
        try {
            hashtable.put(null, 1);
        } catch (NullPointerException e) {
            System.out.println("Hashtable null key rejected: " + e.getMessage());
        }

        try {
            concurrentMap.put("key", null);
        } catch (NullPointerException e) {
            System.out.println("ConcurrentHashMap null value rejected");
        }

        // 2. THREAD SAFETY
        System.out.println("\n--- Thread Safety ---");
        System.out.println("HashMap: NOT thread-safe (fastest single-threaded)");
        System.out.println("Hashtable: Thread-safe (synchronized methods, slower)");
        System.out.println("ConcurrentHashMap: Thread-safe (optimized for concurrency)");

        // 3. PERFORMANCE CHARACTERISTICS
        System.out.println("\n--- Performance Characteristics ---");

        long startTime, endTime;
        int iterations = 100000;

        // HashMap performance (single-threaded)
        HashMap<Integer, String> perfHashMap = new HashMap<>();
        startTime = System.nanoTime();
        for (int i = 0; i < iterations; i++) {
            perfHashMap.put(i, "value" + i);
        }
        endTime = System.nanoTime();
        System.out.println("HashMap put operations: " + (endTime - startTime) / 1000000 + "ms");

        // Hashtable performance
        Hashtable<Integer, String> perfHashtable = new Hashtable<>();
        startTime = System.nanoTime();
        for (int i = 0; i < iterations; i++) {
            perfHashtable.put(i, "value" + i);
        }
        endTime = System.nanoTime();
        System.out.println("Hashtable put operations: " + (endTime - startTime) / 1000000 + "ms");

        // ConcurrentHashMap performance
        ConcurrentHashMap<Integer, String> perfConcurrentMap = new ConcurrentHashMap<>();
        startTime = System.nanoTime();
        for (int i = 0; i < iterations; i++) {
            perfConcurrentMap.put(i, "value" + i);
        }
        endTime = System.nanoTime();
        System.out.println("ConcurrentHashMap put operations: " + (endTime - startTime) / 1000000 + "ms");

        // 4. INHERITANCE AND INTERFACES
        System.out.println("\n--- Class Hierarchy ---");
        System.out.println("HashMap extends AbstractMap implements Map, Cloneable, Serializable");
        System.out.println("Hashtable extends Dictionary implements Map, Cloneable, Serializable");
        System.out.println("ConcurrentHashMap extends AbstractMap implements ConcurrentMap, Serializable");

        // 5. WHEN TO USE WHICH
        System.out.println("\n--- When to Use Each ---");
        System.out.println("Use HashMap when:");
        System.out.println("  - Single-threaded environment");
        System.out.println("  - Maximum performance needed");
        System.out.println("  - Null keys/values are required");
        System.out.println();
        System.out.println("Use Hashtable when:");
        System.out.println("  - Legacy code compatibility needed");
        System.out.println("  - Simple thread safety required");
        System.out.println("  - Working with older Java versions");
        System.out.println();
        System.out.println("Use ConcurrentHashMap when:");
        System.out.println("  - High-concurrency environment");
        System.out.println("  - Thread safety with good performance");
        System.out.println("  - Parallel processing capabilities needed");
        System.out.println();
    }

    /**
     * COLLECTIONS UTILITY OPERATIONS
     * Demonstrates how to use Collections class with Map implementations
     */
    public static void demonstrateCollectionsOperations() {
        System.out.println("========== COLLECTIONS UTILITY OPERATIONS ==========");

        HashMap<String, Integer> map = new HashMap<>();
        map.put("apple", 10);
        map.put("banana", 5);
        map.put("cherry", 15);
        map.put("date", 8);

        // 1. SYNCHRONIZED WRAPPERS

        // Collections.synchronizedMap() - Makes HashMap thread-safe
        Map<String, Integer> syncMap = Collections.synchronizedMap(new HashMap<>(map));
        System.out.println("Created synchronized HashMap wrapper");

        // Important: Manual synchronization needed for iteration
        synchronized (syncMap) {
            for (Map.Entry<String, Integer> entry : syncMap.entrySet()) {
                System.out.println("Sync map entry: " + entry.getKey() + " = " + entry.getValue());
            }
        }

        // 2. UNMODIFIABLE WRAPPERS

        // Collections.unmodifiableMap() - Creates read-only view
        Map<String, Integer> unmodifiableMap = Collections.unmodifiableMap(map);
        System.out.println("Created unmodifiable map: " + unmodifiableMap);

        try {
            unmodifiableMap.put("elderberry", 20); // Will throw UnsupportedOperationException
        } catch (UnsupportedOperationException e) {
            System.out.println("Cannot modify unmodifiable map");
        }

        // 3. EMPTY AND SINGLETON MAPS

        // Collections.emptyMap() - Immutable empty map
        Map<String, Integer> emptyMap = Collections.emptyMap();
        System.out.println("Empty map size: " + emptyMap.size());

        // Collections.singletonMap() - Immutable single-entry map
        Map<String, Integer> singletonMap = Collections.singletonMap("single", 42);
        System.out.println("Singleton map: " + singletonMap);

        // 4. OPERATIONS ON MAP VIEWS

        // Working with keySet
        Set<String> keys = map.keySet();
        System.out.println("Original keys: " + keys);

        // Remove from keySet affects original map
        keys.remove("banana");
        System.out.println("After removing from keySet: " + map);

        // Collections operations on keys
        List<String> keyList = new ArrayList<>(map.keySet());
        Collections.sort(keyList); // Sort keys alphabetically
        System.out.println("Sorted keys: " + keyList);

        Collections.reverse(keyList); // Reverse the order
        System.out.println("Reversed keys: " + keyList);

        // Working with values
        Collection<Integer> values = map.values();
        System.out.println("Values: " + values);

        // Find min/max values
        Integer minValue = Collections.min(values);
        Integer maxValue = Collections.max(values);
        System.out.println("Min value: " + minValue + ", Max value: " + maxValue);

        // 5. FREQUENCY AND SEARCHING

        List<Integer> valuesList = new ArrayList<>(values);
        int frequency = Collections.frequency(valuesList, 15);
        System.out.println("Frequency of value 15: " + frequency);

        // Binary search (requires sorted collection)
        Collections.sort(valuesList);
        int index = Collections.binarySearch(valuesList, 10);
        System.out.println("Binary search for value 10, index: " + index);

        // 6. CREATING DIFFERENT MAP TYPES FROM EXISTING DATA

        // Convert to TreeMap (sorted)
        TreeMap<String, Integer> sortedMap = new TreeMap<>(map);
        System.out.println("TreeMap (sorted by keys): " + sortedMap);

        // Convert to LinkedHashMap (insertion order)
        LinkedHashMap<String, Integer> linkedMap = new LinkedHashMap<>(map);
        System.out.println("LinkedHashMap: " + linkedMap);

        // 7. STREAM OPERATIONS (Java 8+)

        System.out.println("\n--- Stream Operations ---");

        // Filter entries
        map.entrySet().stream()
                .filter(entry -> entry.getValue() > 10)
                .forEach(entry -> System.out.println("Value > 10: " + entry));

        // Collect to different map type
        Map<String, String> transformedMap = map.entrySet().stream()
                .collect(HashMap::new, // Supplier
                        (mapArg, entry) -> mapArg.put(entry.getKey().toUpperCase(),
                                "Value: " + entry.getValue()), // Accumulator
                        (map1, map2) -> map1.putAll(map2)); // Combiner
        System.out.println("Transformed map: " + transformedMap);

        // Group by value ranges
        Map<String, List<Map.Entry<String, Integer>>> groupedByRange = map.entrySet().stream()
                .collect(java.util.stream.Collectors.groupingBy(entry -> {
                    int value = entry.getValue();
                    if (value < 10) return "Low";
                    else if (value < 15) return "Medium";
                    else return "High";
                }));
        System.out.println("Grouped by value ranges: " + groupedByRange);

        System.out.println("\n=== GUIDE COMPLETE ===");
        System.out.println("This guide covered all major operations and differences between");
        System.out.println("HashMap, Hashtable, and ConcurrentHashMap, plus Collections utilities.");
    }
}