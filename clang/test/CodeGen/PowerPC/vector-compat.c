// INTEL RUN: not %clang_cc1 -target-feature +altivec -target-feature +vsx \
// INTEL RUN:   -faltivec-src-compat=mixed -triple powerpc-unknown-unknown -S -emit-llvm %s -o - 2>&1 | FileCheck %s --check-prefix=ERROR
// INTEL RUN: %clang_cc1 -target-feature +altivec -target-feature +vsx \
// INTEL RUN:   -faltivec-src-compat=gcc -triple powerpc-unknown-unknown -S -emit-llvm %s -o - | FileCheck %s
// INTEL RUN: not %clang_cc1 -target-feature +altivec -target-feature +vsx \
// INTEL RUN:   -faltivec-src-compat=xl -triple powerpc-unknown-unknown -S -emit-llvm %s -o - 2>&1 | FileCheck %s --check-prefix=ERROR
// INTEL RUN: %clang -mcpu=pwr8 -faltivec-src-compat=gcc --target=powerpc-unknown-unknown -S -emit-llvm %s -o - | FileCheck %s
// INTEL RUN: %clang -mcpu=pwr9 -faltivec-src-compat=gcc --target=powerpc-unknown-unknown -S -emit-llvm %s -o - | FileCheck %s

// CHECK-LABEL: @ui8(
// CHECK:         [[A_ADDR:%.*]] = alloca <16 x i8>, align 16
// CHECK-NEXT:    [[B_ADDR:%.*]] = alloca <16 x i8>, align 16
// CHECK-NEXT:    store <16 x i8> [[A:%.*]], ptr [[A_ADDR]], align 16
// CHECK-NEXT:    store <16 x i8> [[B:%.*]], ptr [[B_ADDR]], align 16
// CHECK-NEXT:    [[TMP0:%.*]] = load <16 x i8>, ptr [[A_ADDR]], align 16
// CHECK-NEXT:    [[TMP1:%.*]] = load <16 x i8>, ptr [[B_ADDR]], align 16
// CHECK-NEXT:    [[CMP:%.*]] = icmp eq <16 x i8> [[TMP0]], [[TMP1]]
// CHECK-NEXT:    [[SEXT:%.*]] = sext <16 x i1> [[CMP]] to <16 x i8>
// CHECK-NEXT:    ret <16 x i8> [[SEXT]]
//
// ERROR: returning 'int' from a function with incompatible result type
vector unsigned char ui8(vector unsigned char a, vector unsigned char b) {
  return a == b;
}

// CHECK-LABEL: @si8(
// CHECK:         [[A_ADDR:%.*]] = alloca <16 x i8>, align 16
// CHECK-NEXT:    [[B_ADDR:%.*]] = alloca <16 x i8>, align 16
// CHECK-NEXT:    store <16 x i8> [[A:%.*]], ptr [[A_ADDR]], align 16
// CHECK-NEXT:    store <16 x i8> [[B:%.*]], ptr [[B_ADDR]], align 16
// CHECK-NEXT:    [[TMP0:%.*]] = load <16 x i8>, ptr [[A_ADDR]], align 16
// CHECK-NEXT:    [[TMP1:%.*]] = load <16 x i8>, ptr [[B_ADDR]], align 16
// CHECK-NEXT:    [[CMP:%.*]] = icmp eq <16 x i8> [[TMP0]], [[TMP1]]
// CHECK-NEXT:    [[SEXT:%.*]] = sext <16 x i1> [[CMP]] to <16 x i8>
// CHECK-NEXT:    ret <16 x i8> [[SEXT]]
//
// ERROR: returning 'int' from a function with incompatible result type
vector signed char si8(vector signed char a, vector signed char b) {
  return a == b;
}

// CHECK-LABEL: @ui16(
// CHECK:         [[A_ADDR:%.*]] = alloca <8 x i16>, align 16
// CHECK-NEXT:    [[B_ADDR:%.*]] = alloca <8 x i16>, align 16
// CHECK-NEXT:    store <8 x i16> [[A:%.*]], ptr [[A_ADDR]], align 16
// CHECK-NEXT:    store <8 x i16> [[B:%.*]], ptr [[B_ADDR]], align 16
// CHECK-NEXT:    [[TMP0:%.*]] = load <8 x i16>, ptr [[A_ADDR]], align 16
// CHECK-NEXT:    [[TMP1:%.*]] = load <8 x i16>, ptr [[B_ADDR]], align 16
// CHECK-NEXT:    [[CMP:%.*]] = icmp eq <8 x i16> [[TMP0]], [[TMP1]]
// CHECK-NEXT:    [[SEXT:%.*]] = sext <8 x i1> [[CMP]] to <8 x i16>
// CHECK-NEXT:    ret <8 x i16> [[SEXT]]
//
// ERROR: returning 'int' from a function with incompatible result type
vector unsigned short ui16(vector unsigned short a, vector unsigned short b) {
  return a == b;
}

// CHECK-LABEL: @si16(
// CHECK:         [[A_ADDR:%.*]] = alloca <8 x i16>, align 16
// CHECK-NEXT:    [[B_ADDR:%.*]] = alloca <8 x i16>, align 16
// CHECK-NEXT:    store <8 x i16> [[A:%.*]], ptr [[A_ADDR]], align 16
// CHECK-NEXT:    store <8 x i16> [[B:%.*]], ptr [[B_ADDR]], align 16
// CHECK-NEXT:    [[TMP0:%.*]] = load <8 x i16>, ptr [[A_ADDR]], align 16
// CHECK-NEXT:    [[TMP1:%.*]] = load <8 x i16>, ptr [[B_ADDR]], align 16
// CHECK-NEXT:    [[CMP:%.*]] = icmp eq <8 x i16> [[TMP0]], [[TMP1]]
// CHECK-NEXT:    [[SEXT:%.*]] = sext <8 x i1> [[CMP]] to <8 x i16>
// CHECK-NEXT:    ret <8 x i16> [[SEXT]]
//
// ERROR: returning 'int' from a function with incompatible result type
vector signed short si16(vector signed short a, vector signed short b) {
  return a == b;
}

// CHECK-LABEL: @ui32(
// CHECK:         [[A_ADDR:%.*]] = alloca <4 x i32>, align 16
// CHECK-NEXT:    [[B_ADDR:%.*]] = alloca <4 x i32>, align 16
// CHECK-NEXT:    store <4 x i32> [[A:%.*]], ptr [[A_ADDR]], align 16
// CHECK-NEXT:    store <4 x i32> [[B:%.*]], ptr [[B_ADDR]], align 16
// CHECK-NEXT:    [[TMP0:%.*]] = load <4 x i32>, ptr [[A_ADDR]], align 16
// CHECK-NEXT:    [[TMP1:%.*]] = load <4 x i32>, ptr [[B_ADDR]], align 16
// CHECK-NEXT:    [[CMP:%.*]] = icmp eq <4 x i32> [[TMP0]], [[TMP1]]
// CHECK-NEXT:    [[SEXT:%.*]] = sext <4 x i1> [[CMP]] to <4 x i32>
// CHECK-NEXT:    ret <4 x i32> [[SEXT]]
//
// ERROR: returning 'int' from a function with incompatible result type
vector unsigned int ui32(vector unsigned int a, vector unsigned int b) {
  return a == b;
}

// CHECK-LABEL: @si32(
// CHECK:         [[A_ADDR:%.*]] = alloca <4 x i32>, align 16
// CHECK-NEXT:    [[B_ADDR:%.*]] = alloca <4 x i32>, align 16
// CHECK-NEXT:    store <4 x i32> [[A:%.*]], ptr [[A_ADDR]], align 16
// CHECK-NEXT:    store <4 x i32> [[B:%.*]], ptr [[B_ADDR]], align 16
// CHECK-NEXT:    [[TMP0:%.*]] = load <4 x i32>, ptr [[A_ADDR]], align 16
// CHECK-NEXT:    [[TMP1:%.*]] = load <4 x i32>, ptr [[B_ADDR]], align 16
// CHECK-NEXT:    [[CMP:%.*]] = icmp eq <4 x i32> [[TMP0]], [[TMP1]]
// CHECK-NEXT:    [[SEXT:%.*]] = sext <4 x i1> [[CMP]] to <4 x i32>
// CHECK-NEXT:    ret <4 x i32> [[SEXT]]
//
// ERROR: returning 'int' from a function with incompatible result type
vector signed int si32(vector signed int a, vector signed int b) {
  return a == b;
}

// CHECK-LABEL: @si64(
// CHECK:         [[A_ADDR:%.*]] = alloca <2 x i64>, align 16
// CHECK-NEXT:    [[B_ADDR:%.*]] = alloca <2 x i64>, align 16
// CHECK-NEXT:    store <2 x i64> [[A:%.*]], ptr [[A_ADDR]], align 16
// CHECK-NEXT:    store <2 x i64> [[B:%.*]], ptr [[B_ADDR]], align 16
// CHECK-NEXT:    [[TMP0:%.*]] = load <2 x i64>, ptr [[A_ADDR]], align 16
// CHECK-NEXT:    [[TMP1:%.*]] = load <2 x i64>, ptr [[B_ADDR]], align 16
// CHECK-NEXT:    [[CMP:%.*]] = icmp eq <2 x i64> [[TMP0]], [[TMP1]]
// CHECK-NEXT:    [[SEXT:%.*]] = sext <2 x i1> [[CMP]] to <2 x i64>
// CHECK-NEXT:    ret <2 x i64> [[SEXT]]
//
// ERROR: returning 'int' from a function with incompatible result type
vector long long si64(vector long long a, vector long long b) {
  return a == b;
}

// CHECK-LABEL: @f32(
// CHECK:         [[A_ADDR:%.*]] = alloca <4 x float>, align 16
// CHECK-NEXT:    [[B_ADDR:%.*]] = alloca <4 x float>, align 16
// CHECK-NEXT:    store <4 x float> [[A:%.*]], ptr [[A_ADDR]], align 16
// CHECK-NEXT:    store <4 x float> [[B:%.*]], ptr [[B_ADDR]], align 16
// CHECK-NEXT:    [[TMP0:%.*]] = load <4 x float>, ptr [[A_ADDR]], align 16
// CHECK-NEXT:    [[TMP1:%.*]] = load <4 x float>, ptr [[B_ADDR]], align 16
// CHECK-NEXT:    [[CMP:%.*]] = fcmp oeq <4 x float> [[TMP0]], [[TMP1]]
// CHECK-NEXT:    [[SEXT:%.*]] = sext <4 x i1> [[CMP]] to <4 x i32>
// CHECK-NEXT:    ret <4 x i32> [[SEXT]]
//
// ERROR: returning 'int' from a function with incompatible result type
vector int f32(vector float a, vector float b) {
  return a == b;
}

// CHECK-LABEL: @f64(
// CHECK:         [[A_ADDR:%.*]] = alloca <2 x double>, align 16
// CHECK-NEXT:    [[B_ADDR:%.*]] = alloca <2 x double>, align 16
// CHECK-NEXT:    store <2 x double> [[A:%.*]], ptr [[A_ADDR]], align 16
// CHECK-NEXT:    store <2 x double> [[B:%.*]], ptr [[B_ADDR]], align 16
// CHECK-NEXT:    [[TMP0:%.*]] = load <2 x double>, ptr [[A_ADDR]], align 16
// CHECK-NEXT:    [[TMP1:%.*]] = load <2 x double>, ptr [[B_ADDR]], align 16
// CHECK-NEXT:    [[CMP:%.*]] = fcmp oeq <2 x double> [[TMP0]], [[TMP1]]
// CHECK-NEXT:    [[SEXT:%.*]] = sext <2 x i1> [[CMP]] to <2 x i64>
// CHECK-NEXT:    ret <2 x i64> [[SEXT]]
//
// ERROR: returning 'int' from a function with incompatible result type
vector long long f64(vector double a, vector double b) {
  return a == b;
}
