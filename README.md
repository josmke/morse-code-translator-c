# Morse Code Decoder with Predictive Logic (C) 📻

A specialized command-line tool developed in **C** to decode Morse code sequences into text. This project was created as a challenge for the **Algorithms and Programming II** course at **Mackenzie**.

## 🚀 Key Features

- **Accurate Decoding:** Translates Morse signals (`.` and `-`) into the English alphabet (A-Z).
- **Predictive Suggestions:** A unique feature where using an asterisk (`*`) at the end of a partial Morse sequence triggers a suggestion mode, showing all possible character matches in brackets `[]`.
- **Space Handling:** Intelligent management of single spaces (letter separators) and double spaces (word separators).
- **Efficient Mapping:** Uses optimized string comparison and buffer management for real-time translation.

## 🛠️ Technical Deep Dive

The core logic revolves around a two-array dictionary system and dynamic buffer processing:
- **Buffer Management:** Sequentially processes command-line arguments to isolate individual Morse symbols.
- **Pattern Matching:** Implements `strcmp` for exact matches and `strncmp` for the suggestion logic.
- **Complexity:** Focuses on $O(n \cdot m)$ time complexity for translation, where $n$ is the input size and $m$ is the alphabet size.

## 💻 How to Use

1. **Compile the program:**
   ```bash
   gcc main.c -o decoder

2. **Run a standard translation:**
   ```bash
     ./decoder ".... . .-.. .-.. ---  .-- --- .-. .-.. -.."
     # Output: HELLO WORLD

3. **Use the Suggestion Mode:**
   ```bash
   ./decoder "..*"
   # Output: [IJDGHFBSV] (Shows all letters starting with "..")

## 👥 Contributors
- José Maike Ferreira Ferro
- Enzo Ferreira de Andrade
- Gabriel Valieri

- **Developed as a practical exercise in String Manipulation and Algorithmic Logic.**
