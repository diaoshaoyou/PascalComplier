; ModuleID = 'main'
source_filename = "main"

@__tmp_str = global [256 x i8] zeroinitializer
@a = global i32 0
@b = global double 0.000000e+00
@c = global i1 false
@d = global i32 0
@e = global [256 x i8] zeroinitializer
@f = global i8 0

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
  ret i32 0
}

define void @f1(i32) {
entry:
  %1 = alloca i32
  store i32 %0, i32* %1
  %2 = alloca [4 x i32]
  %3 = alloca [5 x [256 x i8]]
  ret void
}

define void @f2(i1) {
entry:
  %1 = alloca i1
  store i1 %0, i1* %1
  %2 = alloca { i32, [256 x i8], double }
  %3 = alloca { i32, [256 x i8], double }
  ret void
}
