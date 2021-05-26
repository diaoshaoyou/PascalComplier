; ModuleID = 'main'
source_filename = "main"

@__tmp_str = global [256 x i8] zeroinitializer
@garr = global [5 x i32] zeroinitializer
@0 = constant [5 x i8] c"arr[\00"
@1 = private unnamed_addr constant [3 x i8] c"%s\00", align 1
@2 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@3 = constant [4 x i8] c"]: \00"
@4 = private unnamed_addr constant [3 x i8] c"%s\00", align 1
@5 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@6 = constant [8 x i8] c"; garr[\00"
@7 = private unnamed_addr constant [3 x i8] c"%s\00", align 1
@8 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@9 = constant [4 x i8] c"]: \00"
@10 = private unnamed_addr constant [3 x i8] c"%s\00", align 1
@11 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@12 = private unnamed_addr constant [2 x i8] c"\0A\00", align 1

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
  call void @test()
  ret i32 0
}

define void @test() {
entry:
  %0 = alloca i32
  %1 = alloca [5 x i32]
  %2 = alloca [256 x i8]
  %3 = load i32, i32* %0
  store i32 2, i32* %0
  br label %while

while:                                            ; preds = %loop, %entry
  %4 = load i32, i32* %0
  %5 = icmp sge i32 %4, -2
  br i1 %5, label %loop, label %cont

loop:                                             ; preds = %while
  %6 = load i32, i32* %0
  %7 = sub i32 %6, -2
  %8 = getelementptr inbounds [5 x i32], [5 x i32]* %1, i32 0, i32 %7
  %9 = load i32, i32* %0
  %10 = sub i32 2, %9
  store i32 %10, i32* %8
  %11 = load i32, i32* %0
  %12 = sub i32 %11, -2
  %13 = getelementptr inbounds [5 x i32], [5 x i32]* @garr, i32 0, i32 %12
  %14 = load i32, i32* %0
  %15 = mul i32 %14, %14
  store i32 %15, i32* %13
  %16 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @1, i32 0, i32 0), [5 x i8]* @0)
  %17 = load i32, i32* %0
  %18 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @2, i32 0, i32 0), i32 %17)
  %19 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @4, i32 0, i32 0), [4 x i8]* @3)
  %20 = load i32, i32* %0
  %21 = sub i32 %20, -2
  %22 = getelementptr inbounds [5 x i32], [5 x i32]* %1, i32 0, i32 %21
  %23 = load i32, i32* %22
  %24 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @5, i32 0, i32 0), i32 %23)
  %25 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @7, i32 0, i32 0), [8 x i8]* @6)
  %26 = load i32, i32* %0
  %27 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @8, i32 0, i32 0), i32 %26)
  %28 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @10, i32 0, i32 0), [4 x i8]* @9)
  %29 = load i32, i32* %0
  %30 = sub i32 %29, -2
  %31 = getelementptr inbounds [5 x i32], [5 x i32]* @garr, i32 0, i32 %30
  %32 = load i32, i32* %31
  %33 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @11, i32 0, i32 0), i32 %32)
  %34 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @12, i32 0, i32 0))
  %35 = load i32, i32* %0
  %36 = sub i32 %35, 1
  store i32 %36, i32* %0
  br label %while

cont:                                             ; preds = %while
  ret void
}
