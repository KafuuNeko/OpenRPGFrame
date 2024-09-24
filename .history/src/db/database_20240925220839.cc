#include "database.h"

#include "db/impl/database_impl.h"
#include "db/models/tables.h"

namespace frame::db {

std::unique_ptr<IDatabase> InitDatabase(const std::string &file) {
  return CreateDatabase(file, MakeUsersTable());
}

} // namespace frame::db
