# Copyrights 2011 Yunrang Inc. All Rights Reserved.
# Author: jianxu@yunrang.com (Xu Jian)
#
#Description:
#   Mysql interface function.

cc_library(name = 'mysql_base',
          srcs = ['connection.cc',
                  'query.cc',
                  'result.cc',
                 ],
          deps = ['//base:base',
                  '//third_party/mysql/lib:mysqlclient_r',
                  '//third_party/zlib/lib:z',
                 ] ,
          )

cc_library(name = 'bind',
          srcs = ['bind.cc',
                 ],
          deps = [':mysql_base',
                ],
         )

cc_library(name = 'transaction',
          srcs = ['transaction.cc',
                 ],
          deps = [':mysql_base',
                 ],
          )

# cc_binary(name = 'bind_test',
#           srcs = ['bind_test.cc',
#                  ],
#           deps = [':bind',
#                   '//util/mysql_client/testdata:blob_test_proto',
#                   '//base:base',
#                  ],
#         )
# 

cc_binary(name = 'transaction_test',
           srcs = ['transaction_test.cc',
                  ],
           deps = [':transaction',
                  ],
         )

# cc_binary(name = 'result_test',
#            srcs = ['result_test.cc',
#                   ],
#            deps = [':mysql_base',
#                    '//util/mysql_client/testdata:blob_test_proto',
#                    '//util/mysql_client/testdata:blob_test_thrift',
#                   ],
#          )
# 

cc_binary(name = 'query_test',
           srcs = ['query_test.cc',
                  ],
           deps = [':mysql_base',
                   '//base:base',
                  ],
         )

cc_binary(name = 'connection_test',
           srcs = ['connection_test.cc',
                  ],
           deps = [':mysql_base',
                  ],
         )
