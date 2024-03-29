/*
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Notes:
You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
*/

public class Stack {
    // Push element x onto stack.
    Queue Q = new Queue();
    
    int last = 0;
    public void Push(int x) {
        Q.Enqueue(x);
        for(int i = 0; i<Q.Count - 1; i++){
           Q.Enqueue(Q.Dequeue());
        }

    }

    // Removes the element on top of the stack.
    public void Pop() {
       Q.Dequeue();
    }

    // Get the top element.
    public int Top() {
       return (int)Q.Peek();
    }

    // Return whether the stack is empty.
    public bool Empty() {
        return Q.Count == 0;
    }
}