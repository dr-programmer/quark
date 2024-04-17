target triple = "x86_64-unknown-linux-gnu"
declare i32 @printf (ptr, ...)
define i32 @fibonachi (i32 %0) {
.fibonachi_body:
%.8a = alloca i32
store i32 %0, ptr %.8a
%1 = load i32, ptr %.8a
%2 = zext i1 1 to i32
%3 = icmp sle i32 %1, %2
br i1 %3, label %.L0, label %.L1
.L0:
%4 = load i32, ptr %.8a
ret i32 %4
.retExit0:
br label %.L2
.L1:
%5 = load i32, ptr %.8a
%6 = zext i1 1 to i32
%7 =  sub i32 %5, %6
%8 = call i32 (i32) @fibonachi (i32 %7)
%9 = load i32, ptr %.8a
%10 = zext i8 2 to i32
%11 =  sub i32 %9, %10
%12 = call i32 (i32) @fibonachi (i32 %11)
%13 =  add i32 %8, %12
ret i32 %13
.retExit1:
br label %.L2
.L2:
unreachable
}
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
%.8var = alloca i32
%0 = zext i1 0 to i32
store i32 %0, ptr %.8var
%1 = zext i8 6 to i32
%2 = call i32 (i32) @fibonachi (i32 %1)
store i32 %2, ptr %.8var
%3 = load i32, ptr %.8var
%4 = call i32 (i32) @printINT (i32 %3)
%.16ptr = alloca ptr
store ptr %.8var, ptr %.16ptr
%5 = load ptr, ptr %.16ptr
%6 = load i32, ptr %5
%7 = call i32 (i32) @printINT (i32 %6)
%.24ptr1 = alloca ptr
%8 = load ptr, ptr %.16ptr
store ptr %8, ptr %.24ptr1
%9 = load ptr, ptr %.24ptr1
%10 = load i32, ptr %9
%11 = call i32 (i32) @printINT (i32 %10)
%12 = zext i8 6 to i32
%13 = load ptr, ptr %.16ptr
%14 = load i32, ptr %13
store i32 %12, ptr %13
%15 = load i32, ptr %.8var
%16 = call i32 (i32) @printINT (i32 %15)
%.72arr = alloca [6 x i32]
store [6 x i32] [i32 1, i32 2, i32 3, i32 4, i32 5, i32 6], ptr %.72arr
%17 = load [6 x i32], ptr %.72arr
%18 = getelementptr [6 x i32], ptr %.72arr, i1 0, i1 0 
%19 = load i32, ptr %18
%20 = call i32 (i32) @printINT (i32 %19)
%.80i = alloca i32
%21 = zext i1 0 to i32
store i32 %21, ptr %.80i
br label %.L3
.L3:
%22 = load i32, ptr %.80i
%23 = zext i8 6 to i32
%24 = icmp slt i32 %22, %23
br i1 %24, label %.L4, label %.L5
.L4:
%25 = load [6 x i32], ptr %.72arr
%26 = load i32, ptr %.80i
%27 = getelementptr [6 x i32], ptr %.72arr, i1 0, i32 %26 
%28 = load i32, ptr %27
%29 = call i32 (i32) @printINT (i32 %28)
%30 = load i32, ptr %.80i
%31 =  add i32 %30, 1
store i32 %31, ptr %.80i
br label %.L3
.L5:
ret i32 0
.retExit0:
unreachable
}
