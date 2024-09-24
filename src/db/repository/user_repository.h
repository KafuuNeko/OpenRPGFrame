#ifndef USER_REPOSITORY_H_
#define USER_REPOSITORY_H_

#include <cstdint>
#include <memory>

#include "db/models/user_model.h"

namespace frame::db {

class IUserRepository {
public:
  virtual ~IUserRepository() = default;
  virtual std::unique_ptr<UserModel> QueryUserById(int64_t uid) = 0;
  virtual int64_t InsertUser(const UserModel &user) = 0;
};

} // namespace frame::db

#endif