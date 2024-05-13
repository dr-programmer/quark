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
%1 = getelementptr [6 x i32], ptr %.48arr, i1 0, i8 2 
%2 = load i32, ptr %1
%3 = call i32 (i32) @printINT (i32 %2)
ret void
.retExit0:
unreachable
}
define void @main () {
.main_body:
%.48arr = alloca [6 x i32]
store [6 x i32] [i32 1, i32 2, i32 3, i32 4, i32 5, i32 6], ptr %.48arr
%0 = sext i8 6 to i32
%1 = load [6 x i32], ptr %.48arr
%2 = getelementptr [6 x i32], ptr %.48arr, i1 0, i1 1 
%3 = load i32, ptr %2
store i32 %0, ptr %2
%4 = load [6 x i32], ptr %.48arr
%5 = getelementptr [6 x i32], ptr %.48arr, i1 0, i8 5 
%6 = load i32, ptr %5
%7 = call i32 (i32) @printINT (i32 %6)
call void () @function ()
%8 =  mul i8 -1, 6
%9 = sext i8 %8 to i32
%10 = call i32 (i32) @printINT (i32 %9)
ret void
.retExit0:
unreachable
}
