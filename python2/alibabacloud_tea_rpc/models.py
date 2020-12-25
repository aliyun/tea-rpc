# -*- coding: utf-8 -*-
# This file is auto-generated, don't edit it. Thanks.
from Tea.model import TeaModel
from Tea.converter import TeaConverter

from alibabacloud_credentials.client import Client as CredentialClient


class Config(TeaModel):
    """
    Model for initing client
    """
    def __init__(self, access_key_id=None, access_key_secret=None, security_token=None, protocol=None,
                 region_id=None, read_timeout=None, connect_timeout=None, http_proxy=None, https_proxy=None, credential=None,
                 endpoint=None, no_proxy=None, max_idle_conns=None, network=None, user_agent=None, suffix=None,
                 socks_5proxy=None, socks_5net_work=None, endpoint_type=None, open_platform_endpoint=None, type=None):
        # accesskey id
        self.access_key_id = TeaConverter.to_unicode(access_key_id)  # type: unicode
        # accesskey secret
        self.access_key_secret = TeaConverter.to_unicode(access_key_secret)  # type: unicode
        # security token
        self.security_token = TeaConverter.to_unicode(security_token)  # type: unicode
        # http protocol
        self.protocol = TeaConverter.to_unicode(protocol)  # type: unicode
        # region id
        self.region_id = TeaConverter.to_unicode(region_id)  # type: unicode
        # read timeout
        self.read_timeout = read_timeout  # type: int
        # connect timeout
        self.connect_timeout = connect_timeout  # type: int
        # http proxy
        self.http_proxy = TeaConverter.to_unicode(http_proxy)  # type: unicode
        # https proxy
        self.https_proxy = TeaConverter.to_unicode(https_proxy)  # type: unicode
        # credential
        self.credential = credential  # type: CredentialClient
        # endpoint
        self.endpoint = TeaConverter.to_unicode(endpoint)  # type: unicode
        # proxy white list
        self.no_proxy = TeaConverter.to_unicode(no_proxy)  # type: unicode
        # max idle conns
        self.max_idle_conns = max_idle_conns  # type: int
        # network for endpoint
        self.network = TeaConverter.to_unicode(network)  # type: unicode
        # user agent
        self.user_agent = TeaConverter.to_unicode(user_agent)  # type: unicode
        # suffix for endpoint
        self.suffix = TeaConverter.to_unicode(suffix)  # type: unicode
        # socks5 proxy
        self.socks_5proxy = TeaConverter.to_unicode(socks_5proxy)  # type: unicode
        # socks5 network
        self.socks_5net_work = TeaConverter.to_unicode(socks_5net_work)  # type: unicode
        # endpoint type
        self.endpoint_type = TeaConverter.to_unicode(endpoint_type)  # type: unicode
        # OpenPlatform endpoint
        self.open_platform_endpoint = TeaConverter.to_unicode(open_platform_endpoint)  # type: unicode
        # credential type
        self.type = TeaConverter.to_unicode(type)  # type: unicode

    def validate(self):
        if self.region_id is not None:
            self.validate_pattern(self.region_id, 'region_id', '^[a-zA-Z0-9_-]+$')
        if self.network is not None:
            self.validate_pattern(self.network, 'network', '^[a-zA-Z0-9_-]+$')
        if self.suffix is not None:
            self.validate_pattern(self.suffix, 'suffix', '^[a-zA-Z0-9_-]+$')

    def to_map(self):
        result = dict()
        if self.access_key_id is not None:
            result['accessKeyId'] = self.access_key_id
        if self.access_key_secret is not None:
            result['accessKeySecret'] = self.access_key_secret
        if self.security_token is not None:
            result['securityToken'] = self.security_token
        if self.protocol is not None:
            result['protocol'] = self.protocol
        if self.region_id is not None:
            result['regionId'] = self.region_id
        if self.read_timeout is not None:
            result['readTimeout'] = self.read_timeout
        if self.connect_timeout is not None:
            result['connectTimeout'] = self.connect_timeout
        if self.http_proxy is not None:
            result['httpProxy'] = self.http_proxy
        if self.https_proxy is not None:
            result['httpsProxy'] = self.https_proxy
        if self.credential is not None:
            result['credential'] = self.credential
        if self.endpoint is not None:
            result['endpoint'] = self.endpoint
        if self.no_proxy is not None:
            result['noProxy'] = self.no_proxy
        if self.max_idle_conns is not None:
            result['maxIdleConns'] = self.max_idle_conns
        if self.network is not None:
            result['network'] = self.network
        if self.user_agent is not None:
            result['userAgent'] = self.user_agent
        if self.suffix is not None:
            result['suffix'] = self.suffix
        if self.socks_5proxy is not None:
            result['socks5Proxy'] = self.socks_5proxy
        if self.socks_5net_work is not None:
            result['socks5NetWork'] = self.socks_5net_work
        if self.endpoint_type is not None:
            result['endpointType'] = self.endpoint_type
        if self.open_platform_endpoint is not None:
            result['openPlatformEndpoint'] = self.open_platform_endpoint
        if self.type is not None:
            result['type'] = self.type
        return result

    def from_map(self, m=None):
        m = m or dict()
        if m.get('accessKeyId') is not None:
            self.access_key_id = m.get('accessKeyId')
        if m.get('accessKeySecret') is not None:
            self.access_key_secret = m.get('accessKeySecret')
        if m.get('securityToken') is not None:
            self.security_token = m.get('securityToken')
        if m.get('protocol') is not None:
            self.protocol = m.get('protocol')
        if m.get('regionId') is not None:
            self.region_id = m.get('regionId')
        if m.get('readTimeout') is not None:
            self.read_timeout = m.get('readTimeout')
        if m.get('connectTimeout') is not None:
            self.connect_timeout = m.get('connectTimeout')
        if m.get('httpProxy') is not None:
            self.http_proxy = m.get('httpProxy')
        if m.get('httpsProxy') is not None:
            self.https_proxy = m.get('httpsProxy')
        if m.get('credential') is not None:
            self.credential = m.get('credential')
        if m.get('endpoint') is not None:
            self.endpoint = m.get('endpoint')
        if m.get('noProxy') is not None:
            self.no_proxy = m.get('noProxy')
        if m.get('maxIdleConns') is not None:
            self.max_idle_conns = m.get('maxIdleConns')
        if m.get('network') is not None:
            self.network = m.get('network')
        if m.get('userAgent') is not None:
            self.user_agent = m.get('userAgent')
        if m.get('suffix') is not None:
            self.suffix = m.get('suffix')
        if m.get('socks5Proxy') is not None:
            self.socks_5proxy = m.get('socks5Proxy')
        if m.get('socks5NetWork') is not None:
            self.socks_5net_work = m.get('socks5NetWork')
        if m.get('endpointType') is not None:
            self.endpoint_type = m.get('endpointType')
        if m.get('openPlatformEndpoint') is not None:
            self.open_platform_endpoint = m.get('openPlatformEndpoint')
        if m.get('type') is not None:
            self.type = m.get('type')
        return self


