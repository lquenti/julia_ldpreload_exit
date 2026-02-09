#include<variant>
#include<queue>
#include<cstdio>
#include<dlfcn.h>
struct A {};
static std::queue<std::variant<A>> q = {};

extern "C" {
void _exit(int status) {
    printf("duck _exit\n");
    void (*real__exit)(int) = reinterpret_cast<void (*)(int)>(dlsym(RTLD_NEXT, "_exit"));
    q.push(A{});
    real__exit(status);
}
}
