; ModuleID = 'main'
source_filename = "main"

@__tmp_str = global [256 x i8] zeroinitializer
@i = global i32 0
@0 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@1 = private unnamed_addr constant [2 x i8] c"\0A\00", align 1
@2 = constant [8 x i8] c"i < 100\00"
@3 = private unnamed_addr constant [3 x i8] c"%s\00", align 1
@4 = private unnamed_addr constant [2 x i8] c"\0A\00", align 1
@5 = constant [9 x i8] c"i >= 100\00"
@6 = private unnamed_addr constant [3 x i8] c"%s\00", align 1
@7 = private unnamed_addr constant [2 x i8] c"\0A\00", align 1
@8 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@9 = private unnamed_addr constant [2 x i8] c"\0A\00", align 1

declare i32 @printf(i8*, ...)

declare i32 @sprintf(i8*, i8*, ...)

declare i32 @abs(i32)

declare double @fabs(double)

declare double @sqrt(double)

declare i8* @strcpy(i8*, i8*)

declare i32 @strlen(i8*)

declare i32 @getchar()

define i32 @main() {
entry:
  store i32 101, i32* @i
  %0 = load i32, i32* @i
  %1 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @0, i32 0, i32 0), i32 %0)
  %2 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @1, i32 0, i32 0))
  %3 = load i32, i32* @i
  %4 = icmp slt i32 %3, 100
  br i1 %4, label %then, label %else

then:                                             ; preds = %entry
  %5 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @3, i32 0, i32 0), [8 x i8]* @2)
  %6 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @4, i32 0, i32 0))
  br label %cont

else:                                             ; preds = %entry
  %7 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @6, i32 0, i32 0), [9 x i8]* @5)
  %8 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @7, i32 0, i32 0))
  br label %cont

cont:                                             ; preds = %else, %then
  store i32 1, i32* @i
  br label %while

while:                                            ; preds = %loop, %cont
  %9 = load i32, i32* @i
  %10 = icmp slt i32 %9, 10
  br i1 %10, label %loop, label %cont1

loop:                                             ; preds = %while
  %11 = load i32, i32* @i
  %12 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @8, i32 0, i32 0), i32 %11)
  %13 = load i32, i32* @i
  %14 = add i32 %13, 1
  store i32 %14, i32* @i
  br label %while

cont1:                                            ; preds = %while
  %15 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @9, i32 0, i32 0))
  ret i32 0
}
