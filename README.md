# Theory of Computing Code Repository

Welcome to the Theory of Computing Code Repository! This GitHub repository hosts a collection of code implementations related to theoretical computer science concepts. Below is a brief overview of the codes available:

## 1. DFA with Specific Tuples

This code demonstrates the construction of Deterministic Finite Automata (DFA) using specific tuples. DFAs are fundamental in understanding regular languages and pattern matching.

### Explanation
  This code is a C++ implementation of a finite automaton that processes a given input string consisting of only 0s and 1s. 
  The automaton has three states: A, B, and C. It starts in state A and transitions between states based on the input 
  characters according to the following rules:
  
  1. If the current state is A and the input character is 0, it stays in state A.
  2. If the current state is A and the input character is 1, it transitions to state B.
  3. If the current state is B and the input character is 0, it transitions to state A.
  4. If the current state is B and the input character is 1, it transitions to state C.
  5. If the current state is C and the input character is 0, it transitions to state A.
  6. If the current state is C and the input character is 1, it stays in state C.
  
  The code first takes an input string from the user and then processes it using the finite automaton. It keeps track of the current state and prints the transitions made during the processing of the input string. After processing the entire string, it determines if the final state is C. If the final state is C, the given string is accepted; otherwise, it is rejected.

  ```bash
  Example:
  Suppose the input string provided by the user is "101001." Let's walk through the automaton's transitions for this string:
  
  Start --> A(1) --> B(0) --> A(1) --> A(0) --> A(0) --> B(1) --> C*(0) --> Done
  
  Since the automaton ends in state C, the output will be:
  Given String is accepted.
   ```

## 2. NFA to DFA Conversion

Explore the conversion process from Non-deterministic Finite Automata (NFA) to DFA, a crucial step in simplifying automata and optimizing language recognition.
This C++ code implements the conversion of a given Nondeterministic Finite Automaton (NFA) to its corresponding Deterministic Finite Automaton (DFA). The program takes user input for the NFA transitions and then generates the corresponding DFA transitions based on the provided NFA.

### Explanation with Example:
  Let's take a simple NFA as an example:
  
  NFA with 3 states: A, B, C
  - Transition from A to 0: B
  - Transition from A to 1: A
  - Transition from B to 0: C
  - Transition from B to 1: B
  - Transition from C to 0: C
  - Transition from C to 1: C
  
  1. The user will input the transitions for each state of the NFA:
     - From state A through 0 transition: B
     - From state A through 1 transition: A
     - From state B through 0 transition: C
     - From state B through 1 transition: B
     - From state C through 0 transition: C
     - From state C through 1 transition: C
  
  2. The program will print the NFA table:
  ```
  NFA Table
  
  _______________________________
  State   0   1
  A       B   A
  B       C   B
  C       C   C
  ```
  
  3. The program will convert the NFA to a DFA and print the DFA table:
  ```
  DFA Table
  
  _______________________________
  State   0   1
  A       B   A
  B       C   B
  C       C   C
  BC      C   B
  ```
  
  In the DFA table, a new state "BC" is added, representing the set of states {B, C} combined through the ε (epsilon) transition. The DFA has one additional state compared to the NFA.

----
## 3. CFG Conversion

Understand how to convert Context-Free Grammars (CFG) into various other forms, such as Chomsky Normal Form or Greibach Normal Form, which facilitates parsing and analysis.

This C++ code defines a Context-Free Grammar (CFG) parser for a given string. It checks if the string follows a specific grammar rule defined by the CFG. The CFG rules are as follows:

1. The input string can only contain '0', '1', '+', '*', '(', and ')'.
2. The CFG non-terminal 'E' can be replaced with either '0' or '1'.
3. The CFG non-terminal 'E' can be concatenated with other 'E's using '+' or '*' operators.
4. The parenthesis '(' and ')' can be used for grouping.

The code takes a user-input string and then applies the CFG rules to determine if the string is accepted or not. If the string is successfully parsed and follows the CFG rules, it prints "String is accepted." Otherwise, it prints "String is not accepted."


### Example:
  Let's consider the string "1+(0*1)". The CFG parsing process for this string would be as follows:
  ```
  1. Start with the input string: "1+(0*1)".
  2. '1' can be replaced with 'E', so the string becomes "E+(0*1)".
  3. '0' can be replaced with 'E', so the string becomes "E+(E*1)".
  4. '1' can be replaced with 'E', so the string becomes "E+(E*E)".
  5. The entire string "E+(E*E)" is equivalent to 'E', so the final string is 'E'.
  ```
  Since the parsing process is successful, the output will be "String is accepted."
  
  The code handles various scenarios, such as incorrect characters in the input string, unbalanced parentheses, and incorrect use of operators.

----
## 4. Universal DFA

Discover the implementation of a Universal Deterministic Finite Automaton capable of simulating other DFAs. This concept plays a significant role in language recognition and computation theory.

This C++ code represents a Universal Deterministic Finite Automaton (DFA) that accepts or rejects strings based on a given set of states, transitions, and final states. The program takes input for the number of states, start state, final states, and transition functions for input symbols '0' and '1'. It then prompts the user to enter a string, which will be checked for acceptance or rejection by the DFA.

### Explanation with an example:

  Let's assume we have the following DFA:
  ```
  Number of states (Q): 3
  Start state (q0): 1
  Number of final states (f): 1
  Final state(s) (F): 3
  Transition table:
  1 --> 0 --> 2
  1 --> 1 --> 3
  2 --> 0 --> 2
  2 --> 1 --> 2
  3 --> 0 --> 3
  3 --> 1 --> 2
  ```
  The DFA diagram:
  ```
         0       1
     --> 2  <--  1 (Start, Final)
       ^  |       |
       |  V       V
       3 <--  2 (Final)
  ```
  
  Now, suppose we want to check the string "101" for acceptance:
  
  1. The program will start from the start state, i.e., state 1.
  2. It will read the first symbol '1', transitioning from state 1 to state 3.
  3. Next, it reads the symbol '0', transitioning from state 3 to state 3.
  4. Finally, it reads the last symbol '1', transitioning from state 3 to state 2.
  
  After processing the entire string, the DFA ends at state 2.
  
  Output:
  ```
  Steps are :
  Start --> 1 --> (1 ) --> 3 --> (0 ) --> 3 --> (1 ) --> 2
  
  String is accepted
  ```
  
  The program displays the steps taken while processing the string. In this case, the DFA ends up in one of the final states (state 2), so the string "101" is accepted.

----

## 5. NPDA (Non-deterministic Pushdown Automaton)

Witness the code for creating a Non-deterministic Pushdown Automaton, a powerful model used in context-free language recognition and parsing.

This code implements a Pushdown Automaton (PDA) to check if a given string is of the form "wwR", where "w" is any string, and "wR" represents the reverse of "w". The PDA uses a stack to keep track of characters read from the input string.

Let's break down the code and explain it step by step:

1. The code includes necessary header files and defines a stack "pda" and a global variable "current_state" to keep track of the PDA's state.

2. The function "start_state" is called when the PDA is in state 0. It pushes the character "c" onto the stack and prints a transition statement.

3. The function "final_state" is called when the PDA is in state 1. It checks if the character "c" matches the top of the stack. If they match, it pops the stack and prints a transition statement.

4. The function "PDA" takes the input string "s" and its length "len" as arguments and simulates the PDA's behavior.

5. The PDA iterates over each character in the input string. If it reaches the middle of the string (i.e., i == len), it transitions to state 1 and pops the stack if the character matches the top.

6. Depending on the current state, the PDA either calls the "start_state" or "final_state" function.

7. After processing all characters, the PDA checks if the top of the stack is 'z'. If it is, the input string is accepted; otherwise, it is rejected.

8. In the "main" function, the PDA is initialized with the character 'z' on the stack.

9. The user is prompted to enter a string.

10. If the length of the string is odd (i.e., s.length()%2 != 0), it is rejected immediately.

11. Otherwise, the "PDA" function is called with half the length of the input string (since it's checking for "wwR").

12. If the PDA returns true, the input string is accepted; otherwise, it is rejected.

### Example:
  Let's say we input the string "abccba". The stack is initially ['z']. The PDA processes each character:
  
  1. "a": It's the start of the string, so the PDA pushes 'a' onto the stack: ['z', 'a'].
  2. "b": The PDA is still in state 0, so it pushes 'b' onto the stack: ['z', 'a', 'b'].
  3. "c": The PDA is still in state 0, so it pushes 'c' onto the stack: ['z', 'a', 'b', 'c'].
  4. "c": The PDA is still in state 0, so it pushes 'c' onto the stack: ['z', 'a', 'b', 'c', 'c'].
  5. "b": The PDA is still in state 0, so it pushes 'b' onto the stack: ['z', 'a', 'b', 'c', 'c', 'b'].
  6. "a": The PDA is still in state 0, so it pushes 'a' onto the stack: ['z', 'a', 'b', 'c', 'c', 'b', 'a'].
  
  At this point, the PDA reaches the middle of the string. It transitions to state 1 and starts checking the second half.
  
  7. "a": The PDA is in state 1, and 'a' matches the top of the stack, so it pops 'a': ['z', 'a', 'b', 'c', 'c', 'b'].
  8. "b": The PDA is still in state 1, and 'b' matches the top of the stack, so it pops 'b': ['z', 'a', 'b', 'c', 'c'].
  9. "c": The PDA is still in state 1, and 'c' matches the top of the stack, so it pops 'c': ['z', 'a', 'b', 'c'].
  
  The PDA has processed the entire string, and the stack now contains ['z', 'a', 'b']. Since the top of the stack is not 'z', the input string "abccba" is rejected.

----
## 6. CFG to PDA Conversion

Explore the process of converting Context-Free Grammars (CFG) to Pushdown Automata (PDA), enabling the recognition of context-free languages through stack-based computation.
This code is a C++ program that converts context-free grammar (CFG) production rules into production rules for a Pushdown Automaton (PDA). The program takes the number of production rules as input, then prompts the user to input the non-terminal symbol and its corresponding production rule for each production. Finally, it generates the corresponding PDA production rules for the given CFG.

### Example:
  Suppose we have the following CFG production rules:
  
  1. S -> aA | bB
  2. A -> a
  3. B -> b
  
  The program will take the input as follows:
  ```
  Enter the no of Production Rules of CFG: 3
  Please enter the Production rules of CFG:
  S aA | bB
  A a
  B b
  ```
  
  Then, it will output the corresponding PDA production rules for non-terminal symbols:
  ```
  The Corresponding Production Rules For PDA are:
  Rules For Non-Terminal Symbols are:
  dl(q,null,S) --> dl(q,aA) | dl(q,bB)
  dl(q,null,A) --> dl(q,a)
  dl(q,null,B) --> dl(q,b)
  ```
  
  Additionally, the program appends the following two PDA production rules for terminals:
  ```
  dl(q,0,0)--> dl(q,null)
  dl(q,1,1) --> dl(q,null)
  ```
  
  These rules signify that when the PDA encounters 0, it will pop 0 from the stack, and when it encounters 1, it will pop 1 from the stack.
  
---

Feel free to explore, learn, and contribute to this repository to expand your understanding of theoretical computer science and its applications in computing and language theory. If you have any questions, suggestions, or improvements, please don't hesitate to open an issue or submit a pull request. Happy coding!
