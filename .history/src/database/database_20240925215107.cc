#include "database.h"

#include "database/impl/database_impl.h"

#include "database/models/tables.h"

namespace frame::database {

std::unique_ptr<IDatabase> InitDatabase(const std::string &file) {
    return CreateDatabase(file, MakeUsersTable());
}

} // namespace frame::database
