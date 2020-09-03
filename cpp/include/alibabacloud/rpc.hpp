// This file is auto-generated, don't edit it. Thanks.

#ifndef ALIBABACLOUD_RPC_H_
#define ALIBABACLOUD_RPC_H_

#include <alibabacloud/credential.hpp>
#include <alibabacloud/rpcutil.hpp>
#include <alibabacloud/util.hpp>
#include <boost/any.hpp>
#include <darabonba/core.hpp>
#include <iostream>
#include <map>

using namespace Darabonba;
using namespace std;

namespace Alibabacloud_RPC {
class Config : public Model {
public:
  explicit Config(const std::map<string, boost::any> &config) : Model(config) {};
  Config();
  ~Config();

  string getAccessKeyId(){
    string name = "accessKeyId";
    string prop_val;
    if (_properties.find(name) != _properties.end()) {
      boost::any val = _properties.at(name);
      prop_val = boost::any_cast<string>(val);
    }
    return prop_val;
  }
  void setAccessKeyId(string val){
    string name = "accessKeyId";
    boost::any prop_val(val);
    _properties.insert(pair<string, boost::any>(name, prop_val));
  }
  string getAccessKeySecret(){
    string name = "accessKeySecret";
    string prop_val;
    if (_properties.find(name) != _properties.end()) {
      boost::any val = _properties.at(name);
      prop_val = boost::any_cast<string>(val);
    }
    return prop_val;
  }
  void setAccessKeySecret(string val){
    string name = "accessKeySecret";
    boost::any prop_val(val);
    _properties.insert(pair<string, boost::any>(name, prop_val));
  }
  string getSecurityToken(){
    string name = "securityToken";
    string prop_val;
    if (_properties.find(name) != _properties.end()) {
      boost::any val = _properties.at(name);
      prop_val = boost::any_cast<string>(val);
    }
    return prop_val;
  }
  void setSecurityToken(string val){
    string name = "securityToken";
    boost::any prop_val(val);
    _properties.insert(pair<string, boost::any>(name, prop_val));
  }
  string getProtocol(){
    string name = "protocol";
    string prop_val;
    if (_properties.find(name) != _properties.end()) {
      boost::any val = _properties.at(name);
      prop_val = boost::any_cast<string>(val);
    }
    return prop_val;
  }
  void setProtocol(string val){
    string name = "protocol";
    boost::any prop_val(val);
    _properties.insert(pair<string, boost::any>(name, prop_val));
  }
  string getRegionId(){
    string name = "regionId";
    string prop_val;
    if (_properties.find(name) != _properties.end()) {
      boost::any val = _properties.at(name);
      prop_val = boost::any_cast<string>(val);
    }
    return prop_val;
  }
  void setRegionId(string val){
    string name = "regionId";
    boost::any prop_val(val);
    _properties.insert(pair<string, boost::any>(name, prop_val));
  }
  int getReadTimeout(){
    string name = "readTimeout";
    int prop_val;
    if (_properties.find(name) != _properties.end()) {
      boost::any val = _properties.at(name);
      prop_val = boost::any_cast<int>(val);
    }
    return prop_val;
  }
  void setReadTimeout(int val){
    string name = "readTimeout";
    boost::any prop_val(val);
    _properties.insert(pair<string, boost::any>(name, prop_val));
  }
  int getConnectTimeout(){
    string name = "connectTimeout";
    int prop_val;
    if (_properties.find(name) != _properties.end()) {
      boost::any val = _properties.at(name);
      prop_val = boost::any_cast<int>(val);
    }
    return prop_val;
  }
  void setConnectTimeout(int val){
    string name = "connectTimeout";
    boost::any prop_val(val);
    _properties.insert(pair<string, boost::any>(name, prop_val));
  }
  string getHttpProxy(){
    string name = "httpProxy";
    string prop_val;
    if (_properties.find(name) != _properties.end()) {
      boost::any val = _properties.at(name);
      prop_val = boost::any_cast<string>(val);
    }
    return prop_val;
  }
  void setHttpProxy(string val){
    string name = "httpProxy";
    boost::any prop_val(val);
    _properties.insert(pair<string, boost::any>(name, prop_val));
  }
  string getHttpsProxy(){
    string name = "httpsProxy";
    string prop_val;
    if (_properties.find(name) != _properties.end()) {
      boost::any val = _properties.at(name);
      prop_val = boost::any_cast<string>(val);
    }
    return prop_val;
  }
  void setHttpsProxy(string val){
    string name = "httpsProxy";
    boost::any prop_val(val);
    _properties.insert(pair<string, boost::any>(name, prop_val));
  }
  Credential getCredential(){
    string name = "credential";
    Credential prop_val;
    if (_properties.find(name) != _properties.end()) {
      boost::any val = _properties.at(name);
      prop_val = boost::any_cast<Credential>(val);
    }
    return prop_val;
  }
  void setCredential(Credential val){
    string name = "credential";
    boost::any prop_val(val);
    _properties.insert(pair<string, boost::any>(name, prop_val));
  }
  string getEndpoint(){
    string name = "endpoint";
    string prop_val;
    if (_properties.find(name) != _properties.end()) {
      boost::any val = _properties.at(name);
      prop_val = boost::any_cast<string>(val);
    }
    return prop_val;
  }
  void setEndpoint(string val){
    string name = "endpoint";
    boost::any prop_val(val);
    _properties.insert(pair<string, boost::any>(name, prop_val));
  }
  string getNoProxy(){
    string name = "noProxy";
    string prop_val;
    if (_properties.find(name) != _properties.end()) {
      boost::any val = _properties.at(name);
      prop_val = boost::any_cast<string>(val);
    }
    return prop_val;
  }
  void setNoProxy(string val){
    string name = "noProxy";
    boost::any prop_val(val);
    _properties.insert(pair<string, boost::any>(name, prop_val));
  }
  int getMaxIdleConns(){
    string name = "maxIdleConns";
    int prop_val;
    if (_properties.find(name) != _properties.end()) {
      boost::any val = _properties.at(name);
      prop_val = boost::any_cast<int>(val);
    }
    return prop_val;
  }
  void setMaxIdleConns(int val){
    string name = "maxIdleConns";
    boost::any prop_val(val);
    _properties.insert(pair<string, boost::any>(name, prop_val));
  }
  string getNetwork(){
    string name = "network";
    string prop_val;
    if (_properties.find(name) != _properties.end()) {
      boost::any val = _properties.at(name);
      prop_val = boost::any_cast<string>(val);
    }
    return prop_val;
  }
  void setNetwork(string val){
    string name = "network";
    boost::any prop_val(val);
    _properties.insert(pair<string, boost::any>(name, prop_val));
  }
  string getUserAgent(){
    string name = "userAgent";
    string prop_val;
    if (_properties.find(name) != _properties.end()) {
      boost::any val = _properties.at(name);
      prop_val = boost::any_cast<string>(val);
    }
    return prop_val;
  }
  void setUserAgent(string val){
    string name = "userAgent";
    boost::any prop_val(val);
    _properties.insert(pair<string, boost::any>(name, prop_val));
  }
  string getSuffix(){
    string name = "suffix";
    string prop_val;
    if (_properties.find(name) != _properties.end()) {
      boost::any val = _properties.at(name);
      prop_val = boost::any_cast<string>(val);
    }
    return prop_val;
  }
  void setSuffix(string val){
    string name = "suffix";
    boost::any prop_val(val);
    _properties.insert(pair<string, boost::any>(name, prop_val));
  }
  string getSocks5Proxy(){
    string name = "socks5Proxy";
    string prop_val;
    if (_properties.find(name) != _properties.end()) {
      boost::any val = _properties.at(name);
      prop_val = boost::any_cast<string>(val);
    }
    return prop_val;
  }
  void setSocks5Proxy(string val){
    string name = "socks5Proxy";
    boost::any prop_val(val);
    _properties.insert(pair<string, boost::any>(name, prop_val));
  }
  string getSocks5NetWork(){
    string name = "socks5NetWork";
    string prop_val;
    if (_properties.find(name) != _properties.end()) {
      boost::any val = _properties.at(name);
      prop_val = boost::any_cast<string>(val);
    }
    return prop_val;
  }
  void setSocks5NetWork(string val){
    string name = "socks5NetWork";
    boost::any prop_val(val);
    _properties.insert(pair<string, boost::any>(name, prop_val));
  }
  string getEndpointType(){
    string name = "endpointType";
    string prop_val;
    if (_properties.find(name) != _properties.end()) {
      boost::any val = _properties.at(name);
      prop_val = boost::any_cast<string>(val);
    }
    return prop_val;
  }
  void setEndpointType(string val){
    string name = "endpointType";
    boost::any prop_val(val);
    _properties.insert(pair<string, boost::any>(name, prop_val));
  }
  string getOpenPlatformEndpoint(){
    string name = "openPlatformEndpoint";
    string prop_val;
    if (_properties.find(name) != _properties.end()) {
      boost::any val = _properties.at(name);
      prop_val = boost::any_cast<string>(val);
    }
    return prop_val;
  }
  void setOpenPlatformEndpoint(string val){
    string name = "openPlatformEndpoint";
    boost::any prop_val(val);
    _properties.insert(pair<string, boost::any>(name, prop_val));
  }
  string getType(){
    string name = "type";
    string prop_val;
    if (_properties.find(name) != _properties.end()) {
      boost::any val = _properties.at(name);
      prop_val = boost::any_cast<string>(val);
    }
    return prop_val;
  }
  void setType(string val){
    string name = "type";
    boost::any prop_val(val);
    _properties.insert(pair<string, boost::any>(name, prop_val));
  }
};
class Client {
public:
  Client();
  ~Client();

  string get_endpoint(){
    string name = "_endpoint";
    string prop_val;
    if (_properties.find(name) != _properties.end()) {
      boost::any val = _properties.at(name);
      prop_val = boost::any_cast<string>(val);
    }
    return prop_val;
  }
  void set_endpoint(string val){
    string name = "_endpoint";
    boost::any prop_val(val);
    _properties.insert(pair<string, boost::any>(name, prop_val));
  }
  string get_regionId(){
    string name = "_regionId";
    string prop_val;
    if (_properties.find(name) != _properties.end()) {
      boost::any val = _properties.at(name);
      prop_val = boost::any_cast<string>(val);
    }
    return prop_val;
  }
  void set_regionId(string val){
    string name = "_regionId";
    boost::any prop_val(val);
    _properties.insert(pair<string, boost::any>(name, prop_val));
  }
  string get_protocol(){
    string name = "_protocol";
    string prop_val;
    if (_properties.find(name) != _properties.end()) {
      boost::any val = _properties.at(name);
      prop_val = boost::any_cast<string>(val);
    }
    return prop_val;
  }
  void set_protocol(string val){
    string name = "_protocol";
    boost::any prop_val(val);
    _properties.insert(pair<string, boost::any>(name, prop_val));
  }
  string get_userAgent(){
    string name = "_userAgent";
    string prop_val;
    if (_properties.find(name) != _properties.end()) {
      boost::any val = _properties.at(name);
      prop_val = boost::any_cast<string>(val);
    }
    return prop_val;
  }
  void set_userAgent(string val){
    string name = "_userAgent";
    boost::any prop_val(val);
    _properties.insert(pair<string, boost::any>(name, prop_val));
  }
  string get_endpointRule(){
    string name = "_endpointRule";
    string prop_val;
    if (_properties.find(name) != _properties.end()) {
      boost::any val = _properties.at(name);
      prop_val = boost::any_cast<string>(val);
    }
    return prop_val;
  }
  void set_endpointRule(string val){
    string name = "_endpointRule";
    boost::any prop_val(val);
    _properties.insert(pair<string, boost::any>(name, prop_val));
  }
  map<string, string> get_endpointMap(){
    string name = "_endpointMap";
    map<string, string> prop_val;
    if (_properties.find(name) != _properties.end()) {
      boost::any val = _properties.at(name);
      prop_val = boost::any_cast<map<string, string>>(val);
    }
    return prop_val;
  }
  void set_endpointMap(map<string, string> val){
    string name = "_endpointMap";
    boost::any prop_val(val);
    _properties.insert(pair<string, boost::any>(name, prop_val));
  }
  string get_suffix(){
    string name = "_suffix";
    string prop_val;
    if (_properties.find(name) != _properties.end()) {
      boost::any val = _properties.at(name);
      prop_val = boost::any_cast<string>(val);
    }
    return prop_val;
  }
  void set_suffix(string val){
    string name = "_suffix";
    boost::any prop_val(val);
    _properties.insert(pair<string, boost::any>(name, prop_val));
  }
  int get_readTimeout(){
    string name = "_readTimeout";
    int prop_val;
    if (_properties.find(name) != _properties.end()) {
      boost::any val = _properties.at(name);
      prop_val = boost::any_cast<int>(val);
    }
    return prop_val;
  }
  void set_readTimeout(int val){
    string name = "_readTimeout";
    boost::any prop_val(val);
    _properties.insert(pair<string, boost::any>(name, prop_val));
  }
  int get_connectTimeout(){
    string name = "_connectTimeout";
    int prop_val;
    if (_properties.find(name) != _properties.end()) {
      boost::any val = _properties.at(name);
      prop_val = boost::any_cast<int>(val);
    }
    return prop_val;
  }
  void set_connectTimeout(int val){
    string name = "_connectTimeout";
    boost::any prop_val(val);
    _properties.insert(pair<string, boost::any>(name, prop_val));
  }
  string get_httpProxy(){
    string name = "_httpProxy";
    string prop_val;
    if (_properties.find(name) != _properties.end()) {
      boost::any val = _properties.at(name);
      prop_val = boost::any_cast<string>(val);
    }
    return prop_val;
  }
  void set_httpProxy(string val){
    string name = "_httpProxy";
    boost::any prop_val(val);
    _properties.insert(pair<string, boost::any>(name, prop_val));
  }
  string get_httpsProxy(){
    string name = "_httpsProxy";
    string prop_val;
    if (_properties.find(name) != _properties.end()) {
      boost::any val = _properties.at(name);
      prop_val = boost::any_cast<string>(val);
    }
    return prop_val;
  }
  void set_httpsProxy(string val){
    string name = "_httpsProxy";
    boost::any prop_val(val);
    _properties.insert(pair<string, boost::any>(name, prop_val));
  }
  string get_socks5Proxy(){
    string name = "_socks5Proxy";
    string prop_val;
    if (_properties.find(name) != _properties.end()) {
      boost::any val = _properties.at(name);
      prop_val = boost::any_cast<string>(val);
    }
    return prop_val;
  }
  void set_socks5Proxy(string val){
    string name = "_socks5Proxy";
    boost::any prop_val(val);
    _properties.insert(pair<string, boost::any>(name, prop_val));
  }
  string get_socks5NetWork(){
    string name = "_socks5NetWork";
    string prop_val;
    if (_properties.find(name) != _properties.end()) {
      boost::any val = _properties.at(name);
      prop_val = boost::any_cast<string>(val);
    }
    return prop_val;
  }
  void set_socks5NetWork(string val){
    string name = "_socks5NetWork";
    boost::any prop_val(val);
    _properties.insert(pair<string, boost::any>(name, prop_val));
  }
  string get_noProxy(){
    string name = "_noProxy";
    string prop_val;
    if (_properties.find(name) != _properties.end()) {
      boost::any val = _properties.at(name);
      prop_val = boost::any_cast<string>(val);
    }
    return prop_val;
  }
  void set_noProxy(string val){
    string name = "_noProxy";
    boost::any prop_val(val);
    _properties.insert(pair<string, boost::any>(name, prop_val));
  }
  string get_network(){
    string name = "_network";
    string prop_val;
    if (_properties.find(name) != _properties.end()) {
      boost::any val = _properties.at(name);
      prop_val = boost::any_cast<string>(val);
    }
    return prop_val;
  }
  void set_network(string val){
    string name = "_network";
    boost::any prop_val(val);
    _properties.insert(pair<string, boost::any>(name, prop_val));
  }
  string get_productId(){
    string name = "_productId";
    string prop_val;
    if (_properties.find(name) != _properties.end()) {
      boost::any val = _properties.at(name);
      prop_val = boost::any_cast<string>(val);
    }
    return prop_val;
  }
  void set_productId(string val){
    string name = "_productId";
    boost::any prop_val(val);
    _properties.insert(pair<string, boost::any>(name, prop_val));
  }
  int get_maxIdleConns(){
    string name = "_maxIdleConns";
    int prop_val;
    if (_properties.find(name) != _properties.end()) {
      boost::any val = _properties.at(name);
      prop_val = boost::any_cast<int>(val);
    }
    return prop_val;
  }
  void set_maxIdleConns(int val){
    string name = "_maxIdleConns";
    boost::any prop_val(val);
    _properties.insert(pair<string, boost::any>(name, prop_val));
  }
  string get_endpointType(){
    string name = "_endpointType";
    string prop_val;
    if (_properties.find(name) != _properties.end()) {
      boost::any val = _properties.at(name);
      prop_val = boost::any_cast<string>(val);
    }
    return prop_val;
  }
  void set_endpointType(string val){
    string name = "_endpointType";
    boost::any prop_val(val);
    _properties.insert(pair<string, boost::any>(name, prop_val));
  }
  string get_openPlatformEndpoint(){
    string name = "_openPlatformEndpoint";
    string prop_val;
    if (_properties.find(name) != _properties.end()) {
      boost::any val = _properties.at(name);
      prop_val = boost::any_cast<string>(val);
    }
    return prop_val;
  }
  void set_openPlatformEndpoint(string val){
    string name = "_openPlatformEndpoint";
    boost::any prop_val(val);
    _properties.insert(pair<string, boost::any>(name, prop_val));
  }
  Alibabacloud_Credential::Client get_credential(){
    string name = "_credential";
    Alibabacloud_Credential::Client prop_val;
    if (_properties.find(name) != _properties.end()) {
      boost::any val = _properties.at(name);
      prop_val = boost::any_cast<Alibabacloud_Credential::Client>(val);
    }
    return prop_val;
  }
  void set_credential(Alibabacloud_Credential::Client val){
    string name = "_credential";
    boost::any prop_val(val);
    _properties.insert(pair<string, boost::any>(name, prop_val));
  }
  Client(Config config);
  map<string, boost::any> doRequest(string action, string protocol, string method, string version, string authType, map<string, boost::any> query, map<string, boost::any> body, Alibabacloud_Util::RuntimeOptions runtime);
  string getUserAgent();
  string getAccessKeyId();
  string getAccessKeySecret();
  string getSecurityToken();
  void checkConfig(Config config);
};
} // namespace Alibabacloud_RPC

#endif
