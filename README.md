# Text Analysis C

## Overview 🌐

**Text Analysis C** is a Text Processing Toolkit written in ANSI C. This repository contains a collection of C programs designed for various text processing tasks, each catering to specific needs in text analysis and manipulation. Currently, the toolkit includes two main programs:

- **Balanced Bracket Checker (BBC)**: A utility to check if brackets in the input text are correctly balanced, considering various scenarios such as strings and comments in the code.
- **ASCII Sequence Compressor (ASC)**: This program compresses sequences of consecutive ASCII characters, efficiently shortening strings by representing continuous sequences with a start and end character.

The toolkit aims to provide robust and efficient solutions for common text processing challenges in programming and data analysis.

![image](https://github.com/Dor-sketch/TextAnalysisC/assets/138825033/725b77aa-1dd6-43de-8040-c9c77fa10724)

---

## Programs Included 📜

### 1. Balanced Bracket Checker (BBC)

- **Purpose**: Checks if brackets in the input text are correctly balanced.
- **Features**:
  - Validates `()`, `{}`, and `[]` brackets.
  - Skips brackets inside strings and comments.
  - Reports unbalanced lines and single curly braces.
- See [BBC/README.md](BBC/README.md) for more details.

### 2. ASCII Sequence Compressor (ASC)

- **Purpose**: Compresses sequences of consecutive ASCII characters.
- **Features**:
  - Detects and compresses sequences where each character's ASCII value is one greater than the previous character.
  - Compresses sequences longer than two characters into a start and end character, separated by a dash (`-`).
- See [ASC/README.md](ASC/README.md) for more details.

## How to Use 🛠️

1. **Compilation**:
   - Each program can be compiled using a C compiler like `gcc`.
   - Example for BBC:

     ```bash
     gcc -o bbc bbc.c
     ```

   - Example for ASC:

     ```bash
     gcc -o asc asc.c
     ```

2. **Execution**:
   - Run the compiled program in a terminal or command prompt.
   - For BBC:

     ```bash
     ./bbc
     ```

   - For ASC:

     ```bash
     ./asc
     ```

   - Follow on-screen instructions for each program.

## Contributing 🤝

Contributions to the **C Text Processing Toolkit** are welcome! Whether it's adding new tools, enhancing existing ones, or fixing bugs, your input is valuable. Feel free to fork the repository, make your changes, and submit a pull request.

## Future Enhancements 🔮

- Expand the toolkit with more text processing programs.
- Enhance existing programs to handle more complex scenarios, like file input.

## License ⚖️

This project is open-source and available under [LICENSE] (add your license here).

Thank you for exploring the **C Text Processing Toolkit**!
