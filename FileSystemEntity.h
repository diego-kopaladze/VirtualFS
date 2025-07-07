#ifndef FILESYSTEMENTITY_H
#define FILESYSTEMENTITY_H

#include <iostream>
#include <string>
#include "I_Printable.h"

class FileSystemEntity : public I_Printable {
private:
    std::string name;
protected:
    void setName(const std::string& new_name) { name = new_name; }
public:
    explicit FileSystemEntity(const std::string& name);
    virtual void open() = 0;
    virtual void remove() = 0;
    virtual void rename(const std::string& new_name) = 0;
    virtual std::ostream& print(std::ostream& os) const = 0;
    const std::string& getName() const { return name; }
    virtual ~FileSystemEntity();
};

#endif //FILESYSTEMENTITY_H
