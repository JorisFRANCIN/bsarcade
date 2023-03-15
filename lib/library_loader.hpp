/*
** EPITECH PROJECT, 2023
** library_loader.hpp
** File description:
** .hpp file for loading library
*/

#ifndef LIBRARY_LOADER_HPP_
   #define LIBRARY_LOADER_HPP_

   #include <string>

#ifdef __cplusplus
   extern "C" {
#endif

   #include <stdio.h>
   #include <stdlib.h>
   #include <dlfcn.h>
   #include <gnu/lib-names.h>
   #include <stdio.h>

void libbar_ctor() __attribute__((constructor));
void libbar_dtor() __attribute__((destructor));

void libfoo_ctor() __attribute__((constructor));
void libfoo_dtor() __attribute__((destructor));

void libgra_ctor() __attribute__((constructor));
void libgra_dtor() __attribute__((destructor));

void entryPoint();

#ifdef __cplusplus
   }
#endif

class IDisplayModule {
   public:
      virtual ~IDisplayModule() = default;
      virtual void init() = 0;
      virtual void stop() = 0;
      virtual const std::string &getName() const = 0;
};

#endif /* !LIBRARY_LOADER_HPP_ */
