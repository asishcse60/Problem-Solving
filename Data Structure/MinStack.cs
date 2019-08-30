public class MinStack {
    Stack<int>stack = new Stack<int>();
    Stack<int>minStack = new Stack<int>();
    minStack.Push(int.MaxValue);
    public void Push(int x) {
        stack.Push(x);
        if(x<=minStack.Peek())
          minStack.Push(x);
          
    }

    public void Pop() {
        int pNum = stack.Pop();
        if(pNum == minStack.Peek())
         minStack.Pop();
    }

    public int Top() {
        return stack.Peek();
    }

    public int GetMin() {
        return minStack.Peek();
    }
}