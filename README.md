# Recursive Descent Parser

---

## 🎯 Aim
To implement a **Recursive Descent Parser** using C++ for a simple context-free grammar and verify whether a given string adheres to the grammar rules.

---

## 📚 Grammar Definition

The grammar followed is:
S → aSb | c

This grammar states:
- A string can be a single `'c'`, or
- An `'a'` followed by another valid `S` and a closing `'b'`.

### Examples of Valid Strings:
- `c`
- `acb`
- `aacbb`
- `aaacbbb`

---

## 🧠 Explanation & Logic

This program uses **recursive descent parsing**, a technique for implementing a top-down parser where each non-terminal symbol is translated into a function.

### Parsing Strategy:
- Start parsing from the start symbol `S`.
- If the current character is `'a'`:
  - Match `'a'`
  - Recursively call `S()`
  - Match `'b'`
- If the current character is `'c'`:
  - Accept as base case
- Else:
  - Throw a parsing error

### Key Functions:
- `peek()`: Returns current character without consuming it.
- `getNextChar()`: Advances to the next character.
- `match(expected_char)`: Ensures current character matches the expected, else throws error.
- `S()`: Recursive function implementing the grammar.

---

## 🔁 Sample Input/Output

### ✅ Valid Inputs
```yaml
Input: aacbb
Output: The input string is valid according to the grammar.
```

```yaml
Input: c
Output: The input string is valid according to the grammar.
```

### ❌ Invalid Inputs
```yaml
Input: acbb
Output: Error: Expected 'b' at position 3
```

```yaml
Input: ab
Output: Error: Invalid character in input at position 1
```

---

## 🌍 Real-World Applications

- **Compilers** – For syntax analysis in programming languages
- **Interpreters** – To evaluate expressions or commands
- **Syntax Validators** – For config files or domain-specific languages
- **Natural Language Processing** – Parsing structured language constructs

---

## 🏗️ How to Compile and Run

### Compile:
```bash
g++ recursive_descent_parser.cpp -o parser
```
### Run:
```bash
./parser
```

---
