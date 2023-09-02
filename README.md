# The Quark programming language
## About
The structure of the Quark compiler is as follows:
  1. **Scanner** --> "Scans" the given file and creates and returns all the tokens which are the words of the language _(If an invalid token is reached, it returns an error)_
     - Written in **flex**
  3. **Parser** --> "Parses" the tokens _(the output of the Scanner)_, applies syntax checks and structures them in a large data structure - **Abstract Syntax Tree** also refered to as **AST**
     - Written in **bison**
  5. **Semantic Analyser** --> "Analyses" the AST, performes scope checking using a symbol table _(implemented with a stack of hash tables)_ and applies type checking
     - Written in **C**
  7. **Optimizer** --> Applies higher level optimizations _(like Constant folding)_ and tweaks the AST to a high level **Intermediate Representation** also refered to as **IR**
     - Written in **C**
  9. **Code generator** --> Generates assembly instruction from the high level IR
     - Technically there are two codegenerators - a _production_ and _debug_: the first one generates LLVM assembly and **is highly optimized**, and the second one generates directly X86 assembly but with **no low level optimizations**. Thus the _production_ codegenerator has longer compile-time but faster run-time and the _debug_ codegenerator has faster compile-time but longer run-time.
     - Written in **C** and **LLVM assembly / X86 assembly**
  - ***Important notice*** - To be exact, the **Optimizer** and the **Code generator** are implemented simultaneously.

## Build dependencies
The following must be installed in order to build the Quark compiler
 - `gcc` and `make` - For linux: `sudo apt install build-essential`
 - `clang` - For linux: `sudo apt install clang`
 - `llvm-config` - For linux: `sudo apt install llvm-config`
 - `flex` - For linux: `sudo apt install flex`
 - `bison` - For linux: `sudo apt install bison`

 - ***Important notice*** - If you are on linux, make sure to run `sudo apt update` and then `sudo apt upgrade` before installing any of the dependencies.
