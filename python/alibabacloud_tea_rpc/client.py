# This file is auto-generated, don't edit it. Thanks.
import time

from alibabacloud_credentials.client import Client as alibabacloud_credentials_client_Client
from alibabacloud_tea_rpc import models as alibabacloud_tea_rpc_models
from alibabacloud_tea_util.client import Client as alibabacloud_tea_util_client_Client
from Tea.exceptions import TeaException as Tea_exceptions_TeaException
from alibabacloud_credentials import models as alibabacloud_credentials_models
from alibabacloud_tea_util import models as alibabacloud_tea_util_models
from Tea.request import TeaRequest as Tea_request_TeaRequest
from Tea.core import TeaCore as Tea_core_TeaCore
from Tea.response import TeaResponse as Tea_response_TeaResponse
from alibabacloud_rpc_util.client import Client as alibabacloud_rpc_util_client_Client
from Tea.exceptions import UnretryableException as Tea_exceptions_UnretryableException


"""
This is for RPC SDK
"""
class Client:
    def __init__(self, config, _endpoint="", _region_id="", _protocol="", _user_agent="", _endpoint_rule="", _endpoint_map=None, _suffix="", _read_timeout=0, _connect_timeout=0, _http_proxy="", _https_proxy="", _socks_5proxy="", _socks_5net_work="", _no_proxy="", _network="", _product_id="", _max_idle_conns=0, _endpoint_type="", _open_platform_endpoint="", _credential=None):
        """
        Init client with Config
        @param config config contains the necessary information to create a client
        """
        self._endpoint = _endpoint
        self._region_id = _region_id
        self._protocol = _protocol
        self._user_agent = _user_agent
        self._endpoint_rule = _endpoint_rule
        self._endpoint_map = {}
        self._suffix = _suffix
        self._read_timeout = _read_timeout
        self._connect_timeout = _connect_timeout
        self._http_proxy = _http_proxy
        self._https_proxy = _https_proxy
        self._socks_5proxy = _socks_5proxy
        self._socks_5net_work = _socks_5net_work
        self._no_proxy = _no_proxy
        self._network = _network
        self._product_id = _product_id
        self._max_idle_conns = _max_idle_conns
        self._endpoint_type = _endpoint_type
        self._open_platform_endpoint = _open_platform_endpoint
        self._credential = _credential
        if alibabacloud_tea_util_client_Client.is_unset(config) :
            raise Tea_exceptions_TeaException({
                "code" : "ParameterMissing",
                "message" : "'config' can not be unset"
                })
        if not alibabacloud_tea_util_client_Client.empty(config.access_key_id) and not alibabacloud_tea_util_client_Client.empty(config.access_key_secret) :
            if not alibabacloud_tea_util_client_Client.empty(config.security_token) :
                config.type = "sts"
            else :
                config.type = "access_key"
            credential_config = alibabacloud_credentials_models.Config(
                access_key_id = config.access_key_id,
                type = config.type,
                access_key_secret = config.access_key_secret,
                security_token = config.security_token
            )
            self._credential = alibabacloud_credentials_client_Client(credential_config)
        elif not alibabacloud_tea_util_client_Client.is_unset(config.credential) :
            self._credential = config.credential
        else :
            raise Tea_exceptions_TeaException({
                "code" : "ParameterMissing",
                "message" : "'accessKeyId' and 'accessKeySecret' or 'credential' can not be unset"
                })
        self._network = config.network
        self._suffix = config.suffix
        self._endpoint = config.endpoint
        self._protocol = config.protocol
        self._region_id = config.region_id
        self._user_agent = config.user_agent
        self._read_timeout = config.read_timeout
        self._connect_timeout = config.connect_timeout
        self._http_proxy = config.http_proxy
        self._https_proxy = config.https_proxy
        self._no_proxy = config.no_proxy
        self._socks_5proxy = config.socks_5proxy
        self._socks_5net_work = config.socks_5net_work
        self._max_idle_conns = config.max_idle_conns
        self._endpoint_type = config.endpoint_type
        self._open_platform_endpoint = config.open_platform_endpoint


    def do_request(self, action, protocol, method, version, auth_type, query, body, runtime):
        """
        Encapsulate the request and invoke the network
        @param action api name
        @param protocol http or https
        @param method e.g. GET
        @param version product version
        @param authType when authType is Anonymous, the signature will not be calculate
        @param pathname pathname of every api
        @param query which contains request params
        @param body content of request
        @param runtime which controls some details of call api, such as retry times
        @return the response
        """
        runtime.validate()
        _runtime = {
            "timeouted" : "retry",
            "readTimeout" : alibabacloud_tea_util_client_Client.default_number(runtime.read_timeout, self._read_timeout),
            "connectTimeout" : alibabacloud_tea_util_client_Client.default_number(runtime.connect_timeout, self._connect_timeout),
            "httpProxy" : alibabacloud_tea_util_client_Client.default_string(runtime.http_proxy, self._http_proxy),
            "httpsProxy" : alibabacloud_tea_util_client_Client.default_string(runtime.https_proxy, self._https_proxy),
            "noProxy" : alibabacloud_tea_util_client_Client.default_string(runtime.no_proxy, self._no_proxy),
            "maxIdleConns" : alibabacloud_tea_util_client_Client.default_number(runtime.max_idle_conns, self._max_idle_conns),
            "retry" : {
                "retryable" : runtime.autoretry,
                "maxAttempts" : alibabacloud_tea_util_client_Client.default_number(runtime.max_attempts, 3)
                },
            "backoff" : {
                "policy" : alibabacloud_tea_util_client_Client.default_string(runtime.backoff_policy, "no"),
                "period" : alibabacloud_tea_util_client_Client.default_number(runtime.backoff_period, 1)
                },
            "ignoreSSL" : runtime.ignore_ssl
            }
        _last_request = None
        _last_exception = None
        _now = time.time()
        _retry_times = 0
        while Tea_core_TeaCore.allow_retry(_runtime["retry"], _retry_times, _now) :
            if _retry_times > 0 :
                _backoff_time = Tea_core_TeaCore.get_backoff_time(_runtime["backoff"], _retry_times)
                if _backoff_time > 0 :
                    Tea_core_TeaCore.sleep(_backoff_time)
            _retry_times = _retry_times + 1
            try :
                _request = Tea_request_TeaRequest()
                _request.protocol = alibabacloud_tea_util_client_Client.default_string(self._protocol, protocol)
                _request.method = method
                _request.pathname = "/"
                _request.query = alibabacloud_rpc_util_client_Client.query(Tea_core_TeaCore.merge({
                    "Action" : action,
                    "Format" : "json",
                    "Timestamp" : alibabacloud_rpc_util_client_Client.get_timestamp(),
                    "Version" : version,
                    "SignatureNonce" : alibabacloud_tea_util_client_Client.get_nonce()
                    }, query))
                # endpoint is setted in product client
                _request.headers = {
                    "host" : self._endpoint,
                    "user-agent" : self.get_user_agent()
                    }
                if not alibabacloud_tea_util_client_Client.is_unset(body) :
                    tmp = alibabacloud_tea_util_client_Client.anyify_map_value(alibabacloud_rpc_util_client_Client.query(body))
                    _request.body = alibabacloud_tea_util_client_Client.to_form_string(tmp)
                    _request.headers["content-type"] = "application/x-www-form-urlencoded"
                if not alibabacloud_tea_util_client_Client.equal_string(auth_type, "Anonymous") :
                    access_key_id = self.get_access_key_id()
                    access_key_secret = self.get_access_key_secret()
                    security_token = self.get_security_token()
                    if not alibabacloud_tea_util_client_Client.empty(security_token) :
                        _request.query["SecurityToken"] = security_token
                    _request.query["SignatureMethod"] = "HMAC-SHA1"
                    _request.query["SignatureVersion"] = "1.0"
                    _request.query["AccessKeyId"] = access_key_id
                    signed_param = Tea_core_TeaCore.merge(_request.query,
                        alibabacloud_rpc_util_client_Client.query(body))
                    _request.query["Signature"] = alibabacloud_rpc_util_client_Client.get_signature_v1(signed_param, _request.method, access_key_secret)
                _last_request = _request
                _response= Tea_core_TeaCore.do_action(_request, _runtime)
                obj = alibabacloud_tea_util_client_Client.read_as_json(_response.body)
                res = alibabacloud_tea_util_client_Client.assert_as_map(obj)
                if alibabacloud_tea_util_client_Client.is_4xx(_response.status_code) or alibabacloud_tea_util_client_Client.is_5xx(_response.status_code) :
                    raise Tea_exceptions_TeaException({
                        "message" : res["Message"],
                        "data" : res,
                        "code" : res["Code"]
                        })
                return res
            except Exception as e :
                if Tea_core_TeaCore.is_retryable(e) :
                    _last_exception = e
                    continue
                raise e
        raise Tea_exceptions_UnretryableException(_last_request, _last_exception)

    def get_user_agent(self):
        """
        Get user agent
        @return user agent
        """
        user_agent = alibabacloud_tea_util_client_Client.get_user_agent(self._user_agent)
        return user_agent

    def get_access_key_id(self):
        """
        Get accesskey id by using credential
        @return accesskey id
        """
        if alibabacloud_tea_util_client_Client.is_unset(self._credential) :
            return ''
        access_key_id = self._credential.get_access_key_id()
        return access_key_id

    def get_access_key_secret(self):
        """
        Get accesskey secret by using credential
        @return accesskey secret
        """
        if alibabacloud_tea_util_client_Client.is_unset(self._credential) :
            return ''
        secret = self._credential.get_access_key_secret()
        return secret

    def get_security_token(self):
        """
        Get security token by using credential
        @return security token
        """
        if alibabacloud_tea_util_client_Client.is_unset(self._credential) :
            return ''
        token = self._credential.get_security_token()
        return token

    def check_config(self, config):
        """
        If the endpointRule and config.endpoint are empty, throw error
        @param config config contains the necessary information to create a client
        """
        if alibabacloud_tea_util_client_Client.empty(self._endpoint_rule) and alibabacloud_tea_util_client_Client.empty(config.endpoint) :
            raise Tea_exceptions_TeaException({
                "code" : "ParameterMissing",
                "message" : "'config.endpoint' can not be empty"
                })
