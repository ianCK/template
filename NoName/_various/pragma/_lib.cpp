#define _GLIBCXX_GTHREAD_USE_WEAK 0
// Skylake
#pragma GCC target( \
  "adx,aes,avx2,avx,bmi2,bmi,clflushopt,cx16,f16c,fma,fsgsbase,hle,lzcnt,movbe,sse4,pclmul,popcnt,prfchw,sahf,sse3,sse4.1,sse4.2,ssse3,xsavec,xsave,xsaveopt,xsaves")
// Sandy Bridge
#pragma GCC target( \
  "avx,cx16,pclmul,popcnt,sahf,sse3,sse4.1,sse4.2,sse4,ssse3,xsave,xsaveopt")
