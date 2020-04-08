// This file is auto-generated, don't edit it. Thanks.

using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Threading.Tasks;

using Tea;
using Tea.Utils;

using AlibabaCloud.RPCClient.Models;

namespace AlibabaCloud.RPCClient
{
    public class Client 
    {
        protected string _endpoint;
        protected string _regionId;
        protected string _protocol;
        protected string _userAgent;
        protected string _endpointRule;
        protected Dictionary<string, string> _endpointMap;
        protected string _suffix;
        protected int? _readTimeout;
        protected int? _connectTimeout;
        protected string _httpProxy;
        protected string _httpsProxy;
        protected string _socks5Proxy;
        protected string _socks5NetWork;
        protected string _noProxy;
        protected string _network;
        protected string _productId;
        protected int? _maxIdleConns;
        protected string _endpointType;
        protected string _openPlatformEndpoint;
        protected Aliyun.Credentials.Client _credential;

        public Client(Config config)
        {
            Aliyun.Credentials.Models.Config credentialConfig = null;
            if (AlibabaCloud.TeaUtil.Common.IsUnset(config.ToMap()))
            {
                config = new Config();
                this._credential = new Aliyun.Credentials.Client(null);
            }
            else
            {
                credentialConfig = new Aliyun.Credentials.Models.Config
                {
                    AccessKeyId = config.AccessKeyId,
                    Type = config.Type,
                    AccessKeySecret = config.AccessKeySecret,
                    SecurityToken = config.SecurityToken,
                };
                this._credential = new Aliyun.Credentials.Client(credentialConfig);
            }
            this._network = config.Network;
            this._suffix = config.Suffix;
            this._endpoint = config.Endpoint;
            this._protocol = config.Protocol;
            this._regionId = config.RegionId;
            this._userAgent = config.UserAgent;
            this._readTimeout = config.ReadTimeout;
            this._connectTimeout = config.ConnectTimeout;
            this._httpProxy = config.HttpProxy;
            this._httpsProxy = config.HttpsProxy;
            this._noProxy = config.NoProxy;
            this._socks5Proxy = config.Socks5Proxy;
            this._socks5NetWork = config.Socks5NetWork;
            this._maxIdleConns = config.MaxIdleConns;
            this._endpointType = config.EndpointType;
            this._openPlatformEndpoint = config.OpenPlatformEndpoint;
        }

        public Dictionary<string, object> DoRequest(string action, string protocol, string method, string authType, Dictionary<string, object> query, Dictionary<string, object> body, AlibabaCloud.TeaUtil.Models.RuntimeOptions runtime)
        {
            Dictionary<string, object> runtime_ = new Dictionary<string, object>
            {
                {"timeouted", "retry"},
                {"readTimeout", AlibabaCloud.TeaUtil.Common.DefaultNumber(runtime.ReadTimeout, _readTimeout)},
                {"connectTimeout", AlibabaCloud.TeaUtil.Common.DefaultNumber(runtime.ConnectTimeout, _connectTimeout)},
                {"httpProxy", AlibabaCloud.TeaUtil.Common.DefaultString(runtime.HttpProxy, _httpProxy)},
                {"httpsProxy", AlibabaCloud.TeaUtil.Common.DefaultString(runtime.HttpsProxy, _httpsProxy)},
                {"noProxy", AlibabaCloud.TeaUtil.Common.DefaultString(runtime.NoProxy, _noProxy)},
                {"maxIdleConns", AlibabaCloud.TeaUtil.Common.DefaultNumber(runtime.MaxIdleConns, _maxIdleConns)},
                {"retry", new Dictionary<string, object>
                {
                    {"retryable", runtime.Autoretry},
                    {"maxAttempts", AlibabaCloud.TeaUtil.Common.DefaultNumber(runtime.MaxAttempts, 3)},
                }},
                {"backoff", new Dictionary<string, object>
                {
                    {"policy", AlibabaCloud.TeaUtil.Common.DefaultString(runtime.BackoffPolicy, "no")},
                    {"period", AlibabaCloud.TeaUtil.Common.DefaultNumber(runtime.BackoffPeriod, 1)},
                }},
                {"ignoreSSL", runtime.IgnoreSSL},
            };

            TeaRequest _lastRequest = null;
            Exception _lastException = null;
            long _now = System.DateTime.Now.Millisecond;
            int _retryTimes = 0;
            while (TeaCore.AllowRetry((IDictionary) runtime_["retry"], _retryTimes, _now))
            {
                if (_retryTimes > 0)
                {
                    int backoffTime = TeaCore.GetBackoffTime((IDictionary)runtime_["backoff"], _retryTimes);
                    if (backoffTime > 0)
                    {
                        TeaCore.Sleep(backoffTime);
                    }
                }
                _retryTimes = _retryTimes + 1;
                try
                {
                    TeaRequest request_ = new TeaRequest();
                    request_.Protocol = AlibabaCloud.TeaUtil.Common.DefaultString(_protocol, protocol);
                    request_.Method = method;
                    request_.Pathname = "/";
                    request_.Query = AlibabaCloud.Commons.Common.Query(TeaConverter.merge<object>
                    (
                        new Dictionary<string, object>()
                        {
                            {"Action", action},
                            {"Format", "json"},
                            {"Timestamp", AlibabaCloud.Commons.Common.GetTimestamp()},
                            {"Version", "2019-12-30"},
                            {"SignatureNonce", AlibabaCloud.TeaUtil.Common.GetNonce()},
                        },
                        query
                    ));
                    if (!AlibabaCloud.TeaUtil.Common.IsUnset(body))
                    {
                        Dictionary<string, object> tmp = AlibabaCloud.TeaUtil.Common.AnyifyMapValue(AlibabaCloud.Commons.Common.Query(body));
                        request_.Body = TeaCore.BytesReadable(AlibabaCloud.TeaUtil.Common.ToFormString(tmp));
                    }
                    // endpoint is setted in product client
                    request_.Headers = new Dictionary<string, string>
                    {
                        {"host", _endpoint},
                        {"user-agent", GetUserAgent()},
                    };
                    if (!AlibabaCloud.TeaUtil.Common.EqualString(authType, "Anonymous"))
                    {
                        string accessKeyId = GetAccessKeyId();
                        string accessKeySecret = GetAccessKeySecret();
                        string securityToken = GetSecurityToken();
                        if (!AlibabaCloud.TeaUtil.Common.Empty(securityToken))
                        {
                            request_.Query["SecurityToken"] = securityToken;
                        }
                        request_.Query["SignatureMethod"] = "HMAC-SHA1";
                        request_.Query["SignatureVersion"] = "1.0";
                        request_.Query["AccessKeyId"] = accessKeyId;
                        request_.Query["Signature"] = AlibabaCloud.Commons.Common.GetSignature(request_, accessKeySecret);
                    }
                    _lastRequest = request_;
                    TeaResponse response_ = TeaCore.DoAction(request_, runtime_);

                    object obj = AlibabaCloud.TeaUtil.Common.ReadAsJSON(response_.Body);
                    Dictionary<string, object> res = AlibabaCloud.TeaUtil.Common.AssertAsMap(obj);
                    if (AlibabaCloud.TeaUtil.Common.Is4xx(response_.StatusCode) || AlibabaCloud.TeaUtil.Common.Is5xx(response_.StatusCode))
                    {
                        throw new TeaException(new Dictionary<string, object>
                        {
                            {"message", res.Get("Message")},
                            {"data", res},
                            {"code", res.Get("Code")},
                        });
                    }
                    return res;
                }
                catch (Exception e)
                {
                    if (TeaCore.IsRetryable(e))
                    {
                        _lastException = e;
                        continue;
                    }
                    throw e;
                }
            }

            throw new TeaUnretryableException(_lastRequest, _lastException);
        }

        public async Task<Dictionary<string, object>> DoRequestAsync(string action, string protocol, string method, string authType, Dictionary<string, object> query, Dictionary<string, object> body, AlibabaCloud.TeaUtil.Models.RuntimeOptions runtime)
        {
            Dictionary<string, object> runtime_ = new Dictionary<string, object>
            {
                {"timeouted", "retry"},
                {"readTimeout", AlibabaCloud.TeaUtil.Common.DefaultNumber(runtime.ReadTimeout, _readTimeout)},
                {"connectTimeout", AlibabaCloud.TeaUtil.Common.DefaultNumber(runtime.ConnectTimeout, _connectTimeout)},
                {"httpProxy", AlibabaCloud.TeaUtil.Common.DefaultString(runtime.HttpProxy, _httpProxy)},
                {"httpsProxy", AlibabaCloud.TeaUtil.Common.DefaultString(runtime.HttpsProxy, _httpsProxy)},
                {"noProxy", AlibabaCloud.TeaUtil.Common.DefaultString(runtime.NoProxy, _noProxy)},
                {"maxIdleConns", AlibabaCloud.TeaUtil.Common.DefaultNumber(runtime.MaxIdleConns, _maxIdleConns)},
                {"retry", new Dictionary<string, object>
                {
                    {"retryable", runtime.Autoretry},
                    {"maxAttempts", AlibabaCloud.TeaUtil.Common.DefaultNumber(runtime.MaxAttempts, 3)},
                }},
                {"backoff", new Dictionary<string, object>
                {
                    {"policy", AlibabaCloud.TeaUtil.Common.DefaultString(runtime.BackoffPolicy, "no")},
                    {"period", AlibabaCloud.TeaUtil.Common.DefaultNumber(runtime.BackoffPeriod, 1)},
                }},
                {"ignoreSSL", runtime.IgnoreSSL},
            };

            TeaRequest _lastRequest = null;
            Exception _lastException = null;
            long _now = System.DateTime.Now.Millisecond;
            int _retryTimes = 0;
            while (TeaCore.AllowRetry((IDictionary) runtime_["retry"], _retryTimes, _now))
            {
                if (_retryTimes > 0)
                {
                    int backoffTime = TeaCore.GetBackoffTime((IDictionary)runtime_["backoff"], _retryTimes);
                    if (backoffTime > 0)
                    {
                        TeaCore.Sleep(backoffTime);
                    }
                }
                _retryTimes = _retryTimes + 1;
                try
                {
                    TeaRequest request_ = new TeaRequest();
                    request_.Protocol = AlibabaCloud.TeaUtil.Common.DefaultString(_protocol, protocol);
                    request_.Method = method;
                    request_.Pathname = "/";
                    request_.Query = AlibabaCloud.Commons.Common.Query(TeaConverter.merge<object>
                    (
                        new Dictionary<string, object>()
                        {
                            {"Action", action},
                            {"Format", "json"},
                            {"Timestamp", AlibabaCloud.Commons.Common.GetTimestamp()},
                            {"Version", "2019-12-30"},
                            {"SignatureNonce", AlibabaCloud.TeaUtil.Common.GetNonce()},
                        },
                        query
                    ));
                    if (!AlibabaCloud.TeaUtil.Common.IsUnset(body))
                    {
                        Dictionary<string, object> tmp = AlibabaCloud.TeaUtil.Common.AnyifyMapValue(AlibabaCloud.Commons.Common.Query(body));
                        request_.Body = TeaCore.BytesReadable(AlibabaCloud.TeaUtil.Common.ToFormString(tmp));
                    }
                    // endpoint is setted in product client
                    request_.Headers = new Dictionary<string, string>
                    {
                        {"host", _endpoint},
                        {"user-agent", GetUserAgent()},
                    };
                    if (!AlibabaCloud.TeaUtil.Common.EqualString(authType, "Anonymous"))
                    {
                        string accessKeyId = await GetAccessKeyIdAsync();
                        string accessKeySecret = await GetAccessKeySecretAsync();
                        string securityToken = await GetSecurityTokenAsync();
                        if (!AlibabaCloud.TeaUtil.Common.Empty(securityToken))
                        {
                            request_.Query["SecurityToken"] = securityToken;
                        }
                        request_.Query["SignatureMethod"] = "HMAC-SHA1";
                        request_.Query["SignatureVersion"] = "1.0";
                        request_.Query["AccessKeyId"] = accessKeyId;
                        request_.Query["Signature"] = AlibabaCloud.Commons.Common.GetSignature(request_, accessKeySecret);
                    }
                    _lastRequest = request_;
                    TeaResponse response_ = await TeaCore.DoActionAsync(request_, runtime_);

                    object obj = AlibabaCloud.TeaUtil.Common.ReadAsJSON(response_.Body);
                    Dictionary<string, object> res = AlibabaCloud.TeaUtil.Common.AssertAsMap(obj);
                    if (AlibabaCloud.TeaUtil.Common.Is4xx(response_.StatusCode) || AlibabaCloud.TeaUtil.Common.Is5xx(response_.StatusCode))
                    {
                        throw new TeaException(new Dictionary<string, object>
                        {
                            {"message", res.Get("Message")},
                            {"data", res},
                            {"code", res.Get("Code")},
                        });
                    }
                    return res;
                }
                catch (Exception e)
                {
                    if (TeaCore.IsRetryable(e))
                    {
                        _lastException = e;
                        continue;
                    }
                    throw e;
                }
            }

            throw new TeaUnretryableException(_lastRequest, _lastException);
        }

        public string GetUserAgent()
        {
            string userAgent = AlibabaCloud.TeaUtil.Common.GetUserAgent(_userAgent);
            return userAgent;
        }

        public string GetAccessKeyId()
        {
            if (AlibabaCloud.TeaUtil.Common.IsUnset(_credential))
            {
                return "";
            }
            string accessKeyId = this._credential.GetAccessKeyId();
            return accessKeyId;
        }

        public async Task<string> GetAccessKeyIdAsync()
        {
            if (AlibabaCloud.TeaUtil.Common.IsUnset(_credential))
            {
                return "";
            }
            string accessKeyId = await this._credential.GetAccessKeyIdAsync();
            return accessKeyId;
        }

        public string GetAccessKeySecret()
        {
            if (AlibabaCloud.TeaUtil.Common.IsUnset(_credential))
            {
                return "";
            }
            string secret = this._credential.GetAccessKeySecret();
            return secret;
        }

        public async Task<string> GetAccessKeySecretAsync()
        {
            if (AlibabaCloud.TeaUtil.Common.IsUnset(_credential))
            {
                return "";
            }
            string secret = await this._credential.GetAccessKeySecretAsync();
            return secret;
        }

        public string GetSecurityToken()
        {
            if (AlibabaCloud.TeaUtil.Common.IsUnset(_credential))
            {
                return "";
            }
            string token = this._credential.GetSecurityToken();
            return token;
        }

        public async Task<string> GetSecurityTokenAsync()
        {
            if (AlibabaCloud.TeaUtil.Common.IsUnset(_credential))
            {
                return "";
            }
            string token = await this._credential.GetSecurityTokenAsync();
            return token;
        }

        public void CheckConfig(Config config)
        {
            if (AlibabaCloud.TeaUtil.Common.Empty(_endpointRule) && AlibabaCloud.TeaUtil.Common.Empty(config.Endpoint))
            {
                throw new TeaException(new Dictionary<string, string>
                {
                    {"name", "ParameterMissing"},
                    {"message", "'config.endpoint' can not be empty"},
                });
            }
        }

    }
}
