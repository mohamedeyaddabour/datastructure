# 🚂 Shunting Yard Algorithm (Infix to Postfix)

The **Shunting Yard Algorithm** (invented by Edsger Dijkstra) is a method for parsing mathematical expressions. It is commonly used to convert **Infix** notation (readable by humans, e.g., `3 + 4`) into **Postfix** notation (Reverse Polish Notation, readable by computers, e.g., `3 4 +`).

Computers prefer Postfix because it eliminates the need for parentheses and respects operator precedence strictly using a Stack.

---

## 📜 The Rules

1.  **Operands (A, B, C, 1, 2...):** Print to Output immediately.
2.  **Operators (+, -, *, /):**
    * If the Stack is empty, push the operator.
    * If the Stack is NOT empty:
        * Compare the precedence of the current operator with the top of the Stack.
        * If **Top > Current** OR **Top == Current**: Pop the Top and print to Output. Repeat until the condition fails, then push the current operator.
        * If **Top < Current**: Push the current operator.
3.  **Left Parenthesis `(`:** Push to Stack.
4.  **Right Parenthesis `)`:** Pop from Stack and print to Output until a `(` is found. Discard both parentheses.

**Precedence Order:**
1.  `^` (Highest)
2.  `*` and `/`
3.  `+` and `-` (Lowest)

---

## 🔍 Trace Example 1: `a * b + c`

**Goal:** Respect that multiplication (`*`) happens before addition (`+`).

| Step | Symbol | Stack Action | Stack State | Output (Postfix) | Logic |
| :--- | :---: | :--- | :--- | :--- | :--- |
| 1 | `a` | - | Empty | `a` | Operand → Output |
| 2 | `*` | Push | `*` | `a` | Stack empty → Push |
| 3 | `b` | - | `*` | `ab` | Operand → Output |
| 4 | `+` | Pop `*`, Push `+` | `+` | `ab*` | `*` has higher precedence than `+`. Pop `*`. |
| 5 | `c` | - | `+` | `ab*c` | Operand → Output |
| 6 | End | Pop `+` | Empty | `ab*c+` | Input empty → Pop all |

**Final Result:** `ab*c+`

---

## 🔍 Trace Example 2: `(a + b) * c`

**Goal:** Parentheses `()` force the addition to happen before multiplication.

| Step | Symbol | Stack Action | Stack State | Output (Postfix) | Logic |
| :--- | :---: | :--- | :--- | :--- | :--- |
| 1 | `(` | Push | `(` | - | Always push `(` |
| 2 | `a` | - | `(` | `a` | Operand → Output |
| 3 | `+` | Push | `( +` | `a` | `(` does not force pop. Push `+`. |
| 4 | `b` | - | `( +` | `ab` | Operand → Output |
| 5 | `)` | Pop until `(` | `(` | `ab+` | Found `)`. Pop `+`. Stop at `(`. |
| 6 | | Pop `(` | Empty | `ab+` | Discard parentheses. |
| 7 | `*` | Push | `*` | `ab+` | Stack empty → Push |
| 8 | `c` | - | `*` | `ab+c` | Operand → Output |
| 9 | End | Pop `*` | Empty | `ab+c*` | Input empty → Pop all |

**Final Result:** `ab+c*`

---

## 💡 Summary Comparison

| Infix | Postfix | Meaning |
| :--- | :--- | :--- |
| `a * b + c` | `ab*c+` | Multiply `a` and `b`, then add `c`. |
| `(a + b) * c` | `ab+c*` | Add `a` and `b`, then multiply the result by `c`. |