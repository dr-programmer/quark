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
%9 = add i8 10, 0
%10 = zext i8 %9 to i32
%11 = icmp sgt i32 %8, %10
br i1 %11, label %.L0, label %.L1
.L0:
%12 = load i32, ptr %.8a
%13 = load i32, ptr %.16b
%14 =  add i32 %12, %13
ret i32 %14
.retExit0:
br label %.L2
.L1:
%15 = load i32, ptr %.8a
%16 = add i1 1, 0
%17 = zext i1 %16 to i32
%18 =  add i32 %15, %17
%19 = load i32, ptr %.16b
%20 = add i1 1, 0
%21 = zext i1 %20 to i32
%22 =  add i32 %19, %21
%23 = call i32 (i32, i32) @function (i32 %18, i32 %22)
ret i32 %23
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
%2 = add i1 1, 0
%3 = zext i1 %2 to i32
%4 = icmp sle i32 %1, %3
br i1 %4, label %.L3, label %.L4
.L3:
%5 = load i32, ptr %.8a
%6 = alloca [5 x i8]
store [4 x i8] c"%d\0A\00", ptr %6
%7 = call i32 (ptr, ...) @printf (ptr %6, i32 %5)
ret i32 %5
.retExit0:
br label %.L5
.L4:
%8 = load i32, ptr %.8a
%9 = add i1 1, 0
%10 = zext i1 %9 to i32
%11 =  sub i32 %8, %10
%12 = call i32 (i32) @fibonachi (i32 %11)
%13 = load i32, ptr %.8a
%14 = add i8 2, 0
%15 = zext i8 %14 to i32
%16 =  sub i32 %13, %15
%17 = call i32 (i32) @fibonachi (i32 %16)
%18 =  add i32 %12, %17
%19 = alloca [5 x i8]
store [4 x i8] c"%d\0A\00", ptr %19
%20 = call i32 (ptr, ...) @printf (ptr %19, i32 %18)
ret i32 %18
.retExit1:
br label %.L5
.L5:
unreachable
}
%21 = add i8 3, 0
@x = global i32 %21
%22 = add i8 6, 0
@y = global i32 %22
define i32 @main () {
.main_body:
%.48arr = alloca [6 x i32]
%0 = add i1 1, 0
%1 = add i8 2, 0
%2 = add i8 3, 0
%3 = add i8 4, 0
%4 = add i8 5, 0
%5 = add i8 6, 0
store [6 x i32] [i32 1, i32 2, i32 3, i32 4, i32 5, i32 6], ptr %.48arr
%.54str = alloca [6 x i8]
store [6 x i8] c"Hello\00", ptr %.54str
%.62check = alloca i32
%6 = load [6 x i32], ptr %.48arr
%7 = add i8 5, 0
%8 = getelementptr [6 x i32], ptr %.48arr, i1 0, i8 %7 
%9 = load i32, ptr %8
store i32 %9, ptr %.62check
%.70a = alloca i32
%10 = add i8 5, 0
%11 = add i8 3, 0
%12 =  add i8 %10, %11
%13 = add i8 2, 0
%14 =  sub i8 %12, %13
%15 = zext i8 %14 to i32
store i32 %15, ptr %.70a
%.78b = alloca i32
%16 = add i8 6, 0
%17 = zext i8 %16 to i32
store i32 %17, ptr %.78b
%.79temp = alloca i1
%18 = add i1 1, 0
store i1 %18, ptr %.79temp
%19 = add i8 5, 0
%20 = add i8 5, 0
%21 = icmp  eq i8 %19, %20
%22 = add i32 0, 0
%23 = zext i1 %21 to i32
%24 = icmp  ne i32 %23, %22
%25 = load i1, ptr %.79temp
%26 = add i1 1, 0
%27 = icmp  eq i1 %25, %26
%28 = add i32 0, 0
%29 = zext i1 %27 to i32
%30 = icmp  ne i32 %29, %28
%31 = and i1 %24, %30
br i1 %31, label %.L6, label %.L7
.L6:
%32 = load i32, ptr %.70a
%33 = load i32, ptr %.78b
%34 =  add i32 %32, %33
store i32 %34, ptr %.70a
%35 = load i32, ptr @x
%36 = call i32 (i32) @printINT (i32 %35)
br label %.L8
.L7:
%37 = load i32, ptr %.70a
%38 = load i32, ptr %.78b
%39 =  sub i32 %37, %38
store i32 %39, ptr %.70a
br label %.L8
.L8:
%.87i = alloca i32
%40 = add i1 0, 0
%41 = zext i1 %40 to i32
store i32 %41, ptr %.87i
br label %.L9
.L9:
%42 = load i32, ptr %.87i
%43 = add i8 10, 0
%44 = zext i8 %43 to i32
%45 = icmp slt i32 %42, %44
br i1 %45, label %.L10, label %.L11
.L10:
%46 = load i32, ptr %.70a
%47 = load i32, ptr %.87i
%48 =  add i32 %46, %47
store i32 %48, ptr %.70a
%49 = load i32, ptr %.87i
%50 = add i32 1, 0
%51 =  add i32 %49, %50
store i32 %51, ptr %.87i
br label %.L9
.L11:
%52 = load i32, ptr %.70a
%53 = load i32, ptr %.78b
%54 = icmp slt i32 %52, %53
%55 = load i32, ptr %.70a
%56 = load i32, ptr %.78b
%57 = load i32, ptr %.78b
store i32 %57, ptr %.70a
%58 = load i32, ptr %.70a
%59 = load i32, ptr %.78b
%60 =  add i32 %58, %59
%61 = add i8 3, 0
%62 = zext i8 %61 to i32
store i32 %62, ptr %.70a
%.95c = alloca double
%63 = fadd double 3.300000, 0
store double %63, ptr %.95c
%64 = load i32, ptr %.70a
%65 = load double, ptr %.95c
%66 = sitofp i32 %64 to double
%67 = fcmp olt double %66, %65
%68 = load double, ptr %.95c
%69 = add i32 1, 0
%70 = sitofp i32 %69 to double
%71 = fadd double %68, %70
store double %71, ptr %.95c
%72 = load i32, ptr %.70a
%73 = load double, ptr %.95c
%74 = sitofp i32 %72 to double
%75 = fadd double %74, %73
store double %75, ptr %.95c
%76 = load i32, ptr %.70a
store i32 %76, ptr @y
%77 = load i32, ptr @y
%78 = load i32, ptr @x
%79 =  sub i32 %77, %78
store i32 %79, ptr %.70a
%80 = load i32, ptr %.70a
%81 = add i8 3, 0
%82 = zext i8 %81 to i32
%83 =  mul i32 %80, %82
%84 = add i1 1, 0
%85 = zext i1 %84 to i32
%86 =  sub i32 %83, %85
store i32 %86, ptr %.78b
%87 = load i32, ptr %.78b
ret i32 %87
.retExit0:
unreachable
}
