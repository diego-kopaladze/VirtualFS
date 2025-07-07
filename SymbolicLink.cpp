#include "SymbolicLink.h"
#include <iostream>

SymbolicLink::SymbolicLink(const std::string& name, std::shared_ptr<FileSystemEntity> target)
    : FileSystemEntity(name), target(target) {}

void SymbolicLink::open() {
    if (target != nullptr)
        target->open();
    else
        std::cout << "Broken symbolic link: " << getName() << std::endl;
}

void SymbolicLink::remove() {
    if (target) {
        target = nullptr;
        std::cout << "Symbolic link '" << getName() << "' removed (link broken).\n";
    } else {
        std::cout << "Symbolic link '" << getName() << "' is already broken.\n";
    }
}

void SymbolicLink::rename(const std::string& new_name) {
    setName(new_name);
}

std::ostream& SymbolicLink::print(std::ostream& os) const {
    os << "Symlink: " << getName() << " -> ";
    if (target)
        os << target->getName();
    else
        os << "[broken link]";
    return os;
}
