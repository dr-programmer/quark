.printINT_body:
.function_body:
.main_body:
%0 = load i32, ptr %a
%1 = load i32, ptr %b
%2 = load i32, ptr %b
store i32 %2, ptr %a
store i32 %0, ptr %a
store i32 %0, ptr %b
