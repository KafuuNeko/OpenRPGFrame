#ifndef TABLES_H_
#define TABLES_H_

#include "user_model.h"

#include <sqlite_orm.h>

namespace frame::db {

inline auto MakeUsersTable() {
  return sqlite_orm::make_table(
      "users",
      sqlite_orm::make_column("uid", &UserModel::uid,
                              sqlite_orm::primary_key().autoincrement()),
      sqlite_orm::make_column("username", &UserModel::username),
      sqlite_orm::make_column("registration_time",
                              &UserModel::registration_time),
      sqlite_orm::make_column("latest_request_time",
                              &UserModel::latest_request_time));
}

} // namespace frame::db

#endif