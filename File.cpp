#include "File.h"
#include <iostream>

File::File(const std::string& name, const std::string& content)
    : FileSystemEntity(name), content(content) {}

void File::open() {
    std::cout << content << std::endl;
}

void File::remove() {
    content.clear();
}

void File::rename(const std::string& new_name) {
    setName(new_name);
}

std::ostream& File::print(std::ostream& os) const {
    os << "File: " << getName() << " (content: \"" << content << "\")";
    return os;
}

File::~File() = default;

void File::write(const std::string& new_content) {
    content = new_content;
}
