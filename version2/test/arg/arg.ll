; ModuleID = 'main'
source_filename = "main"

@__tmp_str = global [256 x i8] zeroinitializer
@i = global i32 0
@r = global double 0.000000e+00
@0 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@1 = private unnamed_addr constant [2 x i8] c"\0A\00", align 1
@2 = private unnamed_addr constant [3 x i8] c"%f\00", align 1
@3 = private unnamed_addr constant [2 x i8] c"\0A\00", align 1
@4 = private unnamed_addr constant [3 x i8] c"%c\00", align 1
@5 = private unnamed_addr constant [2 x i8] c"\0A\00", align 1

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
  store i32 2, i32* @i
  store double 1.440000e+00, double* @r
  %0 = load double, double* @r
  %1 = fptosi double %0 to i32
  call void @test1(i32 %1)
  %2 = load double, double* @r
  call void @test2(double %2)
  %3 = load i32, i32* @i
  call void @test1(i32 %3)
  %4 = load i32, i32* @i
  %5 = sitofp i32 %4 to double
  call void @test2(double %5)
  call void @test1(i32 1)
  call void @test2(double 1.000000e+00)
  call void @test3(i8 99)
  ret i32 0
}

define void @test1(i32) {
entry:
  %1 = alloca i32
  store i32 %0, i32* %1
  %2 = load i32, i32* %1
  %3 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @0, i32 0, i32 0), i32 %2)
  %4 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @1, i32 0, i32 0))
  ret void
}

define void @test2(double) {
entry:
  %1 = alloca double
  store double %0, double* %1
  %2 = load double, double* %1
  %3 = call double @sqrt(double %2)
  %4 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @2, i32 0, i32 0), double %3)
  %5 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @3, i32 0, i32 0))
  ret void
}

define void @test3(i8) {
entry:
  %1 = alloca i8
  store i8 %0, i8* %1
  %2 = load i8, i8* %1
  %3 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @4, i32 0, i32 0), i8 %2)
  %4 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @5, i32 0, i32 0))
  ret void
}
