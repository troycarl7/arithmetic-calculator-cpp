Developed a command-line calculator in C++ capable of parsing and evaluating arithmetic expressions entered as strings. 
The program processes user input without relying on built-in evaluation 
        libraries by implementing a custom parsing and computation system.

Tokenization of raw string input into numerical values and operators, 
          supporting both spaced and non-spaced expressions (e.g., 3+5*2-4)
          
Implementation of operator precedence through a two-pass evaluation system 
             (handling multiplication/division before addition/subtraction)
             
Dynamic data handling using std::vector, with in-place modification and reduction of operands and operators
Robust string manipulation using functions such as substr, find_first_of, and stod
- String parsing and manipulation
- Data structures (vectors)
- Algorithm design for expression evaluation
- Control flow and memory-safe operations in C++
