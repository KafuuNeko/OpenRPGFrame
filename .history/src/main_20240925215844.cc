#include <iostream>
#include <ostream>
#include "store/database.h"
#include "store/models/user_model.h"

int main() {
    auto db = frame::database::InitDatabase("./test.sqlite");
    auto user = frame::database::UserModel{-1, "kafuu", 0, 0};
    auto id = db->GetUserRepository()->InsertUser(user);

    std::cout << "Insert, uid = " << id << std::endl;
    auto res = db->GetUserRepository()->QueryUserById(id);
    std::cout << "Username: " << res->username << std::endl;
    return 0;
}