# ASCII Sequence Compressor (ASC)

## Overview 📖

**ASCII Sequence Compressor (ASC)** is a C program designed to compress sequences of consecutive ASCII characters. The program identifies sequences where the ASCII value of each character is one greater than the previous character and compresses these sequences into a shorter form.

## Key Features 🔑

- **Sequence Detection** 🔍: Identifies sequences of consecutive ASCII characters.
- **Compression** 🗜️: Compresses sequences longer than two characters into a start and end character separated by a dash (`-`), effectively reducing the length of the string.

## How to Use 🛠️

1. **Compile the Program**:
   - Use the included Makefile to compile the program.

        ```bash
        make
        ```

2. **Run the Program**:
   - Execute the compiled program in a terminal or command prompt.

        ```bash
        ./con
        ```

   - Enter a line of characters for compression. The program will output the original and compressed versions.

## Example 🌟

Interactive console output 1
![!\[Alt text\](<con eampples.png>)](<con examples.png>)

Interactive console output 2
![Alt text](<con eamp 2.png>)

## Functionality 🧩

- The `contract` function processes the input string and compresses it.
- Characters that do not form part of a sequence are copied as-is.
- Sequences are detected and compressed into the first and last character, separated by a dash.

## Limitations & Future Enhancements 🔮

- The program currently handles input directly from the console and is limited to processing single lines of input.
- **Future Enhancement**: Extend functionality to handle multiline input and read from files.

## Contributing 🤝

Feel free to contribute to this project by suggesting improvements or submitting pull requests. Any contributions you make are greatly appreciated!
