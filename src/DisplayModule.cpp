/*
** EPITECH PROJECT, 2023
** DisplayModule
** File description:
** ctor and dtor of display module
*/

#include "library_loader.hpp"

libBar::libBar() : ADisplayModule()
{
    _name = "./lib/libbar.so";
}

libBar::~libBar()
{

}

libFoo::libFoo() : ADisplayModule()
{
    _name = "./lib/libfoo.so";
}

libFoo::~libFoo()
{

}

libGra::libGra() : ADisplayModule()
{
    _name = "./lib/libgra.so";
}

libGra::~libGra()
{

}