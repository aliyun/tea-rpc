# -*- coding: utf-8 -*-
# This file is auto-generated, don't edit it. Thanks.
import time

from Tea.exceptions import TeaException, UnretryableException
from Tea.request import TeaRequest
from Tea.core import TeaCore
from typing import Dict, Any

from alibabacloud_credentials.client import Client as CredentialClient
from alibabacloud_tea_rpc import models as rpc_models
from alibabacloud_tea_util.client import Client as UtilClient
from alibabacloud_credentials import models as credential_models
from alibabacloud_tea_util import models as util_models
from alibabacloud_rpc_util.client import Client as RPCUtilClient


class Client:
    """
    This is for RPC SDK
    """
    _endpoint: str = None
    _region_id: str = None
    _protocol: str = None
    _user_agent: str = None
    _endpoint_rule: str = None
    _endpoint_map: Dict[str, str] = None
    _suffix: str = None
    _read_timeout: int = None
    _connect_timeout: int = None
    _http_proxy: str = None
    _https_proxy: str = None
    _socks_5proxy: str = None
    _socks_5net_work: str = None
    _no_proxy: str = None
    _network: str = None
    _product_id: str = None
    _max_idle_conns: int = None
    _endpoint_type: str = None
    _open_platform_endpoint: str = None
    _credential: CredentialClient = None

    def __init__(
        self, 
        config: rpc_models.Config,
    ):
        """
        Init client with Config
        @param config: config contains the necessary information to create a client
        """
        if UtilClient.is_unset(config):
            raise TeaException({
                'code': 'ParameterMissing',
                'message': "'config' can not be unset"
            })
        UtilClient.validate_model(config)
        if not UtilClient.empty(config.access_key_id) and not UtilClient.empty(config.access_key_secret):
            if not UtilClient.empty(config.security_token):
                config.type = 'sts'
            else:
                config.type = 'access_key'
            credential_config = credential_models.Config(
                access_key_id=config.access_key_id,
                type=config.type,
                access_key_secret=config.access_key_secret,
                security_token=config.security_token
            )
            self._credential = CredentialClient(credential_config)
        elif not UtilClient.is_unset(config.credential):
            self._credential = config.credential
        else:
            raise TeaException({
                'code': 'ParameterMissing',
                'message': "'accessKeyId' and 'accessKeySecret' or 'credential' can not be unset"
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

    def do_request(
        self,
        action: str,
        protocol: str,
        method: str,
        version: str,
        auth_type: str,
        query: dict,
        body: dict,
        runtime: util_models.RuntimeOptions,
    ) -> dict:
        """
        Encapsulate the request and invoke the network
        @param action: api name
        @param protocol: http or https
        @param method: e.g. GET
        @param version: product version
        @param auth_type: when authType is Anonymous, the signature will not be calculate
        @param pathname: pathname of every api
        @param query: which contains request params
        @param body: content of request
        @param runtime: which controls some details of call api, such as retry times
        @return: the response
        """
        runtime.validate()
        _runtime = {
            'timeouted': 'retry',
            'readTimeout': UtilClient.default_number(runtime.read_timeout, self._read_timeout),
            'connectTimeout': UtilClient.default_number(runtime.connect_timeout, self._connect_timeout),
            'httpProxy': UtilClient.default_string(runtime.http_proxy, self._http_proxy),
            'httpsProxy': UtilClient.default_string(runtime.https_proxy, self._https_proxy),
            'noProxy': UtilClient.default_string(runtime.no_proxy, self._no_proxy),
            'maxIdleConns': UtilClient.default_number(runtime.max_idle_conns, self._max_idle_conns),
            'retry': {
                'retryable': runtime.autoretry,
                'maxAttempts': UtilClient.default_number(runtime.max_attempts, 3)
            },
            'backoff': {
                'policy': UtilClient.default_string(runtime.backoff_policy, 'no'),
                'period': UtilClient.default_number(runtime.backoff_period, 1)
            },
            'ignoreSSL': runtime.ignore_ssl
        }
        _last_request = None
        _last_exception = None
        _now = time.time()
        _retry_times = 0
        while TeaCore.allow_retry(_runtime.get('retry'), _retry_times, _now):
            if _retry_times > 0:
                _backoff_time = TeaCore.get_backoff_time(_runtime.get('backoff'), _retry_times)
                if _backoff_time > 0:
                    TeaCore.sleep(_backoff_time)
            _retry_times = _retry_times + 1
            try:
                _request = TeaRequest()
                _request.protocol = UtilClient.default_string(self._protocol, protocol)
                _request.method = method
                _request.pathname = '/'
                _request.query = RPCUtilClient.query(TeaCore.merge({
                    'Action': action,
                    'Format': 'json',
                    'Timestamp': RPCUtilClient.get_timestamp(),
                    'Version': version,
                    'SignatureNonce': UtilClient.get_nonce()
                }, query))
                # endpoint is setted in product client
                _request.headers = {
                    'x-acs-version': version,
                    'x-acs-action': action,
                    'host': self._endpoint,
                    'user-agent': self.get_user_agent()
                }
                if not UtilClient.is_unset(body):
                    tmp = UtilClient.anyify_map_value(RPCUtilClient.query(body))
                    _request.body = UtilClient.to_form_string(tmp)
                    _request.headers['content-type'] = 'application/x-www-form-urlencoded'
                if not UtilClient.equal_string(auth_type, 'Anonymous'):
                    access_key_id = self.get_access_key_id()
                    access_key_secret = self.get_access_key_secret()
                    security_token = self.get_security_token()
                    if not UtilClient.empty(security_token):
                        _request.query['SecurityToken'] = security_token
                    _request.query['SignatureMethod'] = 'HMAC-SHA1'
                    _request.query['SignatureVersion'] = '1.0'
                    _request.query['AccessKeyId'] = access_key_id
                    signed_param = TeaCore.merge(_request.query,
                        RPCUtilClient.query(body))
                    _request.query['Signature'] = RPCUtilClient.get_signature_v1(signed_param, _request.method, access_key_secret)
                _last_request = _request
                _response = TeaCore.do_action(_request, _runtime)
                obj = UtilClient.read_as_json(_response.body)
                res = UtilClient.assert_as_map(obj)
                if UtilClient.is_4xx(_response.status_code) or UtilClient.is_5xx(_response.status_code):
                    raise TeaException({
                        'code': '%s' % self.default_any(res.get('Code'), res.get('code')),
                        'message': 'code: %s, %s request id: %s' % (_response.status_code, self.default_any(res.get('Message'), res.get('message')), self.default_any(res.get('RequestId'), res.get('requestId'))),
                        'data': res
                    })
                return res
            except Exception as e:
                if TeaCore.is_retryable(e):
                    _last_exception = e
                    continue
                raise e
        raise UnretryableException(_last_request, _last_exception)

    async def do_request_async(
        self,
        action: str,
        protocol: str,
        method: str,
        version: str,
        auth_type: str,
        query: dict,
        body: dict,
        runtime: util_models.RuntimeOptions,
    ) -> dict:
        """
        Encapsulate the request and invoke the network
        @param action: api name
        @param protocol: http or https
        @param method: e.g. GET
        @param version: product version
        @param auth_type: when authType is Anonymous, the signature will not be calculate
        @param pathname: pathname of every api
        @param query: which contains request params
        @param body: content of request
        @param runtime: which controls some details of call api, such as retry times
        @return: the response
        """
        runtime.validate()
        _runtime = {
            'timeouted': 'retry',
            'readTimeout': UtilClient.default_number(runtime.read_timeout, self._read_timeout),
            'connectTimeout': UtilClient.default_number(runtime.connect_timeout, self._connect_timeout),
            'httpProxy': UtilClient.default_string(runtime.http_proxy, self._http_proxy),
            'httpsProxy': UtilClient.default_string(runtime.https_proxy, self._https_proxy),
            'noProxy': UtilClient.default_string(runtime.no_proxy, self._no_proxy),
            'maxIdleConns': UtilClient.default_number(runtime.max_idle_conns, self._max_idle_conns),
            'retry': {
                'retryable': runtime.autoretry,
                'maxAttempts': UtilClient.default_number(runtime.max_attempts, 3)
            },
            'backoff': {
                'policy': UtilClient.default_string(runtime.backoff_policy, 'no'),
                'period': UtilClient.default_number(runtime.backoff_period, 1)
            },
            'ignoreSSL': runtime.ignore_ssl
        }
        _last_request = None
        _last_exception = None
        _now = time.time()
        _retry_times = 0
        while TeaCore.allow_retry(_runtime.get('retry'), _retry_times, _now):
            if _retry_times > 0:
                _backoff_time = TeaCore.get_backoff_time(_runtime.get('backoff'), _retry_times)
                if _backoff_time > 0:
                    TeaCore.sleep(_backoff_time)
            _retry_times = _retry_times + 1
            try:
                _request = TeaRequest()
                _request.protocol = UtilClient.default_string(self._protocol, protocol)
                _request.method = method
                _request.pathname = '/'
                _request.query = RPCUtilClient.query(TeaCore.merge({
                    'Action': action,
                    'Format': 'json',
                    'Timestamp': RPCUtilClient.get_timestamp(),
                    'Version': version,
                    'SignatureNonce': UtilClient.get_nonce()
                }, query))
                # endpoint is setted in product client
                _request.headers = {
                    'x-acs-version': version,
                    'x-acs-action': action,
                    'host': self._endpoint,
                    'user-agent': self.get_user_agent()
                }
                if not UtilClient.is_unset(body):
                    tmp = UtilClient.anyify_map_value(RPCUtilClient.query(body))
                    _request.body = UtilClient.to_form_string(tmp)
                    _request.headers['content-type'] = 'application/x-www-form-urlencoded'
                if not UtilClient.equal_string(auth_type, 'Anonymous'):
                    access_key_id = await self.get_access_key_id_async()
                    access_key_secret = await self.get_access_key_secret_async()
                    security_token = await self.get_security_token_async()
                    if not UtilClient.empty(security_token):
                        _request.query['SecurityToken'] = security_token
                    _request.query['SignatureMethod'] = 'HMAC-SHA1'
                    _request.query['SignatureVersion'] = '1.0'
                    _request.query['AccessKeyId'] = access_key_id
                    signed_param = TeaCore.merge(_request.query,
                        RPCUtilClient.query(body))
                    _request.query['Signature'] = RPCUtilClient.get_signature_v1(signed_param, _request.method, access_key_secret)
                _last_request = _request
                _response = await TeaCore.async_do_action(_request, _runtime)
                obj = await UtilClient.read_as_json_async(_response.body)
                res = UtilClient.assert_as_map(obj)
                if UtilClient.is_4xx(_response.status_code) or UtilClient.is_5xx(_response.status_code):
                    raise TeaException({
                        'code': '%s' % self.default_any(res.get('Code'), res.get('code')),
                        'message': 'code: %s, %s request id: %s' % (_response.status_code, self.default_any(res.get('Message'), res.get('message')), self.default_any(res.get('RequestId'), res.get('requestId'))),
                        'data': res
                    })
                return res
            except Exception as e:
                if TeaCore.is_retryable(e):
                    _last_exception = e
                    continue
                raise e
        raise UnretryableException(_last_request, _last_exception)

    def get_user_agent(self) -> str:
        """
        Get user agent
        @return: user agent
        """
        user_agent = UtilClient.get_user_agent(self._user_agent)
        return user_agent

    def get_access_key_id(self) -> str:
        """
        Get accesskey id by using credential
        @return: accesskey id
        """
        if UtilClient.is_unset(self._credential):
            return ''
        access_key_id = self._credential.get_access_key_id()
        return access_key_id

    async def get_access_key_id_async(self) -> str:
        """
        Get accesskey id by using credential
        @return: accesskey id
        """
        if UtilClient.is_unset(self._credential):
            return ''
        access_key_id = await self._credential.get_access_key_id_async()
        return access_key_id

    def get_access_key_secret(self) -> str:
        """
        Get accesskey secret by using credential
        @return: accesskey secret
        """
        if UtilClient.is_unset(self._credential):
            return ''
        secret = self._credential.get_access_key_secret()
        return secret

    async def get_access_key_secret_async(self) -> str:
        """
        Get accesskey secret by using credential
        @return: accesskey secret
        """
        if UtilClient.is_unset(self._credential):
            return ''
        secret = await self._credential.get_access_key_secret_async()
        return secret

    def get_security_token(self) -> str:
        """
        Get security token by using credential
        @return: security token
        """
        if UtilClient.is_unset(self._credential):
            return ''
        token = self._credential.get_security_token()
        return token

    async def get_security_token_async(self) -> str:
        """
        Get security token by using credential
        @return: security token
        """
        if UtilClient.is_unset(self._credential):
            return ''
        token = await self._credential.get_security_token_async()
        return token

    def check_config(
        self,
        config: rpc_models.Config,
    ) -> None:
        """
        If the endpointRule and config.endpoint are empty, throw error
        @param config: config contains the necessary information to create a client
        """
        if UtilClient.empty(self._endpoint_rule) and UtilClient.empty(config.endpoint):
            raise TeaException({
                'code': 'ParameterMissing',
                'message': "'config.endpoint' can not be empty"
            })

    @staticmethod
    def default_any(
        input_value: Any,
        default_value: Any,
    ) -> Any:
        """
        If inputValue is not null, return it or return defaultValue
        @param input_value:  users input value
        @param default_value: default value
        @return: the final result
        """
        if UtilClient.is_unset(input_value):
            return default_value
        return input_value
