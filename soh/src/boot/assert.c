#include "global.h"

#ifndef __SWITCH__
#ifdef __WIIU__
void _assert(const char* exp, const char* file, s32 line) {
#elif defined(__OpenBSD__)
void __assert(const char* exp, int line, const char* file) {
#elif defined(__FreeBSD__)
void __assert(const char *, const char *, int, const char *) __dead2 {    
#else
void __assert(const char* exp, const char* file, s32 line) {
#endif
    char msg[256];

    osSyncPrintf("Assertion failed: %s, file %s, line %d, thread %d\n", exp, file, line, osGetThreadId(NULL));
    sprintf(msg, "ASSERT: %s:%d(%d)", file, line, osGetThreadId(NULL));
    Fault_AddHungupAndCrashImpl(msg, exp);
}
#endif
