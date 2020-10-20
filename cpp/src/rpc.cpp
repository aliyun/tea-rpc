// This file is auto-generated, don't edit it. Thanks.

#include <alibabacloud/rpc.hpp>
#include <alibabacloud/credential.hpp>
#include <alibabacloud/rpcutil.hpp>
#include <boost/any.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/throw_exception.hpp>
#include <darabonba/core.hpp>
#include <darabonba/util.hpp>
#include <iostream>
#include <map>

using namespace std;

using namespace Alibabacloud_RPC;

Alibabacloud_RPC::Client::Client(shared_ptr<Config> config) {
  if (Darabonba_Util::Client::isUnset(config)) {
    BOOST_THROW_EXCEPTION(Darabonba::Error(map<string, string>({
      {"code", "ParameterMissing"},
      {"message", "'config' can not be unset"}
    })));
  }
  Darabonba_Util::Client::validateModel(config);
  if (!Darabonba_Util::Client::empty(config->accessKeyId) && !Darabonba_Util::Client::empty(config->accessKeySecret)) {
    if (!Darabonba_Util::Client::empty(config->securityToken)) {
      config->type = make_shared<string>("sts");
    }
    else {
      config->type = make_shared<string>("access_key");
    }
    Alibabacloud_Credential::Config credentialConfig(map<string, string>({
      {"accessKeyId", !config->accessKeyId ? NULL : *config->accessKeyId},
      {"type", !config->type ? NULL : *config->type},
      {"accessKeySecret", !config->accessKeySecret ? NULL : *config->accessKeySecret},
      {"securityToken", !config->securityToken ? NULL : *config->securityToken}
    }));
    _credential = make_shared<Alibabacloud_Credential::Client>(make_shared<Alibabacloud_Credential::Config>(credentialConfig));
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

map<string, boost::any> Alibabacloud_RPC::Client::doRequest(shared_ptr<string> action,
                                                            shared_ptr<string> protocol,
                                                            shared_ptr<string> method,
                                                            shared_ptr<string> version,
                                                            shared_ptr<string> authType,
                                                            shared_ptr<map<string, boost::any>> query,
                                                            shared_ptr<map<string, boost::any>> body,
                                                            shared_ptr<Darabonba_Util::RuntimeOptions> runtime) {
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
      {"retryable", boost::any(!runtime->autoretry ? NULL : *runtime->autoretry)},
      {"maxAttempts", boost::any(Darabonba_Util::Client::defaultNumber(runtime->maxAttempts, make_shared<int>(3)))}
    }))},
    {"backoff", boost::any(map<string, boost::any>({
      {"policy", boost::any(Darabonba_Util::Client::defaultString(runtime->backoffPolicy, make_shared<string>("no")))},
      {"period", boost::any(Darabonba_Util::Client::defaultNumber(runtime->backoffPeriod, make_shared<int>(1)))}
    }))},
    {"ignoreSSL", boost::any(!runtime->ignoreSSL ? NULL : *runtime->ignoreSSL)}
  };
  Darabonba::Request _lastRequest;
  std::exception _lastException;
  int _now = 0;
  int _retryTimes = 0;
  while (Darabonba::Core::allowRetry(make_shared<boost::any>(runtime_.at("retry")), make_shared<int>(_retryTimes), make_shared<int>(_now))) {
    if (_retryTimes > 0) {
      int _backoffTime = Darabonba::Core::getBackoffTime(make_shared<boost::any>(runtime_.at("backoff")), make_shared<int>(_retryTimes));
      if (_backoffTime > 0) {
        Darabonba::Core::sleep(make_shared<int>(_backoffTime));
      }
    }
    _retryTimes = _retryTimes + 1;
    try {
      Darabonba::Request request_ = Darabonba::Request();
      request_.protocol = Darabonba_Util::Client::defaultString(_protocol, protocol);
      request_.method = *method;
      request_.pathname = "/";
      request_.query = Alibabacloud_RPCUtil::Client::query(Darabonba::Converter::mapPointer(Darabonba::Converter::merge(map<string, boost::any>({
        {"Action", boost::any(!action ? NULL : *action)},
        {"Format", boost::any("json")},
        {"Timestamp", boost::any(Alibabacloud_RPCUtil::Client::getTimestamp())},
        {"Version", boost::any(!version ? NULL : *version)},
        {"SignatureNonce", boost::any(Darabonba_Util::Client::getNonce())}
      }), *query)));
      // endpoint is setted in product client
      request_.headers = {
        {"x-acs-version", !version ? NULL : *version},
        {"x-acs-action", !action ? NULL : *action},
        {"host", !_endpoint ? NULL : *_endpoint},
        {"user-agent", getUserAgent()}
      };
      if (!Darabonba_Util::Client::isUnset(body)) {
        map<string, boost::any> tmp = Darabonba_Util::Client::anyifyMapValue(make_shared<map<string, string>>(Alibabacloud_RPCUtil::Client::query(body)));
        request_.body = Darabonba::Converter::toStream(Darabonba_Util::Client::toFormString(make_shared<map<string, boost::any>>(tmp)));
        request_.headers.insert(pair<string, string>("content-type", "application/x-www-form-urlencoded"));
      }
      if (!Darabonba_Util::Client::equalString(authType, make_shared<string>("Anonymous"))) {
        string accessKeyId = getAccessKeyId();
        string accessKeySecret = getAccessKeySecret();
        string securityToken = getSecurityToken();
        if (!Darabonba_Util::Client::empty(make_shared<string>(securityToken))) {
          request_.query.insert(pair<string, string>("SecurityToken", securityToken));
        }
        request_.query.insert(pair<string, string>("SignatureMethod", "HMAC-SHA1"));
        request_.query.insert(pair<string, string>("SignatureVersion", "1.0"));
        request_.query.insert(pair<string, string>("AccessKeyId", accessKeyId));
        map<string, string> signedParam = Darabonba::Converter::merge(map<string, string>(request_.query), map<string, string>(Alibabacloud_RPCUtil::Client::query(body)));
        request_.query.insert(pair<string, string>("Signature", Alibabacloud_RPCUtil::Client::getSignatureV1(make_shared<map<string, string>>(signedParam), make_shared<string>(request_.method), make_shared<string>(accessKeySecret))));
      }
      _lastRequest = request_;
      Darabonba::Response response_= Darabonba::Core::doAction(request_, runtime_);
      boost::any obj = Darabonba_Util::Client::readAsJSON(response_.body);
      map<string, boost::any> res = Darabonba_Util::Client::assertAsMap(make_shared<boost::any>(obj));
      if (Darabonba_Util::Client::is4xx(make_shared<int>(response_.statusCode)) || Darabonba_Util::Client::is5xx(make_shared<int>(response_.statusCode))) {
        BOOST_THROW_EXCEPTION(Darabonba::Error(map<string, boost::any>({
          {"code", boost::any(string("" + Darabonba::Converter::toString(Client::defaultAny(make_shared<boost::any>(res.at("Code")), make_shared<boost::any>(res.at("code")))) + ""))},
          {"message", boost::any(string("code: " + boost::lexical_cast<string>(response_.statusCode) + ", " + Darabonba::Converter::toString(Client::defaultAny(make_shared<boost::any>(res.at("Message")), make_shared<boost::any>(res.at("message")))) + " request id: " + Darabonba::Converter::toString(Client::defaultAny(make_shared<boost::any>(res.at("RequestId")), make_shared<boost::any>(res.at("requestId")))) + ""))},
          {"data", boost::any(res)}
        })));
      }
      return res;
    }
    catch (std::exception &e) {
      if (Darabonba::Core::isRetryable(e)) {
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

void Alibabacloud_RPC::Client::checkConfig(shared_ptr<Config> config) {
  if (Darabonba_Util::Client::empty(_endpointRule) && Darabonba_Util::Client::empty(config->endpoint)) {
    BOOST_THROW_EXCEPTION(Darabonba::Error(map<string, string>({
      {"code", "ParameterMissing"},
      {"message", "'config.endpoint' can not be empty"}
    })));
  }
}

boost::any Alibabacloud_RPC::Client::defaultAny(shared_ptr<boost::any> inputValue, shared_ptr<boost::any> defaultValue) {
  if (Darabonba_Util::Client::isUnset(inputValue)) {
    return *defaultValue;
  }
  return *inputValue;
}

