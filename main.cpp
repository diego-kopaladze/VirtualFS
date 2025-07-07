#include <iostream>
#include <memory>
#include <sstream>
#include <vector>
#include <string>
#include "Directory.h"
#include "File.h"
#include "SymbolicLink.h"

// Helper: find child by name in current dir
std::shared_ptr<FileSystemEntity> find_child(const std::shared_ptr<Directory>& dir, const std::string& name) {
    for (const auto& child : dir->getChildren()) { // you may need to add getChildren()
        if (child->getName() == name)
            return child;
    }
    return nullptr;
}

int main() {
    auto root = std::make_shared<Directory>("root");
    auto current = root;
    std::vector<std::shared_ptr<Directory>> dir_stack; // for cd ..

    std::string line;
    std::cout << "Welcome to your virtual FS. Type 'help' for commands.\n";

    while (true) {
        std::cout << current->getName() << "> ";
        std::getline(std::cin, line);
        std::istringstream iss(line);
        std::string cmd;
        iss >> cmd;

        if (cmd == "exit") break;

        else if (cmd == "help") {
            std::cout << "Available Commands:\n"
                      << "  mkf NAME           - Create a new folder\n"
                      << "  mkfl NAME          - Create a new file\n"
                      << "  cd NAME            - Change directory into NAME\n"
                      << "  cd ..              - Go up to the parent directory\n"
                      << "  ls                 - List contents of current directory\n"
                      << "  rm NAME            - Remove file or folder named NAME\n"
                      << "  rename OLD NEW     - Rename OLD to NEW\n"
                      << "  write NAME CONTENT - Write CONTENT to file NAME\n"
                      << "  open NAME          - Open a file or folder\n"
                      << "  pwd                - Show current path\n"
                      << "  help               - Show this help message\n"
                      << "  exit               - Exit the program\n";
        }


        else if (cmd == "mkf") {
            std::string name; iss >> name;
            current->add(std::make_shared<Directory>(name));
        }

        else if (cmd == "mkfl") {
            std::string name; iss >> name;
            current->add(std::make_shared<File>(name));
        }

        else if (cmd == "cd") {
            std::string name; iss >> name;
            if (name == "..") {
                if (!dir_stack.empty()) {
                    current = dir_stack.back();
                    dir_stack.pop_back();
                }
            } else {
                auto child = find_child(current, name);
                auto dir = std::dynamic_pointer_cast<Directory>(child);
                if (dir) {
                    dir_stack.push_back(current);
                    current = dir;
                } else {
                    std::cout << name << ": not a directory\n";
                }
            }
        }

        else if (cmd == "ls") {
            current->open();
        }

        else if (cmd == "rm") {
            std::string name; iss >> name;
            current->remove(name);
        }

        else if (cmd == "rename") {
            std::string old_name, new_name; iss >> old_name >> new_name;
            auto child = find_child(current, old_name);
            if (child) child->rename(new_name);
            else std::cout << "No such file or directory\n";
        }

        else if (cmd == "write") {
            std::string name, content;
            iss >> name;
            std::getline(iss, content);
            if (auto file = std::dynamic_pointer_cast<File>(find_child(current, name))) {
                file->write(content.substr(1)); // remove leading space
            } else {
                std::cout << "File not found or is not a file\n";
            }
        }

        else if (cmd == "open") {
            std::string name; iss >> name;
            auto child = find_child(current, name);
            if (child) child->open();
            else std::cout << "File or directory not found\n";
        }

        else if (cmd == "pwd") {
            std::cout << "/"; // simplistic, improve later
            for (const auto& dir : dir_stack) std::cout << dir->getName() << "/";
            std::cout << current->getName() << "\n";
        }

        else {
            std::cout << "Unknown command\n";
        }
    }

    return 0;
}
