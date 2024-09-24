#ifndef DATABASE_H_
#define DATABASE_H_

#include "store/repository/user_repository.h"

#include <memory>

namespace frame::database {

class IDatabase {
public:
    virtual ~IDatabase() = default;

    virtual std::unique_ptr<IUserRepository> GetUserRepository() = 0;
};

std::unique_ptr<IDatabase> InitDatabase(const std::string &file);

} // namespace frame::database

#endif