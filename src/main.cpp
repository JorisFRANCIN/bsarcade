/*
** EPITECH PROJECT, 2023
** main
** File description:
** main bootstrap
*/

#include "library_loader.hpp"

int main()
{
    void *handle;
    void (*fptr_t)(void);
    char *error;

    std::unique_ptr<IDisplayModule>libbar = std::make_unique<libBar>();
    std::unique_ptr<IDisplayModule>libfoo = std::make_unique<libFoo>();
    std::unique_ptr<IDisplayModule>libgra = std::make_unique<libGra>();

    libbar->init();
    libfoo->init();
    libgra->init();
    handle = dlopen(libbar->getName().c_str(), RTLD_LAZY);
    if (!handle) {
            fprintf(stderr, "%s\n", dlerror());
            exit(EXIT_FAILURE);
        }
    dlerror();
    *(void **) (&fptr_t) = dlsym(handle, "entryPoint");
    (*fptr_t)();
    dlclose(handle);
    handle = dlopen(libfoo->getName().c_str(), RTLD_LAZY);
    if (!handle) {
            fprintf(stderr, "%s\n", dlerror());
            exit(EXIT_FAILURE);
        }
    dlerror();
    *(void **) (&fptr_t) = dlsym(handle, "entryPoint");
    (*fptr_t)();
    dlclose(handle);
    handle = dlopen(libgra->getName().c_str(), RTLD_LAZY);
    if (!handle) {
            fprintf(stderr, "%s\n", dlerror());
            exit(EXIT_FAILURE);
        }
    dlerror();
    *(void **) (&fptr_t) = dlsym(handle, "entryPoint");
    (*fptr_t)();
    dlclose(handle);
    libbar->stop();
    libfoo->stop();
    libgra->stop();

    return 0;
}
