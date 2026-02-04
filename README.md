###🚀 Balanced Parentheses Checker
I have added balance_parentheses.cpp to demonstrate a practical application of the Linked List-based Stack.

###📝 Problem Description
The goal is to determine if a string of brackets—( ), [ ], and { }—is mathematically "balanced." A string is balanced if:

Every opening bracket has a corresponding closing bracket of the same type.

Brackets are closed in the correct order (Last-In, First-Out).

🛠️ Implementation Details
This program utilizes the Stack class logic to track opening brackets:

Push: When an opening bracket (, [, or { is encountered, it is added to the stack.

Pop: When a closing bracket is encountered, the program checks the stackTop():

If they match (e.g., ( and )), the top is popped.

If they don't match or the stack is empty, the string is unbalanced.

Final Check: If the stack is empty after scanning the entire string, the input is balanced.

> Click the links below to jump directly to the source code.
> [Balance_Parantheses.cpp] (./Balance_Parantheses.cpp)
