#include "revert_string.h"
#include <stdio.h>
#include <dlfcn.h>

int main() {
    void *lib_handle;
    void (*revert_string)(char *);
    char *error;

    lib_handle = dlopen("librevert.so", RTLD_LAZY);
    if (!lib_handle) {
        fprintf(stderr, "%s\n", dlerror());
        return 1;
    }

    revert_string = dlsym(lib_handle, "RevertString");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s\n", error);
        return 1;
    }

    char str[] = "Hello, World!";
    revert_string(str);
    printf("Reverted string: %s\n", str);

    dlclose(lib_handle);
    return 0;
}