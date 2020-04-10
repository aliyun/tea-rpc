// This file is auto-generated, don't edit it. Thanks.
package com.aliyun.tearpc;

import com.aliyun.tea.*;
import com.aliyun.tearpc.models.*;

public class Client {

    public String _endpoint;
    public String _regionId;
    public String _protocol;
    public String _userAgent;
    public String _endpointRule;
    public java.util.Map<String, String> _endpointMap;
    public String _suffix;
    public Integer _readTimeout;
    public Integer _connectTimeout;
    public String _httpProxy;
    public String _httpsProxy;
    public String _socks5Proxy;
    public String _socks5NetWork;
    public String _noProxy;
    public String _network;
    public String _productId;
    public Integer _maxIdleConns;
    public String _endpointType;
    public String _openPlatformEndpoint;
    public com.aliyun.credentials.Client _credential;
    public Client(Config config) throws Exception {
        com.aliyun.credentials.models.Config credentialConfig = null;
        if (com.aliyun.teautil.Common.isUnset(TeaModel.buildMap(config))) {
            config = new Config();
            this._credential = new com.aliyun.credentials.Client(null);
        } else {
            credentialConfig = com.aliyun.credentials.models.Config.build(TeaConverter.buildMap(
                new TeaPair("accessKeyId", config.accessKeyId),
                new TeaPair("type", config.type),
                new TeaPair("accessKeySecret", config.accessKeySecret),
                new TeaPair("securityToken", config.securityToken)
            ));
            this._credential = new com.aliyun.credentials.Client(credentialConfig);
        }

        this._network = config.network;
        this._suffix = config.suffix;
        this._endpoint = config.endpoint;
        this._protocol = config.protocol;
        this._regionId = config.regionId;
        this._userAgent = config.userAgent;
        this._readTimeout = config.readTimeout;
        this._connectTimeout = config.connectTimeout;
        this._httpProxy = config.httpProxy;
        this._httpsProxy = config.httpsProxy;
        this._noProxy = config.noProxy;
        this._socks5Proxy = config.socks5Proxy;
        this._socks5NetWork = config.socks5NetWork;
        this._maxIdleConns = config.maxIdleConns;
        this._endpointType = config.endpointType;
        this._openPlatformEndpoint = config.openPlatformEndpoint;
    }

    public java.util.Map<String, Object> doRequest(String action, String protocol, String method, String version, String authType, java.util.Map<String, Object> query, java.util.Map<String, Object> body, com.aliyun.teautil.models.RuntimeOptions runtime) throws Exception {
        java.util.Map<String, Object> runtime_ = TeaConverter.buildMap(
            new TeaPair("timeouted", "retry"),
            new TeaPair("readTimeout", com.aliyun.teautil.Common.defaultNumber(runtime.readTimeout, _readTimeout)),
            new TeaPair("connectTimeout", com.aliyun.teautil.Common.defaultNumber(runtime.connectTimeout, _connectTimeout)),
            new TeaPair("httpProxy", com.aliyun.teautil.Common.defaultString(runtime.httpProxy, _httpProxy)),
            new TeaPair("httpsProxy", com.aliyun.teautil.Common.defaultString(runtime.httpsProxy, _httpsProxy)),
            new TeaPair("noProxy", com.aliyun.teautil.Common.defaultString(runtime.noProxy, _noProxy)),
            new TeaPair("maxIdleConns", com.aliyun.teautil.Common.defaultNumber(runtime.maxIdleConns, _maxIdleConns)),
            new TeaPair("retry", TeaConverter.buildMap(
                new TeaPair("retryable", runtime.autoretry),
                new TeaPair("maxAttempts", com.aliyun.teautil.Common.defaultNumber(runtime.maxAttempts, 3))
            )),
            new TeaPair("backoff", TeaConverter.buildMap(
                new TeaPair("policy", com.aliyun.teautil.Common.defaultString(runtime.backoffPolicy, "no")),
                new TeaPair("period", com.aliyun.teautil.Common.defaultNumber(runtime.backoffPeriod, 1))
            )),
            new TeaPair("ignoreSSL", runtime.ignoreSSL)
        );

        TeaRequest _lastRequest = null;
        long _now = System.currentTimeMillis();
        int _retryTimes = 0;
        while (Tea.allowRetry((java.util.Map<String, Object>) runtime_.get("retry"), _retryTimes, _now)) {
            if (_retryTimes > 0) {
                int backoffTime = Tea.getBackoffTime(runtime_.get("backoff"), _retryTimes);
                if (backoffTime > 0) {
                    Tea.sleep(backoffTime);
                }
            }
            _retryTimes = _retryTimes + 1;
            try {
                TeaRequest request_ = new TeaRequest();
                request_.protocol = com.aliyun.teautil.Common.defaultString(_protocol, protocol);
                request_.method = method;
                request_.pathname = "/";
                request_.query = com.aliyun.common.Common.query(TeaConverter.merge(Object.class,
                    TeaConverter.buildMap(
                        new TeaPair("Action", action),
                        new TeaPair("Format", "json"),
                        new TeaPair("Timestamp", com.aliyun.common.Common.getTimestamp()),
                        new TeaPair("Version", version),
                        new TeaPair("SignatureNonce", com.aliyun.teautil.Common.getNonce())
                    ),
                    query
                ));
                java.util.Map<String, String> signedParam = TeaConverter.merge(String.class,
                    request_.query,
                    com.aliyun.common.Common.query(body)
                );
                if (!com.aliyun.teautil.Common.isUnset(body)) {
                    java.util.Map<String, Object> tmp = com.aliyun.teautil.Common.anyifyMapValue(com.aliyun.common.Common.query(body));
                    request_.body = Tea.toReadable(com.aliyun.teautil.Common.toFormString(tmp));
                }

                // endpoint is setted in product client
                request_.headers = TeaConverter.buildMap(
                    new TeaPair("host", _endpoint),
                    new TeaPair("user-agent", this.getUserAgent())
                );
                if (!com.aliyun.teautil.Common.equalString(authType, "Anonymous")) {
                    String accessKeyId = this.getAccessKeyId();
                    String accessKeySecret = this.getAccessKeySecret();
                    String securityToken = this.getSecurityToken();
                    if (!com.aliyun.teautil.Common.empty(securityToken)) {
                        request_.query.put("SecurityToken", securityToken);
                    }

                    request_.query.put("SignatureMethod", "HMAC-SHA1");
                    request_.query.put("SignatureVersion", "1.0");
                    request_.query.put("AccessKeyId", accessKeyId);
                    request_.query.put("Signature", com.aliyun.common.Common.getSignature(signedParam, request_.method, accessKeySecret));
                }

                _lastRequest = request_;
                TeaResponse response_ = Tea.doAction(request_, runtime_);

                Object obj = com.aliyun.teautil.Common.readAsJSON(response_.body);
                java.util.Map<String, Object> res = com.aliyun.teautil.Common.assertAsMap(obj);
                if (com.aliyun.teautil.Common.is4xx(response_.statusCode) || com.aliyun.teautil.Common.is5xx(response_.statusCode)) {
                    throw new TeaException(TeaConverter.buildMap(
                        new TeaPair("message", res.get("Message")),
                        new TeaPair("data", res),
                        new TeaPair("code", res.get("Code"))
                    ));
                }

                return res;
            } catch (Exception e) {
                if (Tea.isRetryable(e)) {
                    continue;
                }
                throw e;
            }
        }

        throw new TeaUnretryableException(_lastRequest);
    }

    public String getUserAgent() throws Exception {
        String userAgent = com.aliyun.teautil.Common.getUserAgent(_userAgent);
        return userAgent;
    }

    public String getAccessKeyId() throws Exception {
        if (com.aliyun.teautil.Common.isUnset(_credential)) {
            return "";
        }

        String accessKeyId = _credential.getAccessKeyId();
        return accessKeyId;
    }

    public String getAccessKeySecret() throws Exception {
        if (com.aliyun.teautil.Common.isUnset(_credential)) {
            return "";
        }

        String secret = _credential.getAccessKeySecret();
        return secret;
    }

    public String getSecurityToken() throws Exception {
        if (com.aliyun.teautil.Common.isUnset(_credential)) {
            return "";
        }

        String token = _credential.getSecurityToken();
        return token;
    }

    public void checkConfig(Config config) throws Exception {
        if (com.aliyun.teautil.Common.empty(_endpointRule) && com.aliyun.teautil.Common.empty(config.endpoint)) {
            throw new TeaException(TeaConverter.buildMap(
                new TeaPair("name", "ParameterMissing"),
                new TeaPair("message", "'config.endpoint' can not be empty")
            ));
        }

    }
}
