declare i32 @printf (ptr, ...)
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
%3 = zext i1 %2 to i32
%4 = icmp  ne i32 %3, 0
%5 = load i32, ptr @x
%6 = zext i8 3 to i32
%7 = icmp  eq i32 %5, %6
%8 = zext i1 %7 to i32
%9 = icmp  ne i32 %8, 0
%10 = icmp  eq i1 %4, %9
br i1 %10, label %.L6, label %.L7
.L6:
%11 = load i32, ptr %.8a
%12 = load i32, ptr %.16b
%13 =  add i32 %11, %12
store i32 %13, ptr %.8a
%14 = load i32, ptr @x
%15 = call i32 (i32) @printINT (i32 %14)
br label %.L8
.L7:
%16 = load i32, ptr %.8a
%17 = load i32, ptr %.16b
%18 =  sub i32 %16, %17
store i32 %18, ptr %.8a
br label %.L8
.L8:
%.25i = alloca i32
%19 = zext i1 0 to i32
store i32 %19, ptr %.25i
br label %.L9
.L9:
%20 = load i32, ptr %.25i
%21 = zext i8 10 to i32
%22 = icmp slt i32 %20, %21
br i1 %22, label %.L10, label %.L11
.L10:
%23 = load i32, ptr %.8a
%24 = load i32, ptr %.25i
%25 =  add i32 %23, %24
store i32 %25, ptr %.8a
%26 = load i32, ptr %.25i
%27 =  add i32 %26, 1
store i32 %27, ptr %.25i
br label %.L9
.L11:
%28 = load i32, ptr %.8a
%29 = load i32, ptr %.16b
%30 = icmp slt i32 %28, %29
%31 = load i32, ptr %.8a
%32 = load i32, ptr %.16b
%33 = load i32, ptr %.16b
store i32 %33, ptr %.8a
%34 = load i32, ptr %.8a
%35 = load i32, ptr %.16b
%36 =  add i32 %34, %35
%37 = zext i8 3 to i32
store i32 %37, ptr %.8a
%.33c = alloca double
store double 3.300000, ptr %.33c
%38 = load i32, ptr %.8a
%39 = load double, ptr %.33c
%40 = sitofp i32 %38 to double
%41 = fcmp olt double %40, %39
%42 = load double, ptr %.33c
%43 = sitofp i32 1 to double
%44 = fadd double %42, %43
store double %44, ptr %.33c
%45 = load i32, ptr %.8a
%46 = load double, ptr %.33c
%47 = sitofp i32 %45 to double
%48 = fadd double %47, %46
store double %48, ptr %.33c
%49 = load i32, ptr %.8a
store i32 %49, ptr @y
%50 = load i32, ptr @y
%51 = load i32, ptr @x
%52 =  sub i32 %50, %51
store i32 %52, ptr %.8a
%53 = load i32, ptr %.8a
%54 = zext i8 3 to i32
%55 =  mul i32 %53, %54
%56 = zext i1 1 to i32
%57 =  sub i32 %55, %56
store i32 %57, ptr %.16b
%58 = zext i8 6 to i32
%59 = call i32 (i32) @fibonachi (i32 %58)
%60 = load i32, ptr %.16b
ret i32 %60
.retExit0:
unreachable
}
