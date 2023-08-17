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
MOV y, %rbx
MOV %rbx, %rsi
MOV x, %rbx
MOV %rbx, %rdi
PUSHQ %r10
PUSHQ %r11
CALL function
MOV %rax, %rbx
POPQ %r11
POPQ %r10
MOV %rbx, -16(%rbp)
