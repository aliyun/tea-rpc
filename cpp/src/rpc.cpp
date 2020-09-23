// This file is auto-generated, don't edit it. Thanks.

#include <alibabacloud/rpc.hpp>
#include <alibabacloud/credential.hpp>
#include <alibabacloud/rpcutil.hpp>
#include <boost/any.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/throw_exception.hpp>
#include <cpprest/streams.h>
#include <darabonba/core.hpp>
#include <darabonba/util.hpp>
#include <iostream>
#include <map>

using namespace std;

Alibabacloud_RPC::Client::Client(Config *config) {
  if (Darabonba_Util::Client::isUnset(config)) {
    BOOST_THROW_EXCEPTION(Darabonba::Error(map<string, string>({
      {"code", "ParameterMissing"},
      {"message", "'config' can not be unset"}
    })));
  }
  Darabonba_Util::Client::validateModel(config);
  if (!Darabonba_Util::Client::empty(config->accessKeyId) && !Darabonba_Util::Client::empty(config->accessKeySecret)) {
    if (!Darabonba_Util::Client::empty(config->securityToken)) {
      config->type = new string("sts");
    }
    else {
      config->type = new string("access_key");
    }
    Alibabacloud_Credential::Config credentialConfig = Alibabacloud_Credential::Config(new map<string, string>({
      {"accessKeyId", *config->accessKeyId},
      {"type", *config->type},
      {"accessKeySecret", *config->accessKeySecret},
      {"securityToken", *config->securityToken}
    }));
    _credential = new Alibabacloud_Credential::Client(Alibabacloud_Credential::Client(new Alibabacloud_Credential::Config(credentialConfig)));
  }
  else if (!Darabonba_Util::Client::isUnset(config->credential)) {
    _credential = config->credential;
  }
  else {
    BOOST_THROW_EXCEPTION(Darabonba::Error(map<string, string>({
      {"code", "ParameterMissing"},
      {"message", "'accessKeyId' and 'accessKeySecret' or 'credential' can not be unset"}
    })));
  }
  _network = config->network;
  _suffix = config->suffix;
  _endpoint = config->endpoint;
  _protocol = config->protocol;
  _regionId = config->regionId;
  _userAgent = config->userAgent;
  _readTimeout = config->readTimeout;
  _connectTimeout = config->connectTimeout;
  _httpProxy = config->httpProxy;
  _httpsProxy = config->httpsProxy;
  _noProxy = config->noProxy;
  _socks5Proxy = config->socks5Proxy;
  _socks5NetWork = config->socks5NetWork;
  _maxIdleConns = config->maxIdleConns;
  _endpointType = config->endpointType;
  _openPlatformEndpoint = config->openPlatformEndpoint;
};

map<string, boost::any> Alibabacloud_RPC::Client::doRequest(string *action,
                                                            string *protocol,
                                                            string *method,
                                                            string *version,
                                                            string *authType,
                                                            map<string, boost::any> *query,
                                                            map<string, boost::any> *body,
                                                            Darabonba_Util::RuntimeOptions *runtime) {
  runtime->validate();
  map<string, boost::any> runtime_ = {
    {"timeouted", boost::any("retry")},
    {"readTimeout", boost::any(Darabonba_Util::Client::defaultNumber(runtime->readTimeout, _readTimeout))},
    {"connectTimeout", boost::any(Darabonba_Util::Client::defaultNumber(runtime->connectTimeout, _connectTimeout))},
    {"httpProxy", boost::any(Darabonba_Util::Client::defaultString(runtime->httpProxy, _httpProxy))},
    {"httpsProxy", boost::any(Darabonba_Util::Client::defaultString(runtime->httpsProxy, _httpsProxy))},
    {"noProxy", boost::any(Darabonba_Util::Client::defaultString(runtime->noProxy, _noProxy))},
    {"maxIdleConns", boost::any(Darabonba_Util::Client::defaultNumber(runtime->maxIdleConns, _maxIdleConns))},
    {"retry", boost::any(map<string, boost::any>({
      {"retryable", boost::any(*runtime->autoretry)},
      {"maxAttempts", boost::any(Darabonba_Util::Client::defaultNumber(runtime->maxAttempts, new int(3)))}
    }))},
    {"backoff", boost::any(map<string, boost::any>({
      {"policy", boost::any(Darabonba_Util::Client::defaultString(runtime->backoffPolicy, new string("no")))},
      {"period", boost::any(Darabonba_Util::Client::defaultNumber(runtime->backoffPeriod, new int(1)))}
    }))},
    {"ignoreSSL", boost::any(*runtime->ignoreSSL)}
  };
  Darabonba::Request _lastRequest;
  std::exception _lastException;
  int _now = 0;
  int _retryTimes = 0;
  while (Darabonba::Core::allowRetry(new boost::any(runtime_["retry"]), new int(_retryTimes), new int(_now))) {
    if (_retryTimes > 0) {
      int _backoffTime = Darabonba::Core::getBackoffTime(new boost::any(runtime_["backoff"]), new int(_retryTimes));
      if (_backoffTime > 0) {
        Darabonba::Core::sleep(new int(_backoffTime));
      }
    }
    _retryTimes = _retryTimes + 1;
    try {
      Darabonba::Request request_ = Darabonba::Request();
      request_.protocol = Darabonba_Util::Client::defaultString(_protocol, protocol);
      request_.method = *method;
      request_.pathname = "/";
      request_.query = Alibabacloud_RPCUtil::Client::query(Darabonba::Converter::mapPointer(Darabonba::Converter::merge(map<string, boost::any>({
        {"Action", boost::any(*action)},
        {"Format", boost::any("json")},
        {"Timestamp", boost::any(Alibabacloud_RPCUtil::Client::getTimestamp())},
        {"Version", boost::any(*version)},
        {"SignatureNonce", boost::any(Darabonba_Util::Client::getNonce())}
      }), *query)));
      // endpoint is setted in product client
      request_.headers = {
        {"x-acs-version", *version},
        {"x-acs-action", *action},
        {"host", *_endpoint},
        {"user-agent", getUserAgent()}
      };
      if (!Darabonba_Util::Client::isUnset(body)) {
        map<string, boost::any> tmp = Darabonba_Util::Client::anyifyMapValue(new map<string, string>(Alibabacloud_RPCUtil::Client::query(body)));
        request_.body = Darabonba_Util::Client::toFormString(new map<string, boost::any>(tmp));
        request_.headers.insert(pair<string, string>("content-type", "application/x-www-form-urlencoded"));
      }
      if (!Darabonba_Util::Client::equalString(authType, new string("Anonymous"))) {
        string accessKeyId = getAccessKeyId();
        string accessKeySecret = getAccessKeySecret();
        string securityToken = getSecurityToken();
        if (!Darabonba_Util::Client::empty(&securityToken)) {
          request_.query.insert(pair<string, string>("SecurityToken", securityToken));
        }
        request_.query.insert(pair<string, string>("SignatureMethod", "HMAC-SHA1"));
        request_.query.insert(pair<string, string>("SignatureVersion", "1.0"));
        request_.query.insert(pair<string, string>("AccessKeyId", accessKeyId));
        map<string, string> signedParam = Darabonba::Converter::merge(map<string, string>(request_.query), map<string, string>(Alibabacloud_RPCUtil::Client::query(body)));
        request_.query.insert(pair<string, string>("Signature", Alibabacloud_RPCUtil::Client::getSignatureV1(new map<string, string>(signedParam), new string(request_.method), new string(accessKeySecret))));
      }
      _lastRequest = request_;
      Darabonba::Response response_= Darabonba::Core::doAction(request_, runtime_);
      boost::any obj = Darabonba_Util::Client::readAsJSON(new concurrency::streams::istream(response_.body));
      map<string, boost::any> res = Darabonba_Util::Client::assertAsMap(new boost::any(obj));
      if (Darabonba_Util::Client::is4xx(new int(response_.statusCode)) || Darabonba_Util::Client::is5xx(new int(response_.statusCode))) {
        BOOST_THROW_EXCEPTION(Darabonba::Error(map<string, boost::any>({
          {"code", boost::any(string("" + Darabonba::Converter::toString(Client::defaultAny(new boost::any(res["Code"]), new boost::any(res["code"]))) + ""))},
          {"message", boost::any(string("code: " + boost::lexical_cast<string>(response_.statusCode) + ", " + Darabonba::Converter::toString(Client::defaultAny(new boost::any(res["Message"]), new boost::any(res["message"]))) + " request id: " + Darabonba::Converter::toString(Client::defaultAny(new boost::any(res["RequestId"]), new boost::any(res["requestId"]))) + ""))},
          {"data", boost::any(res)}
        })));
      }
      return res;
    }
    catch (std::exception &e) {
      if (Darabonba::Core::isRetryable(&e)) {
        _lastException = e;
        continue;
      }
      BOOST_THROW_EXCEPTION(e);
    }
  }
  BOOST_THROW_EXCEPTION(Darabonba::UnretryableError(_lastRequest, _lastException));
}

string Alibabacloud_RPC::Client::getUserAgent() {
  string userAgent = Darabonba_Util::Client::getUserAgent(_userAgent);
  return userAgent;
}

string Alibabacloud_RPC::Client::getAccessKeyId() {
  if (Darabonba_Util::Client::isUnset(_credential)) {
    return string("");
  }
  string accessKeyId = _credential->getAccessKeyId();
  return accessKeyId;
}

string Alibabacloud_RPC::Client::getAccessKeySecret() {
  if (Darabonba_Util::Client::isUnset(_credential)) {
    return string("");
  }
  string secret = _credential->getAccessKeySecret();
  return secret;
}

string Alibabacloud_RPC::Client::getSecurityToken() {
  if (Darabonba_Util::Client::isUnset(_credential)) {
    return string("");
  }
  string token = _credential->getSecurityToken();
  return token;
}

void Alibabacloud_RPC::Client::checkConfig(Config *config) {
  if (Darabonba_Util::Client::empty(_endpointRule) && Darabonba_Util::Client::empty(config->endpoint)) {
    BOOST_THROW_EXCEPTION(Darabonba::Error(map<string, string>({
      {"code", "ParameterMissing"},
      {"message", "'config.endpoint' can not be empty"}
    })));
  }
}

boost::any Alibabacloud_RPC::Client::defaultAny(boost::any *inputValue, boost::any *defaultValue) {
  if (Darabonba_Util::Client::isUnset(inputValue)) {
    return *defaultValue;
  }
  return *inputValue;
}

