.text
.global printINT
printINT:
PUSHQ %rbp
MOVQ %rsp, %rbp
PUSHQ %rdi
SUB $8, %rsp
PUSHQ %rbx
PUSHQ %r12
PUSHQ %r13
PUSHQ %r14
PUSHQ %r15
MOV -8(%rbp), %rbx
MOV %rbx, %rax
MOV %rax, %rsi
.L0: .string "%d\n"
MOV $.L0, %rdi
PUSHQ %rax
PUSHQ %rcx
PUSHQ %r10
PUSHQ %r11
XOR %rax, %rax
CALL printf
PUSHQ %r11
PUSHQ %r10
POPQ %rcx
POPQ %rax
JMP .printINT_epilogue
.printINT_epilogue:
POPQ %r15
POPQ %r14
POPQ %r13
POPQ %r12
POPQ %rbx
MOVQ %rbp, %rsp
POPQ %rbp
RET
.text
.global function
function:
PUSHQ %rbp
MOVQ %rsp, %rbp
PUSHQ %rdi
PUSHQ %rsi
SUB $0, %rsp
PUSHQ %rbx
PUSHQ %r12
PUSHQ %r13
PUSHQ %r14
PUSHQ %r15
MOV -8(%rbp), %rbx
MOV -16(%rbp), %r10
ADD %rbx, %r10
MOV %r10, %rax
JMP .function_epilogue
.function_epilogue:
POPQ %r15
POPQ %r14
POPQ %r13
POPQ %r12
POPQ %rbx
MOVQ %rbp, %rsp
POPQ %rbp
RET
.data
x: .quad 3
.data
y: .quad 6
.text
.global main
main:
PUSHQ %rbp
MOVQ %rsp, %rbp
PUSHQ %rdi
SUB $24, %rsp
PUSHQ %rbx
PUSHQ %r12
PUSHQ %r13
PUSHQ %r14
PUSHQ %r15
MOV $5, %rbx
MOV %rbx, -16(%rbp)
MOV $6, %r10
MOV %r10, -24(%rbp)
MOV -16(%rbp), %r11
MOV -24(%rbp), %r11
MOV -24(%rbp), %r11
MOV %r11, -16(%rbp)
MOV -16(%rbp), %r11
MOV -24(%rbp), %r12
ADD %r11, %r12
MOV y, %r11
MOV x, %r12
SUB %r12, %r11
MOV %r11, -16(%rbp)
MOV y, %r11
MOV %r11, %rsi
MOV x, %r11
MOV %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL function
POPQ %r11
POPQ %r10
MOV %rax, %r11
MOV %r11, -24(%rbp)
MOV %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL printINT
POPQ %r11
POPQ %r10
MOV %rax, %r11
MOV -24(%rbp), %r11
MOV %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL printINT
POPQ %r11
POPQ %r10
MOV %rax, %r11
MOV -16(%rbp), %r11
MOV $3, %r12
MOV %r11, %rax
IMUL %r12
MOV %rax, %r12
MOV $1, %r11
SUB %r11, %r12
MOV %r12, -24(%rbp)
MOV -24(%rbp), %r11
MOV %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL printINT
POPQ %r11
POPQ %r10
MOV %rax, %r11
.main_epilogue:
POPQ %r15
POPQ %r14
POPQ %r13
POPQ %r12
POPQ %rbx
MOVQ %rbp, %rsp
POPQ %rbp
RET
