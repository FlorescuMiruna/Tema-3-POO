#include <exception>

using namespace std;

class Exceptie : public exception
{
    const char* what_arg;
public:
    Exceptie(const char* what_arg) noexcept;
    ~Exceptie() noexcept {};
    const char* what() const noexcept;

};
