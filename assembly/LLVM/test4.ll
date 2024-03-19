declare i32 @printf (ptr, ...)

@.str = constant [4 x i8] c"%d\0A\00"

@x = constant i32 3
@y = constant i32 6

define i32 @main () {
.main_body:

    %a = alloca i32
    %b = alloca i32
    %c = alloca double
    %temp = alloca i1
    %i = alloca i32

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
    br label %.L2
    .L1:
    %6 = load i32, ptr %a
    %7 = load i32, ptr %b
    %8 =  sub i32 %6, %7
    store i32 %8, ptr %a
    br label %.L2
    .L2:
    store i32 0, ptr %i
    br label %.L3
    .L3:
    %9 = load i32, ptr %i
    %10 = icmp slt i32 %9, 10
    br i1 %10, label %.L4, label %.L5
    .L4:
    %11 = load i32, ptr %a
    %12 = load i32, ptr %i
    %13 =  add i32 %11, %12
    store i32 %13, ptr %a
    %14 = load i32, ptr %i
    %.call1 = call i32 (ptr, ...) @printf(ptr @.str, i32 %14)
    %.call2 = call i32 (ptr, ...) @printf(ptr @.str, i32 %13)
    %15 =  add i32 %14, 1
    store i32 %15, ptr %i
    br label %.L3
    .L5:
    %16 = load i32, ptr %a
    %17 = load i32, ptr %b
    %18 = icmp slt i32 %16, %17
    %19 = load i32, ptr %a
    %20 = load i32, ptr %b
    %21 = load i32, ptr %b
    store i32 %21, ptr %a
    %22 = load i32, ptr %a
    %23 = load i32, ptr %b
    %24 =  add i32 %22, %23
    store i8 3, ptr %a
    store double 3.300000, ptr %c
    %25 = load i32, ptr %a
    %26 = load double, ptr %c
    ret i32 %23
}