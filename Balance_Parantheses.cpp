#include <iostream>
using namespace std;

class nodeStack 
{
    public:
        char data;
        nodeStack *next;
};

class Stack 
{
    private:
        nodeStack *top;
    public:
        Stack() { top = NULL; }
        void push(char);
        void pop();
        char stackTop();
        bool isEmpty(); 
        void displayStack();  // New method to show stack contents to achieve 2(a,ii)
};

bool Stack::isEmpty() 
{
    return (top == NULL);
}

void Stack::push(char newitem) 
{
    nodeStack *newNode = new nodeStack;
    if (newNode == NULL) {
        cout << "Cannot allocate memory..." << endl;
    }
    else {
        newNode->data = newitem;
        newNode->next = top;
        top = newNode;
        cout << "Item pushed to stack: " << newitem << endl; // Track push operation
    }
}

void Stack::pop() 
{
    nodeStack *delnode;
    if (isEmpty()) {
        cout << "Sorry, Cannot pop item drom stack. Stack is still empty!" << endl;
    } 
    else {
        delnode = top;
        cout << "Item to be popped from stack is: " << stackTop()<<endl;  //Track pop operation
        top = delnode->next;  
        delete(delnode);
    }
}

char Stack::stackTop() 
{
    if (isEmpty()) {
        cout << "Sorry, stack is still empty" << endl;
        return '\0'; // Return null character if stack is empty
    } else {
        return top->data;
    }
}

// Display stack contents (top to bottom)
void Stack::displayStack() 
{
    int count = 0;
    string stackContents = "\"";
    nodeStack *current = top;
    while (current != NULL) {
        stackContents += current->data;
        count++;
        current = current->next;
    }
    
    stackContents += "\"";
    
    if (count == 0) {
        cout << "Stack: [EMPTY] (count=0)" << endl;
    } else {
        cout << "Stack: [" << stackContents << "] (count=" << count << ")" << endl;
    }
}

bool isOpeningBracket(char ch) {
    return ch == '(' || ch == '[' || ch == '{';
}

bool isClosingBracket(char ch) {
    return ch == ')' || ch == ']' || ch == '}';
}

bool isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '[' && closing == ']') ||
           (opening == '{' && closing == '}');
}

int main()
{
    Stack aStack;
    char ch;
    bool isBalanced = true;
    
    cout << "Enter a string of parentheses: ";
    while (cin.get(ch) && ch != '\n' && isBalanced) {
        // Show current character being processed
        cout << "\n--- Processing: '" << ch << "' ---" << endl;
        
        // add the character to the stack 
        if (isOpeningBracket(ch)) {
            aStack.push(ch);
            aStack.displayStack();
        }
        // if the closing parenthesis with no match
        else if (isClosingBracket(ch)) {
            if (aStack.isEmpty()) {
                isBalanced = false;
                aStack.displayStack();
                cout << "Unmatched detected!" << endl;
                break; // Exit the loop if unbalanced
            }
            // Check if the top of the stack matches the current closing parenthesis
            // If it does, pop the stack; if not, report unbalanced
            else if (isMatchingPair(aStack.stackTop(), ch)) {
                aStack.pop();
                aStack.displayStack();
            }
            else {
                isBalanced = false;
                cout << "Mismatched brackets! Expected '" << (aStack.stackTop() == '(' ? ')' : aStack.stackTop() == '[' ? ']' : '}') << "' but found '" << ch << "'" << endl;
                break; // Exit the loop if unbalanced
            }
        }
    }

    // After processing all parenthesis, check if the stack is empty
    // If it is empty, all opening parentheses were matched; if not, report unbalanced
    cout << "\n--- Final Check ---" << endl;
    if (isBalanced && aStack.isEmpty()) {
        cout << "Final Result: Balanced parentheses!" << endl;
    } else {
        cout << "Final Result:Unbalanced parentheses!" << endl;
        if (!aStack.isEmpty()) {
            cout << "REASON: " << aStack.stackTop() << " unmatched parentheses remain" << endl;
        }
    }
    aStack.displayStack();
    return 0;
}