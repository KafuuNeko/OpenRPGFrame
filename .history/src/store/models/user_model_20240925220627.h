#ifndef USER_MODEL_H_
#define USER_MODEL_H_

#include <cstdint>
#include <string>

namespace frame::db {

struct UserModel {
  static std::string TABLE_NAME = "12";
  int64_t uid;
  std::string username;
  int64_t registration_time;
  int64_t latest_request_time;
};

} // namespace frame::db

#endif