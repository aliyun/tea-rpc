// This file is auto-generated, don't edit it. Thanks.

#include <alibabacloud/rpc.hpp>
#include <alibabacloud/credential.hpp>
#include <alibabacloud/rpcutil.hpp>
#include <boost/any.hpp>
#include <boost/exception/all.hpp>
#include <darabonba/core.hpp>
#include <darabonba/util.hpp>
#include <iostream>
#include <map>

using namespace Darabonba;
using namespace std;

Alibabacloud_RPC::Client::Client(Config config) {
  if (Darabonba_Util::Client::isUnset(config)) {
    BOOST_THROW_EXCEPTION(Error({
      {"code", "ParameterMissing"},
      {"message", "'config' can not be unset"}
    }));
  }
  Darabonba_Util::Client::validateModel(config);
  if (!Darabonba_Util::Client::empty(config.accessKeyId) && !Darabonba_Util::Client::empty(config.accessKeySecret)) {
    if (!Darabonba_Util::Client::empty(config.securityToken)) {
      config.type = "sts";
    }
    else {
      config.type = "access_key";
    }
    Alibabacloud_Credential::Config credentialConfig = new Alibabacloud_Credential::Config({
      {"accessKeyId", config.accessKeyId},
      {"type", config.type},
      {"accessKeySecret", config.accessKeySecret},
      {"securityToken", config.securityToken}
    });
    this->_credential = new Alibabacloud_Credential::Client(credentialConfig);
  }
  else if (!Darabonba_Util::Client::isUnset(config.credential)) {
    this->_credential = config.credential;
  }
  else {
    BOOST_THROW_EXCEPTION(Error({
      {"code", "ParameterMissing"},
      {"message", "'accessKeyId' and 'accessKeySecret' or 'credential' can not be unset"}
    }));
  }
  this->_network = config.network;
  this->_suffix = config.suffix;
  this->_endpoint = config.endpoint;
  this->_protocol = config.protocol;
  this->_regionId = config.regionId;
  this->_userAgent = config.userAgent;
  this->_readTimeout = config.readTimeout;
  this->_connectTimeout = config.connectTimeout;
  this->_httpProxy = config.httpProxy;
  this->_httpsProxy = config.httpsProxy;
  this->_noProxy = config.noProxy;
  this->_socks5Proxy = config.socks5Proxy;
  this->_socks5NetWork = config.socks5NetWork;
  this->_maxIdleConns = config.maxIdleConns;
  this->_endpointType = config.endpointType;
  this->_openPlatformEndpoint = config.openPlatformEndpoint;
};

map<string, boost::any> Alibabacloud_RPC::Client::doRequest(string action, string protocol, string method, string version, string authType, map<string, boost::any> query, map<string, boost::any> body, Darabonba_Util::RuntimeOptions runtime){
  runtime->validate();
  map<string, boost::any> runtime_ = {
    {"timeouted", "retry"},
    {"readTimeout", Darabonba_Util::Client::defaultNumber(runtime.readTimeout, this->_readTimeout)},
    {"connectTimeout", Darabonba_Util::Client::defaultNumber(runtime.connectTimeout, this->_connectTimeout)},
    {"httpProxy", Darabonba_Util::Client::defaultString(runtime.httpProxy, this->_httpProxy)},
    {"httpsProxy", Darabonba_Util::Client::defaultString(runtime.httpsProxy, this->_httpsProxy)},
    {"noProxy", Darabonba_Util::Client::defaultString(runtime.noProxy, this->_noProxy)},
    {"maxIdleConns", Darabonba_Util::Client::defaultNumber(runtime.maxIdleConns, this->_maxIdleConns)},
    {"retry", map<string, boost::any>({
      {"retryable", runtime.autoretry},
      {"maxAttempts", Darabonba_Util::Client::defaultNumber(runtime.maxAttempts, 3)}
    })},
    {"backoff", map<string, boost::any>({
      {"policy", Darabonba_Util::Client::defaultString(runtime.backoffPolicy, "no")},
      {"period", Darabonba_Util::Client::defaultNumber(runtime.backoffPeriod, 1)}
    })},
    {"ignoreSSL", runtime.ignoreSSL}
  };
  Request _lastRequest = nullptr;
  boost::exception _lastException = nullptr;
  int _now = static_cast<long int>(time(NULL));
  int _retryTimes = 0;
  while (Core::allowRetry(runtime_["retry"], _retryTimes, _now)) {
    if (_retryTimes > 0) {
      int _backoffTime = Core::getBackoffTime(runtime_["backoff"], _retryTimes);
      if (_backoffTime > 0) {
        Core::sleep(_backoffTime);
      }
    }
    _retryTimes = _retryTimes + 1;
    try {
      Request request_ = new Request();
      request_.protocol = Darabonba_Util::Client::defaultString(this->_protocol, protocol);
      request_.method = method;
      request_.pathname = "/";
      request_.query = Alibabacloud_RPCUtil::Client::query({
        {"Action", action},
        {"Format", "json"},
        {"Timestamp", Alibabacloud_RPCUtil::Client::getTimestamp()},
        {"Version", version},
        {"SignatureNonce", Darabonba_Util::Client::getNonce()},
        {"", query}
      });
      // endpoint is setted in product client
      request_.headers = {
        {"x-acs-version", version},
        {"x-acs-action", action},
        {"host", this->_endpoint},
        {"user-agent", this.getUserAgent()}
      };
      if (!Darabonba_Util::Client::isUnset(body)) {
        map<string, boost::any> tmp = Darabonba_Util::Client::anyifyMapValue(Alibabacloud_RPCUtil::Client::query(body));
        request_.body = Darabonba_Util::Client::toFormString(tmp);
        request_.headers.insert(pair<string, string>("content-type", "application/x-www-form-urlencoded"));
      }
      if (!Darabonba_Util::Client::equalString(authType, "Anonymous")) {
        string accessKeyId = this.getAccessKeyId();
        string accessKeySecret = this.getAccessKeySecret();
        string securityToken = this.getSecurityToken();
        if (!Darabonba_Util::Client::empty(securityToken)) {
          request_.query.insert(pair<string, string>("SecurityToken", securityToken));
        }
        request_.query.insert(pair<string, string>("SignatureMethod", "HMAC-SHA1"));
        request_.query.insert(pair<string, string>("SignatureVersion", "1.0"));
        request_.query.insert(pair<string, string>("AccessKeyId", accessKeyId));
        map<string, string> signedParam = {
          {"", request_.query},
          {"", Alibabacloud_RPCUtil::Client::query(body)}
        };
        request_.query.insert(pair<string, string>("Signature", Alibabacloud_RPCUtil::Client::getSignatureV1(signedParam, request_.method, accessKeySecret)));
      }
      _lastRequest = request_;
      Response response_= Core::doRequest(request_, runtime_);
      boost::any obj = Darabonba_Util::Client::readAsJSON(response_.body);
      map<string, boost::any> res = Darabonba_Util::Client::assertAsMap(obj);
      if (Darabonba_Util::Client::is4xx(response_.statusCode) || Darabonba_Util::Client::is5xx(response_.statusCode)) {
        BOOST_THROW_EXCEPTION(Error({
          {"code", "" + Client::defaultAny(res["Code"], res["code"]) + "Error"},
          {"message", "code: " + response_.statusCode + ", " + Client::defaultAny(res["Message"], res["message"]) + " requestid: " + Client::defaultAny(res["RequestId"], res["requestId"]) + ""},
          {"data", res}
        }));
      }
      return res;
    }
    catch (boost::exception &e) {
      if (Core::isRetryable(e)) {
        _lastException = e;
        continue;
      }
      BOOST_THROW_EXCEPTION(e);
    }
  }
  BOOST_THROW_EXCEPTION(UnretryableError(_lastRequest, _lastException));
}

string Alibabacloud_RPC::Client::getUserAgent(){
  string userAgent = Darabonba_Util::Client::getUserAgent(this->_userAgent);
  return userAgent;
}

string Alibabacloud_RPC::Client::getAccessKeyId(){
  if (Darabonba_Util::Client::isUnset(this->_credential)) {
    return '';
  }
  string accessKeyId = this->_credential.getAccessKeyId();
  return accessKeyId;
}

string Alibabacloud_RPC::Client::getAccessKeySecret(){
  if (Darabonba_Util::Client::isUnset(this->_credential)) {
    return '';
  }
  string secret = this->_credential.getAccessKeySecret();
  return secret;
}

string Alibabacloud_RPC::Client::getSecurityToken(){
  if (Darabonba_Util::Client::isUnset(this->_credential)) {
    return '';
  }
  string token = this->_credential.getSecurityToken();
  return token;
}

void Alibabacloud_RPC::Client::checkConfig(Config config){
  if (Darabonba_Util::Client::empty(this->_endpointRule) && Darabonba_Util::Client::empty(config.endpoint)) {
    BOOST_THROW_EXCEPTION(Error({
      {"code", "ParameterMissing"},
      {"message", "'config.endpoint' can not be empty"}
    }));
  }
}

boost::any Alibabacloud_RPC::Client::defaultAny(boost::any inputValue, boost::any defaultValue){
  if (Darabonba_Util::Client::isUnset(inputValue)) {
    return defaultValue;
  }
  return inputValue;
}

