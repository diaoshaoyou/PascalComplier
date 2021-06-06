; ModuleID = 'main'
source_filename = "main"

@__tmp_str = global [256 x i8] zeroinitializer
@a = global i32 0
@b = global i32 0
@c = global i32 0
@d = global double 0.000000e+00
@e = global double 0.000000e+00
@f = global i1 false
@0 = constant [5 x i8] c"gcd=\00"
@1 = private unnamed_addr constant [3 x i8] c"%s\00", align 1
@2 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@3 = private unnamed_addr constant [2 x i8] c"\0A\00", align 1

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
  store i32 27, i32* @a
  store i32 12, i32* @b
  %0 = load i32, i32* @a
  %1 = load i32, i32* @b
  %2 = call i32 @gcd(i32 %0, i32 %1)
  store i32 %2, i32* @c
  %3 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @1, i32 0, i32 0), [5 x i8]* @0)
  %4 = load i32, i32* @c
  %5 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @2, i32 0, i32 0), i32 %4)
  %6 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @3, i32 0, i32 0))
  ret i32 0
}

define i32 @gcd(i32, i32) {
entry:
  %2 = alloca i32
  store i32 %0, i32* %2
  %3 = alloca i32
  store i32 %1, i32* %3
  %4 = alloca i32
  %5 = load i32, i32* %3
  %6 = icmp eq i32 %5, 0
  br i1 %6, label %then, label %else

then:                                             ; preds = %entry
  %7 = load i32, i32* %2
  store i32 %7, i32* %4
  br label %cont

else:                                             ; preds = %entry
  %8 = load i32, i32* %3
  %9 = load i32, i32* %2
  %10 = load i32, i32* %3
  %11 = srem i32 %9, %10
  %12 = call i32 @gcd(i32 %8, i32 %11)
  store i32 %12, i32* %4
  br label %cont

cont:                                             ; preds = %else, %then
  %13 = load i32, i32* %4
  ret i32 %13
}
