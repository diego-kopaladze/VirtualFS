#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "FileSystemEntity.h"
#include <vector>
#include <memory>
#include <string>

class Directory : public FileSystemEntity {
private:
    std::vector<std::shared_ptr<FileSystemEntity>> children;
    void printRecursive(std::ostream& os, int indent) const;
public:
    explicit Directory(const std::string& name);
    ~Directory() override = default;

    void open() override;
    void add(std::shared_ptr<FileSystemEntity> entity);
    void remove(const std::string& name);
    void rename(const std::string& new_name) override;
    void remove() override;
    std::ostream& print(std::ostream& os) const override;

    // ✅ NEW: For CLI to read contents
    const std::vector<std::shared_ptr<FileSystemEntity>>& getChildren() const;
};

#endif //DIRECTORY_H
