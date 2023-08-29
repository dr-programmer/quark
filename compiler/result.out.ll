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
%3 = load i32, ptr %.62check
%4 = call i32 (i32) @printINT (i32 %3)
%5 = load [6 x i8], ptr %.54str
%6 = getelementptr [6 x i8], ptr %.54str, i1 0, i1 0 
%7 = load i8, ptr %6
%8 = zext i8 %7 to i32
%9 = call i32 (i32) @printINT (i32 %8)
%.70a = alloca i32
%10 = zext i8 5 to i32
store i32 %10, ptr %.70a
%.78b = alloca i32
%11 = zext i8 6 to i32
store i32 %11, ptr %.78b
%.79temp = alloca i1
store i1 1, ptr %.79temp
%12 = load i32, ptr %.70a
%13 = load i32, ptr %.78b
%14 = icmp  eq i32 %12, %13
%15 = zext i1 %14 to i32
%16 = icmp  ne i32 %15, 0
%17 = load i32, ptr @x
%18 = zext i8 3 to i32
%19 = icmp  eq i32 %17, %18
%20 = zext i1 %19 to i32
%21 = icmp  ne i32 %20, 0
%22 = icmp  eq i1 %16, %21
br i1 %22, label %.L6, label %.L7
.L6:
%23 = load i32, ptr %.70a
%24 = load i32, ptr %.78b
%25 =  add i32 %23, %24
store i32 %25, ptr %.70a
%26 = load i32, ptr @x
%27 = call i32 (i32) @printINT (i32 %26)
br label %.L8
.L7:
%28 = load i32, ptr %.70a
%29 = load i32, ptr %.78b
%30 =  sub i32 %28, %29
store i32 %30, ptr %.70a
br label %.L8
.L8:
%.87i = alloca i32
%31 = zext i1 0 to i32
store i32 %31, ptr %.87i
br label %.L9
.L9:
%32 = load i32, ptr %.87i
%33 = zext i8 10 to i32
%34 = icmp slt i32 %32, %33
br i1 %34, label %.L10, label %.L11
.L10:
%35 = load i32, ptr %.70a
%36 = load i32, ptr %.87i
%37 =  add i32 %35, %36
store i32 %37, ptr %.70a
%38 = load i32, ptr %.87i
%39 =  add i32 %38, 1
store i32 %39, ptr %.87i
br label %.L9
.L11:
%40 = load i32, ptr %.70a
%41 = load i32, ptr %.78b
%42 = icmp slt i32 %40, %41
%43 = load i32, ptr %.70a
%44 = load i32, ptr %.78b
%45 = load i32, ptr %.78b
store i32 %45, ptr %.70a
%46 = load i32, ptr %.70a
%47 = load i32, ptr %.78b
%48 =  add i32 %46, %47
%49 = zext i8 3 to i32
store i32 %49, ptr %.70a
%.95c = alloca double
store double 3.300000, ptr %.95c
%50 = load i32, ptr %.70a
%51 = load double, ptr %.95c
%52 = sitofp i32 %50 to double
%53 = fcmp olt double %52, %51
%54 = load double, ptr %.95c
%55 = sitofp i32 1 to double
%56 = fadd double %54, %55
store double %56, ptr %.95c
%57 = load i32, ptr %.70a
%58 = load double, ptr %.95c
%59 = sitofp i32 %57 to double
%60 = fadd double %59, %58
store double %60, ptr %.95c
%61 = load i32, ptr %.70a
store i32 %61, ptr @y
%62 = load i32, ptr @y
%63 = load i32, ptr @x
%64 =  sub i32 %62, %63
store i32 %64, ptr %.70a
%65 = load i32, ptr %.70a
%66 = zext i8 3 to i32
%67 =  mul i32 %65, %66
%68 = zext i1 1 to i32
%69 =  sub i32 %67, %68
store i32 %69, ptr %.78b
%70 = zext i8 6 to i32
%71 = call i32 (i32) @fibonachi (i32 %70)
%72 = load i32, ptr %.78b
ret i32 %72
.retExit0:
unreachable
}
