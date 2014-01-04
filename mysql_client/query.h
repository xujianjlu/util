// Copyrights 2011 Yunrang Inc. All Rights Reserved.
// Author: jianxu@yunrang.com (Xu Jian)

#ifndef UTIL_MYSQL_CLIENT_QUERY_H_
#define UTIL_MYSQL_CLIENT_QUERY_H_

#include <string>
#include <vector>

#include "base/basictypes.h"

namespace util_mysql {
class MysqlResult;
class MysqlConnection;

class MysqlQuery {
 public:
  explicit MysqlQuery(MysqlConnection *conn);
  virtual ~MysqlQuery();

  // when you want to execute query with blob data,
  // you have two choices:
  // 1. after you generate string from proto or thrift, you should
  //    use this method to convert to an ordinary string, then you
  //    can use it.
  // 2. use parameter bind (see bind_test.cc for more examples)
  // 3. FromBlobToString == EscapeString
  bool FromBlobToString(const std::string &blob, std::string *ouput);
  bool EscapeString(const std::string &input, std::string *ouput);

  uint64 Insert(const std::string &table_name,
                const std::string &columns,
                const std::string &values,
                bool replace = false);  // whether replace if exist

  uint64 Insert(const std::string &table_name,
                const std::string &columns,
                const std::vector<std::string> &values,
                bool replace = false);  // whether replace if exist

  uint64 Update(const std::string &table_name,
                const std::string &expression,
                const std::string &conditions);

  uint64 Update(const std::string &table_name, const std::string &expression);

  uint64 Delete(const std::string &table_name, const std::string &conditions);

  uint64 Delete(const std::string &table_name);

  uint64 Count(const std::string &table_name,
               const std::string &columns,
               const std::string &conditions);
  uint64 Count(const std::string &table_name,
               const std::string &columns);

  bool Select(const std::string &table_name,
              const std::string &columns,
              const std::string &conditions,
              MysqlResult *result);

  bool Select(const std::string &table_name,
              const std::string &columns,
              MysqlResult *result);

  bool Execute(const std::string &query, MysqlResult *result);

  uint64 Execute(const std::string &query);

 private:
  void AddConditions(const std::string &conditions, std::string *query_str);
  bool ExecuteInternal(const std::string &query, MysqlResult *result);

  uint64 ExecuteInternal(const std::string &query);

  MysqlConnection *conn_;
  DISALLOW_COPY_AND_ASSIGN(MysqlQuery);
};
}  // namespace util_mysql

#endif  // UTIL_MYSQL_CLIENT_QUERY_H_
