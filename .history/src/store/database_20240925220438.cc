#include "database.h"

#include "store/impl/database_impl.h"
#include "store/models/tables.h"

namespace frame::db {

std::unique_ptr<IDatabase> InitDatabase(const std::string &file) {
  return CreateDatabase(file, MakeUsersTable());
}

} // namespace frame::db
