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
%.48arr = alloca [6 x i32]
store [6 x i32] [i32 1, i32 2, i32 3, i32 4, i32 5, i32 6], ptr %.48arr
%.54str = alloca [6 x i8]
store [6 x i8] c"Hello\00", ptr %.54str
%.62check = alloca i32
%0 = load [6 x i32], ptr %.48arr
%1 = getelementptr [6 x i32], ptr %.48arr, i1 0, i8 5 
%2 = load i32, ptr %1
store i32 %2, ptr %.62check
%.70a = alloca i32
%3 = load [6 x i32], ptr %.48arr
%4 = getelementptr [6 x i32], ptr %.48arr, i1 0, i8 4 
%5 = load i32, ptr %4
%6 = zext i8 3 to i32
%7 =  add i32 %5, %6
%8 = zext i8 2 to i32
%9 =  sub i32 %7, %8
store i32 %9, ptr %.70a
%10 = zext i8 8 to i32
%11 = load [6 x i32], ptr %.48arr
%12 = getelementptr [6 x i32], ptr %.48arr, i1 0, i8 4 
%13 = load i32, ptr %12
store i32 %10, ptr %12
%14 = load [6 x i32], ptr %.48arr
%15 = getelementptr [6 x i32], ptr %.48arr, i1 0, i8 4 
%16 = load i32, ptr %15
%17 = call i32 (i32) @printINT (i32 %16)
%18 = load i32, ptr %.70a
%19 = call i32 (i32) @printINT (i32 %18)
%.78b = alloca i32
%20 = zext i8 6 to i32
store i32 %20, ptr %.78b
%.79temp = alloca i1
store i1 1, ptr %.79temp
%21 = icmp  eq i8 5, 5
%22 = zext i1 %21 to i32
%23 = icmp  ne i32 %22, 0
%24 = load i1, ptr %.79temp
%25 = icmp  eq i1 %24, 1
%26 = zext i1 %25 to i32
%27 = icmp  ne i32 %26, 0
%28 = and i1 %23, %27
br i1 %28, label %.L6, label %.L7
.L6:
%29 = load i32, ptr %.70a
%30 = load i32, ptr %.78b
%31 =  add i32 %29, %30
store i32 %31, ptr %.70a
%32 = load i32, ptr @x
%33 = call i32 (i32) @printINT (i32 %32)
br label %.L8
.L7:
%34 = load i32, ptr %.70a
%35 = load i32, ptr %.78b
%36 =  sub i32 %34, %35
store i32 %36, ptr %.70a
br label %.L8
.L8:
%.87i = alloca i32
%37 = zext i1 0 to i32
store i32 %37, ptr %.87i
br label %.L9
.L9:
%38 = load i32, ptr %.87i
%39 = zext i8 10 to i32
%40 = icmp slt i32 %38, %39
br i1 %40, label %.L10, label %.L11
.L10:
%41 = load i32, ptr %.70a
%42 = load i32, ptr %.87i
%43 =  add i32 %41, %42
store i32 %43, ptr %.70a
%44 = load i32, ptr %.87i
%45 =  add i32 %44, 1
store i32 %45, ptr %.87i
br label %.L9
.L11:
%46 = load i32, ptr %.70a
%47 = load i32, ptr %.78b
%48 = icmp slt i32 %46, %47
%49 = load i32, ptr %.70a
%50 = load i32, ptr %.78b
%51 = load i32, ptr %.78b
store i32 %51, ptr %.70a
%52 = load i32, ptr %.70a
%53 = load i32, ptr %.78b
%54 =  add i32 %52, %53
%55 = zext i8 3 to i32
store i32 %55, ptr %.70a
%.95c = alloca double
store double 3.300000, ptr %.95c
%56 = load i32, ptr %.70a
%57 = load double, ptr %.95c
%58 = sitofp i32 %56 to double
%59 = fcmp olt double %58, %57
%60 = load double, ptr %.95c
%61 = sitofp i32 1 to double
%62 = fadd double %60, %61
store double %62, ptr %.95c
%63 = load i32, ptr %.70a
%64 = load double, ptr %.95c
%65 = sitofp i32 %63 to double
%66 = fadd double %65, %64
store double %66, ptr %.95c
%67 = load i32, ptr %.70a
store i32 %67, ptr @y
%68 = load i32, ptr @y
%69 = load i32, ptr @x
%70 =  sub i32 %68, %69
store i32 %70, ptr %.70a
%71 = load i32, ptr %.70a
%72 = zext i8 3 to i32
%73 =  mul i32 %71, %72
%74 = zext i1 1 to i32
%75 =  sub i32 %73, %74
store i32 %75, ptr %.78b
%76 = load i32, ptr %.78b
ret i32 %76
.retExit0:
unreachable
}
