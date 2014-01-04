// Copyrights 2011 Yunrang Inc. All Rights Reserved.
// Author: jianxu@yunrang.com (Xu Jian)

#ifndef UTIL_MYSQL_CLIENT_RESULT_H_
#define UTIL_MYSQL_CLIENT_RESULT_H_

#include <map>
#include <string>

#include "base/basictypes.h"
#include "third_party/mysql/include/mysql.h"

namespace util_mysql {
class MysqlQuery;

class MysqlResult {
 public:
  MysqlResult();
  ~MysqlResult();
  void Reset(MYSQL_RES *res);

  bool FetchRow();

  uint64 GetRowsNum() const;

  uint64 GetFieldsNum() const;

  void GetFieldName(int32 column_index, std::string *name);
  uint64 GetFieldWidth(int32 column_index);

  bool GetValue(int32 column_index, std::string *result);
  bool GetValue(int32 column_index, int32 *result);
  bool GetValue(int32 column_index, int64 *result);
  bool GetValue(int32 column_index, uint64 *result);
  bool GetValue(int32 column_index, double  *result);
  bool GetValue(int32 column_index, bool *result);

  bool GetValue(const std::string &column_name, std::string *result);
  bool GetValue(const std::string &column_name, int32 *result);
  bool GetValue(const std::string &column_name, int64 *result);
  bool GetValue(const std::string &column_name, uint64 *result);
  bool GetValue(const std::string &column_name, double *result);
  bool GetValue(const std::string &column_name, bool *result);
  bool GetColumnIndex(const std::string &column_name, int32 *index);

 private:

  void Clean();
  std::map<std::string, int32> name_index_map_;
  MYSQL_RES *res_;
  MYSQL_FIELD *fields_;
  MYSQL_ROW current_row_;
  DISALLOW_COPY_AND_ASSIGN(MysqlResult);
};
}  // namespace util_mysql

#endif  // UTIL_MYSQL_CLIENT_RESULT_H_
