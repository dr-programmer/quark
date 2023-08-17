.data
    x: .quad 3
    y: .quad 6
    str: .string "a = %d\n"

.text
.global main
main:
    PUSHQ   %rbp
    MOVQ    %rsp, %rbp

MOV -8(%rbp), %rbx
MOV -16(%rbp), %r10
ADD %rbx, %r10
MOV y, %rbx
MOV x, %r10
MOV %rbx, %rax
CQO
IDIV %r10
MOV %rax, %r10
MOV %r10, -8(%rbp)

    MOV $str, %rdi
    MOV -8(%rbp), %rsi
    MOV $0, %rax
    CALL printf

    MOVQ    %rbp, %rsp
    POPQ    %rbp
    RET
