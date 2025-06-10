Here, I implemented stack using array and linked list.

stack.h file is used as the blueprint. It is used for abstraction only. every function here is pure virtual. SO, those are overloaded in liststack.cpp and arraystack.cpp

For arraystack, I just kept tracking the size of the arrat and resized when needed. I added the new pushed members at the last of the array and updated size and resized if needed.
Push is easy for array. just added it at the end. for pop we just decreased the size and resized if needed.

For liststack, I used linked list to implement the stack. I added the pushed item at the head of the linked list and popped from here. It gives us O(1) time complexity for that.
I just updated the head of the list for push and pop and other size related operations are done by keeping a size variable.

For test.cpp, I just pushed and popped items in the stack and checked if it is working correctly. Then compiled all files together to check if it works fine.

-2305004