# This file is auto-generated, don't edit it. Thanks.
from Tea.model import TeaModel

"""
Model for initing client
"""


class Config(TeaModel):
    def __init__(self, access_key_id="", access_key_secret="", security_token="", protocol="", region_id="",
                 read_timeout=0, connect_timeout=0, http_proxy="", https_proxy="", credential=None, endpoint="",
                 no_proxy="", max_idle_conns=0, network="", user_agent="", suffix="", socks_5proxy="",
                 socks_5net_work="", endpoint_type="", open_platform_endpoint="", type=""):
        self.access_key_id = access_key_id
        self.access_key_secret = access_key_secret
        self.security_token = security_token
        self.protocol = protocol
        self.region_id = region_id
        self.read_timeout = read_timeout
        self.connect_timeout = connect_timeout
        self.http_proxy = http_proxy
        self.https_proxy = https_proxy
        self.credential = credential
        self.endpoint = endpoint
        self.no_proxy = no_proxy
        self.max_idle_conns = max_idle_conns
        self.network = network
        self.user_agent = user_agent
        self.suffix = suffix
        self.socks_5proxy = socks_5proxy
        self.socks_5net_work = socks_5net_work
        self.endpoint_type = endpoint_type
        self.open_platform_endpoint = open_platform_endpoint
        self.type = type

    def validate(self):
        if self.credential:
            self.credential.validate()

    def to_map(self):
        result = {}
        result['accessKeyId'] = self.access_key_id
        result['accessKeySecret'] = self.access_key_secret
        result['securityToken'] = self.security_token
        result['protocol'] = self.protocol
        result['regionId'] = self.region_id
        result['readTimeout'] = self.read_timeout
        result['connectTimeout'] = self.connect_timeout
        result['httpProxy'] = self.http_proxy
        result['httpsProxy'] = self.https_proxy
        result['credential'] = self.credential
        result['endpoint'] = self.endpoint
        result['noProxy'] = self.no_proxy
        result['maxIdleConns'] = self.max_idle_conns
        result['network'] = self.network
        result['userAgent'] = self.user_agent
        result['suffix'] = self.suffix
        result['socks5Proxy'] = self.socks_5proxy
        result['socks5NetWork'] = self.socks_5net_work
        result['endpointType'] = self.endpoint_type
        result['openPlatformEndpoint'] = self.open_platform_endpoint
        result['type'] = self.type
        return result

    def from_map(self, map={}):
        self.access_key_id = map.get('accessKeyId')
        self.access_key_secret = map.get('accessKeySecret')
        self.security_token = map.get('securityToken')
        self.protocol = map.get('protocol')
        self.region_id = map.get('regionId')
        self.read_timeout = map.get('readTimeout')
        self.connect_timeout = map.get('connectTimeout')
        self.http_proxy = map.get('httpProxy')
        self.https_proxy = map.get('httpsProxy')
        self.credential = map.get('credential')
        self.endpoint = map.get('endpoint')
        self.no_proxy = map.get('noProxy')
        self.max_idle_conns = map.get('maxIdleConns')
        self.network = map.get('network')
        self.user_agent = map.get('userAgent')
        self.suffix = map.get('suffix')
        self.socks_5proxy = map.get('socks5Proxy')
        self.socks_5net_work = map.get('socks5NetWork')
        self.endpoint_type = map.get('endpointType')
        self.open_platform_endpoint = map.get('openPlatformEndpoint')
        self.type = map.get('type')
        return self
