define i32 @printINT (i32 %0) {
.printINT_body:
%a = alloca i32
store i32 %0, ptr %a
%1 = load i32, ptr %a
ret i32 %1
}
define i32 @function (i32 %0, i32 %1) {
.function_body:
%a = alloca i32
store i32 %0, ptr %a
%b = alloca i32
store i32 %1, ptr %b
%2 = load i32, ptr %a
%3 = load i32, ptr %b
%4 =  add i32 %2, %3
ret i32 %4
}
@x = global i32 3
@y = global i32 6
define i32 @main () {
.main_body:
%a = alloca i32
store i32 5, ptr %a
%b = alloca i32
store i32 6, ptr %b
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
br label %.L2
.L1:
%6 = load i32, ptr %a
%7 = load i32, ptr %b
%8 =  sub i32 %6, %7
store i32 %8, ptr %a
br label %.L2
.L2:
%i = alloca i32
%9 = zext i1 0 to i32
store i32 %9, ptr %i
br label %.L3
.L3:
%10 = load i32, ptr %i
%11 = icmp slt i32 %10, 10
br i1 %11, label %.L4, label %.L5
.L4:
%12 = load i32, ptr %a
%13 = load i32, ptr %i
%14 =  add i32 %12, %13
store i32 %14, ptr %a
%15 = load i32, ptr %i
%16 =  add i32 %15, 1
store i32 %16, ptr %i
br label %.L3
.L5:
%17 = load i32, ptr %a
%18 = load i32, ptr %b
%19 = icmp slt i32 %17, %18
%20 = load i32, ptr %a
%21 = load i32, ptr %b
%22 = load i32, ptr %b
store i32 %22, ptr %a
%23 = load i32, ptr %a
%24 = load i32, ptr %b
%25 =  add i32 %23, %24
%26 = zext i8 3 to i32
store i32 %26, ptr %a
%c = alloca double
store double 3.300000, ptr %c
%27 = load double, ptr %c
%28 = sitofp i32 1 to double
%29 = fadd double %27, %28
store double %29, ptr %c
%30 = load i32, ptr %a
%31 = load double, ptr %c
%32 = sitofp i32 %30 to double
%33 = fadd double %32, %31
store double %33, ptr %c
%34 = load i32, ptr %a
store i32 %34, ptr @y
%35 = load i32, ptr @y
%36 = load i32, ptr @x
%37 =  sub i32 %35, %36
store i32 %37, ptr %a
%38 = load i32, ptr %a
%39 = zext i8 3 to i32
%40 =  mul i32 %38, %39
%41 = zext i1 1 to i32
%42 =  sub i32 %40, %41
store i32 %42, ptr %b
%43 = load i32, ptr %b
ret i32 %43
}
