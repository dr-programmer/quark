.printINT_body:
%0 = load i32, ptr %a
ret i32 %0
.function_body:
%0 = load i32, ptr %a
%1 = load i32, ptr %b
%2 =  add i32 %0, %1
ret i32 %2
.main_body:
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
%20 = fadd double %18, %19
store double %20, ptr %c
%21 = load i32, ptr %a
@y = i32 %21
%22 = i32 @y
%23 = i32 @x
%24 =  sub i32 %22, %23
store i32 %24, ptr %a
%25 = load i32, ptr %a
%26 =  mul i32 %25, 3
%27 =  sub i32 %26, 1
store i32 %27, ptr %b
%28 = load i32, ptr %b
ret i32 %28
