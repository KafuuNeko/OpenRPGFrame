#ifndef USER_REPOSITORY_IMPL_H_
#define USER_REPOSITORY_IMPL_H_

#include <algorithm>
#include <cstdint>
#include <memory>
#include <system_error>

#include "sqlite_orm.h"

#include "db/models/user_model.h"
#include "db/repository/user_repository.h"


namespace frame::db {

template <class... DBO> class UserRepositoryImpl : public IUserRepository {
  using StorageType = sqlite_orm::internal::storage_t<DBO...>;

public:
  UserRepositoryImpl(const StorageType &storage) : storage_(storage) {}

  std::unique_ptr<UserModel> QueryUserById(int64_t uid) override {
    try {
      return std::make_unique<UserModel>(
          std::move(storage_.template get<UserModel>(uid)));
    } catch (std::system_error e) {
    }
    return std::make_unique<UserModel>();
  }

  int64_t InsertUser(const UserModel &user) override {
    return storage_.insert(user);
  }

private:
  StorageType storage_;
};

} // namespace frame::db
#endif