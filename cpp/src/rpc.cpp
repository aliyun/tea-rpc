// This file is auto-generated, don't edit it. Thanks.

#include <alibabacloud/credential.hpp>
#include <alibabacloud/rpc.hpp>
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

Alibabacloud_RPC::Client::Client(const shared_ptr<Config> &config) {
  if (Darabonba_Util::Client::isUnset<Config>(config)) {
    BOOST_THROW_EXCEPTION(Darabonba::Error(
        map<string, string>({{"code", "ParameterMissing"},
                             {"message", "'config' can not be unset"}})));
  }
  Darabonba_Util::Client::validateModel(config);
  if (!Darabonba_Util::Client::empty(config->accessKeyId) &&
      !Darabonba_Util::Client::empty(config->accessKeySecret)) {
    if (!Darabonba_Util::Client::empty(config->securityToken)) {
      config->type = make_shared<string>("sts");
    } else {
      config->type = make_shared<string>("access_key");
    }
    shared_ptr<Alibabacloud_Credential::Config> credentialConfig =
        make_shared<Alibabacloud_Credential::Config>(map<string, boost::any>(
            {{"accessKeyId", !config->accessKeyId
                                 ? boost::any()
                                 : boost::any(*config->accessKeyId)},
             {"type", !config->type ? boost::any() : boost::any(*config->type)},
             {"accessKeySecret", !config->accessKeySecret
                                     ? boost::any()
                                     : boost::any(*config->accessKeySecret)},
             {"securityToken", !config->securityToken
                                   ? boost::any()
                                   : boost::any(*config->securityToken)}}));
    _credential =
        make_shared<Alibabacloud_Credential::Client>(credentialConfig);
  } else if (!Darabonba_Util::Client::isUnset<Alibabacloud_Credential::Client>(
                 config->credential)) {
    _credential = config->credential;
  } else {
    BOOST_THROW_EXCEPTION(Darabonba::Error(map<string, string>(
        {{"code", "ParameterMissing"},
         {"message", "'accessKeyId' and 'accessKeySecret' or 'credential' can "
                     "not be unset"}})));
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

map<string, boost::any> Alibabacloud_RPC::Client::doRequest(
    shared_ptr<string> action, shared_ptr<string> protocol,
    shared_ptr<string> method, shared_ptr<string> version,
    shared_ptr<string> authType, shared_ptr<map<string, boost::any>> query,
    shared_ptr<map<string, boost::any>> body,
    shared_ptr<Darabonba_Util::RuntimeOptions> runtime) {
  runtime->validate();
  shared_ptr<map<string, boost::any>> runtime_ = make_shared<
      map<string, boost::any>>(map<string, boost::any>(
      {{"timeouted", boost::any(string("retry"))},
       {"readTimeout", boost::any(Darabonba_Util::Client::defaultNumber(
                           runtime->readTimeout, _readTimeout))},
       {"connectTimeout", boost::any(Darabonba_Util::Client::defaultNumber(
                              runtime->connectTimeout, _connectTimeout))},
       {"httpProxy", boost::any(string(Darabonba_Util::Client::defaultString(
                         runtime->httpProxy, _httpProxy)))},
       {"httpsProxy", boost::any(string(Darabonba_Util::Client::defaultString(
                          runtime->httpsProxy, _httpsProxy)))},
       {"noProxy", boost::any(string(Darabonba_Util::Client::defaultString(
                       runtime->noProxy, _noProxy)))},
       {"maxIdleConns", boost::any(Darabonba_Util::Client::defaultNumber(
                            runtime->maxIdleConns, _maxIdleConns))},
       {"retry", boost::any(map<string, boost::any>(
                     {{"retryable", !runtime->autoretry
                                        ? boost::any()
                                        : boost::any(*runtime->autoretry)},
                      {"maxAttempts",
                       boost::any(Darabonba_Util::Client::defaultNumber(
                           runtime->maxAttempts, make_shared<int>(3)))}}))},
       {"backoff",
        boost::any(map<string, boost::any>(
            {{"policy",
              boost::any(string(Darabonba_Util::Client::defaultString(
                  runtime->backoffPolicy, make_shared<string>("no"))))},
             {"period", boost::any(Darabonba_Util::Client::defaultNumber(
                            runtime->backoffPeriod, make_shared<int>(1)))}}))},
       {"ignoreSSL", !runtime->ignoreSSL ? boost::any()
                                         : boost::any(*runtime->ignoreSSL)}}));
  shared_ptr<Darabonba::Request> _lastRequest;
  shared_ptr<std::exception> _lastException;
  shared_ptr<int> _now = make_shared<int>(0);
  shared_ptr<int> _retryTimes = make_shared<int>(0);
  while (Darabonba::Core::allowRetry(
      make_shared<boost::any>((*runtime_)["retry"]), _retryTimes, _now)) {
    if (*_retryTimes > 0) {
      shared_ptr<int> _backoffTime =
          make_shared<int>(Darabonba::Core::getBackoffTime(
              make_shared<boost::any>((*runtime_)["backoff"]), _retryTimes));
      if (*_backoffTime > 0) {
        Darabonba::Core::sleep(_backoffTime);
      }
    }
    _retryTimes = make_shared<int>(*_retryTimes + 1);
    try {
      shared_ptr<Darabonba::Request> request_ =
          make_shared<Darabonba::Request>();
      request_->protocol =
          Darabonba_Util::Client::defaultString(_protocol, protocol);
      request_->method = *method;
      request_->pathname = "/";
      request_->query = Alibabacloud_RPCUtil::Client::query(
          Darabonba::Converter::mapPointer(Darabonba::Converter::merge(
              map<string, boost::any>(
                  {{"Action", !action ? boost::any() : boost::any(*action)},
                   {"Format", boost::any(string("json"))},
                   {"Timestamp",
                    boost::any(
                        string(Alibabacloud_RPCUtil::Client::getTimestamp()))},
                   {"Version", !version ? boost::any() : boost::any(*version)},
                   {"SignatureNonce",
                    boost::any(string(Darabonba_Util::Client::getNonce()))}}),
              !query ? map<string, boost::any>() : *query)));
      // endpoint is setted in product client
      request_->headers = {{"x-acs-version", !version ? string() : *version},
                           {"x-acs-action", !action ? string() : *action},
                           {"host", !_endpoint ? string() : *_endpoint},
                           {"user-agent", getUserAgent()}};
      if (!Darabonba_Util::Client::isUnset<map<string, boost::any>>(body)) {
        shared_ptr<map<string, boost::any>> tmp =
            make_shared<map<string, boost::any>>(
                Darabonba_Util::Client::anyifyMapValue(
                    make_shared<map<string, string>>(
                        Alibabacloud_RPCUtil::Client::query(body))));
        request_->body = Darabonba::Converter::toStream(
            Darabonba_Util::Client::toFormString(tmp));
        request_->headers.insert(pair<string, string>(
            "content-type", "application/x-www-form-urlencoded"));
      }
      if (!Darabonba_Util::Client::equalString(
              authType, make_shared<string>("Anonymous"))) {
        shared_ptr<string> accessKeyId = make_shared<string>(getAccessKeyId());
        shared_ptr<string> accessKeySecret =
            make_shared<string>(getAccessKeySecret());
        shared_ptr<string> securityToken =
            make_shared<string>(getSecurityToken());
        if (!Darabonba_Util::Client::empty(securityToken)) {
          request_->query.insert(
              pair<string, string>("SecurityToken", *securityToken));
        }
        request_->query.insert(
            pair<string, string>("SignatureMethod", "HMAC-SHA1"));
        request_->query.insert(pair<string, string>("SignatureVersion", "1.0"));
        request_->query.insert(
            pair<string, string>("AccessKeyId", *accessKeyId));
        shared_ptr<map<string, string>> signedParam =
            make_shared<map<string, string>>(Darabonba::Converter::merge(
                map<string, string>(), request_->query,
                Alibabacloud_RPCUtil::Client::query(body)));
        request_->query.insert(pair<string, string>(
            "Signature", Alibabacloud_RPCUtil::Client::getSignatureV1(
                             signedParam, make_shared<string>(request_->method),
                             accessKeySecret)));
      }
      _lastRequest = request_;
      shared_ptr<Darabonba::Response> response_ =
          make_shared<Darabonba::Response>(
              Darabonba::Core::doAction(request_, runtime_));
      shared_ptr<boost::any> obj = make_shared<boost::any>(
          Darabonba_Util::Client::readAsJSON(response_->body));
      shared_ptr<map<string, boost::any>> res =
          make_shared<map<string, boost::any>>(
              Darabonba_Util::Client::assertAsMap(obj));
      if (Darabonba_Util::Client::is4xx(
              make_shared<int>(response_->statusCode)) ||
          Darabonba_Util::Client::is5xx(
              make_shared<int>(response_->statusCode))) {
        BOOST_THROW_EXCEPTION(Darabonba::Error(map<string, boost::any>(
            {{"code", boost::any(string(
                          "" +
                          Darabonba::Converter::toString(Client::defaultAny(
                              make_shared<boost::any>((*res)["Code"]),
                              make_shared<boost::any>((*res)["code"]))) +
                          ""))},
             {"message",
              boost::any(string(
                  "code: " +
                  boost::lexical_cast<string>(response_->statusCode) + ", " +
                  Darabonba::Converter::toString(Client::defaultAny(
                      make_shared<boost::any>((*res)["Message"]),
                      make_shared<boost::any>((*res)["message"]))) +
                  " request id: " +
                  Darabonba::Converter::toString(Client::defaultAny(
                      make_shared<boost::any>((*res)["RequestId"]),
                      make_shared<boost::any>((*res)["requestId"]))) +
                  ""))},
             {"data", !res ? boost::any() : boost::any(*res)}})));
      }
      return *res;
    } catch (std::exception &e) {
      if (Darabonba::Core::isRetryable(e)) {
        _lastException = make_shared<std::exception>(e);
        continue;
      }
      BOOST_THROW_EXCEPTION(e);
    }
  }
  BOOST_THROW_EXCEPTION(
      Darabonba::UnretryableError(_lastRequest, _lastException));
}

string Alibabacloud_RPC::Client::getUserAgent() {
  shared_ptr<string> userAgent =
      make_shared<string>(Darabonba_Util::Client::getUserAgent(_userAgent));
  return *userAgent;
}

string Alibabacloud_RPC::Client::getAccessKeyId() {
  if (Darabonba_Util::Client::isUnset<Alibabacloud_Credential::Client>(
          _credential)) {
    return string("");
  }
  shared_ptr<string> accessKeyId =
      make_shared<string>(_credential->getAccessKeyId());
  return *accessKeyId;
}

string Alibabacloud_RPC::Client::getAccessKeySecret() {
  if (Darabonba_Util::Client::isUnset<Alibabacloud_Credential::Client>(
          _credential)) {
    return string("");
  }
  shared_ptr<string> secret =
      make_shared<string>(_credential->getAccessKeySecret());
  return *secret;
}

string Alibabacloud_RPC::Client::getSecurityToken() {
  if (Darabonba_Util::Client::isUnset<Alibabacloud_Credential::Client>(
          _credential)) {
    return string("");
  }
  shared_ptr<string> token =
      make_shared<string>(_credential->getSecurityToken());
  return *token;
}

void Alibabacloud_RPC::Client::checkConfig(shared_ptr<Config> config) {
  if (Darabonba_Util::Client::empty(_endpointRule) &&
      Darabonba_Util::Client::empty(config->endpoint)) {
    BOOST_THROW_EXCEPTION(Darabonba::Error(map<string, string>(
        {{"code", "ParameterMissing"},
         {"message", "'config.endpoint' can not be empty"}})));
  }
}

boost::any
Alibabacloud_RPC::Client::defaultAny(const boost::any &inputValue,
                                     const boost::any &defaultValue) {
  if (Darabonba_Util::Client::isUnset<boost::any>(inputValue)) {
    return defaultValue;
  }
  return inputValue;
}
