declare i32 @printf (ptr, ...)

@.str = constant [5 x i8] c"%lf\0A\00"

@x = constant i32 3
@y = constant i32 6

define i32 @main () {
    .main_body:

    %a = alloca i32
    %b = alloca i32
    %c = alloca double

    %0 = load i32, ptr %a
    %1 = load i32, ptr %b
    %2 = load i32, ptr %b
    store i32 %2, ptr %a
    %3 = load i32, ptr %a
    %4 = load i32, ptr %b
    %5 =  add i32 %3, %4
    store i32 3, ptr %a
    store double 3.300000, ptr %c
    %6 = load i32, ptr %a
    %7 = load double, ptr %c
    %8 = fadd double %7, 6.7
    call i32 (ptr, ...) @printf(ptr @.str, double %8 )
    ret i32 0
}