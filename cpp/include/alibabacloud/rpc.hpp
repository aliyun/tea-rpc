// This file is auto-generated, don't edit it. Thanks.

#ifndef ALIBABACLOUD_RPC_H_
#define ALIBABACLOUD_RPC_H_

#include <alibabacloud/credential.hpp>
#include <alibabacloud/rpcutil.hpp>
#include <boost/any.hpp>
#include <darabonba/core.hpp>
#include <darabonba/util.hpp>
#include <iostream>
#include <map>

using namespace Darabonba;
using namespace std;

namespace Alibabacloud_RPC {
class Config : public Model {
public:
  Config(){};
  explicit Config(const std::map<string, boost::any> &config) : Model(config){};

  string *accessKeyId{};
  string *accessKeySecret{};
  string *securityToken{};
  string *protocol{};
  string *regionId{};
  int *readTimeout{};
  int *connectTimeout{};
  string *httpProxy{};
  string *httpsProxy{};
  Alibabacloud_Credential::Client *credential{};
  string *endpoint{};
  string *noProxy{};
  int *maxIdleConns{};
  string *network{};
  string *userAgent{};
  string *suffix{};
  string *socks5Proxy{};
  string *socks5NetWork{};
  string *endpointType{};
  string *openPlatformEndpoint{};
  string *type{};

  ~Config() {
    delete accessKeyId;
    delete accessKeySecret;
    delete securityToken;
    delete protocol;
    delete regionId;
    delete readTimeout;
    delete connectTimeout;
    delete httpProxy;
    delete httpsProxy;
    delete credential;
    delete endpoint;
    delete noProxy;
    delete maxIdleConns;
    delete network;
    delete userAgent;
    delete suffix;
    delete socks5Proxy;
    delete socks5NetWork;
    delete endpointType;
    delete openPlatformEndpoint;
    delete type;
  };
};
class Client {
public:
  string *_endpoint{};
  string *_regionId{};
  string *_protocol{};
  string *_userAgent{};
  string *_endpointRule{};
  map<string, string> *_endpointMap{};
  string *_suffix{};
  int *_readTimeout{};
  int *_connectTimeout{};
  string *_httpProxy{};
  string *_httpsProxy{};
  string *_socks5Proxy{};
  string *_socks5NetWork{};
  string *_noProxy{};
  string *_network{};
  string *_productId{};
  int *_maxIdleConns{};
  string *_endpointType{};
  string *_openPlatformEndpoint{};
  Alibabacloud_Credential::Client *_credential{};
  explicit Client(Config *config);
  map<string, boost::any> doRequest(string *action, string *protocol,
                                    string *method, string *version,
                                    string *authType,
                                    map<string, boost::any> *query,
                                    map<string, boost::any> *body,
                                    Darabonba_Util::RuntimeOptions *runtime);
  string getUserAgent();
  string getAccessKeyId();
  string getAccessKeySecret();
  string getSecurityToken();
  void checkConfig(Config *config);
  static boost::any defaultAny(boost::any *inputValue,
                               boost::any *defaultValue);

  ~Client() {
    delete _endpoint;
    delete _regionId;
    delete _protocol;
    delete _userAgent;
    delete _endpointRule;
    delete _endpointMap;
    delete _suffix;
    delete _readTimeout;
    delete _connectTimeout;
    delete _httpProxy;
    delete _httpsProxy;
    delete _socks5Proxy;
    delete _socks5NetWork;
    delete _noProxy;
    delete _network;
    delete _productId;
    delete _maxIdleConns;
    delete _endpointType;
    delete _openPlatformEndpoint;
    delete _credential;
  };
};
} // namespace Alibabacloud_RPC

#endif
