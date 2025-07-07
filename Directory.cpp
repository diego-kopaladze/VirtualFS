#include "Directory.h"
#include <iostream>
#include <algorithm>

Directory::Directory(const std::string& name) : FileSystemEntity(name) {}

void Directory::add(std::shared_ptr<FileSystemEntity> entity) {
    for (const auto& child : children) {
        if (child->getName() == entity->getName()) {
            std::cout << "Error: '" << entity->getName() << "' already exists in this directory.\n";
            return;
        }
    }
    children.push_back(entity);
}


void Directory::remove(const std::string& name) {
    auto it = std::find_if(children.begin(), children.end(),
        [&name](const std::shared_ptr<FileSystemEntity>& child) {
            return child->getName() == name;
        });
    if (it != children.end()) {
        children.erase(it);
    }
}

void Directory::remove() {
    children.clear();
}

void Directory::rename(const std::string& new_name) {
    setName(new_name);
}

void Directory::open() {
    std::cout << "Directory: " << getName() << "\n\n" << "contents:\n";
    for (const auto& child : children) {
        std::cout << " - " << child->getName() << "\n";
    }
    std::cout << std::endl; // ✅ Adds newline after listing
}


void Directory::printRecursive(std::ostream& os, int indent) const {
    for (int i = 0; i < indent; ++i) os << "  ";
    os << getName() << " (Directory)\n";
    for (const auto& child : children) {
        for (int i = 0; i < indent + 1; ++i) os << "  ";
        os << *child << "\n";
        if (auto dir = std::dynamic_pointer_cast<Directory>(child)) {
            dir->printRecursive(os, indent + 2);
        }
    }
}

std::ostream& Directory::print(std::ostream& os) const {
    printRecursive(os, 0);
    return os;
}

const std::vector<std::shared_ptr<FileSystemEntity>>& Directory::getChildren() const {
    return children;
}
