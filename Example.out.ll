target triple = "x86_64-unknown-linux-gnu"
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
define i32 @main () {
.main_body:
%.8sum = alloca i32
%0 = zext i1 0 to i32
store i32 %0, ptr %.8sum
%.16i = alloca i32
%1 = zext i1 0 to i32
store i32 %1, ptr %.16i
%2 = zext i1 0 to i32
store i32 %2, ptr %.16i
br label %.L0
.L0:
%3 = load i32, ptr %.16i
%4 = zext i8 10 to i32
%5 = icmp slt i32 %3, %4
br i1 %5, label %.L1, label %.L2
.L1:
%6 = load i32, ptr %.8sum
%7 = load i32, ptr %.16i
%8 =  add i32 %6, %7
store i32 %8, ptr %.8sum
%9 = load i32, ptr %.16i
%10 =  add i32 %9, 1
store i32 %10, ptr %.16i
br label %.L0
.L2:
%11 = load i32, ptr %.8sum
%12 = call i32 (i32) @printINT (i32 %11)
%13 = zext i1 1 to i32
store i32 %13, ptr %.8sum
%14 = zext i1 1 to i32
store i32 %14, ptr %.16i
br label %.L3
.L3:
%15 = load i32, ptr %.16i
%16 = zext i8 10 to i32
%17 = icmp slt i32 %15, %16
br i1 %17, label %.L4, label %.L5
.L4:
%18 = load i32, ptr %.8sum
%19 = load i32, ptr %.16i
%20 =  mul i32 %18, %19
store i32 %20, ptr %.8sum
%21 = load i32, ptr %.16i
%22 =  add i32 %21, 1
store i32 %22, ptr %.16i
br label %.L3
.L5:
%23 = load i32, ptr %.8sum
%24 = call i32 (i32) @printINT (i32 %23)
ret i32 0
.retExit0:
unreachable
}
