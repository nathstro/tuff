# Tuff
A tree-walk interpreter for **Tuff**, an esoteric fork of my language nathlang (except way more tuff), written in C++.

### A sample of Tuff code
```
brainrot Tung
bro spawn bruh name idk
ts pls name being name 💔 son
bro speak bruh idk
yap ts pls name maxxing 3 gaining *sahur* 😭 sybau period

larp tripleT being Tung bruh *tung* idk 🥀
tripleT pls speak bruh idk 🙏
```
Expected output: **"tungtungtungsahur"**

### Keywords
| Code                         | Comment                                                            |
| ---------------------------- | ------------------------------------------------------------------ |
| bruh ... idk                 | PARENTHESES ( )                                                    |
| frfr                         | TRUE                                                               |
| cap                          | FALSE                                                              |
| chopped                      | NIL (no value)                                                     |
| and                          | AND                                                                |
| or                           | OR                                                                 |
| not                          | NOT                                                                |
| larp                         | LET (declares a variable)                                          |
| being                        | ASSIGN (assigns a value to a variable, equivalent to '=')          |
| chat ... fr                  | IF...THEN (selection)                                              |
| cooked                       | ELSE (selection)                                                   |
| yo ... being ... : ... : ... | FOR ... FROM ... TO ... STEP ... (count controlled loop)           |
| let ... cook                 | WHILE ... DO (condition controlled loop)                           |
| bro bruh .., .., ... idk     | FUNC(.., .., ...) (declares a function)                            |
| its giving                   | RETURN (returns a value from a function)                           |
| brainrot                     | CLASS (declares a class)                                           |
| period / ong / sybau / son   | END (ends an if statement, a for loop, a )                         |
| spawn                        | CONSTRUCTOR (called when an object of that class is instantiated)  |
| ts                           | THIS (refers to the current instance of a class)                   |
| mommy                        | SUPER (refers to the superclass object)                            |
| ... larping ...              | ... EXTENDS ... (establishes inheritance)                          |
| yap                          | PRINT                                                              |
| pls                          | member access operator (equivalent to '.' in Python, C++ and Java) |
| lowkey                       | <                                                                  |
| lowkenuinely                 | <=                                                                 |
| highkey                      | >                                                                  |
| highkenuinely                | >=                                                                 |
| be                           | ==                                                                 |
| aint                         | !=                                                                 |
| gaining                      | +                                                                  |
| losing                       | -                                                                  |
| maxxing                      | *                                                                  |
| rotting                      | /                                                                  |
| ANY EMOJI                    | ends a statement (equivalent to ';' in C++ and Java)               |

### Coding style
Since emojis separate statements and spaces, newlines and tabs have no meaning in Tuff, they can be omitted at random for more stylised coding. The example code above could also be written as 
```
brainrot Tung
  bro spawn bruh name idk
    ts pls name being name 💔
  son

  bro speak bruh idk
    yap ts pls name maxxing 3 gaining *sahur* 😭
  sybau
period

larp tripleT being Tung bruh *tung* idk 🥀
tripleT pls speak bruh idk 🙏
```
or
```
brainrot Tung bro spawn bruh name idk ts pls name being name 💔 son bro speak bruh idk yap ts pls name maxxing 3 gaining *sahur* 😭 sybau period

larp tripleT being Tung bruh *tung* idk 🥀 tripleT pls speak bruh idk 🙏
```
and both would print the same text.

Still working on a way to get the interpreter online
