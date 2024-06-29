target triple = "x86_64-unknown-linux-gnu"
declare i32 @printf (ptr, ...)
define i32 @printINT (i32 %0) {
.printINT_body:
%.8var = alloca i32
store i32 %0, ptr %.8var
%1 = load i32, ptr %.8var
%2 = alloca [5 x i8]
store [4 x i8] c"%d\0A\00", ptr %2
%3 = call i32 (ptr, ...) @printf (ptr %2, i32 %1)
ret i32 %1
.retExit0:
unreachable
}
define void @function () {
.function_body:
%.48arr = alloca [6 x i32]
store [6 x i32] [i32 1, i32 2, i32 3, i32 4, i32 5, i32 6], ptr %.48arr
%0 = load [6 x i32], ptr %.48arr
%1 = sext i8 2 to i32
%2 = getelementptr [6 x i32], ptr %.48arr, i64 0, i32 %1 
%3 = load i32, ptr %2
%4 = call i32 (i32) @printINT (i32 %3)
ret void
.retExit0:
unreachable
}
define void @main () {
.main_body:
%.48arr = alloca [6 x i32]
store [6 x i32] [i32 1, i32 2, i32 3, i32 4, i32 5, i32 6], ptr %.48arr
%.56index = alloca i32
%0 = sext i8 4 to i32
store i32 %0, ptr %.56index
%1 = load [6 x i32], ptr %.48arr
%2 = load i32, ptr %.56index
%3 = getelementptr [6 x i32], ptr %.48arr, i64 0, i32 %2 
%4 = load i32, ptr %3
store i32 128, ptr %3
%5 = load i32, ptr %.56index
%6 = zext i1 1 to i32
%7 =  sub i32 %5, %6
%8 = call i32 (i32) @printINT (i32 %7)
%9 = load [6 x i32], ptr %.48arr
%10 = load i32, ptr %.56index
%11 = zext i1 1 to i32
%12 =  sub i32 %10, %11
%13 = getelementptr [6 x i32], ptr %.48arr, i64 0, i32 %12 
%14 = load i32, ptr %13
%15 = call i32 (i32) @printINT (i32 %14)
call void () @function ()
%16 =  mul i8 -1, 6
%17 = sext i8 %16 to i32
%18 = call i32 (i32) @printINT (i32 %17)
ret void
.retExit0:
unreachable
}
