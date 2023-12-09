# Balanced Bracket Checker (BBC) 🛠️

## Overview 📖

**Balanced Bracket Checker (BBC)** is a C program designed to verify the correct use of brackets in input text. The program focuses on ensuring that all types of brackets (parentheses `()`, square brackets `[]`, and curly braces `{}`) are properly opened and closed, while intelligently ignoring brackets within string literals and comments.

## Key Features 🔑

- **Bracket Validation** 📏: Checks for balanced usage of `()`, `{}`, and `[]` in the input.
- **Comment & String Handling** 📝: Skips over brackets within string literals and comments, ensuring only relevant brackets are checked.
- **Line-by-Line Analysis** 🔍: Processes the input line by line, providing immediate feedback on each line's bracket balance.
- **Single Curly Brace Tracking** 🗂️: Specifically keeps track of standalone curly braces, which are common in C-like languages.
- **Error Reporting** 🚨: Reports unbalanced brackets, enhancing readability and debugging of code or text.
- **Interactive Console Interface** 💻: Users input text directly, receiving instant feedback on bracket balance.

## How to Use 🛠️

1. **Compile the Program**:
   - Use the included Makefile to compile the program.

        ```bash
        make
        ```

2. **Run the Program**:
   - Execute the compiled program in a terminal or command prompt.

     ```bash
     ./par  <pipe optional input file with '<' operator>
     ```

   - Enter the text for bracket checking. The program will analyze the input and display whether each line is balanced or not.

3. **Interpreting Output**:
   - After each line of input, the program will output whether the line is balanced or not.
   - Lines with single curly braces are marked but do not affect the overall balance unless they are unmatched.
   - Upon completion of the input, the program displays a final message indicating if the entire text is balanced.

## Examples 🌟

**[test.txt](test.txt) file output**

![Alt text](<par exam1.png>)

**[input.txt](input.txt) file output**
![Alt text](<par exam2.png>)

**Interactive console output**
![Alt text](<par exam3.png>)

## Limitations & Future Enhancements 🔮

- The program currently handles input directly from the console. It does not read from files.
- Maximum line size is limited to 100 characters.
- **Future Enhancement**: File input support to check files directly and increase the maximum line size limit.
