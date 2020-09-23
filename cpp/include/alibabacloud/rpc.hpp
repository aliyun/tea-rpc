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

using namespace std;

namespace Alibabacloud_RPC {
class Config : public Darabonba::Model {
protected:
  void _init(){
    _default = {
      {"accessKeyId" , boost::any("")},
      {"accessKeySecret" , boost::any("")},
      {"securityToken" , boost::any("")},
      {"protocol" , boost::any("http")},
      {"regionId" , boost::any("")},
      {"readTimeout" , boost::any("")},
      {"connectTimeout" , boost::any("")},
      {"httpProxy" , boost::any("")},
      {"httpsProxy" , boost::any("")},
      {"credential" , boost::any("")},
      {"endpoint" , boost::any("")},
      {"noProxy" , boost::any("")},
      {"maxIdleConns" , boost::any("")},
      {"network" , boost::any("")},
      {"userAgent" , boost::any("")},
      {"suffix" , boost::any("")},
      {"socks5Proxy" , boost::any("")},
      {"socks5NetWork" , boost::any("")},
      {"endpointType" , boost::any("")},
      {"openPlatformEndpoint" , boost::any("")},
      {"type" , boost::any("")},
    };
  }
public:
  Config() {_init();};
  explicit Config(const std::map<string, boost::any> &config) : Darabonba::Model(config) {_init();};


  map<string, boost::any> toMap() {
    map<string, boost::any> res;
    if (nullptr != accessKeyId) {
      res["accessKeyId"] = boost::any(*accessKeyId);
    }
    if (nullptr != accessKeySecret) {
      res["accessKeySecret"] = boost::any(*accessKeySecret);
    }
    if (nullptr != securityToken) {
      res["securityToken"] = boost::any(*securityToken);
    }
    if (nullptr != protocol) {
      res["protocol"] = boost::any(*protocol);
    }
    if (nullptr != regionId) {
      res["regionId"] = boost::any(*regionId);
    }
    if (nullptr != readTimeout) {
      res["readTimeout"] = boost::any(*readTimeout);
    }
    if (nullptr != connectTimeout) {
      res["connectTimeout"] = boost::any(*connectTimeout);
    }
    if (nullptr != httpProxy) {
      res["httpProxy"] = boost::any(*httpProxy);
    }
    if (nullptr != httpsProxy) {
      res["httpsProxy"] = boost::any(*httpsProxy);
    }
    if (nullptr != credential) {
    }
    if (nullptr != endpoint) {
      res["endpoint"] = boost::any(*endpoint);
    }
    if (nullptr != noProxy) {
      res["noProxy"] = boost::any(*noProxy);
    }
    if (nullptr != maxIdleConns) {
      res["maxIdleConns"] = boost::any(*maxIdleConns);
    }
    if (nullptr != network) {
      res["network"] = boost::any(*network);
    }
    if (nullptr != userAgent) {
      res["userAgent"] = boost::any(*userAgent);
    }
    if (nullptr != suffix) {
      res["suffix"] = boost::any(*suffix);
    }
    if (nullptr != socks5Proxy) {
      res["socks5Proxy"] = boost::any(*socks5Proxy);
    }
    if (nullptr != socks5NetWork) {
      res["socks5NetWork"] = boost::any(*socks5NetWork);
    }
    if (nullptr != endpointType) {
      res["endpointType"] = boost::any(*endpointType);
    }
    if (nullptr != openPlatformEndpoint) {
      res["openPlatformEndpoint"] = boost::any(*openPlatformEndpoint);
    }
    if (nullptr != type) {
      res["type"] = boost::any(*type);
    }
    return res;
  }

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
    accessKeyId = nullptr;
    delete accessKeySecret;
    accessKeySecret = nullptr;
    delete securityToken;
    securityToken = nullptr;
    delete protocol;
    protocol = nullptr;
    delete regionId;
    regionId = nullptr;
    delete readTimeout;
    readTimeout = nullptr;
    delete connectTimeout;
    connectTimeout = nullptr;
    delete httpProxy;
    httpProxy = nullptr;
    delete httpsProxy;
    httpsProxy = nullptr;
    delete credential;
    credential = nullptr;
    delete endpoint;
    endpoint = nullptr;
    delete noProxy;
    noProxy = nullptr;
    delete maxIdleConns;
    maxIdleConns = nullptr;
    delete network;
    network = nullptr;
    delete userAgent;
    userAgent = nullptr;
    delete suffix;
    suffix = nullptr;
    delete socks5Proxy;
    socks5Proxy = nullptr;
    delete socks5NetWork;
    socks5NetWork = nullptr;
    delete endpointType;
    endpointType = nullptr;
    delete openPlatformEndpoint;
    openPlatformEndpoint = nullptr;
    delete type;
    type = nullptr;
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
  map<string, boost::any> doRequest(string *action,
                                    string *protocol,
                                    string *method,
                                    string *version,
                                    string *authType,
                                    map<string, boost::any> *query,
                                    map<string, boost::any> *body,
                                    Darabonba_Util::RuntimeOptions *runtime);
  string getUserAgent();
  string getAccessKeyId();
  string getAccessKeySecret();
  string getSecurityToken();
  void checkConfig(Config *config);
  static boost::any defaultAny(boost::any *inputValue, boost::any *defaultValue);

  ~Client() {
    delete _endpoint;
    _endpoint = nullptr;
    delete _regionId;
    _regionId = nullptr;
    delete _protocol;
    _protocol = nullptr;
    delete _userAgent;
    _userAgent = nullptr;
    delete _endpointRule;
    _endpointRule = nullptr;
    delete _endpointMap;
    _endpointMap = nullptr;
    delete _suffix;
    _suffix = nullptr;
    delete _readTimeout;
    _readTimeout = nullptr;
    delete _connectTimeout;
    _connectTimeout = nullptr;
    delete _httpProxy;
    _httpProxy = nullptr;
    delete _httpsProxy;
    _httpsProxy = nullptr;
    delete _socks5Proxy;
    _socks5Proxy = nullptr;
    delete _socks5NetWork;
    _socks5NetWork = nullptr;
    delete _noProxy;
    _noProxy = nullptr;
    delete _network;
    _network = nullptr;
    delete _productId;
    _productId = nullptr;
    delete _maxIdleConns;
    _maxIdleConns = nullptr;
    delete _endpointType;
    _endpointType = nullptr;
    delete _openPlatformEndpoint;
    _openPlatformEndpoint = nullptr;
    delete _credential;
    _credential = nullptr;
  };
};
} // namespace Alibabacloud_RPC

#endif
