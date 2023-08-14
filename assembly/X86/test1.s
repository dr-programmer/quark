.data
.LC0:   .string "Hello, World! - "
.LC1:   .string "%d \n"
.text
.global main
main:
        PUSHQ   %rbp
        MOVQ    %rsp, %rbp

        MOVQ    $.LC0, %rdi
        MOVQ    $0, %rax
        CALL    printf

        SUBQ    $16, %rsp
        MOVQ    %rax, (%rsp)
        MOVQ    (%rsp), %rsi
        MOVQ    $.LC1, %rdi
        MOVQ    $0, %rax
        CALL    printf

        MOVQ    %rbp, %rsp
        POPQ    %rbp
        # The upper two instructions can be replaced by LEAVE
        RET
