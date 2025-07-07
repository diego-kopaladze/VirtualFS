#ifndef SYMBOLICLINK_H
#define SYMBOLICLINK_H

#include "FileSystemEntity.h"
#include <memory>

class SymbolicLink : public FileSystemEntity {
private:
    std::shared_ptr<FileSystemEntity> target;
public:
    SymbolicLink(const std::string& name, std::shared_ptr<FileSystemEntity> target = nullptr);
    ~SymbolicLink() override = default;

    void open() override;
    void remove() override;
    void rename(const std::string& new_name) override;
    std::ostream& print(std::ostream& os) const override;
};

#endif //SYMBOLICLINK_H
