#ifndef FILE_H
#define FILE_H
#include "FileSystemEntity.h"
#include <string>

class File : public FileSystemEntity {
private:
    std::string content;
public:
    void open() override;
    void remove() override;
    void rename(const std::string& new_name) override;
    std::ostream& print(std::ostream&) const override;

    File(const std::string& name, const std::string& content = "");
    virtual ~File();

    // ✅ NEW
    void write(const std::string& new_content);
};

#endif //FILE_H
