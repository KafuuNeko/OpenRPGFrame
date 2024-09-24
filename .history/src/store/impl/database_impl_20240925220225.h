#ifndef DATABASE_IMPL_H_
#define DATABASE_IMPL_H_

#include "sqlite_orm.h"

#include <memory>
#include <string>
#include <utility>

#include "store/database.h"
#include "store/impl/repository/user_repository_impl.h"

namespace frame::db {

template <class... DBO> class DatabaseImpl : public IDatabase {
  using StorageType = sqlite_orm::internal::storage_t<DBO...>;

public:
  using Self = DatabaseImpl<DBO...>;

  DatabaseImpl(std::string filename, DBO... dbObjects)
      : storage_(sqlite_orm::make_storage(filename,
                                          std::forward<DBO>(dbObjects)...)) {
    storage_.sync_schema();
  }

  std::unique_ptr<IUserRepository> GetUserRepository() override {
    return std::make_unique<UserRepositoryImpl<DBO...>>(storage_);
  }

private:
  StorageType storage_;
};

template <class... DBO>
inline auto CreateDatabase(const std::string &filename, DBO... dbObjects) {
  return std::make_unique<DatabaseImpl<DBO...>>(
      filename, std::forward<DBO>(dbObjects)...);
}

} // namespace frame::db

#endif