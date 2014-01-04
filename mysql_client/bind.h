// Copyrights 2011 Yunrang Inc. All Rights Reserved.
// Author: jianxu@yunrang.com (Xu Jian)

#ifndef UTIL_MYSQL_CLIENT_BIND_H_
#define UTIL_MYSQL_CLIENT_BIND_H_

#include <string>

#include "base/scoped_ptr.h"
#include "util/mysql_client/connection.h"

namespace util_mysql {

class MysqlConnection;

class MysqlBind {
 public:

  MysqlBind(MysqlConnection *conn, const std::string &query);
  ~MysqlBind();

  bool SetParam(int32 column_index, const std::string &data);
  bool SetParam(int32 column_index, uint32 data);
  bool SetParam(int32 column_index, int32 data);
  bool SetParam(int32 column_index, uint64 data);
  bool SetParam(int32 column_index, int64 data);
  bool SetParam(int32 column_index, bool data);
  bool SetParam(int32 column_index, double data);

  uint64 Execute();

  void Close();

 private:
  void ParamInit();
  bool FillParamInfo(int32 column_index,
                      const void *data,
                      size_t size,
                      enum enum_field_types type,
                      bool is_unsigned);
  scoped_array<MYSQL_BIND> bind_;
  MYSQL_STMT *stmt_;
  uint64 param_num_;
  std::string query_statment_;
  MysqlConnection *conn_;
  DISALLOW_COPY_AND_ASSIGN(MysqlBind);
};

}  // namespace util_mysql

#endif  // UTIL_MYSQL_CLIENT_BIND_H_
