/*
** EPITECH PROJECT, 2023
** library_loader.hpp
** File description:
** .hpp file for loading library
*/

#ifndef LIBRARY_LOADER_HPP_
   #define LIBRARY_LOADER_HPP_

   #include <string>
   #include <iostream>
   #include <memory>

#ifdef __cplusplus
   extern "C" {
#endif

   #include <stdio.h>
   #include <stdlib.h>
   #include <dlfcn.h>
   #include <gnu/lib-names.h>
   #include <stdio.h>

// void libbar_ctor() __attribute__((constructor));
// void libbar_dtor() __attribute__((destructor));

// void libfoo_ctor() __attribute__((constructor));
// void libfoo_dtor() __attribute__((destructor));

// void libgra_ctor() __attribute__((constructor));
// void libgra_dtor() __attribute__((destructor));

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

class ADisplayModule : public IDisplayModule {
   public:
      ADisplayModule() {}
      ~ADisplayModule() {}
      void init() override {}
      void stop() override {}
      const std::string &getName() const { return _name; }
   protected:
      std::string _name;
};

class libBar : virtual public ADisplayModule {
   public:
      libBar();
      ~libBar();
      void init() {
         printf("[libbar] Loading bar library...\n");
         _name = "./lib/libbar.so";
      }
      void stop() { printf("[libbar] Closing bar...\n"); }
};

class libFoo : virtual public ADisplayModule {
   public:
      libFoo();
      ~libFoo();
      void init() {
         printf("[libfoo] Loading foo library...\n");
         _name = "./lib/libfoo.so";
      }
      void stop() {
         printf("[libfoo] foo closing...\n");
      }
};

class libGra : virtual public ADisplayModule {
   public:
      libGra();
      ~libGra();
      void init() {
         printf("[libgra] Loading gra library...\n");
         _name = "./lib/libgra.so";
      }
      void stop() {
         printf("[libgra] Gra's getting out...\n");
      }
};

#endif /* !LIBRARY_LOADER_HPP_ */
