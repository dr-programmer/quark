declare i32 @printf (ptr, ...)

@.str = constant [4 x i8] c"%d\0A\00"

define i32 @printINT (i32 %0) {
.printINT_body:
%.8a = alloca i32
store i32 %0, ptr %.8a
%1 = load i32, ptr %.8a
%2 = alloca [5 x i8]
store [4 x i8] c"%d\0A\00", ptr %2
%3 = call i32 (ptr, ...) @printf (ptr %2, i32 %1)
ret i32 %1
.retExit0:
unreachable
}
define i32 @function (i32 %0, i32 %1) {
.function_body:
%.8a = alloca i32
store i32 %0, ptr %.8a
%.16b = alloca i32
store i32 %1, ptr %.16b
%2 = load i32, ptr %.8a
%3 = load i32, ptr %.16b
%4 =  add i32 %2, %3
%5 = call i32 (i32) @printINT (i32 %4)
%6 = load i32, ptr %.8a
%7 = load i32, ptr %.16b
%8 =  add i32 %6, %7
%9 = zext i8 10 to i32
%10 = icmp sgt i32 %8, %9
br i1 %10, label %.L0, label %.L1
.L0:
%11 = load i32, ptr %.8a
%12 = load i32, ptr %.16b
%13 =  add i32 %11, %12
ret i32 %13
.retExit0:
br label %.L2
.L1:
%14 = load i32, ptr %.8a
%15 = zext i1 1 to i32
%16 =  add i32 %14, %15
%17 = load i32, ptr %.16b
%18 = zext i1 1 to i32
%19 =  add i32 %17, %18
%20 = call i32 (i32, i32) @function (i32 %16, i32 %19)
ret i32 %20
.retExit1:
br label %.L2
.L2:
unreachable
}
define i32 @fibonachi (i32 %0) {
.fibonachi_body:
%.8a = alloca i32
store i32 %0, ptr %.8a
%1 = load i32, ptr %.8a
%2 = zext i1 1 to i32
%3 = icmp sle i32 %1, %2
br i1 %3, label %.L3, label %.L4
.L3:
%4 = load i32, ptr %.8a
%5 = alloca [5 x i8]
store [4 x i8] c"%d\0A\00", ptr %5
%6 = call i32 (ptr, ...) @printf (ptr %5, i32 %4)
ret i32 %4
.retExit0:
br label %.L5
.L4:
%7 = load i32, ptr %.8a
%8 = zext i1 1 to i32
%9 =  sub i32 %7, %8
%10 = call i32 (i32) @fibonachi (i32 %9)
%11 = load i32, ptr %.8a
%12 = zext i8 2 to i32
%13 =  sub i32 %11, %12
%14 = call i32 (i32) @fibonachi (i32 %13)
%15 =  add i32 %10, %14
%16 = alloca [5 x i8]
store [4 x i8] c"%d\0A\00", ptr %16
%17 = call i32 (ptr, ...) @printf (ptr %16, i32 %15)
ret i32 %15
.retExit1:
br label %.L5
.L5:
unreachable
}
@x = global i32 3
@y = global i32 6
define i32 @main () {
.main_body:
%.8a = alloca i32
store i32 5, ptr %.8a
%.16b = alloca i32
store i32 6, ptr %.16b
%.17temp = alloca i1
store i1 1, ptr %.17temp
%0 = load i32, ptr %.8a
%1 = load i32, ptr %.16b
%2 = icmp  eq i32 %0, %1
br i1 %2, label %.L6, label %.L7
.L6:
%3 = load i32, ptr %.8a
%4 = load i32, ptr %.16b
%5 =  add i32 %3, %4
store i32 %5, ptr %.8a
br label %.L8
.L7:
%6 = load i32, ptr %.8a
%7 = load i32, ptr %.16b
%8 =  sub i32 %6, %7
store i32 %8, ptr %.8a
br label %.L8
.L8:
%.25i = alloca i32
%9 = zext i1 0 to i32
store i32 %9, ptr %.25i
br label %.L9
.L9:
%10 = load i32, ptr %.25i
%11 = zext i8 10 to i32
%12 = icmp slt i32 %10, %11
br i1 %12, label %.L10, label %.L11
.L10:
%13 = load i32, ptr %.8a
%14 = load i32, ptr %.25i
%15 =  add i32 %13, %14
store i32 %15, ptr %.8a
%16 = load i32, ptr %.25i
%17 =  add i32 %16, 1
store i32 %17, ptr %.25i
br label %.L9
.L11:
%18 = load i32, ptr %.8a
%19 = load i32, ptr %.16b
%20 = icmp slt i32 %18, %19
%21 = load i32, ptr %.8a
%22 = load i32, ptr %.16b
%23 = load i32, ptr %.16b
store i32 %23, ptr %.8a
%24 = load i32, ptr %.8a
%25 = load i32, ptr %.16b
%26 =  add i32 %24, %25
%27 = zext i8 3 to i32
store i32 %27, ptr %.8a
%.33c = alloca double
store double 3.300000, ptr %.33c
%28 = load i32, ptr %.8a
%29 = load double, ptr %.33c
%30 = sitofp i32 %28 to double
%31 = fcmp olt double %30, %29
%32 = load double, ptr %.33c
%33 = sitofp i32 1 to double
%34 = fadd double %32, %33
store double %34, ptr %.33c
%35 = load i32, ptr %.8a
%36 = load double, ptr %.33c
%37 = sitofp i32 %35 to double
%38 = fadd double %37, %36
store double %38, ptr %.33c
%39 = load i32, ptr %.8a
store i32 %39, ptr @y
%40 = load i32, ptr @y
%41 = load i32, ptr @x
%42 =  sub i32 %40, %41
store i32 %42, ptr %.8a
%43 = load i32, ptr @x
%44 = load i32, ptr @y
%45 = call i32 (i32, i32) @function (i32 %43, i32 %44)
store i32 %45, ptr %.16b
%46 = call i32 (i32) @printINT (i32 %45)
%47 = load i32, ptr %.16b
%48 = call i32 (i32) @printINT (i32 %47)
%49 = load i32, ptr %.8a
%50 = zext i8 3 to i32
%51 =  mul i32 %49, %50
%52 = zext i1 1 to i32
%53 =  sub i32 %51, %52
store i32 %53, ptr %.16b
%54 = load i32, ptr %.16b
%55 = call i32 (i32) @printINT (i32 %54)
%56 = zext i8 3 to i32
store i32 %56, ptr %.8a
%57 = call i32 (i32) @printINT (i32 %56)
%58 = zext i1 0 to i32
store i32 %58, ptr %.8a
%59 = call i32 (i32) @fibonachi (i32 %58)
%60 = load i32, ptr %.16b
ret i32 %60
.retExit0:
unreachable
}
