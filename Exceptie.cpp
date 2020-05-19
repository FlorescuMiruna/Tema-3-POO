#include "Exceptie.h"

Exceptie::Exceptie(const char* what_arg) noexcept
{
    this->what_arg = what_arg;
}

const char* Exceptie::what() const noexcept
{
    return this->what_arg;
}
