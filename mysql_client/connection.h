// Copyrights 2011 Yunrang Inc. All Rights Reserved.
// Author: jianxu@yunrang.com (Xu Jian)

#ifndef UTIL_MYSQL_CLIENT2_CONNECTION_H_
#define UTIL_MYSQL_CLIENT2_CONNECTION_H_

#include <string>

#include "base/basictypes.h"
#include "base/mutex.h"

#include "third_party/mysql/include/mysql.h"

namespace base {
  class Mutex;
}

namespace util_mysql {

const uint64 kMysqlIllegalValue = kuint64max;

struct ConnectionOption {
  std::string  host_;
  std::string  user_;
  std::string  password_;
  std::string  database_;
  std::string  socket_;
  uint32       port_;
};

// this class is NOT thread-safe.
// DO NOT share connection between threads.
class MysqlConnection {
 public:
  explicit MysqlConnection(const ConnectionOption &option);

  // establish the real connection to the mysql
  bool Connect();

  // break the connection to the mysql
  void Disconnect();
  bool Reconnect();

  // check if the connection alive
  bool IsAlive();

  // keep the connection alive, will establish a new one
  // if connection has been broken.
  void KeepAlive();

  // do not use this ,use FromBlobToString in query to instead
  uint64 GetEscapeString(const std::string &input, std::string *output);
  uint64 GetAffectedRowNum();
  uint64 GetInsertId();
  MYSQL_STMT * GetStmtHandle();
  uint64 RealQuery(const std::string &query, int32 length);
  const char *GetErrorInfo();
  MYSQL_RES *GetStoreResult();
  MYSQL_RES *GetUseResult();

  void SetPingInterval(int32 interval);
  base::Mutex* GetMutex();
  virtual ~MysqlConnection();

 private:
  bool ConnectInternal();
  ConnectionOption option_;
  MYSQL *mysql_;
  base::Mutex mutex_;
  int32 ping_interval_;
  int32 ping_timestamp_;

  DISALLOW_COPY_AND_ASSIGN(MysqlConnection);
};
}  // namespace util_mysql

#endif  // UTIL_MYSQL_CLIENT2_CONNECTION_H_
