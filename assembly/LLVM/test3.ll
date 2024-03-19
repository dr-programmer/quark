declare i32 @printf (ptr, ...)

@.str = constant [5 x i8] c"%lf\0A\00"

@x = constant i32 3
@y = constant i32 6

define i32 @main () {
.main_body:

    %a = alloca i32
    %b = alloca i32
    %c = alloca double
    %temp = alloca i1

    store i1 1, ptr %temp
    %0 = load i32, ptr %a
    %1 = load i32, ptr %b
    %2 = icmp  eq i32 %0, %1
    br i1 %2, label %.L0, label %.L1
    .L0:
    %3 = load i32, ptr %a
    %4 = load i32, ptr %b
    %5 =  add i32 %3, %4
    store i32 %5, ptr %a
    %.call1 = call i32 (ptr, ...) @printf(ptr @.str, double 1.1)
    br label %.L2
    .L1:
    %6 = load i32, ptr %a
    %7 = load i32, ptr %b
    %8 =  sub i32 %6, %7
    store i32 %8, ptr %a
    %.call2 = call i32 (ptr, ...) @printf(ptr @.str, double 2.2)
    br label %.L2
    .L2:
    %9 = load i32, ptr %a
    %10 = load i32, ptr %b
    %11 = icmp slt i32 %9, %10
    %12 = load i32, ptr %a
    %13 = load i32, ptr %b
    %14 = load i32, ptr %b
    store i32 %14, ptr %a
    %15 = load i32, ptr %a
    %16 = load i32, ptr %b
    %17 =  add i32 %15, %16
    store i8 3, ptr %a
    store double 3.300000, ptr %c
    %18 = load i32, ptr %a
    %19 = load double, ptr %c
    call i32 (ptr, ...) @printf(ptr @.str, double %19)
    ret i32 %18
}