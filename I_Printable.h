#ifndef I_PRINTABLE_H
#define I_PRINTABLE_H

#include <iostream>

class I_Printable {
    friend std::ostream& operator<<(std::ostream& os, const I_Printable& obj);
public:
    virtual std::ostream& print(std::ostream& os) const = 0;
    virtual ~I_Printable() = default;
};

inline std::ostream& operator<<(std::ostream& os, const I_Printable& obj) {
    return obj.print(os);
}

#endif //I_PRINTABLE_H
