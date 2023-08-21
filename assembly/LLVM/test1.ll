declare i32 @puts (ptr)
declare i32 @printf (ptr, ...)

@.str = constant [4 x i8] c"%d\0A\00"

define float @funcion (i32 %0) {
    add i32 1, %0
    %3 = sitofp i32 %2 to float
    %4 = fadd float 1.0, %3
    ret float %4
}

define i32 @main () {
    %x = alloca i32
    %1 = add i32 1, 1
    store i32 %1, ptr %x
    %2 = load i32, ptr %x
    ;call i32 @puts(ptr @.str)
    call i32 @printf(ptr @.str, i32 %2)
    ret i32 %2
}