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
%8 = zext i8 6 to i32
%9 = load ptr, ptr %.16ptr
%10 = load i32, ptr %9
store i32 %8, ptr %9
%11 = load i32, ptr %.8var
%12 = call i32 (i32) @printINT (i32 %11)
%.64arr = alloca [6 x i32]
store [6 x i32] [i32 1, i32 2, i32 3, i32 4, i32 5, i32 6], ptr %.64arr
%13 = load [6 x i32], ptr %.64arr
%14 = getelementptr [6 x i32], ptr %.64arr, i1 0, i1 0 
%15 = load i32, ptr %14
%16 = call i32 (i32) @printINT (i32 %15)
%.72i = alloca i32
%17 = zext i1 0 to i32
store i32 %17, ptr %.72i
br label %.L3
.L3:
%18 = load i32, ptr %.72i
%19 = zext i8 6 to i32
%20 = icmp slt i32 %18, %19
br i1 %20, label %.L4, label %.L5
.L4:
%21 = load [6 x i32], ptr %.64arr
%22 = load i32, ptr %.72i
%23 = getelementptr [6 x i32], ptr %.64arr, i1 0, i32 %22 
%24 = load i32, ptr %23
%25 = call i32 (i32) @printINT (i32 %24)
%26 = load i32, ptr %.72i
%27 =  add i32 %26, 1
store i32 %27, ptr %.72i
br label %.L3
.L5:
ret i32 0
.retExit0:
unreachable
}
