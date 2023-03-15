/*
** EPITECH PROJECT, 2023
** main
** File description:
** main bootstrap
*/

#include "library_loader.hpp"

static const char *libraries[] = {
    "./lib/libfoo.so",
    "./lib/libbar.so",
    "./lib/libgra.so",
    NULL
};

int main()
{
    void *handle[sizeof(libraries)];
    void (*fptr_t[sizeof(libraries)])(void);
    char *error;

    for (int i = 0; libraries[i] != NULL; i++) {
        handle[i] = dlopen(libraries[i], RTLD_LAZY);
        if (!handle) {
            fprintf(stderr, "%s\n", dlerror());
            exit(EXIT_FAILURE);
        }
        dlerror();
    }
    for (int i = 0; libraries[i] != NULL; i++) {
        *(void **) (&fptr_t[i]) = dlsym(handle[i], "entryPoint");
        error = dlerror();
        if (error != NULL) {
            fprintf(stderr, "%s\n", error);
            exit(EXIT_FAILURE);
        }
        (*fptr_t[i])();
    }
    for (int i = 0; libraries[i] != NULL; i++)
        dlclose(handle[i]);
    exit(EXIT_SUCCESS);
}
