# The Quark programming language
## About
### What is Quark?
  Quark is a compiled language written in flex, bison, C, X86 assembly and LLVM assembly.
   - It's purpose is to be the core of future programming languages by giving them the opportunity to use the ready Quark compiler and change or/and add new features on top.
   - The Quark compiler packs up a fully modular structure.
   - Every component of the compiler is independent from the rest and can be changed, removed or even swapped.
   - Incredible flexibility and ease of use when creating your own programming language.
   - Quark also reduces production time by removing the tedious parts of creating a language from the ground up.
   - All creating a good starting point and more time to focus on real features.
### The structure of the Quark compiler is as follows:
  1. **Scanner** --> "Scans" the given file and creates and returns all the tokens which are the words of the language _(If an invalid token is reached, it returns an error)_
     - Written in **flex**
  3. **Parser** --> "Parses" the tokens _(the output of the Scanner)_, applies syntax checks and structures them in a large data structure - **Abstract Syntax Tree** also refered to as **AST**
     - Written in **bison**
  5. **Semantic Analyser** --> "Analyses" the AST, performes scope checking using a symbol table _(implemented with a stack of hash tables)_ and applies type checking
     - Written in **C**
  7. **Optimizer** --> Applies high level optimizations _(like Constant folding)_ and tweaks the AST to a high level **Intermediate Representation** also refered to as **IR**
     - Written in **C**
  9. **Code generator** --> Generates assembly instruction from the high level IR
     - Technically there are two codegenerators - a _production_ and _debug_: the first one generates LLVM assembly and **is highly optimized**, and the second one generates directly X86 assembly but with **no low level optimizations**. Thus the _production_ codegenerator has longer compile-time but faster run-time and the _debug_ codegenerator has faster compile-time but longer run-time.
     - Written in **C** and **LLVM assembly / X86 assembly**
  > [!NOTE]
  > To be exact, parts of the **Optimizer** and the **Code generator** are implemented simultaneously.

## Build dependencies
The following must be installed in order to build the Quark compiler:
 - `gcc` and `make` - For Linux: `sudo apt install build-essential`
 - `clang` - For Linux: `sudo apt install clang`
 - `llvm` - For Linux: `sudo apt install llvm`
 - `flex` - For Linux: `sudo apt install flex`
 - `bison` - For Linux: `sudo apt install bison`
 - `git` - For Linux: `sudo apt install git`

 > [!TIP]
 > If you are on Linux, make sure to run `sudo apt update` and then `sudo apt upgrade` before installing any of the dependencies.

## Build on Linux
  1. Clone the Quark github repository:
     ```
     git clone https://github.com/dr-programmer/quark.git
     ```
  2. Head to the Quark compiler directory:
     ```
     cd quark
     cd compiler
     ```
  3. Build the compiler:
     ```
     make
     ```

## Usage of the Quark compiler
### Basic usage
```
quark [--flags] [filename] [--flags]
```
> [!NOTE]
> As of right now, the Quark compiler supports the following languages: Quark, C, C++
### Flags
  - `-o [filename]` - Tells the compiler how the result file should be called _(If not specified, then the result file is named `a.out`)_.
  - `--debug` - Tells the compiler to use the debug codegenerator _(If not specified, then the production codegenerator is in use)_. Read more about [The Code Generator](#the-structure-of-the-quark-compiler-is-as-follows).
  - `--show-offset` - Tells the compiler to print the stack offset of all called variables.
  - `--show-pcode` - Tells the compiler to structure and print the parsed code back from the AST memory structure. Read more about [The Abstract Syntax Tree](#the-structure-of-the-quark-compiler-is-as-follows).
  - `--help` - Tells the compiler to print the usage manual for the Quark compiler.
> [!TIP]
> Quark uses a convention which implies that flags starting with `-` require an additional specifier after them, and flags with `--` do not.

## Usage of the Quark language
### Example 1
```
printINT[int](a[int]) { ?? Creating a function printINT() with return type int and one int argument a
    give a => stdin; ?? The token => sends the stream to a file_pointer (In this case - stdin)
}

main[int]() { ?? Creating a function main() with return type int
    var[int] = 0; ?? Creating a variable named var with type int
    printINT(var); ?? Calling the function printINT()
    give 0; ?? Returning a value
    <? This is a multiline
    comment in Quark ?>
}
```
### Example 2
```
printINT[int](a[int]) {
    give a => stdin;
}

main[int]() {
    sum[int] = 0;
    i[int] = 0;
    for(i = 0; i < 10; i++) {
        sum += i;
    }
    printINT(sum);
    mul[sum->&]; ?? Renaming sum to mul to save memory and avoid confusion (Both mul and sum point to the same location)
    mul = 1;
    for(i = 1; i < 10; i++) {
        mul *= i;
    }
    printINT(mul);
    give 0;
}
```
### Example 3
```
printINT[int](a[int]) {
    give a => stdin;
}

main[int]() {
    var[int] = 0;
    var = fibonachi(6);
    printINT(var);
    arr[int]^6 = {1, 2, 3, 4, 5, 6}; ?? Creating an array of type int with 6 elements
    printINT(arr->0); ?? Array subscription
    i[int];
    for(i = 0; i < 6; i++) {
        printINT(arr->i);
    }
    give 0; ?? Returning a value
}
```
