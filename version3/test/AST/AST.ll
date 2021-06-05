; ModuleID = 'main'
source_filename = "main"

@__tmp_str = global [256 x i8] zeroinitializer
@i = global i32 0
@0 = constant [6 x i8] c"x < y\00"
@1 = private unnamed_addr constant [3 x i8] c"%s\00", align 1
@2 = private unnamed_addr constant [2 x i8] c"\0A\00", align 1
@3 = constant [7 x i8] c"x >= y\00"
@4 = private unnamed_addr constant [3 x i8] c"%s\00", align 1
@5 = private unnamed_addr constant [2 x i8] c"\0A\00", align 1
@6 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@7 = private unnamed_addr constant [2 x i8] c"\0A\00", align 1
@8 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@9 = private unnamed_addr constant [2 x i8] c"\0A\00", align 1

declare i32 @printf(i8*, ...)

declare i32 @sprintf(i8*, i8*, ...)

declare i32 @scanf(i8*, ...)

declare i32 @abs(i32)

declare double @fabs(double)

declare double @sqrt(double)

declare i8* @strcpy(i8*, i8*)

declare i8* @strcat(i8*, i8*)

declare i32 @strlen(i8*)

declare i32 @atoi(i8*)

declare i32 @getchar()

define i32 @main() {
entry:
  store i32 101, i32* @i
  br i1 true, label %then, label %else

then:                                             ; preds = %entry
  %0 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @1, i32 0, i32 0), [6 x i8]* @0)
  %1 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @2, i32 0, i32 0))
  br label %cont

else:                                             ; preds = %entry
  %2 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @4, i32 0, i32 0), [7 x i8]* @3)
  %3 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @5, i32 0, i32 0))
  br label %cont

cont:                                             ; preds = %else, %then
  store i32 0, i32* @i
  br label %repeat

repeat:                                           ; preds = %repeat, %cont
  %4 = load i32, i32* @i
  %5 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @6, i32 0, i32 0), i32 %4)
  %6 = load i32, i32* @i
  %7 = add i32 %6, 1
  store i32 %7, i32* @i
  br i1 true, label %cont1, label %repeat

cont1:                                            ; preds = %repeat
  %8 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @7, i32 0, i32 0))
  br label %while

while:                                            ; preds = %loop, %cont1
  br i1 false, label %loop, label %cont2

loop:                                             ; preds = %while
  %9 = load i32, i32* @i
  %10 = sub i32 %9, 1
  store i32 %10, i32* @i
  %11 = load i32, i32* @i
  %12 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @8, i32 0, i32 0), i32 %11)
  br label %while

cont2:                                            ; preds = %while
  %13 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @9, i32 0, i32 0))
  ret i32 0
}
