#include "db/database.h"
#include "db/models/user_model.h"
#include <iostream>
#include <ostream>


int main() {
  auto db = frame::db::InitDatabase("./test.sqlite");
  auto user = frame::db::UserModel{-1, "kafuu", 0, 0};
  auto id = db->GetUserRepository()->InsertUser(user);

  std::cout << "Insert, uid = " << id << std::endl;
  auto res = db->GetUserRepository()->QueryUserById(id);
  std::cout << "Username: " << res->username << std::endl;
  return 0;
}